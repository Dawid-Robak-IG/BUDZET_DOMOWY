#include "../inc/RaportWindow.hpp"

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <algorithm>

RaportWindow::RaportWindow(QWidget *parent) : QMainWindow(parent) {
    r_centralWidget = new QWidget(this);         
    mainLayout = new QVBoxLayout(r_centralWidget);        

    setCentralWidget(r_centralWidget);                

    fileMenu = menuBar()->addMenu("Plik");
    savePdfAction = new QAction("Zapisz do PDF", this);
    fileMenu->addAction(savePdfAction);
    connect(savePdfAction, &QAction::triggered, this, &RaportWindow::onSaveToPdfClicked);

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
void RaportWindow::addBarChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title) {
    if (dates.isEmpty() || values.isEmpty() || dates.size() != values.size())
        return;

    QStringList categories;
    for (const QDate& date : dates) {
        categories << date.toString("dd.MM.yyyy");
    }

    auto *set = new QtCharts::QBarSet(title);
    for (double val : values) {
        *set << val;
    }

    auto *series = new QtCharts::QBarSeries();
    series->append(set);

    auto *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->legend()->setVisible(false);

    auto *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto *axisY = new QtCharts::QValueAxis();
    axisY->setTitleText("Kwota");
    double minVal = *std::min_element(values.constBegin(), values.constEnd());
    double maxVal = *std::max_element(values.constBegin(), values.constEnd());
    axisY->setRange(std::min(0.0, minVal), maxVal * 1.1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    auto *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartViews.append(chartView);
    mainLayout->addWidget(chartView);
}
void RaportWindow::saveToPDF(const QString& filePath) {
    if (filePath.isEmpty()){
        qDebug() << "RaportWindow: filePath jest pusty";
        return;
    }

    qDebug() << "RaportWindow: Rozpoczęto procedurę zapisu";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(10, 10, 10, 10), QPageLayout::Millimeter);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QPainter painter(&printer);

    if (!painter.isActive()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się rozpocząć rysowania na PDF.");
        return;
    }

    QWidget *widget = centralWidget();
    if (!widget) {
        QMessageBox::warning(this, "Błąd", "Brak centralnego widżetu.");
        return;
    }

    QSize widgetSize = widget->size();
    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    double scaleX = pageRect.width() / static_cast<double>(widgetSize.width());
    double scaleY = pageRect.height() / static_cast<double>(widgetSize.height());
    double scale = qMin(scaleX, scaleY);

    painter.scale(scale, scale);
    widget->render(&painter);

    painter.end();

    QMessageBox::information(this, "Zapisano", "Raport zapisany do PDF.");
    qDebug() << "RaportWindow: Zakończono procedurę zapisu";
}


void RaportWindow::onSaveToPdfClicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz raport jako PDF", "", "*.pdf");
    if (!fileName.isEmpty()) {
        if (!fileName.endsWith(".pdf"))
            fileName += ".pdf";
        saveToPDF(fileName);
    }
}
