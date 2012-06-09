#include "CoursesPresenter.h"
#include <string>
//#include "CourseItem.h"

void CoursesPresenter::GetSelectedCourse()
{
	_model->SetCurrentCourse(_view->GetSelectedCourse());
}

const Courses CoursesPresenter::GetCoursesItem()
{
	return _model->GetCoursesItem();
}

bool CoursesPresenter::AddCourse()
{
	return _model->AddCourse(*(_view->GetNewCourseItem()).get());
}

bool CoursesPresenter::RemoveCourse()
{
	return _model->RemoveCourse(_view->GetSelectedCourse());
}