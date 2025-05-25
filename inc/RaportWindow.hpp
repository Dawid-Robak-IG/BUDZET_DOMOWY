#pragma once
#include <QWidget>
#include <QtCharts>
#include <QDate>
#include <QDateTime>

class RaportWindow : public QWidget {
    Q_OBJECT
public:
    RaportWindow(QWidget *parent = nullptr);

    void setData(const QVector<QDate>& dates, const QVector<double>& values);

private:
    QtCharts::QChartView* chartView;
};
