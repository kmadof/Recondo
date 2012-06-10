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
		void InitializeLection();
		void SetQuestionOnView();
		void SetAnswerOnView();

	private:
		RecondoView* _view;
		RecondoModel* _model;

		void UpdateInfoItems();
};

#endif
