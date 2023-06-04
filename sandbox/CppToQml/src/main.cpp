#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cppbackend.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<CppBackEnd>("CppBackEnd", 1, 0, "CppBackEnd");

    engine.load(QUrl(QStringLiteral("qrc:rec/interfaces/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}