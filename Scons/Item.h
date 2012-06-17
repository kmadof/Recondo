#include <iostream>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>

#ifndef ITEM
#define ITEM

using namespace std;
typedef boost::gregorian::date gregorian_date;

namespace SuperMemoStrategy
{
	class Item
	{
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			using boost::serialization::make_nvp;
			ar &  make_nvp ("Question", _question);
			ar &  make_nvp ("Answer", _answer);
			ar &  make_nvp ("NumberOfRepetitions", _numberOfRepetitions);
			ar &  make_nvp ("Interval", _interval);
			ar &  make_nvp ("eFactor", _eFactor);
			ar &  make_nvp ("QualityResponse", _qualityResponse);
			ar &  make_nvp ("Date", _date);
		}
		public:
			Item();
			Item(string question, string answer);
			virtual ~Item() {};

			const string	GetQuestion() const { return _question; }
			const string	GetAnswer() const { return _answer; }
			const unsigned	GetNumberOfRepetitions() const { return _numberOfRepetitions; }
			void			IncreaseNumberOfRepetitions();
			const unsigned	GetInterval() const { return _interval; }
			void			SetInterval(unsigned interval) { _interval = interval; }
			const double	GetEFactor() const { return _eFactor; }
			void			SetEFactor(double eFactor) { _eFactor = eFactor; }
			const unsigned	GetQualityResponse() const { return _qualityResponse; }
			void			SetQualityResponse(unsigned qualityResponse);
			gregorian_date  GetDate() const { return _date; }
			void			SetDate(gregorian_date date) { _date = date; }
		private :
			string _question;
			string _answer;
			unsigned _numberOfRepetitions;
			unsigned _interval;
			double _eFactor;
			unsigned _qualityResponse;
			gregorian_date _date;
	};

	typedef boost::shared_ptr<Item> ItemPtr;
	typedef std::list<ItemPtr> Items;
}
#endif