
#ifndef PCONTROLLER_H
#define PCONTROLLER_H

#include <QObject>

#include "product.h"
#include "pmanagement.h"

class PController : public QObject
{
    Q_OBJECT
public:
    explicit PController(QObject *parent = nullptr);
    ~PController();

    int getProductLastRecord();
    int getProductTableSize();
    void newProduct(const QString &name, const QString &description, int &qteStock);
    void updateProduct(int &id, const QString &name, const QString &description, int &qteStock);
    void deleteProduct(int &id);
    QVariant getData();

signals:

private:
    Product *product;
    PManagement *pManagement;
};

#endif // PCONTROLLER_H
