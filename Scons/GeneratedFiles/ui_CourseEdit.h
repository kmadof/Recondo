/********************************************************************************
** Form generated from reading UI file 'CourseEdit.ui'
**
** Created: Mon 11. Jun 01:26:06 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEEDIT_H
#define UI_COURSEEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseEdit
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTableView *tableView;
    QGroupBox *gbQuestion;
    QTextEdit *txtQuestion;
    QGroupBox *gbAnswer;
    QTextEdit *txtAnswer;
    QWidget *layoutWidget_2;
    QHBoxLayout *_2;
    QPushButton *btnNew;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QTextEdit *txtName;
    QLabel *lbPath;
    QTextEdit *txtPath;

    void setupUi(QDialog *CourseEdit)
    {
        if (CourseEdit->objectName().isEmpty())
            CourseEdit->setObjectName(QString::fromUtf8("CourseEdit"));
        CourseEdit->resize(592, 403);
        layoutWidget = new QWidget(CourseEdit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 360, 271, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        tableView = new QTableView(CourseEdit);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 60, 291, 331));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        gbQuestion = new QGroupBox(CourseEdit);
        gbQuestion->setObjectName(QString::fromUtf8("gbQuestion"));
        gbQuestion->setGeometry(QRect(310, 60, 271, 121));
        txtQuestion = new QTextEdit(gbQuestion);
        txtQuestion->setObjectName(QString::fromUtf8("txtQuestion"));
        txtQuestion->setGeometry(QRect(10, 20, 251, 91));
        txtQuestion->setReadOnly(false);
        gbAnswer = new QGroupBox(CourseEdit);
        gbAnswer->setObjectName(QString::fromUtf8("gbAnswer"));
        gbAnswer->setGeometry(QRect(310, 190, 271, 121));
        txtAnswer = new QTextEdit(gbAnswer);
        txtAnswer->setObjectName(QString::fromUtf8("txtAnswer"));
        txtAnswer->setGeometry(QRect(10, 20, 251, 91));
        txtAnswer->setReadOnly(false);
        layoutWidget_2 = new QWidget(CourseEdit);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(310, 320, 271, 33));
        _2 = new QHBoxLayout(layoutWidget_2);
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        btnNew = new QPushButton(layoutWidget_2);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        _2->addWidget(btnNew);

        btnSave = new QPushButton(layoutWidget_2);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        _2->addWidget(btnSave);

        btnCancel = new QPushButton(layoutWidget_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setEnabled(false);

        _2->addWidget(btnCancel);

        horizontalLayoutWidget = new QWidget(CourseEdit);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 571, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbName = new QLabel(horizontalLayoutWidget);
        lbName->setObjectName(QString::fromUtf8("lbName"));

        horizontalLayout->addWidget(lbName);

        txtName = new QTextEdit(horizontalLayoutWidget);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setReadOnly(true);

        horizontalLayout->addWidget(txtName);

        lbPath = new QLabel(horizontalLayoutWidget);
        lbPath->setObjectName(QString::fromUtf8("lbPath"));

        horizontalLayout->addWidget(lbPath);

        txtPath = new QTextEdit(horizontalLayoutWidget);
        txtPath->setObjectName(QString::fromUtf8("txtPath"));
        txtPath->setReadOnly(true);

        horizontalLayout->addWidget(txtPath);


        retranslateUi(CourseEdit);
        QObject::connect(okButton, SIGNAL(clicked()), CourseEdit, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), CourseEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(CourseEdit);
    } // setupUi

    void retranslateUi(QDialog *CourseEdit)
    {
        CourseEdit->setWindowTitle(QApplication::translate("CourseEdit", "Edycja kursu", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("CourseEdit", "Zapisz zmiany", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("CourseEdit", "Zamknij", 0, QApplication::UnicodeUTF8));
        gbQuestion->setTitle(QApplication::translate("CourseEdit", "Pytanie", 0, QApplication::UnicodeUTF8));
        gbAnswer->setTitle(QApplication::translate("CourseEdit", "Odpowied\305\272", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("CourseEdit", "Nowy", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("CourseEdit", "Zapisz element", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("CourseEdit", "Anuluj", 0, QApplication::UnicodeUTF8));
        lbName->setText(QApplication::translate("CourseEdit", "Nazwa kursu:", 0, QApplication::UnicodeUTF8));
        lbPath->setText(QApplication::translate("CourseEdit", "Po\305\202o\305\274enie:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CourseEdit: public Ui_CourseEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEEDIT_H
