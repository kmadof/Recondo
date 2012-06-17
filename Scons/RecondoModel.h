#pragma once

#include <string>
#include <functional>
#include <boost\shared_ptr.hpp>
#include "CourseItem.h"
#include "Course.h"
#include "Item.h"
#include "XmlSettingsLayer.h"
#include "SuperMemo2.h"

#ifndef RECONDO_MODEL_H
#define RECONDO_MODEL_H

using namespace SuperMemoStrategy;

class RecondoModel
{
public:
	RecondoModel();
	~RecondoModel();

	//std::string GetCurrentCourse() const { return _currentLection; }
	CoursePtr GetCurrentCourse() const { return CoursePtr(new CourseItem(_currentCourse)); };
	void SetCurrentCourse(std::string currentLection);
	void SetCourseToEdit(std::string currentCourse);
	CoursePtr GetCourseToEdit() const { return _courseToEdit; }

	const Courses GetCoursesItem();
	bool AddCourse(const CourseItem& courseItem);
	bool RemoveCourse(const std::string& courseName);
	bool IsCourseExist(const std::string& courseName);
	bool IsCourseExist(const CourseItem& course);
	void SaveCourse(std::string path) const;
	Course LoadCourse(std::string path);
	CoursePtr FindCourse(std::string name);

	void SetLastRun();
	void GetItemsToHramonogram();
	void GetItemsToNewMaterials();
	void AddItemToRepeats(ItemPtr item);
	void ClearHarmonogram();
	void ClearNewMaterials();
	void ClearRepeats();
	int GetNumberOfItemHarmonogram() const;
	int GetNumberOfItemNewMaterials() const;
	int GetNumberOfItemRepeats() const;
	ItemPtr GetNextItem();
	ItemPtr GetCurrentItem() const { return _currentItem; }

	Items GetItemsToEdit();
	void SaveChangedItems(const Items& items);

	void SetQualityResponse(unsigned quality);

private:
	CourseItem _currentCourse;
	CoursePtr _courseToEdit;
	Courses _courses;
	
	Course _course;
	Items _harmonogram;
	Items _newMaterials;
	Items _repeats;
	ItemPtr _currentItem;
	bool _isRepeated;

	SuperMemo2* memo;
	XmlSettingsLayer* xml;

	const std::string CURRENT_COURSE_PATH;
	const int NUMBER_OF_NEW_ITEMS;

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