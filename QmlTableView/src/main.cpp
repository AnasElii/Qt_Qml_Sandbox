#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <iostream>
#include <string>

using namespace std;

#include "tablemodel.h"

void dataReady(QVariantList argData)
{
    // Process the data here
    QVariantList dataList = argData;
    for (int i = 0; i < dataList.size(); ++i)
    {
        // QVariantList rowList = dataList[i].toList();
        QVariantList rowData = qvariant_cast<QVariantList>(dataList[i]);

        for (int j = 0; j < rowData.size(); ++j)
        {
            // string rowInfo = rowData[j].toString().toStdString();
            // std::cout << rowInfo << " | ";
            QString itemValue = rowData[j].toString().trimmed();
            qDebug().noquote() << itemValue << " | ";
        }
        qDebug();
    }
}

void fillData()
{
    // Initialize your data here
    QVariantList row1 = {"item1", 13, true};
    QVariantList row2 = {"item2", 22, false};
    QVariantList row3 = {"item3", 31, true};

    QVariantList data;
    data.append(row1);
    data.append(row2);
    data.append(row3);

    // Emit the signal when the data is ready
    emit dataReady(data);
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/Main/interface/main.qml"_qs);

    qmlRegisterType<TableModel>("TableModel", 1, 0, "TableModel");

    qDebug() << "Display Data: ";
    fillData();

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