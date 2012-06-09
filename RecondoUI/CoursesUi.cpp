#include "CoursesUi.h"
#include <qstandarditemmodel.h>
#include "AppSettings.h"
#include <string>
#include <qlist.h>
#include <qlistview.h>
#include <QtGui\qlistview.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include "CourseItem.h"

CoursesUI::CoursesUI(RecondoModel* model, QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	setupUi(this);

	QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(selectedCourse()));
	QObject::connect(btnDelete, SIGNAL(clicked()), this, SLOT(removeCourse()));
	QObject::connect(btnAddCourse, SIGNAL(clicked()), this, SLOT(addCourse()));
	
	_presenter = new CoursesPresenter(this, model);

	FillList();
}

CoursesUI::~CoursesUI()
{
	delete _presenter;
}

void CoursesUI::FillList()
{
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


std::string CoursesUI::GetSelectedCourse()
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
	_presenter->GetSelectedCourse();
}

void CoursesUI::removeCourse()
{
	if (_presenter->RemoveCourse())
		FillList();
}

void CoursesUI::addCourse()
{
	QFileDialog dialog(this);
	dialog.setNameFilter(tr("CourseFile (*.txt *.xml)"));
	dialog.setViewMode(QFileDialog::Detail);
	
	QStringList fileNames;
	if (dialog.exec())
	{
		fileNames = dialog.selectedFiles();
		if(!fileNames.isEmpty())
		{
			std::string coursePath = fileNames[0].toStdString();
			std::string courseName = GetFileName(coursePath);
			_newCourse = CoursePtr(new CourseItem(courseName, coursePath));

			if(!_presenter->AddCourse())
			{
				QMessageBox msgBox;
				msgBox.setText("Wybrany kurs juz istnieje w bazie");
				msgBox.exec();
			}
			else
				FillList();
		}
	}
}

CoursePtr CoursesUI::GetNewCourseItem()
{
	return _newCourse;
}

std::string CoursesUI::GetFileName(const std::string& path)
{
  size_t found = path.find_last_of("/\\");
  if(found > 0)
	  return path.substr(found+1);
  else
	  return "";
}