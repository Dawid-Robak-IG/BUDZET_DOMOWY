
//#include "IncomeForm.hpp"
#include<QMessageBox>
#include "user_panel.hpp"
#include "ui_user_panel.h"
#include "Tab_Wydatki.hpp"
#include<QMessageBox>
#include <QSqlDatabase>

User_Panel::User_Panel(QString email,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::User_Panel),
    userEmail(email),wydatkiManager(nullptr), m_dbManager(nullptr)
    //m_incomeHandler(nullptr)
{
    ui->setupUi(this);

    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);
    ui->label_name->setText(userEmail);
    ui->dateEdit_dataPrzychod->setDate(QDate::currentDate());
 //   loadUserRole();

 //    loadIncomeCategories();

    //m_incomeHandler = new IncomeForm(ui->doubleSpinBox_kwotaPrzychod,
      //                                  ui->comboBox_kategoriaPrzychod,
        //                                ui->dateEdit_dataPrzychod,
          //                              ui->lineEdit_Notatka,
            //                            userEmail,
              //                          this); // this jako parent
    //connect(ui->pushButton, &QPushButton::clicked, m_incomeHandler, &IncomeForm::addIncome);

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
  //   delete m_incomeHandler;
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

