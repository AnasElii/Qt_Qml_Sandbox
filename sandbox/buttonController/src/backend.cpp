#include "backend.h"

Backend::Backend(QObject *parent) : QObject{parent}
{
}

QString Backend::name() const
{
    return m_name;
}

void Backend::setName(const QString &name)
{
    if (m_name == name)
        return;

    qDebug() << "cpp: " << name;
    m_name = name;
    emit nameChanged(m_name);
}
