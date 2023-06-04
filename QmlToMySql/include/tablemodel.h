#include <QObject>
#include <qqml.h>
#include <QAbstractTableModel>

#include "pcontroller.h"

class TableModel : public QAbstractTableModel
{
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    TableModel();
    ~TableModel();

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QString onDataReady(QVariant data) const;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    PController *pController;
};