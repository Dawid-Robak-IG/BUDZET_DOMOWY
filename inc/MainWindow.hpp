#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP


#include <QMainWindow>
#include <QStackedWidget>
#include "Start_Log_Reg.hpp"
#include "User_Panel.hpp"
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
    QStackedWidget *stackedWidget = nullptr;
    Start_Log_Reg *logRegScreen = nullptr;
    User_Panel *m_userPanel = nullptr;

    DatabaseManager *m_dbManager = nullptr;

    enum WidgetIndex { LogRegIndex, UserPanelIndex };
};


#endif // MAINWINDOW_HPP
