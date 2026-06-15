#include "telemetrylogmodel.h"

TelemetryLogModel::TelemetryLogModel(QObject *parent) : QAbstractListModel(parent) {}

int TelemetryLogModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_logs.count();
}

QVariant TelemetryLogModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_logs.count()) return QVariant();

    const LogEntry &entry = m_logs[index.row()];
    switch(role) {
    case TimestampRole: return entry.timestamp;
    case MessageRole: return entry.message;
    case LevelRole: return entry.level;
    default: return QVariant();
    }
}

QHash<int, QByteArray> TelemetryLogModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TimestampRole] = "timestamp";
    roles[MessageRole] = "message";
    roles[LevelRole] = "level";
    return roles;
}

void TelemetryLogModel::appendLog(const QString &message, const QString &level) {
    beginInsertRows(QModelIndex(), m_logs.count(), m_logs.count());

    LogEntry entry;
    entry.timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    entry.message = message;
    entry.level = level;
    m_logs.append(entry);
    endInsertRows();
}