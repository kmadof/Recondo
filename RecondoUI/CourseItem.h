#pragma once

#include <string>
#include <list>
#include <boost\shared_ptr.hpp>

#ifndef COURSE_ITEM_H
#define COURSE_ITEM_H

class CourseItem
{
public:
	CourseItem(std::string courseName, std::string path) : _courseName(courseName), _path(path) {};
	CourseItem(const CourseItem& courseItem) : _courseName(courseItem.GetCourseName()), _path(courseItem.GetPath()) {};
	~CourseItem() {}
	std::string GetCourseName() const { return _courseName; }
	std::string GetPath() const { return _path; }
	friend bool operator==(const CourseItem& lCourse, const CourseItem& rCourse);
	friend bool operator!=(const CourseItem& lCourse, const CourseItem& rCourse);
private:
	std::string _courseName;
	std::string _path;
};

typedef boost::shared_ptr<CourseItem> CoursePtr;
typedef std::list<CoursePtr> Courses;

#endif