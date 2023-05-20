#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <fstream>
#include <string>
#include <QFile>
#include <iostream>
#include "List.h"
#include "airplane.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    protoitem = new QTableWidgetItem();
    protoitem->setTextAlignment(Qt::AlignCenter);
    ui->setupUi(this);
    setWindowTitle("Aviasales");
    QHeaderView* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    QString fileName = QFileDialog::getOpenFileName(this,"Open a file",QDir::homePath());
//    QString *str = new QString("London");
//    QTableWidgetItem *item = new QTableWidgetItem;
//    item->setText(fileName);
//    ui->tableWidget->setItem(0,0,item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable() {
    ui->tableWidget->setRowCount(list.getSize());
    for (int i=0;i<list.getSize();i++) {
        QTableWidgetItem *item1 = protoitem->clone();
        QTableWidgetItem *item2 = protoitem->clone();
        QTableWidgetItem *item3 = protoitem->clone();
        QTableWidgetItem *item4 = protoitem->clone();
        QTableWidgetItem *item5 = protoitem->clone();
        item1->setText(list.get(i).getNumber());
        item2->setText(list.get(i).getDirection());
        item3->setText(list.get(i).getDepTime());
        item4->setText(list.get(i).getSeats());
        item5->setText(list.get(i).getType());
        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        ui->tableWidget->setItem(i,3,item4);
        ui->tableWidget->setItem(i,4,item5);
    }
    ui->tableWidget->setStatusTip("Записей в таблице: "+QString::number(ui->tableWidget->rowCount()));
}
void MainWindow::loadFile() {
    //QString fileName = QFileDialog::getOpenFileName(this,"Open a file",QDir::homePath());
    QFile file("/Users/admin/kursachOOP/Data/data.db");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList cols = line.split(",");
        if (cols.size()!=5) continue;
        Airplane plane = Airplane(cols[0],cols[1],cols[2],cols[3],cols[4]);
        list.add(plane);
    }
    file.close();
    updateTable();
    ui->statusbar->showMessage("Данные загружены!");
}
void MainWindow::on_helpAbout_triggered()
{
    QMessageBox::information(this,"Info","Выполнил:\nСтудент 2 курса\nгруппы ИКПИ-15\nИльницкий Иван Николаевич");
}



void MainWindow::on_fileOpen_triggered()
{
    list.clear();
    loadFile();
}


void MainWindow::on_fileOpen_hovered()
{
   //ui->statusbar->showMessage("Открыть существующую базу данных",2000);
}

void MainWindow::on_fileSave_triggered()
{

}


void MainWindow::on_tableWidget_cellChanged(int row, int column)
{

}


void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{

}


void MainWindow::on_tableWidget_cellPressed(int row, int column)
{
    ui->statusbar->showMessage("Редактирование ячейки");
}


void MainWindow::on_action_triggered()
{
    loadFile();
}

