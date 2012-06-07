#include "RecondoUi.h"
#include <qfiledialog.h>
#include <string>

RecondoUI::RecondoUI(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	QObject::connect(btnShowAnswer, SIGNAL(clicked()), this, SLOT(doThing()));
	QObject::connect(actionChooseCourse, SIGNAL(triggered()), this, SLOT(showCourseForm()));
	QObject::connect(actionReadCourse, SIGNAL(triggered()), this, SLOT(addCourse()));

	_model = new RecondoModel();
	_presenter = new RecondoPresenter(this, _model);
}

RecondoUI::~RecondoUI()
{
	delete _presenter;
	delete _model;
}

void RecondoUI::doThing(void)
{
	//textAnswer-&amp;gt;append(&amp;quot;I did thing A!&amp;quot;);
	textAnswer->setText("HEJ");
}

void RecondoUI::showCourseForm(void)
{
	cForm = new CoursesUI(_model);
	cForm->exec();
}

void RecondoUI::addCourse(void)
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

			_presenter->AddCourse();
		}
	}
}

std::string RecondoUI::GetFileName(const std::string& path)
{
  size_t found = path.find_last_of("/\\");
  if(found > 0)
	  return path.substr(found+1);
  else
	  return "";
}

CoursePtr RecondoUI::GetNewCourseItem()
{
	return _newCourse;
}