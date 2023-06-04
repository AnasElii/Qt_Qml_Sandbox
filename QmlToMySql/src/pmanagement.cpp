
#include "pmanagement.h"

PManagement::PManagement()
{
}

PManagement::~PManagement()
{
}

int PManagement::getTableSize()
{
    Connection::ConnectionOpen();
    int tableSize = Connection::SelectQuery("SELECT * FROM produit").size();
    qDebug() << "c++: Table Size: " << tableSize;
    return tableSize;
}

int PManagement::getLastIndex()
{
    Connection::ConnectionOpen();
    QSqlQuery query = Connection::SelectQuery("SELECT id FROM produit ORDER BY id DESC LIMIT 1");
    if (query.next())
    {
        QString lastRecord = query.value(0).toString();
        qDebug() << "c++: Last Record: " << lastRecord;
        return lastRecord.toInt() + 1;
    }
    return 0;
}

void PManagement::AddProduct(Product &product)
{

    Connection::ConnectionOpen();
    QVector<QVariant> params{product.getName(), product.getDescription(), product.getQteStrock()};
    Connection::CrudQuery("INSERT INTO produit (nom, designation, qteStock) VALUES (?,?,?)", params);
    // Connection::ConnectionClose();
}

void PManagement::UpdateProduct(int &id, Product &product)
{
    Connection::ConnectionOpen();
    QVector<QVariant> params{product.getName(), product.getDescription(), product.getQteStrock(), id};
    Connection::CrudQuery("UPDATE produit SET nom = ?, designation = ?, qteStock = ? WHERE id = ?", params);
    // Connection::ConnectionClose();
}

void PManagement::DeleteProduct(int &id)
{
    Connection::ConnectionOpen();
    QVector<QVariant> params{id};
    Connection::CrudQuery("DELETE FROM produit WHERE id = ?", params);
    // Connection::ConnectionClose();
}

QVariant PManagement::getData()
{
    QVariant data;
    QVariantList dataList = QVariantList{
        QVariantList{QVariant{"1"}, QVariant{"2"}, QVariant{"3"}},
        QVariantList{QVariant{"4"}, QVariant{"5"}, QVariant{"6"}}};
    data = QVariant::fromValue(dataList);
    // data = QVariant::fromValue(QVariantList{{"1", "2", "3"}, {"4", "5", "6"}});
    return data;
}
