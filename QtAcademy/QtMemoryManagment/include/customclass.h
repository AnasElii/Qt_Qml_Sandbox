#ifndef CUSTOMCLASS_H
#define CUSTOMCLASS_H

#include <QObject>
#include <QDebug>

class CustomClass : public QObject
{
    Q_OBJECT
public:
    explicit CustomClass(QObject *parent = nullptr);
    ~CustomClass();

signals:
};

#endif // CUSTOMCLASS_H
