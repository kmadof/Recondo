#pragma once

#include <string>
#include <functional>
#include <boost\shared_ptr.hpp>
#include "CourseItem.h"
#include "Course.h"
#include "Item.h"
#include "XmlSettingsLayer.h"

#ifndef RECONDO_MODEL_H
#define RECONDO_MODEL_H

class RecondoModel
{
public:
	RecondoModel();
	~RecondoModel();

	//std::string GetCurrentCourse() const { return _currentLection; }
	CoursePtr GetCurrentCourse() const { return CoursePtr(new CourseItem(_currentCourse)); };
	void SetCurrentCourse(std::string currentLection);

	const Courses GetCoursesItem();
	bool AddCourse(const CourseItem& courseItem);
	bool RemoveCourse(const std::string& courseName);
	bool IsCourseExist(const std::string& courseName);
	bool IsCourseExist(const CourseItem& course);
	void SaveCourse(std::string path) const;
	Course LoadCourse(std::string path);
	CoursePtr FindCourse(std::string name);

private:
	CourseItem _currentCourse;
	Courses _courses;
	Course _course;
	XmlSettingsLayer* xml;

	const std::string CURRENT_COURSE_PATH;

	void CreateCurrentCourseFile();
};

//struct CompareCourseAndName : public std::binary_function<CoursePtr,std::string,bool> {
//  bool operator() (CoursePtr courseItem, std::string courseName) const {return ( courseItem->GetCourseName() == courseName );}
//};
//
//struct CompareCourse : public std::binary_function<CoursePtr,CourseItem,bool> {
//  bool operator() (CoursePtr courseItem, CourseItem course) const {return ((*courseItem) == course);}
//};

#endif