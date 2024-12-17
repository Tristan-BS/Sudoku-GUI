#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <unordered_set>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , GridLayout(nullptr)
    , GameTimer(new QTimer(this))
    , elapsedSeconds(0)
{
    ui->setupUi(this);

    this->setWindowTitle("Sudoku");
    ui->L_GameHeading->setText(QString::number(GridSize) + "x" + QString::number(GridSize) + " Sudoku");
    ui->TB_MainTabs->tabBar()->setVisible(false);

    connect(GameTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    if (isValidGridSize(GridSize)) {
        createSudokuGrid(GridSize);
        FillSudokuGrid(FillInPercentage);

        StartTime = QTime::currentTime();
        GameTimer->start(1000);
    } else {
        cout << "Ungültige GridSize: " << GridSize << endl;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::isValidGridSize(int size) {
    int root = std::sqrt(size);
    return root * root == size;
}

void MainWindow::createSudokuGrid(int size) {
    if (GridLayout != nullptr) {
        QLayoutItem *Child;
        while ((Child = GridLayout->takeAt(0)) != nullptr) {
            delete Child->widget();
            delete Child;
        }
    } else {
        GridLayout = new QGridLayout(ui->W_GridContainer);
    }

    Cells.resize(size, std::vector<QLineEdit*>(size, nullptr));

    QString regExpPattern;
    if (size <= 9) {
        regExpPattern = QString("[1-%1]").arg(size);
    } else {
        regExpPattern = QString("([1-9]|1[0-%1])").arg(size - 10);
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            QLineEdit *Cell = new QLineEdit(this);
            Cell->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            Cell->setAlignment(Qt::AlignCenter);
            Cell->setFont(QFont("Segoe UI", 12));

            // Calculate the border
            QString topBorder = (row % 3 == 0) ? "2px solid black" : "1px solid lightgrey";
            QString bottomBorder = ((row + 1) % 3 == 0) ? "2px solid black" : "1px solid lightgrey";
            QString leftBorder = (col % 3 == 0) ? "2px solid black" : "1px solid lightgrey";
            QString rightBorder = ((col + 1) % 3 == 0) ? "2px solid black" : "1px solid lightgrey";

            // Outline the 9er blocks
            if (row == 0) topBorder = "3px solid black";
            if (row == size - 1) bottomBorder = "3px solid black";
            if (col == 0) leftBorder = "3px solid black";
            if (col == size - 1) rightBorder = "3px solid black";

            // set Stylesheet
            Cell->setStyleSheet(
                QString(
                    "QLineEdit {"
                    "    background-color: white;"
                    "    color: black;"
                    "    font-family: 'Segoe UI';"
                    "    font-size: 14px;"
                    "    border-top: %1;"
                    "    border-bottom: %2;"
                    "    border-left: %3;"
                    "    border-right: %4;"
                    "    padding: 0;"
                    "}"
                    "QLineEdit:focus {"
                    "    border: 1px solid black;"
                    "}"
                    ).arg(topBorder).arg(bottomBorder).arg(leftBorder).arg(rightBorder)
                );

            QRegularExpression regExp(regExpPattern);
            Cell->setValidator(new QRegularExpressionValidator(regExp, this));
            GridLayout->addWidget(Cell, row, col);
            Cells[row][col] = Cell;
        }
    }

    ui->W_GridContainer->setLayout(GridLayout);
}

void MainWindow::FillSudokuGrid(int Percentage) {
    std::vector<std::vector<int>> Grid(GridSize, std::vector<int>(GridSize, 0));
    SolveSudoku(Grid);
    SolvedGrid = Grid;

    int totalCells = GridSize * GridSize;
    int CellsToFill = (totalCells * Percentage) / 100;

    std::srand(std::time(0));

    while (CellsToFill > 0) {
        int Row = std::rand() % GridSize;
        int Col = std::rand() % GridSize;

        if (Cells[Row][Col]->text().isEmpty()) {
            Cells[Row][Col]->setText(QString::number(SolvedGrid[Row][Col]));
            Cells[Row][Col]->setReadOnly(true);
            CellsToFill--;
        }
    }
}

bool MainWindow::SolveSudoku(std::vector<std::vector<int>>& Grid) {
    for (int Row = 0; Row < GridSize; ++Row) {
        for (int Col = 0; Col < GridSize; ++Col) {
            if (Grid[Row][Col] == 0) {
                for (int Num = 1; Num <= GridSize; ++Num) {
                    if (isSafe(Grid, Row, Col, Num)) {
                        Grid[Row][Col] = Num;
                        if (SolveSudoku(Grid)) {
                            return true;
                        }

                        Grid[Row][Col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool MainWindow::isSafe(std::vector<std::vector<int>>& Grid, int Row, int Col, int Num) {
    int blockSize = std::sqrt(GridSize); // Block size

    for (int x = 0; x < GridSize; ++x) {
        if (Grid[Row][x] == Num || Grid[x][Col] == Num ||
            Grid[Row - Row % blockSize + x / blockSize][Col - Col % blockSize + x % blockSize] == Num) {
            return false;
        }
    }
    return true;
}

void MainWindow::on_B_Check_clicked() {
    std::unordered_set<int> numSet;
    int blockSize = std::sqrt(GridSize);

    // Check rows
    for (int row = 0; row < GridSize; ++row) {
        numSet.clear();
        for (int col = 0; col < GridSize; ++col) {
            QString cellText = Cells[row][col]->text();
            if (cellText.isEmpty()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has empty cells.");
                return;
            }
            int num = cellText.toInt();
            if (numSet.find(num) != numSet.end()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has duplicate numbers in a row.");
                return;
            }
            numSet.insert(num);
        }
    }

    // Check columns
    for (int col = 0; col < GridSize; ++col) {
        numSet.clear();
        for (int row = 0; row < GridSize; ++row) {
            QString cellText = Cells[row][col]->text();
            if (cellText.isEmpty()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has empty cells.");
                return;
            }
            int num = cellText.toInt();
            if (numSet.find(num) != numSet.end()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has duplicate numbers in a column.");
                return;
            }
            numSet.insert(num);
        }
    }

    // Check blocks
    for (int blockRow = 0; blockRow < blockSize; ++blockRow) {
        for (int blockCol = 0; blockCol < blockSize; ++blockCol) {
            numSet.clear();
            for (int row = 0; row < blockSize; ++row) {
                for (int col = 0; col < blockSize; ++col) {
                    QString cellText = Cells[blockRow * blockSize + row][blockCol * blockSize + col]->text();
                    if (cellText.isEmpty()) {
                        QMessageBox::information(this, "Verification failed", "The Sudoku has empty cells.");
                        return;
                    }
                    int num = cellText.toInt();
                    if (numSet.find(num) != numSet.end()) {
                        QMessageBox::information(this, "Verification failed", "The Sudoku has duplicate numbers in a block.");
                        return;
                    }
                    numSet.insert(num);
                }
            }
        }
    }

    QMessageBox::information(this, "Check successful", "Congratulations! \nYou have solved the Sudoku correctly!");
}

void MainWindow::updateTimer() {
    QTime currentTime = QTime::currentTime();
    int totalElapsedSeconds = elapsedSeconds + StartTime.secsTo(currentTime);

    int hours = totalElapsedSeconds / 3600;
    int minutes = (totalElapsedSeconds % 3600) / 60;
    int seconds = totalElapsedSeconds % 60;

    QString timeString = QString("Time: %1:%2:%3")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    ui->L_Timer->setText(timeString);
}

void MainWindow::on_B_ClearFields_clicked() {
    for (int row = 0; row < GridSize; ++row) {
        for (int col = 0; col < GridSize; ++col) {
            if (!Cells[row][col]->isReadOnly()) {
                Cells[row][col]->clear();
            }
        }
    }
}

void MainWindow::on_B_ToggleTime_clicked() {
    if (GameTimer->isActive()) {
        GameTimer->stop();
        elapsedSeconds += StartTime.secsTo(QTime::currentTime());
        ui->B_ToggleTime->setText("Resume");
    } else {
        StartTime = QTime::currentTime();
        GameTimer->start(1000);
        ui->B_ToggleTime->setText("Pause");
    }
}

void MainWindow::on_B_Menu_clicked() {
    ui->TB_MainTabs->setCurrentIndex(0);
}

void MainWindow::on_B_Levels_clicked() {
    ui->TB_MainTabs->setCurrentIndex(1);
}

void MainWindow::on_B_Statistics_clicked() {
    ui->TB_MainTabs->setCurrentIndex(2);
}

void MainWindow::on_B_Settings_clicked() {
    ui->TB_MainTabs->setCurrentIndex(3);
}

void MainWindow::on_B_Exit_clicked() {
    exit(0);
}

void MainWindow::on_B_PlayGame_clicked() {
    cout << "HSIEFSE" << endl;
}
