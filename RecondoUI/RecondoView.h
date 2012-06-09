#pragma once

#include <string>
#include "CourseItem.h"

#ifndef RECONDOVIEW_H
#define RECONDOVIEW_H

class RecondoView
{
public:
	virtual void SetCurrentCourseName(std::string courseName) = 0;
};

#endif
