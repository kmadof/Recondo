#ifndef COURSESUI_H
#define COURSESUI_H

#include <QtGui\qmainwindow.h>
#include <QtGui\qdialog.h>
#include "ui_CoursesDialog.h"
#include "CourseEditUi.h"
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

		std::string GetSelectedCourse();
		CoursePtr GetNewCourseItem();

	private:
		CourseEditUI* cEdit;
		CoursesPresenter* _presenter;
		RecondoModel* _model;
		CoursePtr _newCourse;

		void FillList();
		std::string GetFileName(const std::string& path);

	private slots:
		void selectedCourse(void);
		void removeCourse(void);
		void addCourse(void);
		void editCourse(void);
};

#endif