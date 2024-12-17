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
    QGridLayout *gridLayout_2;
    QLabel *L_Timer;
    QPushButton *B_ToggleTime;
    QSpacerItem *horizontalSpacer;
    QLabel *L_GameHeading;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *B_ClearFields;
    QPushButton *B_Check;
    QWidget *W_GridContainer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        B_Menu = new QPushButton(centralwidget);
        B_Menu->setObjectName("B_Menu");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        B_Menu->setFont(font);
        B_Menu->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        verticalLayout->addWidget(B_Menu);

        B_Levels = new QPushButton(centralwidget);
        B_Levels->setObjectName("B_Levels");
        B_Levels->setFont(font);
        B_Levels->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        verticalLayout->addWidget(B_Levels);

        B_Statistics = new QPushButton(centralwidget);
        B_Statistics->setObjectName("B_Statistics");
        B_Statistics->setFont(font);
        B_Statistics->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        verticalLayout->addWidget(B_Statistics);

        B_Settings = new QPushButton(centralwidget);
        B_Settings->setObjectName("B_Settings");
        B_Settings->setFont(font);
        B_Settings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        verticalLayout->addWidget(B_Settings);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        B_Exit = new QPushButton(centralwidget);
        B_Exit->setObjectName("B_Exit");
        B_Exit->setFont(font);
        B_Exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

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
        gridLayout_2 = new QGridLayout(T_Sudoku);
        gridLayout_2->setObjectName("gridLayout_2");
        L_Timer = new QLabel(T_Sudoku);
        L_Timer->setObjectName("L_Timer");
        sizePolicy.setHeightForWidth(L_Timer->sizePolicy().hasHeightForWidth());
        L_Timer->setSizePolicy(sizePolicy);
        L_Timer->setMaximumSize(QSize(80, 24));

        gridLayout_2->addWidget(L_Timer, 0, 0, 1, 1);

        B_ToggleTime = new QPushButton(T_Sudoku);
        B_ToggleTime->setObjectName("B_ToggleTime");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(B_ToggleTime->sizePolicy().hasHeightForWidth());
        B_ToggleTime->setSizePolicy(sizePolicy1);
        B_ToggleTime->setMinimumSize(QSize(0, 0));
        B_ToggleTime->setMaximumSize(QSize(16777215, 16777215));
        B_ToggleTime->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        gridLayout_2->addWidget(B_ToggleTime, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        L_GameHeading = new QLabel(T_Sudoku);
        L_GameHeading->setObjectName("L_GameHeading");
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        L_GameHeading->setFont(font1);
        L_GameHeading->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(L_GameHeading, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(87, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        B_ClearFields = new QPushButton(T_Sudoku);
        B_ClearFields->setObjectName("B_ClearFields");
        sizePolicy1.setHeightForWidth(B_ClearFields->sizePolicy().hasHeightForWidth());
        B_ClearFields->setSizePolicy(sizePolicy1);
        B_ClearFields->setMaximumSize(QSize(16777215, 16777215));
        B_ClearFields->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        gridLayout_2->addWidget(B_ClearFields, 0, 5, 1, 1);

        B_Check = new QPushButton(T_Sudoku);
        B_Check->setObjectName("B_Check");
        sizePolicy1.setHeightForWidth(B_Check->sizePolicy().hasHeightForWidth());
        B_Check->setSizePolicy(sizePolicy1);
        B_Check->setMaximumSize(QSize(16777215, 16777215));
        B_Check->setFont(font);
        B_Check->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white; \n"
"	color: black;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 12px;\n"
"    border: 1px solid black;\n"
"    border-radius: 5px;\n"
"    padding: 2px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: lightgrey;  \n"
"}\n"
"QPushButton:disabled {\n"
"	background-color: grey;\n"
"	color: darkgrey;\n"
"}"));

        gridLayout_2->addWidget(B_Check, 0, 6, 1, 1);

        W_GridContainer = new QWidget(T_Sudoku);
        W_GridContainer->setObjectName("W_GridContainer");
        sizePolicy.setHeightForWidth(W_GridContainer->sizePolicy().hasHeightForWidth());
        W_GridContainer->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(W_GridContainer, 1, 0, 1, 7);

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
        L_Timer->setText(QCoreApplication::translate("MainWindow", "Time: 24:59:59", nullptr));
        B_ToggleTime->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        L_GameHeading->setText(QCoreApplication::translate("MainWindow", "XxX Sudoku", nullptr));
        B_ClearFields->setText(QCoreApplication::translate("MainWindow", "Clear All", nullptr));
        B_Check->setText(QCoreApplication::translate("MainWindow", "Check for Answer", nullptr));
        TB_MainTabs->setTabText(TB_MainTabs->indexOf(T_Sudoku), QCoreApplication::translate("MainWindow", "Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
