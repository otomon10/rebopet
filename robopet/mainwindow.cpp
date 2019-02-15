#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->imageFace->setStyleSheet("border-image: url(:/face.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}
