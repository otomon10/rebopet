#include <QTest>

#include "tst_gpio.h"
#include "tst_motor.h"

int main(int argc, char *argv[])
{
   int status = 0;

   {
       TestGpio testGpio;
       status |= QTest::qExec(&testGpio, argc, argv);
   }

   {
       TestMotor testMotor;
       status |= QTest::qExec(&testMotor, argc, argv);
   }

   return status;
}
