#include "customclass.h"

CustomClass::CustomClass(QObject *parent)
    : QObject{parent}
{
}

CustomClass::~CustomClass()
{
    qDebug() << objectName() << " Deleted!";
}
