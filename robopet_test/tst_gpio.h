#ifndef TST_GPIO_H
#define TST_GPIO_H

#include <QTest>
#include "../robopet/gpio.h"

class TestGpio : public QObject
{
    Q_OBJECT

public:
    TestGpio();
    ~TestGpio();

private:
    void pinCheck(Gpio *pin);
    Gpio *pin187;
    Gpio *pin186;
    Gpio *pin89;
    Gpio *pin202;

private slots:
    void test_writeAndRead();

};

#endif // TST_GPIO_H
