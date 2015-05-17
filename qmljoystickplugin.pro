TEMPLATE = lib
CONFIG += qt plugin
QT += qml

TARGET = $$qtLibraryTarget(Joystick)
TARGETPATH = Joystick
API_VER=1.0

importPath = $$[QT_INSTALL_QML]/$$replace(TARGETPATH, \\., /).$$API_VER
target.path = $${importPath}

qmldir.path = $${importPath}
qmldir.files += $$PWD/qmldir 

SOURCES += plugin.cpp \
    joystick.cpp \
    linuxjoystick.cpp

HEADERS += \
    joystick.h \
    linuxjoystick.h

OTHER_FILES += README.md

INSTALLS += target qmldir

