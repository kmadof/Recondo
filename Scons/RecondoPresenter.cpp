#include "RecondoPresenter.h"
#include "CourseItem.h"
#include <boost/lexical_cast.hpp>	
#include <string>

void RecondoPresenter::SetCurrentCourseNameOnView()
{
	_view->SetCurrentCourseName(_model->GetCurrentCourse()->GetCourseName());
}

bool RecondoPresenter::InitializeLection()
{
	_model->GetItemsToHramonogram();
	_model->GetItemsToNewMaterials();
	_model->SetLastRun();

	return SetQuestionOnView();
}

void RecondoPresenter::UpdateInfoItems()
{
	int number = _model->GetNumberOfItemHarmonogram();
	std::string s = boost::lexical_cast<string>( number );
	_view->SetNumberOfItemHarmonogram(s);

	number = _model->GetNumberOfItemNewMaterials();
	s = boost::lexical_cast<string>( number );
	_view->SetNumberOfItemNewMaterials(s);

	number = _model->GetNumberOfItemRepeats();
	s = boost::lexical_cast<string>( number );
	_view->SetNumberOfItemRepeats(s);
}

bool RecondoPresenter::SetQuestionOnView()
{
	bool flag = true;
	ItemPtr iPtr = _model->GetNextItem();
	if(iPtr.get() != NULL)
		_view->SetQuestion(iPtr->GetQuestion());
	else
	{
		_view->SetQuestion("");
		flag = false;
	}
	_view->SetAnswer("");
	UpdateInfoItems();
	return flag;
}

void RecondoPresenter::SetAnswerOnView()
{
	_view->SetAnswer(_model->GetCurrentItem()->GetAnswer());
}

void RecondoPresenter::SetQualityResponse(unsigned quality)
{
	_model->SetQualityResponse(quality);
}

void RecondoPresenter::SaveData()
{
	_model->SaveCourse(_model->GetCurrentCourse()->GetPath());
}

void RecondoPresenter::ClearLection()
{
	_model->ClearHarmonogram();
	_model->ClearNewMaterials();
	_model->ClearRepeats();
	UpdateInfoItems();
}