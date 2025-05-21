#ifndef USER_PANEL_HPP
#define USER_PANEL_HPP

#include <QWidget>
#include "ui_user_panel.h"
#include "DatabaseManager.hpp"
#include "IncomeForm.hpp"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

//zarządcy do zakładek i ich elementów
#include "Tab_Wydatki.hpp"
#include "Tab_Uzytkownicy.hpp"

namespace Ui {
class User_Panel;
}

class User_Panel : public QWidget
{
    Q_OBJECT

public:
    explicit User_Panel(QString email = "", QWidget *parent = nullptr);
    ~User_Panel();

    void setDatabaseManager(DatabaseManager* dbManager);
    DatabaseManager* getDatabaseManager() const { return m_dbManager; }

    void setUserEmail(const QString& email);
    void loadUserRole();

    void loadIncomeCategories();

signals:
    void logoutRequested();

public slots:
    void addNewIncomeCategory();

private:
    Ui::User_Panel *ui;
    DatabaseManager* m_dbManager = nullptr;

    Tab_Wydatki *wydatkiManager;
    Tab_Uzytkownicy *uzytkownicyManager;

    QString userEmail;  //email zalogowanego użytkownika


    void displayUserData(const QString &email);
};

#endif // USER_PANEL_HPP
