#include <QThread>
#include "tst_motor.h"

TestMotor::TestMotor() :
    motorR(new Motor(187, 186)),
    motorL(new Motor(89, 202))
{
}

TestMotor::~TestMotor()
{
    test_stop();

    delete motorR;
    delete motorL;
}

void TestMotor::motorCheckStop(Motor *motor)
{
    motor->stop();
    QCOMPARE(Motor::MotorState::Stop,motor->getState());
    motor->run(0.0);
    QCOMPARE(Motor::MotorState::Stop,motor->getState());
}

void TestMotor::motorCheckForward(Motor *motor)
{
    motor->run(1.0);
    QCOMPARE(Motor::MotorState::RunningForward,motor->getState());
}

void TestMotor::motorCheckReverse(Motor *motor)
{
    motor->run(-1.0);
    QCOMPARE(Motor::MotorState::RunningReverse,motor->getState());
}

void TestMotor::motorCheckSpeed(Motor *motor, double speed)
{
    motor->run(speed);
    QCOMPARE(speed, motor->getSpeed());
    if(0 < speed){
        QCOMPARE(Motor::MotorState::RunningForward, motor->getState());
    } else {
        QCOMPARE(Motor::MotorState::RunningReverse,motor->getState());
    }
}

void TestMotor::test_stop()
{
    motorCheckStop(motorL);
    motorCheckStop(motorR);
    QThread::sleep(1);
}

void TestMotor::test_forward()
{
    motorCheckForward(motorL);
    QThread::sleep(1);
    motorCheckForward(motorR);
    QThread::sleep(1);
}

void TestMotor::test_reverse()
{
    motorCheckReverse(motorL);
    QThread::sleep(1);
    motorCheckReverse(motorR);
    QThread::sleep(1);
}

void TestMotor::test_speed()
{
    motorCheckSpeed(motorL, 0.2);
    motorCheckSpeed(motorR, -0.2);
    QThread::sleep(2);
    motorCheckSpeed(motorL, 0.4);
    motorCheckSpeed(motorR, -0.4);
    QThread::sleep(2);
    motorCheckSpeed(motorL, 0.6);
    motorCheckSpeed(motorR, -0.6);
    QThread::sleep(2);
    motorCheckSpeed(motorL, 0.8);
    motorCheckSpeed(motorR, -0.8);
    QThread::sleep(2);
    motorCheckSpeed(motorL, 1.0);
    motorCheckSpeed(motorR, -1.0);
    QThread::sleep(2);
}
