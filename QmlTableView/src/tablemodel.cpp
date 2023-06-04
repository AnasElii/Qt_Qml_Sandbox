#include "tablemodel.h"

TableModel::TableModel()
{
}

TableModel::~TableModel()
{
    // delete pController;
}

int TableModel::rowCount(const QModelIndex &) const
{
    return 4;
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 4;
}

QString TableModel::onDataReady(QVariant data) const
{
    // Process the data here
    return "";
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

    switch (role)
    {
    case Qt::DisplayRole:
        return QString("%1, %2").arg(index.column()).arg(index.row());
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}
