QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../motor/gpio.cpp \
    tst_gpio.cpp \
    main.cpp \
    tst_motor.cpp \
    ../motor/motor.cpp

HEADERS += \
    ../motor/gpio.h \
    tst_gpio.h \
    tst_motor.h \
    ../motor/motor.h
