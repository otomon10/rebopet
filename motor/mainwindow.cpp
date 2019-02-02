#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    motorL(new Motor(89, 202)),
    motorR(new Motor(187, 186))
{
    ui->setupUi(this);

    connect(ui->btnForward, &QPushButton::clicked, [=](){
        motorL->run(ui->SpinBoxPwm->value());
        motorR->run(ui->SpinBoxPwm->value());
    });

    connect(ui->btnReverse, &QPushButton::clicked, [=](){
        motorL->run(-ui->SpinBoxPwm->value());
        motorR->run(-ui->SpinBoxPwm->value());
    });

    connect(ui->btnStop, &QPushButton::clicked, [=](){
        motorL->stop();
        motorR->stop();
    });

    connect(ui->btnTurnRight, &QPushButton::clicked, [=](){
        motorL->run(ui->SpinBoxPwm->value());
        motorR->run(-ui->SpinBoxPwm->value());
    });

    connect(ui->btnTurnLeft, &QPushButton::clicked, [=](){
        motorL->run(-ui->SpinBoxPwm->value());
        motorR->run(ui->SpinBoxPwm->value());
    });

    ui->imageFace->setStyleSheet("border-image: url(:/face.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}
