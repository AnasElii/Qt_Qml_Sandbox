#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    // QQmlApplicationEngine engine;

    // const QUrl url(u"qrc:/mathLib/interface/main.qml"_qs);

    // // write the function to be called from QML
    // QObject::connect(
    //     &engine, &QQmlApplicationEngine::objectCreated,
    //     &app, [url](QObject *obj, const QUrl &objUrl)
    //     {
    //     if (!obj && url == objUrl)
    //         QCoreApplication::exit(-1); },
    //     Qt::QueuedConnection);

    // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // db.setHostName("localhost");
    // db.setPort(3306);
    // db.setDatabaseName("gestion");
    // db.setUserName("root");
    // db.setPassword("1234");
    // bool ok = db.open();

    // if (!db.open())
    // {
    //     qDebug() << "Not Connected!";
    // }
    // else
    // {
    //     qDebug() << "Connected!";
    // }

    // engine.load(url);
    // return app.exec();

    QGuiApplication app(argc, argv);
    // QCoreApplication::addLibraryPath("D:/Cl/Qt/6.5.0/mingw_64/plugins");

    // Load MySQL driver plugin
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("gestion");
    db.setUserName("root");
    db.setPassword("1234");

    // Try to open database connection
    if (!db.open())
    {
        qDebug() << "Failed to connect to database!";
        return 1;
    }

    qDebug() << "Connected to database!";
    QSqlQuery query;
    query.exec("SELECT * FROM produit");
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        qDebug() << id << name;
    }

    db.close();
    return 0;
}