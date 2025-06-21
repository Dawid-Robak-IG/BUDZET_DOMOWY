#include "User_Panel.hpp"
#include <QMessageBox>
#include <QSqlDatabase>
#include "Tab_Wydatki.hpp"
#include "ui_User_Panel.h"

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
    relacjeManager(nullptr),
      budzetManager(nullptr)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);

    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);

    //ui->tabWidget->setTabVisible(1, false);

    ui->tabWidget->setStyleSheet(R"(
    QTabBar::tab {
        background: #daf8e3;
        color: #003b5b;
        padding: 6px;
    }

    QTabBar::tab:selected {
        background:  white;
        color: #003b5b;
    }

    QTabBar::tab:!selected {
        background: #003b5b;
        color: white;
    }
)");
}


void User_Panel::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    if (!daneUzytkownikaManager) {
        daneUzytkownikaManager = new Tab_DaneUzytkownika(userEmail, ui->tab_DaneUzytkownika, this);
        qDebug()<<"Stworzono daneUzytkownika Manager";
        daneUzytkownikaManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla danych uzytkownika";
    } else {
        daneUzytkownikaManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla danych uzytkownika";
    }

    if (!wydatkiManager) {
        wydatkiManager = new Tab_Wydatki(userEmail, ui->tab_Wydatki, this);
        qDebug()<<"Stworzono wydatki Manager";
        wydatkiManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla wydatkow";
    } else {
        wydatkiManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla wydatkow";
    }

    if (!uzytkownicyManager) {
        uzytkownicyManager = new Tab_Uzytkownicy(ui->tab_Uzytkownicy, this);
        qDebug()<<"Stworzono uzytkownicy Manager";
        uzytkownicyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla uzytkownikow";
    } else {
        uzytkownicyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla uzytkownikow";
    }

    if (!przychodyManager) {
        przychodyManager = new Tab_Przychody(userEmail, ui->tab_Przychody, this);
        qDebug()<<"Stworzono przychody Manager";
        przychodyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla przychodow";
    } else {
        przychodyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla przychodow";
    }

    if (!kategorieManager) {
       kategorieManager = new Tab_Kategorie(userEmail, ui->tab_Kategorie, this);
       qDebug()<<"Stworzono kategoria Manager";
       kategorieManager->setDatabaseManager(m_dbManager);
       qDebug()<<"Ustawiono dbManager dla kategorii";
    } else {
       kategorieManager->setDatabaseManager(m_dbManager);
       qDebug()<<"Ustawiono dbManager dla kategorii";
    }

    if (!cyklicznePManager) {
        cyklicznePManager = new Tab_CykliczneP(userEmail, ui->tab_CykliczneP, this);
        qDebug()<<"Stworzono cykliczne P Manager";
        cyklicznePManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla cyklicznych P";
    } else {
        cyklicznePManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla cyklcznych P";
    }

    if (!cykliczneWManager) {
        cykliczneWManager = new Tab_CykliczneW(userEmail, ui->tab_CykliczneW, this);
        qDebug()<<"Stworzono cykliczne W Manager";
        cykliczneWManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla cyklciznych W";
    } else {
        cykliczneWManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla cykliczych W";
    }

    if (!raportyManager) {
       raportyManager = new Tab_Raporty(userEmail, ui->tab_Raporty, this);
       qDebug()<<"Stworzono raporty Manager";
        raportyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla raportu";
    } else {
        raportyManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla raportow";
    }

    if (!dzieciManager) {
       dzieciManager = new Tab_Dzieci(userEmail, ui->tab_Dzieci, this);
       qDebug()<<"Stworzono dzieci Manager";
        dzieciManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla dzieci";
    } else {
        dzieciManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla dzieci";
    }

    if (!relacjeManager) {
        relacjeManager = new Tab_Relacje(userEmail, ui->tab_Relacje, this);
        qDebug()<<"Stworzono relacje Manager";
        relacjeManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla relacji";
    } else {
        relacjeManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla relacji";
    }

    if (!budzetManager) {
        budzetManager = new Tab_Budzet(ui->tab_Budzet, this);
        qDebug()<<"Stworzono tab_budzet";
        budzetManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla budzetu";
    } else {
        budzetManager->setDatabaseManager(m_dbManager);
        qDebug()<<"Ustawiono dbManager dla budzetu";
    }

    // connect(wydatkiManager, &Tab_Wydatki::daneZmienione, budzetManager, &Tab_Budzet::refresh);
    //connect(przychodyManager, &Tab_Przychody::daneZmienione, budzetManager, &Tab_Budzet::refresh);

    connect(wydatkiManager, &Tab_Wydatki::daneZmienione, this, [this]() {
        budzetManager->refresh();
        daneUzytkownikaManager->loadUserData(m_dbManager->get_mail());
    });

    connect(przychodyManager, &Tab_Przychody::daneZmienione, this, [this]() {
        budzetManager->refresh();
        daneUzytkownikaManager->loadUserData(m_dbManager->get_mail());
    });

    setTabsVisibility();
}

User_Panel::~User_Panel()
{
    delete ui;

}

void User_Panel::setUserEmail(const QString& email)
{
    userEmail = email;
    setTabsVisibility();
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
            ui->label_role->setText(role);
            qDebug() << "Zalogowano jako: " << name << surname << "rola:" << role;

        } else {
            QMessageBox::warning(this, "Błąd", "Nie znaleziono użytkownika o podanym emailu.");
             }
    } else {
        qDebug() << "Błąd podczas pobierania danych użytkownika:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać danych użytkownika.");
    }
    setTabsVisibility();
}


void User_Panel::goToStartPage() {
     ui->tabWidget->setCurrentIndex(0);
    cykliczneWManager->goToStartPage();
    cyklicznePManager->goToStartPage();
    uzytkownicyManager->goToStartPage();
    setTabsVisibility();
}
void User_Panel::setTablesByNewUser(){
    cyklicznePManager->setTableStrategy();
    cykliczneWManager->setTableStrategy();
    uzytkownicyManager->setTableStrategy();
    dzieciManager->loadDzieciListComboBox();
    raportyManager->setDatabaseManager(m_dbManager);
    daneUzytkownikaManager->setDatabaseManager(m_dbManager);
    budzetManager->loadOperacjeTable();
    daneUzytkownikaManager->loadUserData(m_dbManager->get_mail());
    setTabsVisibility();
}

void User_Panel::setTabsVisibility()
{
    // Domyślnie pokaż wszystkie zakładki od 0 do 10
    for (int i = 0; i <= 10; ++i) {
        ui->tabWidget->setTabVisible(i, true);
    }

    if (m_dbManager->amIChild()) {
        ui->tabWidget->setTabVisible(4, false);  // kategoria
        ui->tabWidget->setTabVisible(5, false);  //cykliczne przychody
        ui->tabWidget->setTabVisible(6, false);  //cykliczne wydatki
        ui->tabWidget->setTabVisible(9, false);  //dzieci
        ui->tabWidget->setTabVisible(10, false); //relacje

    } else if (m_dbManager->amIParent()) {
        ui->tabWidget->setTabVisible(4, false);  // kategoria
        ui->tabWidget->setTabVisible(10, false); //relacje
    }

    if (m_dbManager->amI_Noone()) {
        ui->tabWidget->setTabVisible(1, false);
        ui->tabWidget->setTabVisible(2, false);
        ui->tabWidget->setTabVisible(3, false);
        ui->tabWidget->setTabVisible(7, false);
        ui->tabWidget->setTabVisible(8, false);
    }

    if (m_dbManager->amIAdult()) {
        ui->tabWidget->setTabVisible(4, false); // kategoria

        ui->tabWidget->setTabVisible(9, false);  //dzieci
        ui->tabWidget->setTabVisible(10, false); //relacje
    }
    if (m_dbManager->amI_admin()) {
        ui->tabWidget->setTabVisible(4, true);
    }
}
