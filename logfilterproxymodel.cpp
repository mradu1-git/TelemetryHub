#include "logfilterproxymodel.h"

LogFilterProxyModel::LogFilterProxyModel(QObject *parent) : QSortFilterProxyModel(parent) {
    m_sourceModel = new TelemetryLogModel(this);
    setSourceModel(m_sourceModel);
    setFilterCaseSensitivity(Qt::CaseInsensitive);

    m_sourceModel->appendLog("Kernel initialization successful", "INFO");
    m_sourceModel->appendLog("Main window UI instantiated", "INFO");
    m_sourceModel->appendLog("High memory consumption overhead warning", "WARN");
    m_sourceModel->appendLog("Database network connection lost", "ERROR");
}

void LogFilterProxyModel::generateFakeLog(const QString &msg, const QString &level) {
    m_sourceModel->appendLog(msg, level);
}

void LogFilterProxyModel::setFilterText(const QString text) {
    setFilterRole(TelemetryLogModel::MessageRole);
    setFilterFixedString(text);
}
void LogFilterProxyModel::setFilterLevel(const QString &level) {
    setFilterRole(TelemetryLogModel::LevelRole);
    if (level == "ALL") {
        setFilterFixedString("");
    } else {
        setFilterFixedString(level);
    }
}