#pragma once

#include <string>
#include "CourseItem.h"
#include "tinyxml2.h"

#ifndef XML_SETTINGS_LAYER_H
#define XML_SETTINGS_LAYER_H

class XmlSettingsLayer
{
public:
	XmlSettingsLayer();
	void SaveCourses(Courses courses);
	Courses LoadCourses();
	void AddCourse(const CourseItem& courseItem);
	void RemoveCourse(const CourseItem& courseItem);
	void SetCurrentCourse(const CourseItem& course);
	CourseItem LoadCurrentCourse();
private:
	std::string _fileSettings;
	CourseItem _currentCourse;

	const std::string XML_ROOT;
	const std::string XML_COURSES;
	const std::string XML_COURSE_ELEMENT;
	const std::string XML_COURSE_NAME_ATTRIBUTE;
	const std::string XML_CURRENT_COURSE;
	const std::string XML_CURRENT_COURSE_ELEMENT;
	const std::string XML_CURRENT_COURSE_NAME_ATTRIBUTE;

};

#endif