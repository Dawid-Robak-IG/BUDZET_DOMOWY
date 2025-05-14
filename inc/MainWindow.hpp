#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QStackedWidget>
#include "LogReg.hpp"  
#include "src/user_panel.hpp"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
      void handleLogin(QString email);
       void handleLogout();

private:
    QStackedWidget *stackedWidget; 
    LogReg *logRegScreen; 
    User_Panel *userPanel=nullptr;


    enum WidgetIndex {
        LogRegIndex,
        UserPanelIndex
    };


};


#endif // MAINWINDOW_HPP
