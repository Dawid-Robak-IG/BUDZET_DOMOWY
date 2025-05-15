#ifndef USER_PANEL_HPP
#define USER_PANEL_HPP

#include <QWidget>
#include "ui_user_panel.h"
#include "IncomeForm.hpp"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class User_Panel;
}

class User_Panel : public QWidget
{
    Q_OBJECT

public:
    explicit User_Panel(QString email = "", QWidget *parent = nullptr);
    void setUserEmail(const QString& email);
    void loadUserRole();
    ~User_Panel();
 void loadIncomeCategories();

signals:
    void logoutRequested();

public slots:
    void addNewIncomeCategory();

private:
    Ui::User_Panel *ui;
    QString userEmail;  //email zalogowanego użytkownika
    IncomeForm *m_incomeHandler;
};

#endif // USER_PANEL_HPP
