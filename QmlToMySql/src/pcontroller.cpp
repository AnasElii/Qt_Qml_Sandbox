
#include "pcontroller.h"
#include <QDebug>

PController::PController(QObject *parent)
    : QObject{parent}
{
}

PController::~PController()
{
    delete product;
    delete pManagement;
}

int PController::getProductLastRecord()
{
    pManagement = new PManagement();
    return pManagement->getLastIndex();
}

int PController::getProductTableSize()
{
    pManagement = new PManagement();
    return pManagement->getTableSize();
}

void PController::newProduct(const QString &name, const QString &description, int &qteStock)
{
    product = new Product();
    product->setName(name);
    product->setDescription(description);
    product->setQteStock(qteStock);

    pManagement = new PManagement();
    pManagement->AddProduct(*product);
}

void PController::updateProduct(int &id, const QString &name, const QString &description, int &qteStock)
{
    product = new Product();
    product->setName(name);
    product->setDescription(description);
    product->setQteStock(qteStock);

    pManagement = new PManagement();
    pManagement->UpdateProduct(id, *product);
}

void PController::deleteProduct(int &id)
{
    pManagement = new PManagement();
    pManagement->DeleteProduct(id);
}

QVariant PController::getData()
{
    pManagement = new PManagement();
    return pManagement->getData();
}
