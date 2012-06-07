#pragma once

#include "CourseItem.h"

#ifndef COURSES_VIEW_H
#define COURSES_VIEW_H

class CoursesView
{
public:
	virtual std::string GetCurrentLection() = 0;
private:

};

#endif