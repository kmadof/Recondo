#pragma once

#include <string>
#include "CourseItem.h"

#ifndef RECONDOVIEW_H
#define RECONDOVIEW_H

class RecondoView
{
public:
	//virtual std::string GetCurrentLection() = 0;
	virtual CoursePtr GetNewCourseItem() = 0;
};

#endif
