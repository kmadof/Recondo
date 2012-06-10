/********************************************************************************
** Form generated from reading UI file 'CoursesForm.ui'
**
** Created: Sat 9. Jun 23:26:38 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESFORM_H
#define UI_COURSESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoursesForm
{
public:
    QWidget *centralwidget;
    QListView *listView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CoursesForm)
    {
        if (CoursesForm->objectName().isEmpty())
            CoursesForm->setObjectName(QString::fromUtf8("CoursesForm"));
        CoursesForm->setWindowModality(Qt::WindowModal);
        CoursesForm->resize(725, 313);
        centralwidget = new QWidget(CoursesForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 701, 121));
        listView->setModelColumn(0);
        CoursesForm->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(CoursesForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CoursesForm->setStatusBar(statusbar);

        retranslateUi(CoursesForm);

        QMetaObject::connectSlotsByName(CoursesForm);
    } // setupUi

    void retranslateUi(QMainWindow *CoursesForm)
    {
        CoursesForm->setWindowTitle(QApplication::translate("CoursesForm", "Menad\305\274er kurs\303\263w", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoursesForm: public Ui_CoursesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESFORM_H
