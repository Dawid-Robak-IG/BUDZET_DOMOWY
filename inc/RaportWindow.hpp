#ifndef RAPORTWINDOW_HPP
#define RAPORTWINDOW_HPP

#include <QWidget>
#include <QVector>
#include <QDate>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtCharts>
#include <QPrinter>
#include <QMenu>
#include <QAction>

class RaportWindow : public QMainWindow {
    Q_OBJECT

    QWidget *r_centralWidget;    
    QMenu* fileMenu;
    QAction* savePdfAction;
    QAction* savePngAction;

public:
    explicit RaportWindow(QWidget *parent = nullptr);
    void addChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title);
    void addStepChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title);
    void addBarChart(const QVector<QDate>& dates, const QVector<double>& values, const QString& title);

    void saveToPDF(const QString& filePath);
    void saveToPNG(const QString& filePath);
    
public slots:
    void onSaveToPngClicked();
    void onSaveToPdfClicked();
private:
    QVBoxLayout *mainLayout = nullptr;
    QVector<QtCharts::QChartView *> chartViews;
};

#endif // RAPORTWINDOW_HPP
