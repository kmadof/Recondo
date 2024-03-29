#pragma once

#include "RecondoView.h"
#include "RecondoModel.h"

#ifndef RECONDO_PRESENETER_H
#define RECONDO_PRESENETER_H

class RecondoPresenter
{
	public:
		RecondoPresenter(RecondoView* view, RecondoModel* model) : _view(view), _model(model) {};

		bool AddCourse();
		void SetCurrentCourseNameOnView();
		bool InitializeLection();
		bool SetQuestionOnView();
		void SetAnswerOnView();
		void SetQualityResponse(unsigned quality);
		void SaveData();
		void ClearLection();

	private:
		RecondoView* _view;
		RecondoModel* _model;

		void UpdateInfoItems();
};

#endif
