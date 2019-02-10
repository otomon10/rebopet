#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <thread>
#include <QObject>

class JoyStick : public QObject
{
    Q_OBJECT

public:
    explicit JoyStick(std::string dev);
    ~JoyStick();
    enum ButtonEvent{
        Up = 4, Down = 6, Left = 7, Right = 5, Triangle = 12, X = 14, Square = 15, Circle = 13,
        L1 = 10, L2 = 8, L3 = 1, R1 = 11, R2 = 9, R3 = 2, Start = 0, Select = 3, PS = 16
    };
    enum AXISEvent{
        LStick_X = 0, LStick_Y, RStick_X, RStick_Y, Acc_X, Acc_Y, Acc_Z,
        UpPressure = 8, RightPressure, DownPressure, LeftPressure, L2Pressure, R2Pressure,
        L1Pressure, R1Pressure, TrianglePressure, CirclePressure, XPressure, SquarePressure
    };

private:
    void polling();
    void checkButton(unsigned char number, short value, ButtonEvent event);
    void checkAxis(unsigned char number, short value, AXISEvent event);
    int fd;
    std::thread th;

signals:
    void buttonPushed(ButtonEvent event);
    void buttonReleased(ButtonEvent event);
    void axisValueChanged(AXISEvent event, short value);

};

#endif // JOYSTICK_H
