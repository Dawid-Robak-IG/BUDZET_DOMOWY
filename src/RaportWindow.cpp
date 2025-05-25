#include "../inc/RaportWindow.hpp"

RaportWindow::RaportWindow(QWidget *parent) : QWidget(parent) {
    chartView = new QtCharts::QChartView(this);
    auto layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
    resize(600, 400);
}

void RaportWindow::setData(const QVector<QDate>& dates, const QVector<double>& values) {
    auto series = new QtCharts::QLineSeries();

    // Dodaj punkty do serii: X to timestamp w ms, Y to wartość
    for (int i = 0; i < dates.size(); ++i) {
        QDateTime dt(dates[i]);
        series->append(dt.toMSecsSinceEpoch(), values[i]);
    }

    auto chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->legend()->hide();

    // Oś X: QDateTimeAxis
    auto axisX = new QtCharts::QDateTimeAxis();
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Data");
    axisX->setMin(QDateTime(dates.first()));
    axisX->setMax(QDateTime(dates.last()));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Oś Y: QValueAxis
    auto axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Kwota");
    // Opcjonalnie ustaw zakres osi Y na podstawie wartości:
    double minVal = *std::min_element(values.constBegin(), values.constEnd());
    double maxVal = *std::max_element(values.constBegin(), values.constEnd());
    axisY->setRange(minVal, maxVal);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}