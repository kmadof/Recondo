/********************************************************************************
** Form generated from reading UI file 'CoursesDialog.ui'
**
** Created: Sun 10. Jun 23:28:06 2012
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
    QPushButton *btnAddCourse;
    QPushButton *btnDelete;
    QPushButton *btnEdit;
    QPushButton *btnCreateCourse;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QListView *listView;

    void setupUi(QDialog *CoursesDialog)
    {
        if (CoursesDialog->objectName().isEmpty())
            CoursesDialog->setObjectName(QString::fromUtf8("CoursesDialog"));
        CoursesDialog->resize(501, 259);
        CoursesDialog->setMinimumSize(QSize(501, 259));
        CoursesDialog->setMaximumSize(QSize(501, 259));
        layoutWidget = new QWidget(CoursesDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 200, 488, 51));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        btnAddCourse = new QPushButton(layoutWidget);
        btnAddCourse->setObjectName(QString::fromUtf8("btnAddCourse"));

        hboxLayout->addWidget(btnAddCourse);

        btnDelete = new QPushButton(layoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        hboxLayout->addWidget(btnDelete);

        btnEdit = new QPushButton(layoutWidget);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));

        hboxLayout->addWidget(btnEdit);

        btnCreateCourse = new QPushButton(layoutWidget);
        btnCreateCourse->setObjectName(QString::fromUtf8("btnCreateCourse"));

        hboxLayout->addWidget(btnCreateCourse);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        listView = new QListView(CoursesDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 481, 181));
        listView->setTextElideMode(Qt::ElideNone);
        listView->setSelectionRectVisible(true);

        retranslateUi(CoursesDialog);
        QObject::connect(okButton, SIGNAL(clicked()), CoursesDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), CoursesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CoursesDialog);
    } // setupUi

    void retranslateUi(QDialog *CoursesDialog)
    {
        CoursesDialog->setWindowTitle(QApplication::translate("CoursesDialog", "Menad\305\274er kurs\303\263w", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnAddCourse->setToolTip(QApplication::translate("CoursesDialog", "Dodanie nowego kursu z pliku do bazy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAddCourse->setText(QApplication::translate("CoursesDialog", "Dodaj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnDelete->setToolTip(QApplication::translate("CoursesDialog", "Usuni\304\231cie kursu z bazy", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnDelete->setText(QApplication::translate("CoursesDialog", "Usu\305\204", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("CoursesDialog", "Edytuj", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnCreateCourse->setToolTip(QApplication::translate("CoursesDialog", "Stworzenie nowego kursu", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnCreateCourse->setText(QApplication::translate("CoursesDialog", "Utw\303\263rz", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        okButton->setToolTip(QApplication::translate("CoursesDialog", "Wybranie nowego kursu. UWAGA w przypadku kiedy kurs jest ju\305\274 wybrany to jest on zast\304\231powany nowym", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        okButton->setText(QApplication::translate("CoursesDialog", "Wybierz", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("CoursesDialog", "Powr\303\263t do poprzedniego okna", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QApplication::translate("CoursesDialog", "Zamknij", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoursesDialog: public Ui_CoursesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSESDIALOG_H
