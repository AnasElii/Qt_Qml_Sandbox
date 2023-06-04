
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
    int m_id;
    QString m_name;
    QString m_description;
    int m_qteStrock;

public:
    Product();
    Product(int &id, const QString &name, const QString &description, int &qteStock);

    int getId();

    QString getName();
    void setName(QString name);

    QString getDescription();
    void setDescription(QString description);

    int getQteStrock();
    void setQteStock(int qteStrock);
};

#endif // PRODUCT_H
