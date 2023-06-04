#include "tablemodel.h"

TableModel::TableModel()
{
    qDebug() << "Fill Data";
    getData();
}

TableModel::~TableModel()
{
    // delete pController;
}

int TableModel::rowCount(const QModelIndex &) const
{
    return pList.size();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 4;
}

void TableModel::getData()
{

    {
        Connection *connection = new Connection();
        Connection::ConnectionOpen();
        QSqlQuery query = Connection::SelectQuery("SELECT * FROM produit");
        pList = connection->getData(query);
    }
}

QVector<QVector<QVariant>> TableModel::onDataReady() const
{
    // Process the data here
    QVector<QVector<QVariant>> dataList;

    QVariant id(0);
    QVariant name("Anas");
    QVariant age(27);
    QVariant isMan(true);

    // ====================
    QVector<QVariant> vList;
    vList.push_back(id);
    vList.push_back(name);
    vList.push_back(age);
    vList.push_back(isMan);
    dataList.push_back(vList);

    // ====================
    QVector<QVariant> vList2;
    vList2.push_back(QVariant(id.toInt() + 1));
    vList2.push_back(name);
    vList2.push_back(age);
    vList2.push_back(isMan);
    dataList.push_back(vList2);

    // ====================
    QVector<QVariant> vList3;
    vList3.push_back(QVariant(id.toInt() + 2));
    vList3.push_back(name);
    vList3.push_back(age);
    vList3.push_back(isMan);
    dataList.push_back(vList3);

    return dataList;
}

Product TableModel::onDataDisplay(int row) const
{
    const auto &p = pList[row];
    return p;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch (role)
    {
    case Qt::DisplayRole:
    {
        if (m_head)
        {
            if (index.column() == 0)
                return "ID";
            if (index.column() == 1)
                return "Nome";
            if (index.column() == 2)
                return "Description";
            if (index.column() == 3)
            {
                m_head = false;
                qDebug() << "Bool: " << m_head;
                return "qteStock";
            }
        }
        Product item = onDataDisplay(index.row());

        if (index.column() == 0)
            return item.getId();
        if (index.column() == 1)
            return item.getName();
        if (index.column() == 2)
            return item.getDescription();
        if (index.column() == 3)
            return item.getQteStrock();
    }
    default:
        break;
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return tr("ID");
        case 1:
            return tr("Name");
        case 2:
            return tr("Description");
        case 3:
            return tr("Quantity in Stock");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    return {{Qt::DisplayRole, "display"}};
}
