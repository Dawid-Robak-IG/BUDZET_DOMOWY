#include "Start_Log_Reg.hpp"
#include "ui_Start_Log_Reg.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Start_Log_Reg::Start_Log_Reg(QWidget *parent): QWidget(parent), ui(new Ui::Start_Log_Reg){

    ui->setupUi(this);

    // Ustaw tło całego widgetu przez paletę (na samym dole)
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor("#a6e3de"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // QLabel z obrazkiem w naturalnym rozmiarze
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(":/Start/resources/startPage.png"));
    backgroundLabel->setScaledContents(false);
    backgroundLabel->setGeometry(0,
                                 0,
                                 backgroundLabel->pixmap()->width(),
                                 backgroundLabel->pixmap()->height());

    backgroundLabel->setAttribute(Qt::WA_TranslucentBackground);
    backgroundLabel->lower(); // umieść na sam dół (pod innymi widgetami)

    ui->stackedWidget->setCurrentIndex(startPageIndex);

    connect(ui->pushButton_Zaloguj, &QPushButton::clicked, [this](){
        ui->stackedWidget->setCurrentIndex(loginPageIndex);
    });

    connect(ui->pushButton_Zarejestruj, &QPushButton::clicked, [this](){
        ui->stackedWidget->setCurrentIndex(registerPageIndex);
    });

    connect(ui->pushButton_powrotLog, &QPushButton::clicked, [this](){
        ui->stackedWidget->setCurrentIndex(startPageIndex);
    });

    connect(ui->pushButton_powrotReg, &QPushButton::clicked, [this](){
        ui->stackedWidget->setCurrentIndex(startPageIndex);
    });

    connect(ui->checkBox_showPasswordLog, &QCheckBox::toggled, this, [this](bool checked){
        ui->lineEdit_passwordLog->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });

    connect(ui->checkBox_showPasswordReg, &QCheckBox::toggled, this, [this](bool checked){
        ui->lineEdit_passwordReg->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
    });


    connect(ui->pushButton_zalogujSie, &QPushButton::clicked, this, &Start_Log_Reg::loginUser);
    connect(ui->pushButton_zarejestrujSie, &QPushButton::clicked, this, &Start_Log_Reg::registerUser);

    connect(ui->infoButton, &QPushButton::clicked, this, [this]() {
        QMessageBox::about(this,
                           "O aplikacji",
                           "Budżet Domowy v1.0\n\n"
                           "Autorzy: Paulina Piorun, Dawid Robak\n\n"

                           "Aplikacja służy do zarządzania domowym budżetem.\n"
                           "Zawiera moduły do kontroli stanu budżetu, zapisywania wydatków, "
                           "przychodów, generowania raportów i więcej.\n\n"
                           "Technologie:\n"
                           "- Qt 5/6 (GUI, bazy danych, MVC)\n"
                           "- C++ (logika aplikacji)\n"
                           "- SQLite (lokalna baza danych)\n"
                           "- Qt Designer (interfejs użytkownika)");
    });

    ui->lineEdit_emailLog->setText("janprus@poczta.com");
    ui->lineEdit_passwordLog->setText("haslo123");

    ui->dateEdit_DOB_Reg->setDate(QDate::currentDate());
}

void Start_Log_Reg::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (backgroundLabel) {
        QPixmap pix(":/Start/startPage.png");
        QPixmap scaled = pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        backgroundLabel->setPixmap(scaled);
        backgroundLabel->setGeometry(0, 0, scaled.width(), scaled.height());
    }
}

Start_Log_Reg::~Start_Log_Reg(){
    delete ui;
}
void Start_Log_Reg::registerUser(){
    if (!isValidReg()) return;

    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        QMessageBox::critical(this, "Błąd", "Baza danych nie jest otwarta!");
        return;
    }

    QString email = ui->lineEdit_emailReg->text();
    QString name = ui->lineEdit_firstNameReg->text();
    QString surname = ui->lineEdit_lastNameReg->text();
    QString birthDate = ui->dateEdit_DOB_Reg->date().toString("yyyy-MM-dd");
    QString password = ui->lineEdit_passwordReg->text();

    if (email.isEmpty() || name.isEmpty() || surname.isEmpty() || birthDate.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
        return;
    }

    // Sprawdzanie, czy użytkownik już istnieje
    QSqlQuery checkUserQuery(m_dbManager->getDatabase());
    checkUserQuery.prepare("SELECT COUNT(*) FROM `Uzytkownik zalogowany` WHERE Email = :email");
    checkUserQuery.bindValue(":email", email);

    if (!checkUserQuery.exec() || !checkUserQuery.next()) {
        qDebug() << "Nie udało się sprawdzić czy dany użytkownik istnieje";
        return;
    }

    if (checkUserQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Błąd", "Użytkownik o podanym emailu już istnieje!");
        return;
    }


    // Ustalenie roli - jeśli to pierwszy użytkownik, przypisz rolę "Admin"
    QString role = "Uzytkownik"; // Domyślna rola
    QSqlQuery countQuery(m_dbManager->getDatabase());
    if (countQuery.exec("SELECT COUNT(*) FROM `Uzytkownik zalogowany`") && countQuery.next()) {
        if (countQuery.value(0).toInt() == 0) {
            role = "Admin";
        }
    } else {
        qDebug() << "Błąd podczas sprawdzania liczby użytkowników:" << countQuery.lastError().text();
    }



    // Dodanie nowego użytkownika z domyślną rolą "Dziecko" i niezablokowanym statusem
    QSqlQuery registerQuery(m_dbManager->getDatabase());
    registerQuery.prepare("INSERT INTO `Uzytkownik zalogowany` "
                          "(Imie, Nazwisko, Email, Haslo, Czy_zablokowany, `Data urodzenia`, Rola) "
                          "VALUES (:name, :surname, :email, :password, :blocked, :birthDate, :role)");
    registerQuery.bindValue(":name", name);
    registerQuery.bindValue(":surname", surname);
    registerQuery.bindValue(":email", email);
    registerQuery.bindValue(":password", password);
    registerQuery.bindValue(":blocked", 0);               // Użytkownik NIEZABLOKOWANY
    registerQuery.bindValue(":birthDate", birthDate);
    registerQuery.bindValue(":role", role);          // Domyślna rola: Dziecko

    if (registerQuery.exec()) {
        QMessageBox::information(this, "Sukces", "Rejestracja zakończona pomyślnie!");
        clear_reg();
        ui->stackedWidget->setCurrentIndex(startPageIndex);
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zarejestrować użytkownika.");
        qDebug() << "Błąd SQL:" << registerQuery.lastError().text();
    }

}


void Start_Log_Reg::loginUser(){
    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        QMessageBox::critical(this, "Błąd", "Baza danych nie jest otwarta!");
        return;
    }

    QString email = ui->lineEdit_emailLog->text();
    QString password = ui->lineEdit_passwordLog->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
        return;
    }

    QSqlQuery query(m_dbManager->getDatabase()); 
    query.prepare("SELECT ID, Czy_zablokowany FROM `Uzytkownik zalogowany` WHERE `Email` = :email AND `Haslo` = :haslo");
    query.bindValue(":email", email);
    query.bindValue(":haslo", password);

    if (!query.exec()) {
        qDebug() << "Błąd logowania:" << query.lastError().text();
        QMessageBox::warning(this, "Błąd", "Błąd podczas logowania.");
        return;
    }

    if(query.next()){
        int blockedStatus = query.value("Czy_zablokowany").toInt();
        if (blockedStatus == 1) {
            QMessageBox::warning(this, "Zablokowany", "Twoje konto jest zablokowane. Skontaktuj się z administratorem.");
            return;
        }

        QMessageBox::information(this, "Sukces", "Zalogowano pomyślnie!");
        int userID = query.value("ID").toInt();
        qDebug() << "ID zalogowanego usera: " << userID;
        m_dbManager->set_logged_user(userID); 

        ui->lineEdit_emailLog->clear();
        ui->lineEdit_passwordLog->clear();
        qDebug()<<"Emitowanie sygnału o pomyślnym zalogowaniu";
        emit loginSuccessful(email);
    } else {
        QMessageBox::warning(this, "Błąd", "Błędny e-mail lub hasło.");
    }
}

bool Start_Log_Reg::isValidReg(){
    QString email = ui->lineEdit_emailReg ->text();
    if (!email.contains('@') || email.indexOf('@') == 0 || email.indexOf('@') == email.length() - 1) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawny adres e-mail.");
        return false;
    }
    QString password = ui->lineEdit_passwordReg->text();
    if (password.length() < 8) {
        QMessageBox::warning(this, "Błąd", "Hasło musi mieć co najmniej 8 znaków.");
        return false;
    }
    return true;
}


void Start_Log_Reg::clear_reg(){
    ui->lineEdit_emailReg->clear();
    ui->lineEdit_firstNameReg->clear();
    ui->lineEdit_lastNameReg->clear();
    ui->dateEdit_DOB_Reg->setDate(QDate::currentDate());
    ui->lineEdit_passwordReg->clear();
}


void Start_Log_Reg::goToStartPage() {
    ui->stackedWidget->setCurrentIndex(startPageIndex);
}
