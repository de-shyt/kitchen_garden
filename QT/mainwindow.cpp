#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("POTATO SIMULATOR");
    setStyleSheet(("background-image: url(:/img/weed.jpg)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    play = new PlayStart(this);
}

