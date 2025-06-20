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
#include "Tab_Kategorie.hpp"
#include "Tab_DaneUzytkownika.hpp"
#include "Tab_CykliczneP.hpp"
#include "Tab_CykliczneW.hpp"
#include "Tab_Raporty.hpp"
#include "Tab_Dzieci.hpp"
#include "Tab_Relacje.hpp"
#include "Tab_Budzet.hpp"

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

    void setTablesByNewUser();

    void setTabsVisibility();
    void displayUserData(const QString &email);

    void goToStartPage();

signals:
    void logoutRequested();

private:
    Ui::User_Panel *ui = nullptr;
    QString userEmail;  //email zalogowanego użytkownika

    DatabaseManager* m_dbManager = nullptr;

    Tab_Wydatki *wydatkiManager = nullptr;
    Tab_Przychody *przychodyManager = nullptr;
    Tab_Uzytkownicy *uzytkownicyManager = nullptr;
    Tab_Kategorie *kategorieManager = nullptr;
    Tab_DaneUzytkownika *daneUzytkownikaManager = nullptr;
    Tab_CykliczneP *cyklicznePManager = nullptr;
    Tab_CykliczneW *cykliczneWManager = nullptr;
    Tab_Raporty *raportyManager = nullptr;
    Tab_Dzieci *dzieciManager = nullptr;
    Tab_Relacje *relacjeManager = nullptr;
    Tab_Budzet *budzetManager = nullptr;
};

#endif // USER_PANEL_H
