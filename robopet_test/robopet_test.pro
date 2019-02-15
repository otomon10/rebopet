QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../robopet/gpio.cpp \
    tst_gpio.cpp \
    main.cpp \
    tst_motor.cpp \
    ../robopet/motor.cpp

HEADERS += \
    ../robopet/gpio.h \
    tst_gpio.h \
    tst_motor.h \
    ../robopet/motor.h
