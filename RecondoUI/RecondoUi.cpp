#include "RecondoUi.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <string>

RecondoUI::RecondoUI(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	QObject::connect(btnShowAnswer, SIGNAL(clicked()), this, SLOT(doThing()));
	QObject::connect(actionChooseCourse, SIGNAL(triggered()), this, SLOT(showCourseForm()));

	_model = new RecondoModel();
	_presenter = new RecondoPresenter(this, _model);
	_presenter->SetCurrentCourseNameOnView();
}

RecondoUI::~RecondoUI()
{
	delete _presenter;
	delete _model;
}

void RecondoUI::doThing(void)
{
	textAnswer->setText("HEJ");
}

void RecondoUI::showCourseForm(void)
{
	cForm = new CoursesUI(_model);
	int result = cForm->exec();
	if(result)
		_presenter->SetCurrentCourseNameOnView();
}

void RecondoUI::SetCurrentCourseName(std::string courseName)
{
	lbCourseName->setText(QString(courseName.c_str()));
}