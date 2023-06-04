
#ifndef QMLCONTOLLER_H
#define QMLCONTOLLER_H

#include <QObject>

#include "pcontroller.h"

class QmlController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(int qteStock READ qteStock WRITE setQteStock NOTIFY qteStockChanged)

public:
    QmlController(QObject *parent = nullptr);
    ~QmlController();

    Q_INVOKABLE void AddProduct();
    Q_INVOKABLE void UpdateProduct();
    Q_INVOKABLE void DeleteProduct();

    int id();
    void setId(int &id);

    QString name();
    void setName(const QString &name);

    QString description();
    void setDescription(const QString &description);

    int qteStock();
    void setQteStock(int &qteStock);

signals:
    void idChanged(int &id);
    void nameChanged(const QString &name);
    void descriptionChanged(const QString &description);
    void qteStockChanged(int &qteStock);
    void newProductContoller(const QString &nome, const QString &description, const int &qteStock);
    void updateProductContoller(int &id, const QString &nome, const QString &description, const int &qteStock);
    void deleteProductContoller(int &id);

private:
    int m_id;
    QString m_name;
    QString m_description;
    int m_qteStock;
    int m_tableSize;
    PController *pController;
};

#endif // QMLCONTOLLER_H
