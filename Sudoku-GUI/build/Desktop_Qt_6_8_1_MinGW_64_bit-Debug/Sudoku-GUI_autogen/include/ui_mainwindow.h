/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *B_Menu;
    QPushButton *B_Levels;
    QPushButton *B_Statistics;
    QPushButton *B_Settings;
    QSpacerItem *verticalSpacer;
    QPushButton *B_Exit;
    QTabWidget *TB_MainTabs;
    QWidget *T_Menu;
    QPushButton *B_PlayGame;
    QWidget *T_Levels;
    QPushButton *pushButton;
    QWidget *T_Statistics;
    QWidget *T_Settings;
    QWidget *T_Sudoku;
    QWidget *W_GridContainer;
    QPushButton *B_Check;
    QPushButton *B_ClearFields;
    QPushButton *B_ToggleTime;
    QLabel *L_Timer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        B_Menu = new QPushButton(centralwidget);
        B_Menu->setObjectName("B_Menu");
        QFont font;
        font.setPointSize(10);
        B_Menu->setFont(font);

        verticalLayout->addWidget(B_Menu);

        B_Levels = new QPushButton(centralwidget);
        B_Levels->setObjectName("B_Levels");
        B_Levels->setFont(font);

        verticalLayout->addWidget(B_Levels);

        B_Statistics = new QPushButton(centralwidget);
        B_Statistics->setObjectName("B_Statistics");
        B_Statistics->setFont(font);

        verticalLayout->addWidget(B_Statistics);

        B_Settings = new QPushButton(centralwidget);
        B_Settings->setObjectName("B_Settings");
        B_Settings->setFont(font);

        verticalLayout->addWidget(B_Settings);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        B_Exit = new QPushButton(centralwidget);
        B_Exit->setObjectName("B_Exit");
        B_Exit->setFont(font);

        verticalLayout->addWidget(B_Exit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        TB_MainTabs = new QTabWidget(centralwidget);
        TB_MainTabs->setObjectName("TB_MainTabs");
        TB_MainTabs->setTabBarAutoHide(false);
        T_Menu = new QWidget();
        T_Menu->setObjectName("T_Menu");
        B_PlayGame = new QPushButton(T_Menu);
        B_PlayGame->setObjectName("B_PlayGame");
        B_PlayGame->setGeometry(QRect(20, 20, 80, 24));
        TB_MainTabs->addTab(T_Menu, QString());
        T_Levels = new QWidget();
        T_Levels->setObjectName("T_Levels");
        pushButton = new QPushButton(T_Levels);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 60, 80, 24));
        TB_MainTabs->addTab(T_Levels, QString());
        T_Statistics = new QWidget();
        T_Statistics->setObjectName("T_Statistics");
        TB_MainTabs->addTab(T_Statistics, QString());
        T_Settings = new QWidget();
        T_Settings->setObjectName("T_Settings");
        TB_MainTabs->addTab(T_Settings, QString());
        T_Sudoku = new QWidget();
        T_Sudoku->setObjectName("T_Sudoku");
        W_GridContainer = new QWidget(T_Sudoku);
        W_GridContainer->setObjectName("W_GridContainer");
        W_GridContainer->setGeometry(QRect(9, 39, 671, 501));
        B_Check = new QPushButton(T_Sudoku);
        B_Check->setObjectName("B_Check");
        B_Check->setGeometry(QRect(569, 10, 111, 25));
        B_Check->setFont(font);
        B_ClearFields = new QPushButton(T_Sudoku);
        B_ClearFields->setObjectName("B_ClearFields");
        B_ClearFields->setGeometry(QRect(480, 10, 80, 24));
        B_ToggleTime = new QPushButton(T_Sudoku);
        B_ToggleTime->setObjectName("B_ToggleTime");
        B_ToggleTime->setGeometry(QRect(100, 10, 80, 24));
        L_Timer = new QLabel(T_Sudoku);
        L_Timer->setObjectName("L_Timer");
        L_Timer->setGeometry(QRect(10, 10, 91, 21));
        TB_MainTabs->addTab(T_Sudoku, QString());

        gridLayout->addWidget(TB_MainTabs, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        TB_MainTabs->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        B_Menu->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        B_Levels->setText(QCoreApplication::translate("MainWindow", "Levels", nullptr));
        B_Statistics->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        B_Settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        B_Exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        B_PlayGame->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Menu), QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Play one", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Levels), QCoreApplication::translate("MainWindow", "Levels", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Statistics), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Settings), QCoreApplication::translate("MainWindow", "Settings", nullptr));
        B_Check->setText(QCoreApplication::translate("MainWindow", "Check for Answer", nullptr));
        B_ClearFields->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        B_ToggleTime->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        L_Timer->setText(QCoreApplication::translate("MainWindow", "Time: 24:59:59", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Sudoku), QCoreApplication::translate("MainWindow", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
