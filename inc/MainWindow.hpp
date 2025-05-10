#include <QMainWindow>
#include <QStackedWidget>
#include "LogReg.hpp"  
#include "MainMenu.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stackedWidget; 
    LogReg *logRegScreen; 
    MainMenu *mainMenu;
};