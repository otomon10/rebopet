#ifndef ROBOPET_H
#define ROBOPET_H

#include <QObject>
#include "mainwindow.h"
#include "joystick.h"
#include "motor.h"

class RoboPet
{
public:
    RoboPet();
private:
    MainWindow *w;
    Motor *motorL;
    Motor *motorR;
    JoyStick *js;
};

#endif // ROBOPET_H
