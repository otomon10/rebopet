#include "robopet.h"

RoboPet::RoboPet() :
    w(new MainWindow()),
    motorL(new Motor(89, 202)),
    motorR(new Motor(187, 186)),
    js(new JoyStick("/dev/input/js0"))
{
    w->show();

    QObject::connect(js, &JoyStick::axisValueChanged, [=](JoyStick::AXISEvent event, short value){
        if(event == JoyStick::AXISEvent::LStick_Y){
            motorL->run(-value/32767.0);
        }
        if(event == JoyStick::AXISEvent::RStick_Y){
            motorR->run(-value/32767.0);
        }
    });
}
