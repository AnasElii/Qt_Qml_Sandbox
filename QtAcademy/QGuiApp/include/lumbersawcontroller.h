#ifndef LUMBERSAWCONTROLLER_H
#define LUMBERSAWCONTROLLER_H

#include <QObject>
#include <qqml.h>

class LumberSawController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWorking READ isWorking NOTIFY isWorkingChanged)
    Q_PROPERTY(int sawSpeed READ sawSpeed WRITE setSawSpeed NOTIFY sawSpeedChanged)
    QML_ELEMENT

public:
    explicit LumberSawController(QObject *parent = nullptr);

    bool isWorking() const;

    int sawSpeed() const;
    void setSawSpeed(int newSawSpeed);

public slots:
    void start();
    void stop();

signals:
    void isWorkingChanged();

    void sawSpeedChanged();

private:
    void setIsWorking(bool newIsWorking);

private:
    bool m_isWorking;
    int m_sawSpeed = 1;
};

#endif // LUMBERSAWCONTROLLER_H
