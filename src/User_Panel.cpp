#include<QMessageBox>
#include "User_Panel.hpp"
#include "ui_User_Panel.h"
#include "Tab_Wydatki.hpp"
#include<QMessageBox>
#include <QSqlDatabase>

User_Panel::User_Panel(QString email,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::User_Panel),
    userEmail(email),
    m_dbManager(nullptr),
    wydatkiManager(nullptr),
    przychodyManager(nullptr),
    uzytkownicyManager(nullptr),
    kategorieManager(nullptr),
    daneUzytkownikaManager(nullptr),
    cyklicznePManager(nullptr),
    cykliczneWManager(nullptr),
    raportyManager(nullptr),
    dzieciManager(nullptr),
    relacjeManager(nullptr)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);

}


void User_Panel::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    if (!daneUzytkownikaManager) {
        daneUzytkownikaManager = new Tab_DaneUzytkownika(userEmail, ui->tab_DaneUzytkownika, this);
        daneUzytkownikaManager->setDatabaseManager(m_dbManager);
    } else {
        daneUzytkownikaManager->setDatabaseManager(m_dbManager);
    }

    if (!wydatkiManager) {
        wydatkiManager = new Tab_Wydatki(userEmail, ui->tab_Wydatki, this);
        wydatkiManager->setDatabaseManager(m_dbManager);
    } else {
        wydatkiManager->setDatabaseManager(m_dbManager);
    }

    if (!uzytkownicyManager) {
        uzytkownicyManager = new Tab_Uzytkownicy(ui->tab_Uzytkownicy, this);
        uzytkownicyManager->setDatabaseManager(m_dbManager);
    } else {
        uzytkownicyManager->setDatabaseManager(m_dbManager);
    }

    if (!przychodyManager) {
        przychodyManager = new Tab_Przychody(userEmail, ui->tab_Przychody, this);
        przychodyManager->setDatabaseManager(m_dbManager);
    } else {
        przychodyManager->setDatabaseManager(m_dbManager);
    }

    if (!kategorieManager) {
       kategorieManager = new Tab_Kategorie(userEmail, ui->tab_Kategorie, this);
       kategorieManager->setDatabaseManager(m_dbManager);
    } else {
       kategorieManager->setDatabaseManager(m_dbManager);
    }
    if (!cyklicznePManager) {
        cyklicznePManager = new Tab_CykliczneP(userEmail, ui->tab_CykliczneP, this);
        cyklicznePManager->setDatabaseManager(m_dbManager);
    } else {
        cyklicznePManager->setDatabaseManager(m_dbManager);
    }

    if (!cykliczneWManager) {
        cykliczneWManager = new Tab_CykliczneW(userEmail, ui->tab_CykliczneW, this);
        cykliczneWManager->setDatabaseManager(m_dbManager);
    } else {
        cykliczneWManager->setDatabaseManager(m_dbManager);
    }

    if (!raportyManager) {
       raportyManager = new Tab_Raporty(userEmail, ui->tab_Raporty, this);
        raportyManager->setDatabaseManager(m_dbManager);
    } else {
        raportyManager->setDatabaseManager(m_dbManager);
    }

    if (!dzieciManager) {
       dzieciManager = new Tab_Dzieci(userEmail, ui->tab_Dzieci, this);
        dzieciManager->setDatabaseManager(m_dbManager);
    } else {
        dzieciManager->setDatabaseManager(m_dbManager);
    }
    if (!relacjeManager) {
        relacjeManager = new Tab_Relacje(userEmail, ui->tab_Relacje, this);
        relacjeManager->setDatabaseManager(m_dbManager);
    } else {
        relacjeManager->setDatabaseManager(m_dbManager);
    }

}


User_Panel::~User_Panel()
{
    delete ui;

}

void User_Panel::setUserEmail(const QString& email)
{
    userEmail = email;
}



void User_Panel::displayUserData(const QString &email){

    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Imie, Nazwisko, Rola FROM `Uzytkownik zalogowany` WHERE Email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.first()) {
            QString name = query.value("Imie").toString();
            QString surname = query.value("Nazwisko").toString();
            QString role = query.value("Rola").toString();

            ui->label_name->setText(name + " " + surname);
            ui->label_role->setText("Rola: " + role);
            qDebug() << "Zalogowano jako: " << name << surname << "rola:" << role;

        } else {
            QMessageBox::warning(this, "Błąd", "Nie znaleziono użytkownika o podanym emailu.");
             }
    } else {
        qDebug() << "Błąd podczas pobierania danych użytkownika:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać danych użytkownika.");
    }

}


void User_Panel::goToStartPage() {
     ui->tabWidget->setCurrentIndex(0);
    cykliczneWManager->goToStartPage();
    cyklicznePManager->goToStartPage();
    uzytkownicyManager->goToStartPage();
}
void User_Panel::setTablesByNewUser(){
    cyklicznePManager->setTableStrategy();
    cykliczneWManager->setTableStrategy();
    uzytkownicyManager->setTableStrategy();
    dzieciManager->loadDzieciListComboBox();
}
