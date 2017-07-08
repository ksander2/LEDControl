TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


SOURCES += main.cpp \
    domain/led.cpp \
    commands/abstractcommand.cpp \
    commands/getledstate.cpp \
    commands/setledstate.cpp \
    commandreceiver.cpp \
    commands/getledcolor.cpp \
    commands/setledcolor.cpp \
    pipemanager.cpp \
    commands/setledrate.cpp \
    commands/getledrate.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    domain/led.h \
    commands/abstractcommand.h \
    commands/getledstate.h \
    commands/setledstate.h \
    commandreceiver.h \
    commands/getledcolor.h \
    commands/setledcolor.h \
    pipemanager.h \
    commands/getledrate.h \
    commands/setledrate.h \
    commands/getledrate.h

