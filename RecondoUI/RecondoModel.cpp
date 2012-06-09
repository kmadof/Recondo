#include <algorithm>
#include <functional>
#include <fstream>
#include <string>
#include <qapplication.h>
#include <boost/archive/xml_oarchive.hpp> 
#include <boost/archive/xml_iarchive.hpp> 
#include <boost/serialization/access.hpp>
#include "RecondoModel.h"
#include "CourseItem.h"
#include "TxtLoader.h"
#include "Course.h"
#include "Item.h"

using namespace SuperMemoStrategy;

RecondoModel::RecondoModel() : CURRENT_COURSE_PATH("currentCourse.cur")
{
	xml = new XmlSettingsLayer();
	_courses = xml->LoadCourses();

	_currentCourse = xml->LoadCurrentCourse();
	if(_currentCourse.GetCourseName() != "")
		_course = LoadCourse(_currentCourse.GetPath());
	else
		_courses = Courses();
}

RecondoModel::~RecondoModel()
{
	delete xml;
}

void RecondoModel::SetCurrentCourse(std::string currentLection)
{ 
	 QString path = QCoreApplication::applicationDirPath();
	 path.append(("/" + CURRENT_COURSE_PATH).c_str());

	 _currentCourse = CourseItem(currentLection, path.toStdString());

	 xml->SetCurrentCourse(_currentCourse);
	 CreateCurrentCourseFile();
	 SaveCourse(_currentCourse.GetPath());
	 
}

const Courses RecondoModel::GetCoursesItem()
{
	return _courses;
}

bool RecondoModel::IsCourseExist(const std::string& courseName)
{
	for(Courses::const_iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		if(it->get()->GetCourseName() == courseName)
			return true;
	}
	return false;
}

bool RecondoModel::IsCourseExist(const CourseItem& course)
{
	for(Courses::const_iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		if(*it->get() == course)
			return true;
	}
	return false;
}

bool RecondoModel::AddCourse(const CourseItem& courseItem)
{
	if(!IsCourseExist(courseItem))
	{
		_courses.push_back(CoursePtr(new CourseItem(courseItem)));
		xml->AddCourse(courseItem);
		return true;
	}
	return false;
}

bool RecondoModel::RemoveCourse(const std::string& courseName)
{
	for(Courses::const_iterator it = _courses.begin(); it != _courses.end(); ++it)
	{
		if(it->get()->GetCourseName() == courseName)
		{
			xml->RemoveCourse(*(it->get()));
			_courses.remove(*it);
			return true;
		}
	}
	return false;
}

CoursePtr RecondoModel::FindCourse(std::string name)
{
	for(Courses::const_iterator it = _courses.begin(); it != _courses.end(); ++it)
		if(it->get()->GetCourseName() == name)
			return *it;
	return CoursePtr();
}

void RecondoModel::CreateCurrentCourseFile()
{
	Items items;

	TxtLoader* loader = new TxtLoader();
	CoursePtr cPtr = FindCourse(_currentCourse.GetCourseName());
	if(cPtr)
	{
		items = loader->Load(cPtr->GetPath());
		_course.SetItems(items);
	}
}

void RecondoModel::SaveCourse(std::string path) const
{
	std::ofstream file(path); 
	boost::archive::xml_oarchive oa(file); 
	oa & BOOST_SERIALIZATION_NVP(_course); 
}

Course RecondoModel::LoadCourse(std::string path)
{ 
  std::ifstream file(path); 
  boost::archive::xml_iarchive ia(file); 
  Course course; // Need to specify expected array size
  ia >> BOOST_SERIALIZATION_NVP(course);
  return course;
} 