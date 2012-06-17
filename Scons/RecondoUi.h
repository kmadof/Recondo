#pragma once

#include <QtGui/QMainWindow>
#include "ui_RecondoUi.h"
#include "CoursesUi.h"
#include "RecondoModel.h"
#include "RecondoPresenter.h"
#include "RecondoView.h"

#ifndef RECONDOUI_H
#define RECONDOUI_H

class RecondoUI : public QMainWindow, private Ui::RecondoUIClass, public RecondoView
{
	Q_OBJECT

	public:
		RecondoUI(QWidget *parent = 0, Qt::WFlags flags = 0);
		~RecondoUI();

		virtual void SetCurrentCourseName(std::string courseName);
		virtual void SetNumberOfItemHarmonogram(std::string number);
		virtual void SetNumberOfItemNewMaterials(std::string number);
		virtual void SetNumberOfItemRepeats(std::string number);
		virtual void SetQuestion(std::string question);
		virtual void SetAnswer(std::string question);

	private:
		Ui::RecondoUIClass ui;
		CoursesUI* cForm;
		RecondoModel* _model;
		RecondoPresenter* _presenter;

		void EnableControls(bool flag);
		void EnableShowAnswer(bool flag);
		void EnableQualityResponse(bool flag);
		void EnableNextQuestion(bool flag);
		void EnableOptions(bool flag);

	private slots:
		void showCourseForm(void);
		void startLection(void);
		void endLection(void);
		void showAnswer(void);
		void nextQuestion(void);
		void setQualityZero(void);
		void setQualityOne(void);
		void setQualityTwo(void);
		void setQualityThree(void);
		void setQualityFour(void);
		void setQualityFive(void);

};

#endif // RECONDOUI_H
