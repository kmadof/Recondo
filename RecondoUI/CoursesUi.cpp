#include "CoursesUi.h"
#include <qstandarditemmodel.h>
#include "AppSettings.h"
#include <string>
#include <qlist.h>
#include <qlistview.h>
#include <QtGui\qlistview.h>
#include "CourseItem.h"

CoursesUI::CoursesUI(RecondoModel* model, QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	setupUi(this);

	QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(selectedCourse()));
	
	_presenter = new CoursesPresenter(this, model);

	Courses courses = _presenter->GetCoursesItem();

	QStandardItemModel *itemModel = new QStandardItemModel(courses.size(), 1);
	itemModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Courses"));
	int i = 0;
	for(Courses::const_iterator it = courses.begin(); it != courses.end(); ++it)
	{
		QStandardItem *item = new QStandardItem(QString(it->get()->GetCourseName().c_str()));
		itemModel->setItem(i++, 0, item);
	}
	
	listView->setModel(itemModel);
}

CoursesUI::~CoursesUI()
{
	delete _presenter;
}

std::string CoursesUI::GetCurrentLection()
{
	QModelIndexList indexes;
	//indexes = listView->selectedIndexes();
	QItemSelectionModel* selModel =  listView->selectionModel();
	QModelIndexList indexList = selModel->selectedRows();
	if(!indexList.empty())
	{
		QModelIndex index = indexList.first();
		QVariant variant = index.data();
		QString data = variant.toString();
		return data.toStdString();
	}
	return "";
}

void CoursesUI::selectedCourse()
{
	_presenter->PutCurrentLection();
}
