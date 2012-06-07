#pragma once

#include <string>
#include "CourseItem.h"
#include "XmlSettingsLayer.h"

#ifndef RECONDO_MODEL_H
#define RECONDO_MODEL_H

class RecondoModel
{
public:
	RecondoModel();
	~RecondoModel();

	std::string GetCurrentLection() const { return _currentLection; }
	void SetCurrentLection(std::string currentLection) { _currentLection = currentLection; }
	//void AddCourse(CourseItem& courseItem);
	void RemoveCourse(std::string courseName);
	const Courses GetCoursesItem();
	void AddCourse(const CourseItem& courseItem);

private:
	std::string _currentLection;
	Courses _courses;
	XmlSettingsLayer* xml;
};

#endif