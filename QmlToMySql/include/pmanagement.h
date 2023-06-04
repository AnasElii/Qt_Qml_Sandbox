
#ifndef MPRODUCT_H
#define MPRODUCT_H

#include <QObject>

#include "product.h"
#include "connection.h"

class PManagement
{

public:
    PManagement();
    ~PManagement();

    int getTableSize();
    int getLastIndex();
    void AddProduct(Product &product);
    void UpdateProduct(int &id, Product &product);
    void DeleteProduct(int &id);
    QVariant getData();
};

#endif // MPRODUCT_H
