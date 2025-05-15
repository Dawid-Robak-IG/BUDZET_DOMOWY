#include "user_panel.hpp"
#include "ui_user_panel.h"
#include "IncomeForm.hpp"
#include<QMessageBox>


User_Panel::User_Panel(QString email,QWidget *parent)
    : QWidget(parent),
    ui(new Ui::User_Panel),
    userEmail(email),
    m_incomeHandler(nullptr)
{
    ui->setupUi(this);

    connect(ui->button_logout, &QPushButton::clicked, this, &User_Panel::logoutRequested);
    ui->label_name->setText(userEmail);
    ui->dateEdit_dataPrzychod->setDate(QDate::currentDate());
    loadUserRole();

     loadIncomeCategories();

    m_incomeHandler = new IncomeForm(ui->doubleSpinBox_kwotaPrzychod,
                                        ui->comboBox_kategoriaPrzychod,
                                        ui->dateEdit_dataPrzychod,
                                        ui->lineEdit_Notatka,
                                        userEmail,
                                        this); // this jako parent
    connect(ui->pushButton, &QPushButton::clicked, m_incomeHandler, &IncomeForm::addIncome);

connect(ui->pushButton_dodajKategoriePrzychod, &QPushButton::clicked, this, &User_Panel::addNewIncomeCategory);

}

void User_Panel::loadIncomeCategories()
{
    QSqlQuery query;
    query.prepare("SELECT Nazwa FROM Kategoria WHERE `Uzytkownik zalogowanyID` = (SELECT ID FROM `Uzytkownik zalogowany` WHERE Email = :email)");
    query.bindValue(":email", userEmail);
    if (query.exec()) {
        while (query.next()) {
            ui->comboBox_kategoriaPrzychod->addItem(query.value(0).toString());
        }
    } else {
        qDebug() << "Błąd ładowania kategorii przychodów:" << query.lastError().text();
    }
}


User_Panel::~User_Panel()
{
    delete ui;
     delete m_incomeHandler;
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


void User_Panel::addNewIncomeCategory()
{
    QString newCategoryName = ui->lineEdit_nowaKategoriaPrzychod->text().trimmed();

    if (newCategoryName.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź nazwę nowej kategorii.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Kategoria (Nazwa, `Uzytkownik zalogowanyID`) "
                  "VALUES (:nazwa, (SELECT ID FROM `Uzytkownik zalogowany` WHERE Email = :email))");
    query.bindValue(":nazwa", newCategoryName);
    query.bindValue(":email", userEmail);

    if (query.exec()) {
        loadIncomeCategories(); // Odśwież listę kategorii w QComboBox
        ui->lineEdit_nowaKategoriaPrzychod->clear();
        QMessageBox::information(this, "Sukces", "Kategoria została dodana.");
    } else {
        qDebug() << "Błąd dodawania kategorii:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać kategorii: " + query.lastError().text());
    }
}
