#pragma once

#include "RecondoModel.h"
#include "CoursesView.h"
#include "CourseItem.h"

#ifndef COURSES_PRESENTER_H
#define COURSES_PRESENTER_H

class CoursesPresenter
{
public:
	CoursesPresenter(CoursesView* view, RecondoModel* model) : _view(view), _model(model) {};

	void GetSelectedCourse();
	const Courses GetCoursesItem();
	bool AddCourse();
	bool RemoveCourse();
private:
	CoursesView* _view;
	RecondoModel* _model;
};

#endif