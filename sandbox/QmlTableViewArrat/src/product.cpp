
#include "product.h"

Product::Product()
{
}

Product::Product(int &id, const QString &name, const QString &description, int &qteStock)
{
    this->m_id = id;
    this->m_name = name;
    this->m_description = description;
    this->m_qteStrock = qteStock;
}

int Product::getId()
{
    return this->m_id;
}

QString Product::getName()
{
    return this->m_name;
}

void Product::setName(QString name)
{
    this->m_name = name;
}

QString Product::getDescription()
{
    return this->m_description;
}

void Product::setDescription(QString description)
{
    this->m_description = description;
}

int Product::getQteStrock()
{
    return this->m_qteStrock;
}

void Product::setQteStock(int qteStrock)
{
    this->m_qteStrock = qteStrock;
}