#include "connection.h"
#include <QDebug>

QSqlDatabase Connection::db = QSqlDatabase();

Connection::Connection(QObject *parent) : QObject(parent)
{
}

Connection::~Connection()
{
    ConnectionClose();
}

bool Connection::ConnectionOpen()
{
    // QCoreApplication::addLibraryPath("D:/Cl/Qt/6.5.0/mingw_64/plugins");
    if (!db.isOpen())
    {
        // Load MySQL driver plugin
        Connection::db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("gestion");
        db.setUserName("root");
        db.setPassword("1234");

        // Try to open database connection
        if (!db.open())
        {
            qDebug() << "Failed to connect to database!";
        }
        else
        {
            qDebug() << "Connected to database!";
        }
    }
    return db.isOpen();
}

void Connection::ConnectionClose()
{
    db.close();
}

QSqlQuery Connection::CrudQuery(const QString &querys, const QVector<QVariant> &params)
{
    QSqlQuery sqlQuery;

    if (!sqlQuery.prepare(querys))
    {
        qDebug() << "Failed to prepare query:" << sqlQuery.lastError().text();
        return sqlQuery;
    }

    for (const auto &param : params)
    {
        sqlQuery.addBindValue(param);
    }

    if (!sqlQuery.exec())
    {
        qDebug() << "Failed to execute query: " << sqlQuery.lastError().text();
        return sqlQuery;
    }

    return sqlQuery;
}

QSqlQuery Connection::SelectQuery(const QString &querys)
{
    QSqlQuery sqlQuery;

    if (!sqlQuery.exec(querys))
    {
        qDebug() << "Failed to execute query: " << sqlQuery.lastError().text();
        return sqlQuery;
    }
    return sqlQuery;
}

void Connection::Display(QSqlQuery &query)
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

QVector<Product> Connection::getData(QSqlQuery &query)
{
    QVector<Product> pList;

    // For the header
    Product *p = new Product();
    Product &product = *p;
    pList.push_back(product);

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString description = query.value(2).toString();
        int qteStock = query.value(3).toInt();

        // For the Rows
        p = new Product(id, name, description, qteStock);
        Product &product = *p;
        pList.push_back(product);

        qDebug() << "| " << id << " | " << name << " | " << description << " | " << qteStock << " |";
    }

    return pList;
}
