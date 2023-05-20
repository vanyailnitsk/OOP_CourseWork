#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "List.h"
#include "airplane.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT;
    QTableWidgetItem *protoitem;
    List<Airplane> list;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTable();
    void loadFile();

private slots:

    void on_helpAbout_triggered();

    void on_fileOpen_triggered();

    void on_fileOpen_hovered();

    void on_fileSave_triggered();

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_tableWidget_cellPressed(int row, int column);

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
