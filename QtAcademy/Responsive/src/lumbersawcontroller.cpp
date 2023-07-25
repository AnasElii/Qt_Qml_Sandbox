#include "lumbersawcontroller.h"

LumberSawController::LumberSawController(QObject *parent)
    : QObject{parent}
{
}

bool LumberSawController::isWorking() const
{
    return m_isWorking;
}

double LumberSawController::sawSpeed() const
{
    return m_sawSpeed;
}

void LumberSawController::setIsWorking(bool isWorking)
{
    if (m_isWorking == isWorking)
        return;

    m_isWorking = isWorking;
    emit isWorkingChanged();
}

void LumberSawController::setSawSpeed(double sawSpeed)
{
    if (m_sawSpeed == sawSpeed)
        return;

    m_sawSpeed = sawSpeed;
    emit sawSpeedChanged();
}

void LumberSawController::start()
{
    setIsWorking(true);
}

void LumberSawController::stop()
{
    setIsWorking(false);
}
