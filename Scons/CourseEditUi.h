#pragma once

#ifndef COURSE_EDIT_UI_H
#define COURSE_EDIT_UI_H

#include <QtGui\qdialog.h>
#include "ui_CourseEdit.h"
#include "CourseEditView.h"
#include "CourseEditPresenter.h"
#include "RecondoModel.h"
#include "Item.h"


class CourseEditUI : public QDialog, private Ui::CourseEdit, public CourseEditView
{
	Q_OBJECT;

	public:
		CourseEditUI(RecondoModel* model, QWidget *parent = 0, Qt::WFlags flags = 0);
		virtual ~CourseEditUI();

		virtual void SetCourseName(std::string name);
		virtual void SetCoursePath(std::string path);

	private:
		CourseEditPresenter* _presenter;
		Items _items;
		ItemPtr _currentItem;
		int _currentRow;
		bool _addingNewItem;

		void FillTable();
	private slots:
		void tableViewCurrentRowChanged(QModelIndex index1,QModelIndex index2);
		void tableViewSelectionChanged( const QItemSelection & selected, const QItemSelection & deselected );
		void changeItem(void);
		void saveItemToFile(void);
		void addNewItem(void);
		void cancelAdd(void);
};

#endif