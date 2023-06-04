
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product
{
    int _id;
    QString _name;
    QString _description;
    int _qteStrock;

public:
    Product();
    Product(const QString &name, const QString &description, int &qteStock);

    int getId();

    QString getName();
    void setName(QString name);

    QString getDescription();
    void setDescription(QString description);

    int getQteStrock();
    void setQteStock(int qteStrock);
};

#endif // PRODUCT_H
