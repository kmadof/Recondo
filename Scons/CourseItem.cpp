#include "CourseItem.h"

bool operator==(const CourseItem& lCourse, const CourseItem& rCourse)
{
	if(lCourse.GetCourseName() == rCourse.GetCourseName() && lCourse.GetPath() == rCourse.GetPath())
		return true;
	else
		return false;
}

bool operator!=(const CourseItem& lCourse, const CourseItem& rCourse)
{
	return !(lCourse == rCourse);
}