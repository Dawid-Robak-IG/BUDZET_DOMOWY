#ifndef RAPORTWINDOW_HPP
#define RAPORTWINDOW_HPP

#include <QWidget>
#include <QVector>
#include <QDate>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtCharts/QChartView>

class RaportWindow : public QWidget {
    Q_OBJECT

public:
    explicit RaportWindow(QWidget *parent = nullptr);
    void addChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title);
    void addStepChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title);

private:
    QVBoxLayout* mainLayout;
    QVector<QtCharts::QChartView*> chartViews;
};

#endif // RAPORTWINDOW_HPP
