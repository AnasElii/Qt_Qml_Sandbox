#ifndef LUMBERSAWCONTOLLER_H
#define LUMBERSAWCONTOLLER_H

#include <QObject>
#include <QQmlEngine>
#include <QTimer>

class LumberSawController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(double sawSpeed READ sawSpeed WRITE setSawSpeed NOTIFY sawSpeedChanged)
    QML_ELEMENT

public:
    explicit LumberSawController(QObject *parent = nullptr);

    enum Status
    {
        IdelStatus = 0,
        WorkingStatus,
        ErrorStatus
    };
    Q_ENUM(Status)

    double sawSpeed() const;
    void setSawSpeed(double sawSpeed);

    Status status() const;

public slots:
    void start();
    void stop();

signals:
    void sawSpeedChanged();
    void statusChanged();

private:
    void setStatus(Status status);

private slots:
    void onTimerTimeout();

private:
    double m_sawSpeed = 1;
    Status m_status = Status::IdelStatus;
    QTimer m_timer;
};

#endif // LUMBERSAWCONTOLLER_H
