#pragma once

#include <string>
#include "CourseItem.h"

#ifndef RECONDOVIEW_H
#define RECONDOVIEW_H

class RecondoView
{
public:
	virtual void SetCurrentCourseName(std::string courseName) = 0;
	virtual void SetNumberOfItemHarmonogram(std::string number) = 0;
	virtual void SetNumberOfItemNewMaterials(std::string number) = 0;
	virtual void SetNumberOfItemRepeats(std::string number) = 0;
	virtual void SetQuestion(std::string question) = 0;
	virtual void SetAnswer(std::string question) = 0;
};

#endif
