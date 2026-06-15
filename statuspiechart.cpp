#include "statuspiechart.h"
#include <QPainter>

StatusPieChart::StatusPieChart(QQuickItem *parent) : QQuickPaintedItem(parent), m_color(Qt::green), m_fillAngle(90.0) {}

void StatusPieChart::paint(QPainter *painter) {
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(QBrush(m_color));
    painter->setPen(Qt::NoPen);

    QRectF rect(0, 0, width(), height());

    int startAngle = 1440;
    int spanAngle = static_cast<int>(-m_fillAngle * 16);
    painter->drawPie(rect, startAngle, spanAngle);
}

QColor StatusPieChart::color() const {
    return m_color;
}

void StatusPieChart::setColor(const QColor &newColor) {
    if (m_color == newColor) return;
    m_color = newColor;
    emit colorChanged();
    update();
}

int StatusPieChart::fillAngle() const {
    return m_fillAngle;
}

void StatusPieChart::setFillAngle(int newAngle) {
    if (m_fillAngle == newAngle) return;
    m_fillAngle = newAngle;
    emit fillAngleChanged();
    update();
}