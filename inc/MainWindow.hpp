#include <QMainWindow>
#include <QStackedWidget>
#include "LogReg.hpp"  

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stackedWidget; 
    LogReg *logRegScreen; 
};