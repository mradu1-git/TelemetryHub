#include "DataEncryptor.h"
#include <QDebug>

DataEncryptor::DataEncryptor(QObject *parent) : QObject(parent)
{
    // Non-visual elements handle data, networks, or encryption algorithms
}

QString DataEncryptor::encryptData(const QString &rawData)
{
    qDebug() << "C++ Encryptor received raw string:" << rawData;

    // A simple Caesar Cipher simulation for demonstration
    QString encrypted = rawData;
    for (int i = 0; i < encrypted.length(); ++i) {
        encrypted[i] = QChar(encrypted[i].unicode() + 1);
    }

    qDebug() << "C++ Encryptor returning processed string:" << encrypted;
    return encrypted;
}