#include "../inc/RaportWindow.hpp"

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <algorithm>

RaportWindow::RaportWindow(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout(this);

    setLayout(mainLayout);
    resize(800, 600);
}

void RaportWindow::addChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title) {
    if (dates.isEmpty() || values.isEmpty()) return;

    auto series = new QtCharts::QLineSeries();
    for (int i = 0; i < dates.size(); ++i) {
        QDateTime dt(dates[i]);
        series->append(dt.toMSecsSinceEpoch(), values[i]);
    }

    auto chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(title);  // <-- tutaj ustawiamy tytuł
    chart->legend()->hide();

    auto axisX = new QtCharts::QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Data");
    axisX->setMin(QDateTime(dates.first()));
    axisX->setMax(QDateTime(dates.last()));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Kwota");
    double minVal = *std::min_element(values.constBegin(), values.constEnd());
    double maxVal = *std::max_element(values.constBegin(), values.constEnd());
    axisY->setRange(minVal, maxVal);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    auto chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartViews.append(chartView);
    mainLayout->addWidget(chartView);
}
void RaportWindow::addStepChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title) {
    if (dates.isEmpty() || values.isEmpty()) return;

    auto series = new QtCharts::QLineSeries();
    for (int i = 0; i < dates.size(); ++i) {
        QDateTime currentDateTime(dates[i]);
        qint64 x = currentDateTime.toMSecsSinceEpoch();

        if (i > 0) {
            QDateTime prevDateTime(dates[i]);
            qint64 prevX = prevDateTime.toMSecsSinceEpoch();
            series->append(prevX, values[i - 1]);
        }

        series->append(x, values[i]);
    }

    auto chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(title); 
    chart->legend()->hide();

    auto axisX = new QtCharts::QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Data");
    axisX->setMin(QDateTime(dates.first()));
    axisX->setMax(QDateTime(dates.last()));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Kwota");
    double minVal = *std::min_element(values.constBegin(), values.constEnd());
    double maxVal = *std::max_element(values.constBegin(), values.constEnd());
    axisY->setRange(minVal, maxVal);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    auto chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartViews.append(chartView);
    mainLayout->addWidget(chartView);
}
