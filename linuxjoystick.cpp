#include "linuxjoystick.h"
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/joystick.h>
#include <cerrno>
#include <QDebug>

LinuxJoystick::LinuxJoystick(QObject *parent) : QThread(parent), fd(-1)
{
}

void LinuxJoystick::openDevice(QString filename)
{
    fd = open(filename.toUtf8().data(), O_RDONLY | O_NONBLOCK);
    if(fd >= 0) {
        int axisCount = 0;
        int buttonCount = 0;
        ioctl( fd, JSIOCGAXES, &axisCount );
        ioctl( fd, JSIOCGBUTTONS, &buttonCount );
        char nameChar[128];
        ioctl( fd, JSIOCGNAME(128), &nameChar );
        emit opened(axisCount, buttonCount, QString::fromUtf8(nameChar));
        start();
    } else {
        qDebug() << Q_FUNC_INFO << "Unable to open joystick " << filename;
    }
}

void LinuxJoystick::run() {
    while(!isInterruptionRequested()) {
        struct js_event js;
        while(read(fd, &js, sizeof(struct js_event)) > 0) {
            switch (js.type & ~JS_EVENT_INIT) {
            case JS_EVENT_AXIS:
                emit axisEvent(js.number, js.value);
                break;
            case JS_EVENT_BUTTON:
                emit buttonEvent(js.number, js.value);
                break;
            }
        }
        if (errno != EAGAIN) {
            qDebug() << Q_FUNC_INFO << "Error reading joystick - quitting.";
            requestInterruption();
        }
        msleep(16); // Sleep at least 16ms
    }
    emit closed();
}
