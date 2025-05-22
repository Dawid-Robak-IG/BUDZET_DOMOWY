#ifndef USER_PANEL_H
#define USER_PANEL_H

#include <QWidget>
#include "ui_User_Panel.h"
#include "DatabaseManager.hpp"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

//zarządcy do zakładek i ich elementów
#include "Tab_Wydatki.hpp"
#include "Tab_Uzytkownicy.hpp"
#include "Tab_Przychody.hpp"

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
    QString userEmail;  //email zalogowanego użytkownika

    DatabaseManager* m_dbManager = nullptr;

    Tab_Wydatki *wydatkiManager;
    Tab_Przychody *przychodyManager;
    Tab_Uzytkownicy *uzytkownicyManager;

    void displayUserData(const QString &email);
};

#endif // USER_PANEL_H
