#include <fcntl.h>
#include <unistd.h>
#include <linux/joystick.h>

#include "joystick.h"

JoyStick::JoyStick(std::string dev)
{
    fd = open(dev.c_str(), O_RDONLY);
    if(fd != -1)
    {
        // using non-blocking mode
        fcntl(fd, F_SETFL, O_NONBLOCK);

        th = std::thread(&JoyStick::polling, this);
        th.detach();
    }
}

JoyStick::~JoyStick()
{
    if(fd != -1) close(fd);
}

void JoyStick::checkButton(unsigned char number, short value, ButtonEvent event) {
    if(number == event)
    {
        if(value == 1)
        {
            emit buttonPushed(event);
        }
        else
        {
            emit buttonReleased(event);
        }
    }
}

void JoyStick::checkAxis(unsigned char number, short value, AXISEvent event) {
    if(number == event)
    {
        emit axisValueChanged(event, value);
    }
}

void JoyStick::polling()
{
    while(true)
    {
        js_event js;
        read(fd, &js, sizeof(js_event));
        switch (js.type & ~JS_EVENT_INIT)
        {
        case JS_EVENT_AXIS:
            checkAxis(js.number, js.value, AXISEvent::LStick_Y);
            checkAxis(js.number, js.value, AXISEvent::RStick_Y);
            checkAxis(js.number, js.value, AXISEvent::Acc_X);
            checkAxis(js.number, js.value, AXISEvent::Acc_Y);
            checkAxis(js.number, js.value, AXISEvent::Acc_Z);
            break;
        case JS_EVENT_BUTTON:
            checkButton(js.number, js.value, ButtonEvent::Up);
            checkButton(js.number, js.value, ButtonEvent::Down);
            checkButton(js.number, js.value, ButtonEvent::Left);
            checkButton(js.number, js.value, ButtonEvent::Right);
            checkButton(js.number, js.value, ButtonEvent::Triangle);
            checkButton(js.number, js.value, ButtonEvent::X);
            checkButton(js.number, js.value, ButtonEvent::Square);
            checkButton(js.number, js.value, ButtonEvent::Circle);
            checkButton(js.number, js.value, ButtonEvent::L1);
            checkButton(js.number, js.value, ButtonEvent::L2);
            checkButton(js.number, js.value, ButtonEvent::L3);
            checkButton(js.number, js.value, ButtonEvent::R1);
            checkButton(js.number, js.value, ButtonEvent::R2);
            checkButton(js.number, js.value, ButtonEvent::R3);
            checkButton(js.number, js.value, ButtonEvent::Start);
            checkButton(js.number, js.value, ButtonEvent::Select);
            checkButton(js.number, js.value, ButtonEvent::PS);
            break;
        default:
            break;
        }
        usleep(1 * 1000);
    }
}
