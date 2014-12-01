TEMPLATE = lib
CONFIG += plugin
QT += qml

DESTDIR = imports/Joystick
TARGET  = qmljoystickplugin

SOURCES += plugin.cpp \
    joystick.cpp \
    linuxjoystick.cpp

pluginfiles.files += \
    imports/Joystick/qmldir \
    imports/Joystick/Joystick.qml

#qml.files = plugins.qml
#qml.path += .
target.path += imports/Joystick
pluginfiles.path += imports/Joystick

OTHER_FILES += README.md

INSTALLS += target qml pluginfiles

HEADERS += \
    joystick.h \
    linuxjoystick.h
