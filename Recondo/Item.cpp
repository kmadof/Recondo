#include "Item.h"
#include "CException.h"

using namespace SuperMemoStrategy;

Item::Item(std::string question, std::string answer)
{
	_question = question;
	_answer = answer;
	_numberOfRepetitions = 0;
	_interval = 1;
	_eFactor = 2.5;
	_qualityResponse = 0;
}

void Item::IncreaseNumberOfRepetitions()
{
	_numberOfRepetitions++;
}

void Item::SetQualityResponse(unsigned qualityResponse)
{
	if(qualityResponse > 5)
		throw CException(__FILE__,__LINE__, "Niew³aœciwa wartoœæ oceny odpowiedzi");
	else
		_qualityResponse = qualityResponse;
	
}