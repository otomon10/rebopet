#include <QApplication>
#include "robopet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RoboPet robopet;

    return a.exec();
}
