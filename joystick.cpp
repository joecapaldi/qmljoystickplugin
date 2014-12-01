#include "joystick.h"
#include "linuxjoystick.h"
#include <QDebug>

Joystick::Joystick(QObject *parent) : QObject(parent), m_number(-1), platformJoystick(0), m_deviceOpen(false),
    m_axisCount(0), m_buttonCount(0)
{
}

Joystick::~Joystick()
{
}

int Joystick::number() const {
    return m_number;
}

bool Joystick::deviceOpen() const
{
    return m_deviceOpen;
}

int Joystick::axisCount() const
{
    return m_axisCount;
}

int Joystick::buttonCount() const
{
    return m_buttonCount;
}

QString Joystick::name() const
{
    return m_name;
}

void Joystick::setNumber(int arg)
{
    qDebug() << Q_FUNC_INFO << arg;
    if (m_number == arg)
        return;

    m_number = arg;
    if(platformJoystick) {
        platformJoystick->requestInterruption();
        platformJoystick->wait(1000);
        platformJoystick->deleteLater();
        platformJoystick = 0;
    }
    if(m_number < 0) return;

    platformJoystick = new LinuxJoystick(this);
    connect(platformJoystick, SIGNAL(axisEvent(int,int)), this, SIGNAL(axisEvent(int,int)), Qt::QueuedConnection);
    connect(platformJoystick, SIGNAL(buttonEvent(int,bool)), this, SIGNAL(buttonEvent(int,bool)), Qt::QueuedConnection);
    connect(platformJoystick, SIGNAL(closed()), this, SLOT(closed()), Qt::QueuedConnection);
    connect(platformJoystick, SIGNAL(opened(int,int,QString)), this, SLOT(opened(int,int,QString)));
    emit numberChanged(m_number);
    platformJoystick->openDevice(QString("/dev/input/js%1").arg(m_number));
}

void Joystick::opened(int axes, int buttons, QString devName) {
    qDebug() << Q_FUNC_INFO << axes << buttons << devName;
    m_deviceOpen = true;
    m_axisCount = axes;
    m_buttonCount = buttons;
    m_name = devName;
    updateStatus();
}

void Joystick::closed() {
    m_deviceOpen = false;
    m_axisCount = 0;
    m_buttonCount = 0;
    m_name = QString::null;
    updateStatus();
    if(platformJoystick) {
        platformJoystick->requestInterruption();
        platformJoystick->wait(1000);
        platformJoystick->deleteLater();
        platformJoystick = 0;
    }
}

void Joystick::updateStatus()
{
    emit axisCountChanged(m_axisCount);
    emit buttonCountChanged(m_buttonCount);
    emit nameChanged(m_name);
    emit deviceOpenChanged(m_deviceOpen);
}
