#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , GridLayout(nullptr)
{
    ui->setupUi(this);

    this->setWindowTitle("Sudoku Game");
    ui->TB_MainTabs->tabBar()->setVisible(false);


    createSudokuGrid(GridSize);

    FillSudokuGrid(99);
}

MainWindow::~MainWindow() {
    delete ui;
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
    if (size == 4) {
        regExpPattern = "[1-4]";
    } else if(size == 5) {
        regExpPattern = "[1-5]";
    } else if(size == 6) {
        regExpPattern = "[1-6]";
    } else if(size == 7) {
        regExpPattern = "[1-7]";
    } else if(size == 8) {
        regExpPattern = "[1-8]";
    } else if(size == 9) {
        regExpPattern = "[1-9]";
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            QLineEdit *Cell = new QLineEdit(this);
            Cell->setFixedSize(40, 40);
            Cell->setAlignment(Qt::AlignCenter);
            Cell->setFont(QFont("Segoe UI", 12));

            QRegularExpression regExp(regExpPattern);
            Cell->setValidator(new QRegularExpressionValidator(regExp, this));
            GridLayout->addWidget(Cell, row, col);
            Cells[row][col] = Cell;
        }
    }
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

        if(Cells[Row][Col]->text().isEmpty()) {
            Cells[Row][Col]->setText(QString::number(SolvedGrid[Row][Col]));
            Cells[Row][Col]->setReadOnly(true);
            CellsToFill--;
        }
    }
}

bool MainWindow::SolveSudoku(std::vector<std::vector<int>>& Grid) {
    for (int Row = 0; Row < GridSize; ++Row) {
        for(int Col = 0; Col < GridSize; ++Col) {
            if(Grid[Row][Col] == 0) {
                for (int Num = 1; Num <= GridSize; ++Num) {
                    if (isSafe(Grid, Row, Col, Num)) {
                        Grid[Row][Col] = Num;
                        if(SolveSudoku(Grid)) {
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
    int blockSize = std::sqrt(GridSize);

    for (int x = 0; x < GridSize; ++x) {
        if (Grid[Row][x] == Num || Grid[x][Col] == Num || Grid[Row - Row % blockSize + x / blockSize][Col - Col % blockSize + x % blockSize] == Num) {
            return false;
        }
    }
    return true;
}

bool MainWindow::isValidGridSize(int size) {
    int root = std::sqrt(size);
    return root * root == size;
}

void MainWindow::on_B_Check_clicked() {
    std::unordered_set<int> numSet;
    int blockSize = std::sqrt(GridSize);

    // Check rows
    for (int row = 0; row < GridSize; ++row) {
        numSet.clear();
        for (int col = 0; col < GridSize; ++col) {
            int num = Cells[row][col]->text().toInt();
            if (numSet.find(num) != numSet.end()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has not been solved correctly.");
                return;
            }
            numSet.insert(num);
        }
    }

    // Check columns
    for (int col = 0; col < GridSize; ++col) {
        numSet.clear();
        for (int row = 0; row < GridSize; ++row) {
            int num = Cells[row][col]->text().toInt();
            if (numSet.find(num) != numSet.end()) {
                QMessageBox::information(this, "Verification failed", "The Sudoku has not been solved correctly.");
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
                    int num = Cells[blockRow * blockSize + row][blockCol * blockSize + col]->text().toInt();
                    if (numSet.find(num) != numSet.end()) {
                        QMessageBox::information(this, "Verification failed", "The Sudoku has not been solved correctly.");
                        return;
                    }
                    numSet.insert(num);
                }
            }
        }
    }

    QMessageBox::information(this, "Check successful", "Congratulations! \nYou have solved the Sudoku correctly!");
}

void MainWindow::on_B_ClearFields_clicked() {

}

void MainWindow::on_B_ToggleTime_clicked() {

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
