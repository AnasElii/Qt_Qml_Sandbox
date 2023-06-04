#include "qmlcontroller.h"
#include <QDebug>

QmlController::QmlController(QObject *parent) : QObject(parent)
{
    qDebug() << "Fill the Id Filed";
    pController = new PController();
    m_tableSize = pController->getProductLastRecord();
    m_id = m_tableSize;
    // QObject::connect(this, &QmlController::newProductContoller, this, &QmlController::setNewProduct);
}

QmlController::~QmlController()
{
    // delete pController;
}

void QmlController::AddProduct()
{
    qDebug() << "c++: Add Method in QmlController";
    if (m_name.isEmpty() || m_name.isEmpty() || m_qteStock == 0)
        return;

    pController = new PController();
    pController->newProduct(m_name, m_description, m_qteStock);

    emit newProductContoller(m_name, m_description, m_qteStock);
}

Q_INVOKABLE void QmlController::UpdateProduct()
{
    qDebug() << "c++: Update Method in QmlController";
    if (m_name.isEmpty() || m_name.isEmpty() || m_qteStock == 0 || (m_id < 0 && m_id > m_tableSize))
        return;

    pController = new PController();
    pController->updateProduct(m_id, m_name, m_description, m_qteStock);

    emit updateProductContoller(m_id, m_name, m_description, m_qteStock);
}

Q_INVOKABLE void QmlController::DeleteProduct()
{
    qDebug() << "c++: Delete Method in QmlController";
    if (m_id < 0 && m_id > m_tableSize)
        return;

    pController = new PController();
    pController->deleteProduct(m_id);

    emit deleteProductContoller(m_id);
}

QString QmlController::name()
{
    return m_name;
}

void QmlController::setName(const QString &name)
{
    if (m_name == name)
        return;

    m_name = name;
    qDebug() << "Name: " << m_name;
    emit nameChanged(name);
}

QString QmlController::description()
{
    return m_description;
}

void QmlController::setDescription(const QString &description)
{
    if (m_description == description)
        return;

    m_description = description;
    emit descriptionChanged(description);
}

int QmlController::qteStock()
{
    return m_qteStock;
}

void QmlController::setQteStock(int &qteStock)
{
    if (m_qteStock == qteStock)
        return;

    m_qteStock = qteStock;
    emit qteStockChanged(qteStock);
}

int QmlController::id()
{
    return m_id;
}

void QmlController::setId(int &id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(id);
}
