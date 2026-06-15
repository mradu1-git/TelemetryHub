#ifndef STATUSPIECHART_H
#define STATUSPIECHART_H

#include <QQuickPaintedItem>
#include <QColor>
#include <QtQml>

class StatusPieChart : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int fillAngle READ fillAngle WRITE setFillAngle NOTIFY fillAngleChanged)

    QML_ELEMENT
public:
    StatusPieChart(QQuickItem *parent = nullptr) ;
    void paint(QPainter *painter) override;
    QColor color() const;
    void setColor(const QColor &newColor);

    int fillAngle() const;
    void setFillAngle(int newAngle);

    StatusPieChart();
signals:
    void colorChanged();
    void fillAngleChanged();
private:
    QColor m_color;
    int m_fillAngle;
};

#endif // STATUSPIECHART_H
