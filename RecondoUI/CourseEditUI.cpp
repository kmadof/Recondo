#include "CourseEditUi.h"
#include <qstandarditemmodel.h>
#include <qmessagebox.h>
#include <boost/lexical_cast.hpp>

//#include "RecondoModel.h"

CourseEditUI::CourseEditUI(RecondoModel* model, QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	setupUi(this);

	_addingNewItem = false;
	_presenter = new CourseEditPresenter(this, model);
	_presenter->SetCourseInfoOnView();
	_items = _presenter->GetItemsToEdit();
	FillTable();

	QItemSelectionModel *sm = tableView->selectionModel();
	QObject::connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
				this, SLOT(tableViewCurrentRowChanged(QModelIndex,QModelIndex)));
	QObject::connect(sm, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
				this, SLOT(tableViewSelectionChanged(QItemSelection,QItemSelection)));
	QObject::connect(btnSave, SIGNAL(clicked()), this, SLOT(changeItem()));
	QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(saveItemToFile()));
	QObject::connect(btnNew, SIGNAL(clicked()), this, SLOT(addNewItem()));
	QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(cancelAdd()));
}

CourseEditUI::~CourseEditUI()
{
	delete _presenter;
}

void CourseEditUI::FillTable()
{
	_items = _presenter->GetItemsToEdit();

	QStandardItemModel *itemModel = new QStandardItemModel(_items.size(), 2);
	
	itemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Pytanie"));
	itemModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Odpowiedz"));
	

	int i = 0;
	for(Items::const_iterator it = _items.begin(); it != _items.end(); ++it)
	{
		QStandardItem *itemQuestion = new QStandardItem(QString(it->get()->GetQuestion().c_str()));
		QStandardItem *itemAnswer = new QStandardItem(QString(it->get()->GetAnswer().c_str()));
		itemModel->setItem(i, 0, itemQuestion);
		itemModel->setItem(i, 1, itemAnswer);
		++i;
	}

	tableView->setModel(itemModel);

}

void CourseEditUI::SetCourseName(std::string name)
{
	txtName->setText(QString(name.c_str()));
}

void CourseEditUI::SetCoursePath(std::string path)
{
	txtPath->setText(QString(path.c_str()));
}

void CourseEditUI::tableViewCurrentRowChanged(QModelIndex index1,QModelIndex index2)
{
	_currentRow = index1.row();
}

void CourseEditUI::tableViewSelectionChanged( const QItemSelection & selected, const QItemSelection & deselected )
{
	if(selected.count() > 0)
	{
		QModelIndexList selectedList = selected.at(0).indexes();
		if(selectedList.count() > 0)
		{
			QString question = selectedList.value(0).data().toString();
			QString answer = selectedList.value(1).data().toString();
			txtQuestion->setText(question);
			txtAnswer->setText(answer);
			for(Items::const_iterator it = _items.begin(); it != _items.end(); ++it)
			{
				if(it->get()->GetQuestion() == question.toStdString() && it->get()->GetAnswer() == answer.toStdString())
				{
					_currentItem = *it;
					return;
				}
				
			}
			_currentItem = ItemPtr();
		}
	}
}

void CourseEditUI::changeItem()
{
	if(_addingNewItem)
	{
		tableView->model()->insertRow(tableView->model()->rowCount());
		//tableView->selectRow(tableView->model()->rowCount()-1);
		QItemSelectionModel *sm = tableView->selectionModel();
		tableView->model()->setData(tableView->model()->index(tableView->model()->rowCount() - 1, 0), QVariant(txtQuestion->toPlainText()));
		tableView->model()->setData(tableView->model()->index(tableView->model()->rowCount() - 1, 1), QVariant(txtAnswer->toPlainText()));
		_items.push_back(ItemPtr(new Item(txtQuestion->toPlainText().toStdString(), txtAnswer->toPlainText().toStdString())));

		btnNew->setEnabled(true);
		btnCancel->setEnabled(false);
	}
	else
	{
		QItemSelectionModel *sm = tableView->selectionModel();
		tableView->model()->setData(tableView->model()->index(_currentRow, 0), QVariant(txtQuestion->toPlainText()));
		tableView->model()->setData(tableView->model()->index(_currentRow, 1), QVariant(txtAnswer->toPlainText()));
		if(_currentItem.get() != NULL)
		{
			_items.remove(_currentItem);
			_currentItem = ItemPtr(new Item(txtQuestion->toPlainText().toStdString(), txtAnswer->toPlainText().toStdString()));
			_items.push_back(_currentItem);
		}
	}
	
	_addingNewItem = false;
}

void CourseEditUI::saveItemToFile()
{
	_presenter->SaveChangedItems(_items);
}

void CourseEditUI::addNewItem()
{
	_addingNewItem = true;
	btnNew->setEnabled(false);
	btnCancel->setEnabled(true);
	txtQuestion->setText("");
	txtAnswer->setText("");
}

void CourseEditUI::cancelAdd()
{
	_addingNewItem = false;
	btnNew->setEnabled(true);
	btnCancel->setEnabled(false);
	txtQuestion->setText("");
	txtAnswer->setText("");
}