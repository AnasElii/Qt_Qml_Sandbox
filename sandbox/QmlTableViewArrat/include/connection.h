#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "product.h"

class Connection : public QObject
{
    Q_OBJECT

public:
    Connection(QObject *parent = nullptr);
    ~Connection();

    static bool ConnectionOpen();
    static void ConnectionClose();
    static QSqlQuery CrudQuery(const QString &querys, const QVector<QVariant> &params = {});
    static QSqlQuery SelectQuery(const QString &querys);
    void Display(QSqlQuery &query);
    QVector<Product> getData(QSqlQuery &query);

private:
    static QSqlDatabase db;
};

#endif // CONNECTION_H