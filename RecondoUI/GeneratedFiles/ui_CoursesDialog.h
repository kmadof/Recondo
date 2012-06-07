/********************************************************************************
** Form generated from reading UI file 'CoursesDialog.ui'
**
** Created: Sun 3. Jun 22:15:02 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSESDIALOG_H
#define UI_COURSESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoursesDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QListView *listView;

    void setupUi(QDialog *CoursesDialog)
    {
        if (CoursesDialog->objectName().isEmpty())
            CoursesDialog->setObjectName(QString::fromUtf8("CoursesDialog"));
        CoursesDialog->resize(338, 240);
        layoutWidget = new QWidget(CoursesDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 200, 321, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        listView = new QListView(CoursesDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 321, 181));
        listView->setSelectionRectVisible(false);

        retranslateUi(CoursesDialog);
        QObject::connect(okButton, SIGNAL(clicked()), CoursesDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), CoursesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CoursesDialog);
    } // setupUi

    void retranslateUi(QDialog *CoursesDialog)
    {
        CoursesDialog->setWindowTitle(QApplication::translate("CoursesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("CoursesDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("CoursesDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoursesDialog: public Ui_CoursesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESDIALOG_H
