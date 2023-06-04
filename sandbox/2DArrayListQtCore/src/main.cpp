#include <QObject>
#include <QCoreApplication>
#include <QVariant>
#include <QDebug>
#include <QException>

using namespace std;

void printVariantList(QList<QList<QVariant>> &variantList)
{
    int fieldWidth = 8;
    QChar padChar = ' ';

    qDebug() << "Medal" << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
    for (int column = 0; column < variantList[0].size(); ++column)
    {
        qDebug() << "C" << column + 1 << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
    }

    qDebug() << "----------------------------";

    for (int row = 0; row < variantList.size(); ++row)
    {
        qDebug() << "Row" << row + 1 << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
        auto &rowMatrix = variantList[row];
        for (int column = 0; column < variantList[0].size(); ++column)
        {
            qDebug() << rowMatrix[column] << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
        }
        qDebug();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QVector<QVector<QVariant>> variantList;
    // variantList.resize(3, vector<int>(3, 0));
    QVariant name("Anas");
    QVariant age(27);
    QVariant isMan(true);

    // for (int row = 0; row < 3; row++)
    // {
    QVector<QVariant> rowVector;
    rowVector.push_back("Anas");
    rowVector.push_back(27);
    rowVector.push_back(true);
    variantList.push_back(rowVector);

    QVector<QVariant> rowVector2;
    rowVector2.push_back("Mouad");
    rowVector2.push_back(30);
    rowVector2.push_back(true);
    variantList.push_back(rowVector2);

    QVector<QVariant> rowVector3;
    rowVector3.push_back("Ikram");
    rowVector3.push_back(24);
    rowVector3.push_back(false);
    variantList.push_back(rowVector3);

    qDebug() << variantList;

    {
        int fieldWidth = 8;
        QChar padChar = ' ';

        qDebug().noquote() << "Medal" << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
        for (int column = 0; column < variantList[0].size(); ++column)
        {
            qDebug().noquote() << "C" << column + 1 << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
        }

        qDebug() << "----------------------------";

        for (int row = 0; row < variantList.size(); ++row)
        {
            qDebug().noquote() << "Row" << row + 1 << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
            auto &rowMatrix = variantList[row];
            for (int column = 0; column < variantList[0].size(); ++column)
            {
                if (rowMatrix[column].canConvert<QString>())
                    qDebug().noquote() << rowMatrix[column].toString() << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
                else if (rowMatrix[column].canConvert<int>())
                    qDebug().noquote() << rowMatrix[column].toInt() << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
                else if (rowMatrix[column].canConvert<bool>())
                    qDebug().noquote() << rowMatrix[column].toBool() << qSetFieldWidth(fieldWidth) << qSetPadChar(padChar);
            }
            qDebug();
        }
    }

    // {
    //     qDebug().nospace() << "Medal\t";
    //     for (int column = 0; column < variantList[0].size(); ++column)
    //     {
    //         qDebug().nospace() << "C" << column + 1 << "\t";
    //     }

    //     qDebug() << "----------------------------";

    //     for (int row = 0; row < variantList.size(); ++row)
    //     {
    //         qDebug().nospace() << "Row" << row + 1 << " ";
    //         auto &rowMatrix = variantList[row];
    //         qDebug().nospace() << '\t';
    //         for (int column = 0; column < variantList[0].size(); ++column)
    //         {
    //             qDebug().nospace() << rowMatrix[column] << '\t';
    //         }
    //         qDebug();
    //     }
    // }

    qDebug()
        << "Display Data: ";

    return app.exec();
}