#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>

#ifndef ITEM
#define ITEM

using namespace std;
//using namespace boost;

namespace SuperMemoStrategy
{
	class Item
	{
		public:
			Item(string question, string answer);
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
		private :
			string _question;
			string _answer;
			unsigned _numberOfRepetitions;
			unsigned _interval;
			double _eFactor;
			unsigned _qualityResponse;
	};

	typedef boost::shared_ptr<Item> ItemPtr;
	typedef std::vector<ItemPtr> Items;
}
#endif