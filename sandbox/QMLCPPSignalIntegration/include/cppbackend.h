#ifndef CPPBACKEND_H
#define CPPBACKEND_H

#include <QObject>

class CPPBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)
    // Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit CPPBackend(QObject *parent = nullptr);

    // Q_INVOKABLE void receiveFromQml();

    int counter() const;
    void setCounter(int counter);

    // QString name() const;
    // void setName(const QString &name);

signals:
    void counterChanged(int counter);
    // void sendToQml(int);
    // void nameChanged(const QString &name);

private:
    int m_counter = 0;
    // QString m_name = "";
};

#endif // CPPBACKEND_H
