#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTime>

void Display(QSqlQuery &query)
{
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString description = query.value(2).toString();
        int qteStock = query.value(3).toInt();

        qDebug() << "| " << id << " | " << name << " | " << description << " | " << qteStock << " |";
    }
}

int main(int argc, char *argv[])
{
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/mathLib/interface/main.qml"_qs);

    // write the function to be called from QML
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl)
        {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    QGuiApplication app(argc, argv);
    // QCoreApplication::addLibraryPath("D:/Cl/Qt/6.5.0/mingw_64/plugins");

    // Load MySQL driver plugin
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("gestion");
    db.setUserName("root");
    db.setPassword("1234");

    // Create Query
    QSqlQuery SelectQuery;
    QSqlQuery CrudQuery;

    // Try to open database connection
    if (!db.open())
    {
        qDebug() << "Failed to connect to database!";
        return 1;
    }
    else
        qDebug() << "Connected to database!";

    SelectQuery.exec("SELECT * FROM produit");

    engine.load(url);
    return app.exec();
}