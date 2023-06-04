#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "tablemodel.h"
#include "qmlcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QmlController qmlController;

    const QUrl url(u"qrc:/Main/interface/main.qml"_qs);

    qmlRegisterType<TableModel>("TableModel", 1, 0, "TableModel");
    engine.rootContext()->setContextProperty("qmlController", &qmlController);

    // write the function to be called from QML
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl)
        {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);
    return app.exec();
}