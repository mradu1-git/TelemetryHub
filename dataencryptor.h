#ifndef DATAENCRYPTOR_H
#define DATAENCRYPTOR_H

#include <QObject>
#include <QString>
#include <QtQml>

class DataEncryptor : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit DataEncryptor(QObject *parent = nullptr);
    Q_INVOKABLE QString encryptData(const QString &rawData);
};

#endif // DATAENCRYPTOR_H
