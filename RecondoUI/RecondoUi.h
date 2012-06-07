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

		CoursePtr GetNewCourseItem();

	private:
		Ui::RecondoUIClass ui;
		CoursesUI* cForm;
		RecondoModel* _model;
		RecondoPresenter* _presenter;
		//Ui::CoursesForm* coForm;
		//Ui::Dialog* dialog;
		std::string GetFileName(const std::string& path);
		CoursePtr _newCourse;

	private slots:
		void doThing(void);
		void showCourseForm(void);
		void addCourse(void);
};

#endif // RECONDOUI_H
