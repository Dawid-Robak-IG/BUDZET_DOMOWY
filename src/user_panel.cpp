#include "user_panel.hpp"
#include "ui_user_panel.h"

User_Panel::User_Panel(QString email,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::User_Panel),
    userEmail(email)
{
    ui->setupUi(this);

    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);
    ui->label_name->setText(userEmail);
    loadUserRole();
}

User_Panel::~User_Panel()
{
    delete ui;
}

void User_Panel::setUserEmail(const QString& email)
{
    userEmail = email;
    ui->label_name->setText(userEmail);
}


void User_Panel::loadUserRole() {
    QSqlQuery query;
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE Email = :email");
    query.bindValue(":email", userEmail);
    if (query.exec()) {
        if (query.next()) {
            QString rola = query.value(0).toString();
            ui->label_role->setText("Rola: " + rola);
        } else {
            qDebug() << "Nie znaleziono użytkownika o emailu:" << userEmail;
        }
    } else {
        qDebug() << "Błąd SQL:" << query.lastError().text();
    }
}
