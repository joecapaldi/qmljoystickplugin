TEMPLATE = lib
CONFIG += plugin
QT += qml

DESTDIR = imports/Joystick
TARGET  = qmljoystickplugin

SOURCES += plugin.cpp \
    joystick.cpp

pluginfiles.files += \
    imports/Joystick/qmldir \
    imports/Joystick/Joystick.qml

qml.files = plugins.qml
#qml.path += $$[QT_INSTALL_EXAMPLES]/qml/qmljoystickplugins
#target.path += $$[QT_INSTALL_EXAMPLES]/qml/qmlextensionplugins/imports/TimeExample
#pluginfiles.path += $$[QT_INSTALL_EXAMPLES]/qml/qmlextensionplugins/imports/TimeExample

OTHER_FILES += README.md

INSTALLS += target qml pluginfiles

HEADERS += \
    joystick.h
