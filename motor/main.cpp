#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "gpio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    return a.exec();
}
