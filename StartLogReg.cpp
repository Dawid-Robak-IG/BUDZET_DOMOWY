#include "StartLogReg.hpp"
#include "ui_StartLogReg.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


Start_Log_Reg::Start_Log_Reg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start_Log_Reg)
{
    ui->setupUi(this);

    // Połączenie przycisków ze Start_page do odpowiednich stron
    connect(ui->pushButton_Zaloguj, &QPushButton::clicked, ui->stackedWidget, &QStackedWidget::setCurrentIndex);
     connect(ui->pushButton_Zarejestruj, &QPushButton::clicked, ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Ustawienie indeksów stron w stackedWidget
    int loginPageIndex = 1; // Indeks strony Login_page
   int registerPageIndex = 2; // Indeks strony Register_page

    // Przekazanie indeksów stron jako argumentów (używając lambdy)
    connect(ui->pushButton_Zaloguj, &QPushButton::clicked, [this, loginPageIndex](){
        ui->stackedWidget->setCurrentIndex(loginPageIndex);
    });

    connect(ui->pushButton_Zarejestruj, &QPushButton::clicked, [this, registerPageIndex](){
         ui->stackedWidget->setCurrentIndex(registerPageIndex);
     });


connect(ui->pushButton_zalogujSie, &QPushButton::clicked, this, &Start_Log_Reg::loginUser);

connect(ui->pushButton_zarejestrujSie, &QPushButton::clicked, this, &Start_Log_Reg::registerUser);


  // connect(this, &Start_Log_Reg::loginSuccessful, this, &Start_Log_Reg::switchToUserPanel);
connectToDatabase();
}







Start_Log_Reg::~Start_Log_Reg()
{
    delete ui;
}


void Start_Log_Reg::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("BUDZET_DOMOWY");
    db.setUserName("root");
    db.setPassword("admin");

    if (!db.open()) {
        qDebug()<<"Couldn't connect to database in logreg\n";
        exit(-1);
    }
}

void Start_Log_Reg::registerUser(){




}


void Start_Log_Reg::loginUser(){


    QString email =ui->lineEdit_emailLog->text();
    QString password = ui->lineEdit_passwordLog->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
        return;
    }

    if (db.isOpen()) {
        QSqlQuery query(db); // Używaj istniejącego połączenia 'db'
        query.prepare("SELECT Email FROM `Uzytkownik zalogowany` WHERE `Email` = :email AND `Haslo` = :haslo");
        query.bindValue(":email", email);
        query.bindValue(":haslo", password);

        if (!query.exec()) {
            qDebug() << "Błąd logowania:" << query.lastError().text();
            QMessageBox::warning(this, "Błąd", "Błąd podczas logowania.");
            return;
        }

        query.next();
        if (query.value(0).toString() == email) {
            QMessageBox::information(this, "Sukces", "Zalogowano pomyślnie!");
            ui->lineEdit_emailLog->clear();
            ui->lineEdit_passwordLog->clear();
            emit loginSuccessful(email); // Sygnał o udanym logowaniu
        } else {
            QMessageBox::warning(this, "Błąd", "Błędny e-mail lub hasło.");
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Baza danych nie jest otwarta!");
        qDebug() << "Baza danych nie jest otwarta w loginUser.";
    }
}
