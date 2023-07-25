#ifndef LUMBERSAWCONTOLLER_H
#define LUMBERSAWCONTOLLER_H

#include <QObject>
#include <QQmlEngine>

class LumberSawController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWorking READ isWorking NOTIFY isWorkingChanged)
    Q_PROPERTY(double sawSpeed READ sawSpeed WRITE setSawSpeed NOTIFY sawSpeedChanged)
    QML_ELEMENT
public:
    explicit LumberSawController(QObject *parent = nullptr);

    bool isWorking() const;
    double sawSpeed() const;
    void setSawSpeed(double sawSpeed);

signals:
    void isWorkingChanged();
    void sawSpeedChanged();

public slots:
    void start();
    void stop();

private:
    void setIsWorking(bool isWorking);

private:
    bool m_isWorking = false;
    double m_sawSpeed = 1;
};

#endif // LUMBERSAWCONTOLLER_H
