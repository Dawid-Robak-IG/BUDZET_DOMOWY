#include<QMessageBox>
#include "User_Panel.hpp"
#include "ui_User_Panel.h"
#include "Tab_Wydatki.hpp"
#include<QMessageBox>
#include <QSqlDatabase>

User_Panel::User_Panel(QString email,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::User_Panel),
    userEmail(email),m_dbManager(nullptr),wydatkiManager(nullptr), przychodyManager(nullptr), uzytkownicyManager(nullptr)

{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);
    ui->label_name->setText(userEmail);
    ui->dateEdit_dataPrzychod->setDate(QDate::currentDate());
     ui->dateEdit_dataWydatek->setDate(QDate::currentDate());


 //   loadUserRole();

 //    loadIncomeCategories();


connect(ui->pushButton_dodajKategoriePrzychod, &QPushButton::clicked, this, &User_Panel::addNewIncomeCategory);

//zakładaka Wydatki
// wydatkiManager = new Tab_Wydatki(userEmail,ui->tab_Wydatki,this);
// if (m_dbManager) {
//     wydatkiManager->setDatabaseManager(m_dbManager);
// } else {
//     qDebug() << "❌ m_dbManager jest nullptr w User_Panel przy tworzeniu Tab_Wydatki";
// }
}


void User_Panel::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;

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

}



void User_Panel::loadIncomeCategories()
{
    if (!m_dbManager) {
        qDebug() << "❌ m_dbManager jest nullptr";
        return;
    }
    if (!m_dbManager->getDatabase().isOpen()) {
        qDebug() << "❌ Baza danych nie jest otwarta";
        return;
    }

    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Nazwa FROM Kategoria");
    if (query.exec()) {
        while (query.next()) {
            ui->comboBox_kategoriaPrzychod->addItem(query.value(0).toString());
            ui->comboBox_kategoriaWydatek->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Błąd ładowania kategorii przychodów:" << query.lastError().text();
    }
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
    if (!m_dbManager) {
        qDebug() << "DatabaseManager nie jest ustawiony!";
        return;
    }
    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE Email = :email");
    query.bindValue(":email", userEmail);
    if (query.exec()) {
        if (query.next()) {
            QString rola = query.value(0).toString();
            ui->label_role->setText("Rola: " + rola);
             displayUserData(userEmail);  //wpisanie danych do danych użytkwnika w panelu
        } else {
            qDebug() << "Nie znaleziono użytkownika o emailu:" << userEmail;
        }
    } else {
        qDebug() << "Błąd SQL:" << query.lastError().text();
    }
}


void User_Panel::addNewIncomeCategory()
{
    QString newCategoryName = ui->lineEdit_nowaKategoriaPrzychod->text().trimmed();

    if (newCategoryName.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź nazwę nowej kategorii.");
        return;
    }

    QSqlQuery idQuery(m_dbManager->getDatabase());
    idQuery.prepare("SELECT ID FROM `Uzytkownik zalogowany` WHERE Email = :email");
    idQuery.bindValue(":email", userEmail);

    if (!idQuery.exec() || !idQuery.next()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się znaleźć użytkownika.");
        return;
    }
    int userId = idQuery.value(0).toInt();

    QSqlQuery insertQuery(m_dbManager->getDatabase());
    insertQuery.prepare("INSERT INTO Kategoria (Nazwa, `Uzytkownik zalogowanyID`) VALUES (:nazwa, :userId)");
    insertQuery.bindValue(":nazwa", newCategoryName);
    insertQuery.bindValue(":userId", userId);

    if (insertQuery.exec()) {
        loadIncomeCategories(); // Odśwież listę kategorii
        ui->lineEdit_nowaKategoriaPrzychod->clear();
        QMessageBox::information(this, "Sukces", "Kategoria została dodana.");
    } else {
        qDebug() << "Błąd dodawania kategorii:" << insertQuery.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać kategorii: " + insertQuery.lastError().text());
    }
}





void User_Panel::displayUserData(const QString &email){

    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Imie, Nazwisko, `Data urodzenia`, Email, Rola FROM `Uzytkownik zalogowany` WHERE Email = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.first()) {
            QString name = query.value("Imie").toString();
            QString surname = query.value("Nazwisko").toString();
            QDate birthDate = query.value("Data urodzenia").toDate();
            QString dbEmail = query.value("Email").toString();
            QString role = query.value("Rola").toString();

            ui->lineEdit_surnameUD->setText(name + " " + surname);
            ui->label_role->setText("(" + role + ")");
            ui->lineEdit_nameUD->setText(name);
            ui->lineEdit_surnameUD->setText(surname);
            ui->dateEdit_DOB_UD->setDate(birthDate);
            ui->lineEdit_emailUD->setText(dbEmail);
        } else {
            QMessageBox::warning(this, "Błąd", "Nie znaleziono użytkownika o podanym emailu.");
             }
    } else {
        qDebug() << "Błąd podczas pobierania danych użytkownika:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać danych użytkownika.");
    }
}

