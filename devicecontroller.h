#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include <QString>
#include <QtQml>
#include <QQmlEngine>

class DeviceController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(QString connectionStatus READ connectionStatus WRITE setConnectionStatus NOTIFY connectionStatusChanged)
    QML_ELEMENT
public:
    explicit DeviceController(QObject *parent = nullptr);
    double temperature() const;
    QString connectionStatus() const;

    void setTemperature(double newTemperature);
    void setConnectionStatus(const QString &newStatus);

    Q_INVOKABLE void resetDevice();
signals:
    void temperatureChanged();
    void connectionStatusChanged();

private:
    double m_temperature;
    QString m_connectionStatus;

};

#endif // DEVICECONTROLLER_H
