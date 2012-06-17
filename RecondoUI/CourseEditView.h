#pragma once

#include <string>

#ifndef COURSE_EDIT_VIEW_H
#define COURSE_EDIT_VIEW_H

class CourseEditView
{
public:
	virtual void SetCourseName(std::string name) = 0;
	virtual void SetCoursePath(std::string path) = 0;
private:

};

#endif