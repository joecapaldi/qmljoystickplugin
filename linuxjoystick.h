#ifndef LINUXJOYSTICK_H
#define LINUXJOYSTICK_H

#include <QThread>
#include <QString>

class LinuxJoystick : public QThread
{
    Q_OBJECT
public:
    explicit LinuxJoystick(QObject *parent = 0);
    void openDevice(QString filename);
    void run() Q_DECL_OVERRIDE;
signals:
    void opened(int axes, int buttons, QString name);
    void closed();
    void axisEvent(int axis, int value);
    void buttonEvent(int button, bool pressed);
private:
    int fd;
};

#endif // LINUXJOYSTICK_H
