/********************************************************************************
** Form generated from reading UI file 'RecondoUi.ui'
**
** Created: Mon 4. Jun 00:54:07 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONDOUI_H
#define UI_RECONDOUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecondoUIClass
{
public:
    QAction *actionChooseCourse;
    QAction *actionStartLection;
    QAction *actionAbout;
    QAction *actionCreateCourse;
    QAction *actionEditCourse;
    QAction *actionClose;
    QAction *actionReadCourse;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnQualityOne;
    QPushButton *btnQualityZero;
    QPushButton *btnQualityTwo;
    QPushButton *btnQualityThree;
    QPushButton *btnQualityFour;
    QPushButton *btnQualityFive;
    QTextEdit *textQuestion;
    QTextEdit *textAnswer;
    QPushButton *btnShowAnswer;
    QPushButton *btnNextQuestion;
    QGroupBox *gbCurrentLection;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *lbPreserveation;
    QLabel *lbNewItems;
    QLabel *lbRepeat;
    QLabel *lbRepeatNumber;
    QLabel *lbNewItemsNumber;
    QLabel *lbPreserveationNumber;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuUser;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RecondoUIClass)
    {
        if (RecondoUIClass->objectName().isEmpty())
            RecondoUIClass->setObjectName(QString::fromUtf8("RecondoUIClass"));
        RecondoUIClass->resize(725, 450);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecondoUIClass->sizePolicy().hasHeightForWidth());
        RecondoUIClass->setSizePolicy(sizePolicy);
        RecondoUIClass->setMinimumSize(QSize(725, 450));
        RecondoUIClass->setMaximumSize(QSize(725, 450));
        actionChooseCourse = new QAction(RecondoUIClass);
        actionChooseCourse->setObjectName(QString::fromUtf8("actionChooseCourse"));
        actionStartLection = new QAction(RecondoUIClass);
        actionStartLection->setObjectName(QString::fromUtf8("actionStartLection"));
        actionAbout = new QAction(RecondoUIClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionCreateCourse = new QAction(RecondoUIClass);
        actionCreateCourse->setObjectName(QString::fromUtf8("actionCreateCourse"));
        actionEditCourse = new QAction(RecondoUIClass);
        actionEditCourse->setObjectName(QString::fromUtf8("actionEditCourse"));
        actionClose = new QAction(RecondoUIClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionReadCourse = new QAction(RecondoUIClass);
        actionReadCourse->setObjectName(QString::fromUtf8("actionReadCourse"));
        centralWidget = new QWidget(RecondoUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 240, 701, 25));
        horizontalLayout = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnQualityOne = new QPushButton(gridLayoutWidget);
        btnQualityOne->setObjectName(QString::fromUtf8("btnQualityOne"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnQualityOne->sizePolicy().hasHeightForWidth());
        btnQualityOne->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityOne);

        btnQualityZero = new QPushButton(gridLayoutWidget);
        btnQualityZero->setObjectName(QString::fromUtf8("btnQualityZero"));
        sizePolicy1.setHeightForWidth(btnQualityZero->sizePolicy().hasHeightForWidth());
        btnQualityZero->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityZero);

        btnQualityTwo = new QPushButton(gridLayoutWidget);
        btnQualityTwo->setObjectName(QString::fromUtf8("btnQualityTwo"));
        sizePolicy1.setHeightForWidth(btnQualityTwo->sizePolicy().hasHeightForWidth());
        btnQualityTwo->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityTwo);

        btnQualityThree = new QPushButton(gridLayoutWidget);
        btnQualityThree->setObjectName(QString::fromUtf8("btnQualityThree"));
        sizePolicy1.setHeightForWidth(btnQualityThree->sizePolicy().hasHeightForWidth());
        btnQualityThree->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityThree);

        btnQualityFour = new QPushButton(gridLayoutWidget);
        btnQualityFour->setObjectName(QString::fromUtf8("btnQualityFour"));
        sizePolicy1.setHeightForWidth(btnQualityFour->sizePolicy().hasHeightForWidth());
        btnQualityFour->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityFour);

        btnQualityFive = new QPushButton(gridLayoutWidget);
        btnQualityFive->setObjectName(QString::fromUtf8("btnQualityFive"));
        btnQualityFive->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnQualityFive->sizePolicy().hasHeightForWidth());
        btnQualityFive->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnQualityFive);

        textQuestion = new QTextEdit(centralWidget);
        textQuestion->setObjectName(QString::fromUtf8("textQuestion"));
        textQuestion->setGeometry(QRect(180, 10, 531, 91));
        textQuestion->setReadOnly(true);
        textAnswer = new QTextEdit(centralWidget);
        textAnswer->setObjectName(QString::fromUtf8("textAnswer"));
        textAnswer->setGeometry(QRect(180, 140, 531, 91));
        textAnswer->setReadOnly(true);
        btnShowAnswer = new QPushButton(centralWidget);
        btnShowAnswer->setObjectName(QString::fromUtf8("btnShowAnswer"));
        btnShowAnswer->setGeometry(QRect(180, 110, 531, 23));
        btnNextQuestion = new QPushButton(centralWidget);
        btnNextQuestion->setObjectName(QString::fromUtf8("btnNextQuestion"));
        btnNextQuestion->setGeometry(QRect(10, 270, 701, 23));
        gbCurrentLection = new QGroupBox(centralWidget);
        gbCurrentLection->setObjectName(QString::fromUtf8("gbCurrentLection"));
        gbCurrentLection->setGeometry(QRect(10, 10, 161, 131));
        formLayoutWidget = new QWidget(gbCurrentLection);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 141, 71));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lbPreserveation = new QLabel(formLayoutWidget);
        lbPreserveation->setObjectName(QString::fromUtf8("lbPreserveation"));

        gridLayout->addWidget(lbPreserveation, 2, 0, 1, 1);

        lbNewItems = new QLabel(formLayoutWidget);
        lbNewItems->setObjectName(QString::fromUtf8("lbNewItems"));

        gridLayout->addWidget(lbNewItems, 1, 0, 1, 1);

        lbRepeat = new QLabel(formLayoutWidget);
        lbRepeat->setObjectName(QString::fromUtf8("lbRepeat"));

        gridLayout->addWidget(lbRepeat, 0, 0, 1, 1);

        lbRepeatNumber = new QLabel(formLayoutWidget);
        lbRepeatNumber->setObjectName(QString::fromUtf8("lbRepeatNumber"));

        gridLayout->addWidget(lbRepeatNumber, 0, 1, 1, 1);

        lbNewItemsNumber = new QLabel(formLayoutWidget);
        lbNewItemsNumber->setObjectName(QString::fromUtf8("lbNewItemsNumber"));

        gridLayout->addWidget(lbNewItemsNumber, 1, 1, 1, 1);

        lbPreserveationNumber = new QLabel(formLayoutWidget);
        lbPreserveationNumber->setObjectName(QString::fromUtf8("lbPreserveationNumber"));

        gridLayout->addWidget(lbPreserveationNumber, 2, 1, 1, 1);

        RecondoUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RecondoUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 725, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuUser = new QMenu(menuBar);
        menuUser->setObjectName(QString::fromUtf8("menuUser"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        RecondoUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RecondoUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RecondoUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RecondoUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RecondoUIClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuUser->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionChooseCourse);
        menuFile->addAction(actionReadCourse);
        menuFile->addAction(actionCreateCourse);
        menuFile->addAction(actionEditCourse);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuUser->addAction(actionStartLection);
        menuHelp->addAction(actionAbout);

        retranslateUi(RecondoUIClass);

        QMetaObject::connectSlotsByName(RecondoUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *RecondoUIClass)
    {
        RecondoUIClass->setWindowTitle(QApplication::translate("RecondoUIClass", "Recondo", 0, QApplication::UnicodeUTF8));
        actionChooseCourse->setText(QApplication::translate("RecondoUIClass", "Wybierz kurs", 0, QApplication::UnicodeUTF8));
        actionStartLection->setText(QApplication::translate("RecondoUIClass", "Rozpocznij lekcj\304\231", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("RecondoUIClass", "O programie", 0, QApplication::UnicodeUTF8));
        actionCreateCourse->setText(QApplication::translate("RecondoUIClass", "Utw\303\263rz w\305\202asny kurs", 0, QApplication::UnicodeUTF8));
        actionEditCourse->setText(QApplication::translate("RecondoUIClass", "Edytuj kurs", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("RecondoUIClass", "Zamknij", 0, QApplication::UnicodeUTF8));
        actionReadCourse->setText(QApplication::translate("RecondoUIClass", "Wczytaj kurs", 0, QApplication::UnicodeUTF8));
        btnQualityOne->setText(QApplication::translate("RecondoUIClass", "0", 0, QApplication::UnicodeUTF8));
        btnQualityZero->setText(QApplication::translate("RecondoUIClass", "1", 0, QApplication::UnicodeUTF8));
        btnQualityTwo->setText(QApplication::translate("RecondoUIClass", "2", 0, QApplication::UnicodeUTF8));
        btnQualityThree->setText(QApplication::translate("RecondoUIClass", "3", 0, QApplication::UnicodeUTF8));
        btnQualityFour->setText(QApplication::translate("RecondoUIClass", "4", 0, QApplication::UnicodeUTF8));
        btnQualityFive->setText(QApplication::translate("RecondoUIClass", "5", 0, QApplication::UnicodeUTF8));
        btnShowAnswer->setText(QApplication::translate("RecondoUIClass", "Poka\305\274 odpowied\305\272", 0, QApplication::UnicodeUTF8));
        btnNextQuestion->setText(QApplication::translate("RecondoUIClass", "Nast\304\231pne pytanie", 0, QApplication::UnicodeUTF8));
        gbCurrentLection->setTitle(QApplication::translate("RecondoUIClass", "Obecna lekcja", 0, QApplication::UnicodeUTF8));
        lbPreserveation->setText(QApplication::translate("RecondoUIClass", "Utrwalanie:", 0, QApplication::UnicodeUTF8));
        lbNewItems->setText(QApplication::translate("RecondoUIClass", "Nowy materia\305\202:", 0, QApplication::UnicodeUTF8));
        lbRepeat->setText(QApplication::translate("RecondoUIClass", "Powt\303\263rki:", 0, QApplication::UnicodeUTF8));
        lbRepeatNumber->setText(QApplication::translate("RecondoUIClass", "0", 0, QApplication::UnicodeUTF8));
        lbNewItemsNumber->setText(QApplication::translate("RecondoUIClass", "0", 0, QApplication::UnicodeUTF8));
        lbPreserveationNumber->setText(QApplication::translate("RecondoUIClass", "0", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("RecondoUIClass", "Plik", 0, QApplication::UnicodeUTF8));
        menuUser->setTitle(QApplication::translate("RecondoUIClass", "U\305\274ytkownik", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("RecondoUIClass", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecondoUIClass: public Ui_RecondoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONDOUI_H
