#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QVariant>

#include "tablemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/Main/interface/main.qml"_qs);

    // qmlRegisterType<TableModel>("myModel", 1, 1, "MyModel");

    // TableModel myModel;

    // engine.rootContext()->setContextProperty("myModel", &myModel);

    qDebug() << "Display Data: ";

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