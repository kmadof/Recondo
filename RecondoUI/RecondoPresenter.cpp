#include "RecondoPresenter.h"
#include "CourseItem.h"
#include <boost/lexical_cast.hpp>	
#include <string>

void RecondoPresenter::SetCurrentCourseNameOnView()
{
	_view->SetCurrentCourseName(_model->GetCurrentCourse()->GetCourseName());
}

void RecondoPresenter::InitializeLection()
{
	_model->GetItemsToHramonogram();
	_model->GetItemsToNewMaterials();
	
	SetQuestionOnView();
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

void RecondoPresenter::SetQuestionOnView()
{
	_view->SetQuestion(_model->GetNextItem()->GetQuestion());
	_view->SetAnswer("");
	UpdateInfoItems();
}

void RecondoPresenter::SetAnswerOnView()
{
	_view->SetAnswer(_model->GetCurrentItem()->GetAnswer());
}