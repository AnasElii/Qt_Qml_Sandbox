#include <QObject>
#include <QCoreApplication>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MyClass *mClass = new MyClass();

    return app.exec();
}