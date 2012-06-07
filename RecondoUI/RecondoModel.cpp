#include "RecondoModel.h"
#include "CourseItem.h"

RecondoModel::RecondoModel()
{
	_currentLection = "";
	xml = new XmlSettingsLayer();
	_courses = xml->LoadCourses();
	//_courses = new Courses();
}

RecondoModel::~RecondoModel()
{
	delete xml;
}
//
//void RecondoModel::AddCourse(CourseItem& courseItem)
//{
//	_courses.push_back(CoursePtr(&courseItem));
//}

void RecondoModel::RemoveCourse(std::string courseName)
{
	for(Courses::const_iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		if(it->get()->GetCourseName() == courseName)
			_courses.remove(*it);
	}
}

const Courses RecondoModel::GetCoursesItem()
{
	return _courses;
}

void RecondoModel::AddCourse(const CourseItem& courseItem)
{
	_courses.push_back(CoursePtr(new CourseItem(courseItem)));
	xml->AddCourse(courseItem);
}