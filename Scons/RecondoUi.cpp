#include "RecondoUi.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <string>

RecondoUI::RecondoUI(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
	QObject::connect(actionChooseCourse, SIGNAL(triggered()), this, SLOT(showCourseForm()));
	QObject::connect(actionStartLection, SIGNAL(triggered()), this, SLOT(startLection()));
	QObject::connect(actionEndLection, SIGNAL(triggered()), this, SLOT(endLection()));

	QObject::connect(btnShowAnswer, SIGNAL(clicked()), this, SLOT(showAnswer()));
	QObject::connect(btnNextQuestion, SIGNAL(clicked()), this, SLOT(nextQuestion()));

	QObject::connect(btnQualityZero, SIGNAL(clicked()), this, SLOT(setQualityZero()));
	QObject::connect(btnQualityOne, SIGNAL(clicked()), this, SLOT(setQualityOne()));
	QObject::connect(btnQualityTwo, SIGNAL(clicked()), this, SLOT(setQualityTwo()));
	QObject::connect(btnQualityThree, SIGNAL(clicked()), this, SLOT(setQualityThree()));
	QObject::connect(btnQualityFour, SIGNAL(clicked()), this, SLOT(setQualityFour()));
	QObject::connect(btnQualityFive, SIGNAL(clicked()), this, SLOT(setQualityFive()));

	_model = new RecondoModel();
	_presenter = new RecondoPresenter(this, _model);
	_presenter->SetCurrentCourseNameOnView();
}

RecondoUI::~RecondoUI()
{
	delete _presenter;
	delete _model;
}

void RecondoUI::EnableControls(bool flag)
{
	btnShowAnswer->setEnabled(flag);
	btnNextQuestion->setEnabled(flag);
	btnQualityZero->setEnabled(flag);
	btnQualityOne->setEnabled(flag);
	btnQualityTwo->setEnabled(flag);
	btnQualityThree->setEnabled(flag);
	btnQualityFour->setEnabled(flag);
	btnQualityFive->setEnabled(flag);
}

void RecondoUI::EnableShowAnswer(bool flag)
{
	btnShowAnswer->setEnabled(flag);
}

void RecondoUI::nextQuestion()
{
	if(_presenter->SetQuestionOnView())
	{
		EnableNextQuestion(false);
		EnableShowAnswer(true);
	}
	else
	{
		_presenter->SaveData();
		EnableOptions(true);
		EnableControls(false);
	}
}

void RecondoUI::EnableQualityResponse(bool flag)
{
	btnQualityZero->setEnabled(flag);
	btnQualityOne->setEnabled(flag);
	btnQualityTwo->setEnabled(flag);
	btnQualityThree->setEnabled(flag);
	btnQualityFour->setEnabled(flag);
	btnQualityFive->setEnabled(flag);
}

void RecondoUI::EnableNextQuestion(bool flag)
{
	btnNextQuestion->setEnabled(flag);
}

void RecondoUI::EnableOptions(bool flag)
{
	actionChooseCourse->setEnabled(flag);
	actionStartLection->setEnabled(flag);
	actionEndLection->setEnabled(!flag);
}

void RecondoUI::startLection()
{
	if(_presenter->InitializeLection())
	{
		EnableOptions(false);
		EnableShowAnswer(true);
	}
	else
	{
		EnableOptions(true);
		EnableControls(false);
	}
	
}

void RecondoUI::endLection()
{
	EnableOptions(true);
	_presenter->ClearLection();
	_presenter->SaveData();
	EnableControls(false);
	//TODO clear collection and save in file
}

void RecondoUI::showAnswer()
{
	_presenter->SetAnswerOnView();
	EnableShowAnswer(false);
	EnableQualityResponse(true);
}

void RecondoUI::setQualityZero(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(0);
}

void RecondoUI::setQualityOne(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(1);
}

void RecondoUI::setQualityTwo(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(2);
}

void RecondoUI::setQualityThree(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(3);
}

void RecondoUI::setQualityFour(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(4);
}

void RecondoUI::setQualityFive(void)
{
	EnableQualityResponse(false);
	EnableNextQuestion(true);
	_presenter->SetQualityResponse(5);
}

void RecondoUI::showCourseForm(void)
{
	cForm = new CoursesUI(_model);
	int result = cForm->exec();
	if(result)
		_presenter->SetCurrentCourseNameOnView();

	delete cForm;
}

void RecondoUI::SetCurrentCourseName(std::string courseName)
{
	lbCourseName->setText(QString(courseName.c_str()));
}

void RecondoUI::SetNumberOfItemHarmonogram(std::string number)
{
	lbHarmonogramNumber->setText(QString(number.c_str()));
}

void RecondoUI::SetNumberOfItemNewMaterials(std::string number)
{
	lbNewItemsNumber->setText(QString(number.c_str()));
}

void RecondoUI::SetNumberOfItemRepeats(std::string number)
{
	lbRepeatNumber->setText(QString(number.c_str()));
}

void RecondoUI::SetQuestion(std::string question)
{
	textQuestion->setText(QString(question.c_str()));
}

void RecondoUI::SetAnswer(std::string question)
{
	textAnswer->setText(QString(question.c_str()));
}