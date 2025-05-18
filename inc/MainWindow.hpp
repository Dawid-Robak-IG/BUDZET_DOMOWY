#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QStackedWidget>
//#include "LogReg.hpp"
#include "StartLogReg.hpp"
#include "src/user_panel.hpp"
#include "DatabaseManager.hpp"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     DatabaseManager* getDatabaseManager() const { return m_dbManager; }

private slots:
       void handleLogin(QString email);
       void handleLogout();

private:
    QStackedWidget *stackedWidget; 
    Start_Log_Reg *logRegScreen;
    User_Panel *m_userPanel;

    DatabaseManager* m_dbManager;


    enum WidgetIndex {
        LogRegIndex,
        UserPanelIndex
    };


};


#endif // MAINWINDOW_HPP
