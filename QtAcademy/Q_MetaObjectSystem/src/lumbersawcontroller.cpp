#include "lumbersawcontroller.h"

LumberSawController::LumberSawController(QObject *parent)
    : QObject{parent}
{
    m_timer.setInterval(1000);
    connect(&m_timer, &QTimer::timeout, this, &LumberSawController::onTimerTimeout);
}

double LumberSawController::sawSpeed() const
{
    return m_sawSpeed;
}

void LumberSawController::start()
{
    setStatus(Status::WorkingStatus);

    m_timer.start();
}

void LumberSawController::stop()
{
    setStatus(Status::IdelStatus);

    m_timer.stop();
}

void LumberSawController::setStatus(Status status)
{
    if (m_status == status)
        return;

    m_status = status;
    emit statusChanged();
}

void LumberSawController::setSawSpeed(double sawSpeed)
{
    if (m_sawSpeed == sawSpeed)
        return;

    m_sawSpeed = sawSpeed;
    emit sawSpeedChanged();
}

LumberSawController::Status LumberSawController::status() const
{
    return m_status;
}

void LumberSawController::onTimerTimeout()
{
    qDebug() << "Error occured";
    setStatus(Status::ErrorStatus);

    m_timer.stop();
}