#ifndef TELEMETRYLOGMODEL_H
#define TELEMETRYLOGMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <QList>
#include <QDateTime>

struct LogEntry {
    QString timestamp;
    QString message;
    QString level;
};

class TelemetryLogModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum LogRoles {
        TimestampRole = Qt::UserRole + 1,
        MessageRole,
        LevelRole
    };

    explicit TelemetryLogModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    void appendLog(const QString &message, const QString &level);
private:
    QList<LogEntry> m_logs;
};

#endif // TELEMETRYLOGMODEL_H
