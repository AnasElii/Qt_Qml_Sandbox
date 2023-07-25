#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQMLContext>

#include "lumbersawcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

    LumberSawController lumberSawController;
    engine.rootContext()->setContextProperty("lumberSawController", &lumberSawController);

    const QUrl url(u"qrc:/mainLib/interfaces/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &application, [url](QObject *obj, const QUrl &objUrl)
        {
        if(!obj && objUrl == url)
            QGuiApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    qDebug() << "Applicaiton name: " << QGuiApplication::applicationName();
    application.setApplicationVersion("1.0.0");
    qDebug() << "Applicaiton version: " << QGuiApplication::applicationVersion();
    qDebug() << "Platform name: " << QGuiApplication::platformName();
    qDebug() << "Platform name: " << application.platformName();
    qDebug() << "Device pixel ratio: " << application.devicePixelRatio();

    return application.exec();
}