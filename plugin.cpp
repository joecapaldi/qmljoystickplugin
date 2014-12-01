#include <QtQml/QQmlExtensionPlugin>
#include <QtQml/qqml.h>
#include <qdebug.h>
#include <qcoreapplication.h>
#include "joystick.h"

class QExampleQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(uri == QLatin1String("Joystick"));
        qmlRegisterType<Joystick>(uri, 1, 0, "Joystick");
    }
};
#include "plugin.moc"
