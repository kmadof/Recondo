#include "RecondoPresenter.h"
#include "CourseItem.h"

void RecondoPresenter::AddCourse()
{
	_model->AddCourse(*(_view->GetNewCourseItem()).get());
}