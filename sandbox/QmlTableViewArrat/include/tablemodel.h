#include <QObject>
#include <qqml.h>
#include <QAbstractTableModel>

#include "connection.h"
#include "product.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    TableModel();
    ~TableModel();

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    void getData();
    QVector<QVector<QVariant>> onDataReady() const;
    Product onDataDisplay(int row) const;

    QVariant data(const QModelIndex &index, int role) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Product> pList;
    mutable bool m_head = true;
};