#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <vector>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QTabBar>
#include <unordered_set>
#include <QMessageBox>

#define VERSION = "0.3.2-BETA"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int GridSize = 5;

private:
    Ui::MainWindow *ui;
    QGridLayout *GridLayout;
    std::vector<std::vector<QLineEdit*>> Cells;
    std::vector<std::vector<int>> SolvedGrid;

    bool SolveSudoku(std::vector<std::vector<int>>& Grid);
    bool isSafe(std::vector<std::vector<int>>& Grid, int Row, int Col, int Num);
    bool isValidGridSize(int Size);

    void createSudokuGrid(int size);
    void FillSudokuGrid(int Percentage);

private slots:

    // Buttons
    void on_B_Menu_clicked();
    void on_B_Levels_clicked();
    void on_B_Statistics_clicked();
    void on_B_Settings_clicked();
    void on_B_Exit_clicked();
    void on_B_PlayGame_clicked();
    void on_B_Check_clicked();
    void on_B_ClearFields_clicked();
    void on_B_ToggleTime_clicked();
};
#endif // MAINWINDOW_H
