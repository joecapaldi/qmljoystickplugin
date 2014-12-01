#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>

class LinuxJoystick;

class Joystick : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(bool deviceOpen READ deviceOpen NOTIFY deviceOpenChanged)
    Q_PROPERTY(int axisCount READ axisCount NOTIFY axisCountChanged)
    Q_PROPERTY(int buttonCount READ buttonCount NOTIFY buttonCountChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(int buttons READ buttons NOTIFY buttonsChanged)

public:
    Joystick(QObject *parent=0);
    ~Joystick();
    int number() const;
    bool deviceOpen() const;
    int axisCount() const;
    int buttonCount() const;
    QString name() const;
    int buttons() const;

public slots:
    void setNumber(int newNumber);
    void close();

signals:
    void numberChanged(int newNumber);
    void deviceOpenChanged(bool isOpen);
    void axisCountChanged(int axisCount);
    void buttonCountChanged(int buttonCount);
    void nameChanged(QString name);
    void axisEvent(int axis, int value);
    void buttonEvent(int button, bool pressed);
    void buttonsChanged(int buttons);

private slots:
    void opened(int axes, int buttons, QString devName);
    void closed();
    void setButtons(int button, bool pressed);

private:
    void updateStatus();

    int m_number;
    LinuxJoystick *platformJoystick;
    bool m_deviceOpen;
    int m_axisCount;
    int m_buttonCount;
    QString m_name;
    int m_buttons;
};

#endif // JOYSTICK_H
