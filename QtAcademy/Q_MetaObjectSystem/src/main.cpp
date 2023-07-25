#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQMLContext>

#include "lumbersawcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

    // Register C++ class to QML
    LumberSawController lumberSawController;
    engine.rootContext()->setContextProperty("lumberSawController", &lumberSawController);

    const QUrl url(u"qrc:/mainLib/interfaces/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &application, [url](QObject *obj, const QUrl &objUrl)
        {
        if(!obj && objUrl == url)
            QGuiApplication::exit(-1); },
        Qt::QueuedConnection);

    // Create Dynamic Properties in Run-Time
    // lumberSawController.setSawSpeed(5);
    // lumberSawController.setObjectName("Saw 3");
    // lumberSawController.setProperty("model", "Cutter 2000 MX");

    // qDebug() << "Object Name: " << lumberSawController.property("objectName")
    //          << " | Model Name: " << lumberSawController.property("model").toString()
    //          << " | Object Speed: " << lumberSawController.property("sawSpeed").toInt();

    // Runtime information
    // qDebug()
    //     << "Class name: " << lumberSawController.metaObject()->className()
    //     << "\nClass info: " << lumberSawController.metaObject()->classInfo(0).name()
    //     << "\nSupper class name: " << lumberSawController.metaObject()->superClass()->className();

    // application.setApplicationVersion("1.0.0");
    // qDebug() << "Applicaiton name: " << QGuiApplication::applicationName()
    //          << " | Applicaiton version: " << QGuiApplication::applicationVersion()
    //          << " | Platform name: " << QGuiApplication::platformName()
    //          << " | Platform name: " << application.platformName()
    //          << " | Device pixel ratio: " << application.devicePixelRatio();

    engine.load(url);
    return application.exec();
}