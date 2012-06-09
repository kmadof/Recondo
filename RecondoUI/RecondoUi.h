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

		void SetCurrentCourseName(std::string courseName);

	private:
		Ui::RecondoUIClass ui;
		CoursesUI* cForm;
		RecondoModel* _model;
		RecondoPresenter* _presenter;


	private slots:
		void doThing(void);
		void showCourseForm(void);

};

#endif // RECONDOUI_H
