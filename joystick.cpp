#include "joystick.h"

Joystick::Joystick(QObject *parent) : QObject(parent), m_number(-1)
{
}

Joystick::~Joystick()
{
}

int Joystick::number() const {
    return m_number;
}

void Joystick::setNumber(int arg)
{
    if (m_number == arg)
        return;

    m_number = arg;
    emit numberChanged(arg);
}
