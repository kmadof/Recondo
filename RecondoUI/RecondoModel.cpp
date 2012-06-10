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

RecondoModel::RecondoModel() : CURRENT_COURSE_PATH("currentCourse.cur"), NUMBER_OF_NEW_ITEMS(30)
{
	xml = new XmlSettingsLayer();
	_courses = xml->LoadCourses();

	_currentCourse = xml->LoadCurrentCourse();
	if(_currentCourse.GetCourseName() != "")
		_course = LoadCourse(_currentCourse.GetPath());
	else
		_course = Course();
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

void RecondoModel::SetLastRun()
{
	_course.SetLastRunDate();
}

void RecondoModel::GetItemsToHramonogram()
{
	Items temp = _course.GetItems();
	gregorian_date now = _course.GetLatRunDate();
	gregorian_date itemDate;
	for(Items::iterator it = temp.begin(); it != temp.end(); ++it)
	{
		itemDate = it->get()->GetDate();
		if(!itemDate.is_not_a_date() && itemDate < now)
		{
			_harmonogram.push_back(*it);
		}
	}
}

void RecondoModel::GetItemsToNewMaterials()
{
	Items temp = _course.GetItems();
	int numberOfItems = 0;
	for(Items::iterator it = temp.begin(); it != temp.end(); ++it)
	{
		if(it->get()->GetNumberOfRepetitions() == 0)
		{
			_newMaterials.push_back(*it);
			++numberOfItems;
			if(numberOfItems == NUMBER_OF_NEW_ITEMS)
				break;
		}
	}
}

void RecondoModel::AddItemToRepeats(ItemPtr item)
{
	_repeats.push_back(item);
}

int RecondoModel::GetNumberOfItemHarmonogram() const
{
	return _harmonogram.size();
}

int RecondoModel::GetNumberOfItemNewMaterials() const
{
	return _newMaterials.size();
}

int RecondoModel::GetNumberOfItemRepeats() const
{
	return _repeats.size();
}

ItemPtr RecondoModel::GetNextItem()
{
	if( _harmonogram.size() > 0)
	{
		_currentItem = _harmonogram.front();
		_harmonogram.pop_front();
	}
	else if( _newMaterials.size() > 0)
	{
		_currentItem = _newMaterials.front();
		_newMaterials.pop_front();
	}
	else if( _harmonogram.size() > 0)
	{
		_currentItem = _repeats.front();
		_repeats.pop_front();
	}
	
	return _currentItem;
}