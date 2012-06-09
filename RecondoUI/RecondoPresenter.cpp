#include "RecondoPresenter.h"
#include "CourseItem.h"

void RecondoPresenter::SetCurrentCourseNameOnView()
{
	_view->SetCurrentCourseName(_model->GetCurrentCourse()->GetCourseName());
}