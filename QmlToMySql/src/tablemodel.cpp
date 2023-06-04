#include "tablemodel.h"

TableModel::TableModel()
{
    pController = new PController();
}

TableModel::~TableModel()
{
    // delete pController;
}

int TableModel::rowCount(const QModelIndex &) const
{
    return pController->getProductTableSize();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QString TableModel::onDataReady(QVariant data) const
{
    // Process the data here
    return "";
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    QVariant data = onDataReady(pController->getData());
    QVariantList dataList;
    QVariantList rowList;

    switch (role)
    {
    case Qt::DisplayRole:
        // return pController->getData()[index.column()][index.row()].toString();
        dataList = data.toList();
        for (int i = 0; i < dataList.size(); ++i)
        {
            rowList = dataList[i].toList();
            for (int j = 0; j < rowList.size(); ++j)
            {
                qDebug() << "c++: " << j << " : " << rowList[j].toString();
                return rowList[j].toString();
            }
        }
        // return QString("%1, %2").arg(index.column()).arg(index.row());
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}
