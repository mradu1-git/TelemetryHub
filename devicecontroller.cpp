#include "devicecontroller.h"
#include <QDebug>

DeviceController::DeviceController(QObject* parent) : QObject(parent),
    m_temperature(0.0), m_connectionStatus("Disconnected")
{
    qDebug() << "Device Controller successfully initialized in C++!";
}

double DeviceController::temperature() const {
    return m_temperature;
}

QString DeviceController::connectionStatus() const {
    return m_connectionStatus;
}
void DeviceController::setTemperature(double newTemperature) {
    if (qFuzzyCompare(m_temperature, newTemperature)) return;
    m_temperature = newTemperature;
    emit temperatureChanged();
    qDebug() << "C++ Engine: Temperature updated to" << m_temperature;
}

void DeviceController::setConnectionStatus(const QString &newStatus)
{
    // Performance Guard Clause: String comparison check to avoid unnecessary redraw overhead
    if (m_connectionStatus == newStatus)
        return;

    m_connectionStatus = newStatus;

    // Notify the QML layer that the connection status string is different now
    emit connectionStatusChanged();
}
void DeviceController::resetDevice()
{
    qDebug() << "C++ Engine: Resetting device metrics to defaults...";

    // We update our values using our own setters.
    // This ensures guard checks run and signals fire naturally.
    setTemperature(25.0);
    setConnectionStatus("Connected & Initialized");
}