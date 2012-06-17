#pragma once

#include "CourseEditView.h"
#include "RecondoModel.h"
#include "Item.h"

#ifndef COURSE_EDIT_PRESENTER_H
#define COURSE_EDIT_PRESENTER_H

class CourseEditPresenter
{
public:
	CourseEditPresenter(CourseEditView* view, RecondoModel* model) : _view(view), _model(model) {}
	virtual ~CourseEditPresenter() {};

	void SetCourseInfoOnView();
	Items GetItemsToEdit();
	void SaveChangedItems(const Items& items);
private:
	CourseEditView* _view;
	RecondoModel* _model;
};

#endif