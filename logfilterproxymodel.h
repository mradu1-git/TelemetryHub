#ifndef LOGFILTERPROXYMODEL_H
#define LOGFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QtQml>
#include "telemetrylogmodel.h"

class LogFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit LogFilterProxyModel(QObject *parent = nullptr);
    Q_INVOKABLE void generateFakeLog(const QString &msg, const QString &level);
    Q_INVOKABLE void setFilterText(const QString &text);
    Q_INVOKABLE void setFilterLevel(const QString &level);
private:
    TelemetryLogModel *m_sourceModel;
};

#endif // LOGFILTERPROXYMODEL_H
