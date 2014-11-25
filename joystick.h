#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>

class Joystick : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)

public:
    Joystick(QObject *parent=0);
    ~Joystick();
    int number() const;
public slots:
    void setNumber(int arg);

signals:
    void numberChanged(int arg);

private:
    int m_number;
};

#endif // JOYSTICK_H
