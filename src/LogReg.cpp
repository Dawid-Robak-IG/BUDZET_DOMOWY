#include "LogReg.hpp"

LogReg::LogReg(QWidget *parent): QWidget(parent) {

    layout = new QHBoxLayout(this);

    setLogin();
    setRegistration();

    layout->addLayout(logLayout,1);
    layout->addLayout(regLayout,1);

    connect(regButton, &QPushButton::clicked, this, &LogReg::registerUser);
    connect(logButton, &QPushButton::clicked, this, &LogReg::loginUser);

    connectToDatabase();
}
void LogReg::setLogin(){
    logLayout = new QVBoxLayout();

    logLayout->addWidget(new QLabel("Logowanie"));

    logMail = new QLineEdit();
    logMail->setPlaceholderText("E-mail");
    logPass = new QLineEdit();
    logPass->setPlaceholderText("Haslo");
    logPass->setEchoMode(QLineEdit::Password);
    logButton = new QPushButton("Zaloguj");

    logLayout->addWidget(logMail);
    logLayout->addWidget(logPass);
    logLayout->addWidget(logButton);
}
void LogReg::setRegistration(){
    regLayout = new QVBoxLayout();

    regLayout->addWidget(new QLabel("Rejestracja"));

    regMail = new QLineEdit();
    regMail->setPlaceholderText("E-mail");
    regName = new QLineEdit();
    regName->setPlaceholderText("Imie");
    regSurrname = new QLineEdit();
    regSurrname->setPlaceholderText("Nazwisko");

    regDate = new QDateEdit();
    regDate->setCalendarPopup(true);
    regDate->setDisplayFormat("yyyy-MM-dd");
    regDate->setDate(QDate::currentDate()); 

    regPass = new QLineEdit();
    regPass->setPlaceholderText("Haslo");
    regPass->setEchoMode(QLineEdit::Password);
    regButton = new QPushButton("Zarejestruj");

    regLayout->addWidget(regMail);
    regLayout->addWidget(regName);
    regLayout->addWidget(regSurrname);
    regLayout->addWidget(regDate);
    regLayout->addWidget(regPass);
    regLayout->addWidget(regButton);
}

void LogReg::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");  
    db.setDatabaseName("BUDZET_DOMOWY");
    db.setUserName("root");     
    db.setPassword("admin");

    if (!db.open()) {
        std::cout<<"Couldn't connect to database in logreg\n";
        exit(-1);
    }
}

void LogReg::registerUser() {
    if(!isValidReg())return;

    QString email = regMail->text();
    QString name = regName->text();
    QString surname = regSurrname->text();
    QString birthDate = regDate->text();
    QString password = regPass->text();

    if (email.isEmpty() || name.isEmpty() || surname.isEmpty() || birthDate.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
        return;
    }

    // Sprawdzanie, czy użytkownik już istnieje
    QSqlQuery checkUserQuery;
    checkUserQuery.prepare("SELECT COUNT(*) FROM `Uzytkownik zalogowany` WHERE Email = :email");
    checkUserQuery.bindValue(":email", email);

    if (!checkUserQuery.exec()) {
        qDebug() << "Nie udało się sprawdzić czy dany użytkownik istnieje";
        return;
    }

    checkUserQuery.next();
    if (checkUserQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Błąd", "Użytkownik o podanym emailu już istnieje!");
        return;
    }

    // Dodanie nowego użytkownika
    QSqlQuery registerQuery;
    registerQuery.prepare("INSERT INTO `Uzytkownik zalogowany` (Imie, Nazwisko, Email, Haslo, Czy_zablokowany, `Data urodzenia`, Rola) "
                          "VALUES (:name, :surname, :email, :password, 0, :birthDate, 'Użytkownik')");
    registerQuery.bindValue(":name", name);
    registerQuery.bindValue(":surname", surname);
    registerQuery.bindValue(":email", email);
    registerQuery.bindValue(":password", password);
    registerQuery.bindValue(":birthDate", birthDate);

    if (registerQuery.exec()) {
        QMessageBox::information(this, "Sukces", "Rejestracja zakończona pomyślnie!");
        clear_reg();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zarejestrować użytkownika.");
    }
}
bool LogReg::isValidReg(){
    QString email = regMail->text();
    if (!email.contains('@') || email.indexOf('@') == 0 || email.indexOf('@') == email.length() - 1) {
        QMessageBox::warning(this, "Błąd", "Wprowadź poprawny adres e-mail.");
        return false;
    }
    QString password = regPass->text();
    if (password.length() < 8) {
        QMessageBox::warning(this, "Błąd", "Hasło musi mieć co najmniej 8 znaków.");
        return false;
    }
    return true;
}

void LogReg::loginUser() {
    QString mail = logMail->text();
    QString password = logPass->text();

    if (mail.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
        return;
    }

    // Sprawdzanie, czy użytkownik istnieje w bazie danych
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM `Uzytkownik zalogowany` WHERE `Email` = ? AND `Haslo` = ?");
    query.addBindValue(mail);
    query.addBindValue(password);

    if (!query.exec()) {
        QMessageBox::warning(this, "Błąd", "Błąd w logowaniu");
        return;
    }

    query.next();
    if (query.value(0).toInt() > 0) {
        QMessageBox::information(this, "Sukces", "Zalogowano pomyślnie!");
        logMail->clear();
        logPass->clear();
        emit loginSuccessful(mail);
    } else {
        QMessageBox::warning(this, "Błąd", "Błędna nazwa użytkownika lub hasło.");
    }
}
void LogReg::clear_reg(){
    regMail->clear();
    regName->clear();
    regSurrname->clear();
    regDate->clear();
    regPass->clear();
}