#include "rotation.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Rotation>("Rotation",1,0,"OrientationClass");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Orientation/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
