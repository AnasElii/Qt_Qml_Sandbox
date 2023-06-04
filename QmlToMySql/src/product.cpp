
#include "product.h"

Product::Product()
{
}

Product::Product(const QString &name, const QString &description, int &qteStock)
{
    this->_name = name;
    this->_description = description;
    this->_qteStrock = qteStock;
}

int Product::getId()
{
    return this->_id;
}

QString Product::getName()
{
    return this->_name;
}

void Product::setName(QString name)
{
    this->_name = name;
}

QString Product::getDescription()
{
    return this->_description;
}

void Product::setDescription(QString description)
{
    this->_description = description;
}

int Product::getQteStrock()
{
    return this->_qteStrock;
}

void Product::setQteStock(int qteStrock)
{
    this->_qteStrock = qteStrock;
}