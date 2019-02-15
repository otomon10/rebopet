#include "tst_gpio.h"

TestGpio::TestGpio()
{
    pin187 = new Gpio(187, Gpio::Out);
    pin186 = new Gpio(186, Gpio::Out);
    pin89 = new Gpio(89, Gpio::Out);
    pin202 = new Gpio(202, Gpio::Out);
}

TestGpio::~TestGpio()
{
    delete pin187;
    delete pin186;
    delete pin89;
    delete pin202;
}

void TestGpio::pinCheck(Gpio *pin){
    pin->write(1);
    QCOMPARE(1, pin->read());
    pin->write(0);
    QCOMPARE(0, pin->read());
}

void TestGpio::test_writeAndRead()
{
    pinCheck(pin187);
    pinCheck(pin186);
    pinCheck(pin89);
    pinCheck(pin202);
}
