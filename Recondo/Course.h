#include <boost/shared_ptr.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "Item.h"

#pragma once

#ifndef COURSE_H
#define COURSE_H

using namespace SuperMemoStrategy;

class Course
{
	friend class boost::serialization::access;
	template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
		using boost::serialization::make_nvp;
		ar &  make_nvp ("LastRun", _lastRun);
        ar &  make_nvp ("Items", _items);
		
    }
public :
	Course() {} ;
	virtual ~Course() {};

	gregorian_date GetLatRunDate() const { return _lastRun; }
	void SetLastRunDate() { _lastRun = boost::gregorian::day_clock::local_day(); }
	void SetItems(Items items) { _items = items; }
	Items GetItems() const { return _items; }

private :
	Items _items;
	gregorian_date _lastRun;
};

#endif COURSE_H
