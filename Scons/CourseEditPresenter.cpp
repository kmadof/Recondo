#include "CourseEditPresenter.h"

void CourseEditPresenter::SetCourseInfoOnView()
{
	_view->SetCourseName(_model->GetCourseToEdit()->GetCourseName());
	_view->SetCoursePath(_model->GetCourseToEdit()->GetPath());
}

Items CourseEditPresenter::GetItemsToEdit()
{
	return _model->GetItemsToEdit();
}

void CourseEditPresenter::SaveChangedItems(const Items& items)
{
	_model->SaveChangedItems(items);
}