#ifndef COURSESUI_H
#define COURSESUI_H

#include <QtGui\qmainwindow.h>
#include <QtGui\qdialog.h>
//#include "ui_CoursesForm.h"
#include "ui_CoursesDialog.h"
#include "CoursesView.h"
#include "CoursesPresenter.h"
#include "RecondoModel.h"
#include "CourseItem.h"

class CoursesUI : public QDialog, private Ui::CoursesDialog, public CoursesView
{
	Q_OBJECT;

	public:
		CoursesUI(RecondoModel* model, QWidget *parent = 0, Qt::WFlags flags = 0);
		~CoursesUI();
		std::string GetCurrentLection();

	private:
		Ui::CoursesDialog ui;
		CoursesPresenter* _presenter;

		//Ui::CoursesForm* coForm;
		//Ui::Dialog* dialog;

	private slots:
		void selectedCourse(void);
};

#endif