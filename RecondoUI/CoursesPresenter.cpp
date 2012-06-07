#include "CoursesPresenter.h"
#include <string>
//#include "CourseItem.h"

void CoursesPresenter::PutCurrentLection()
{
	std::string temp = _view->GetCurrentLection();
	_model->SetCurrentLection(temp);
}

const Courses CoursesPresenter::GetCoursesItem()
{
	return _model->GetCoursesItem();
}