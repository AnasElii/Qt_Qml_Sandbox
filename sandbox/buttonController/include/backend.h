
#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include <QObject>
#include <QDebug>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

signals:
    void nameChanged(const QString &name);

private:
    QString m_name;
};

#endif // BUTTONCONTROLLER_H
