#ifndef TESTMOTOR_H
#define TESTMOTOR_H

#include <QTest>
#include "../robopet/motor.h"

class TestMotor : public QObject
{
    Q_OBJECT

public:
    TestMotor();
    ~TestMotor();

private:
    void motorCheckStop(Motor *motor);
    void motorCheckForward(Motor *motor);
    void motorCheckReverse(Motor *motor);
    void motorCheckSpeed(Motor *motor, double speed);
    Motor *motorR;
    Motor *motorL;

private slots:
    void test_stop();
    void test_forward();
    void test_reverse();
    void test_speed();
};

#endif // TESTMOTOR_H
