#include "LogReg.hpp"

LogReg::LogReg(QWidget *parent): QWidget(parent) {

    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    registerButton = new QPushButton("Zarejestruj", this);
    loginButton = new QPushButton("Zaloguj", this);

    // Layout dla formularza
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Nazwa użytkownika:"));
    layout->addWidget(usernameEdit);
    layout->addWidget(new QLabel("Hasło:"));
    layout->addWidget(passwordEdit);
    layout->addWidget(registerButton);
    layout->addWidget(loginButton);

    // Połączenie przycisków z odpowiednimi slotami
    // connect(registerButton, &QPushButton::clicked, this, &LogReg::registerUser);
    // connect(loginButton, &QPushButton::clicked, this, &LogReg::loginUser);

    // // Połączenie z bazą danych
    // if (!connectToDatabase()) {
    //     qDebug() << "Błąd połączenia z bazą danych!";
    // }
}

// bool LogReg::connectToDatabase() {
//     // Konfiguracja połączenia z bazą danych MySQL
//     db = QSqlDatabase::addDatabase("QMYSQL");
//     db.setHostName("localhost");   // Adres hosta (zwykle localhost)
//     db.setDatabaseName("your_database_name");  // Nazwa bazy danych
//     db.setUserName("root");        // Użytkownik bazy danych
//     db.setPassword("your_password"); // Hasło do bazy danych

//     if (!db.open()) {
//         qDebug() << "Błąd połączenia z bazą danych: " << db.lastError();
//         return false;
//     }
//     return true;
// }

// void LogReg::registerUser() {
//     QString username = usernameEdit->text();
//     QString password = passwordEdit->text();

//     if (username.isEmpty() || password.isEmpty()) {
//         QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
//         return;
//     }

//     // Sprawdzanie, czy użytkownik już istnieje
//     QSqlQuery query;
//     query.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
//     query.addBindValue(username);
//     if (!query.exec()) {
//         qDebug() << "Błąd zapytania do bazy: " << query.lastError();
//         return;
//     }

//     query.next();
//     if (query.value(0).toInt() > 0) {
//         QMessageBox::warning(this, "Błąd", "Użytkownik o tej nazwie już istnieje!");
//         return;
//     }

//     // Dodanie nowego użytkownika do bazy danych
//     query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
//     query.addBindValue(username);
//     query.addBindValue(password);
//     if (query.exec()) {
//         QMessageBox::information(this, "Sukces", "Rejestracja zakończona pomyślnie!");
//     } else {
//         QMessageBox::warning(this, "Błąd", "Nie udało się zarejestrować użytkownika.");
//     }
// }

// void LogReg::loginUser() {
//     QString username = usernameEdit->text();
//     QString password = passwordEdit->text();

//     if (username.isEmpty() || password.isEmpty()) {
//         QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione!");
//         return;
//     }

//     // Sprawdzanie, czy użytkownik istnieje w bazie danych
//     QSqlQuery query;
//     query.prepare("SELECT COUNT(*) FROM users WHERE username = ? AND password = ?");
//     query.addBindValue(username);
//     query.addBindValue(password);

//     if (!query.exec()) {
//         qDebug() << "Błąd zapytania do bazy: " << query.lastError();
//         return;
//     }

//     query.next();
//     if (query.value(0).toInt() > 0) {
//         qDebug() << "Zalogowano użytkownika: " << username;
//         QMessageBox::information(this, "Sukces", "Zalogowano pomyślnie!");
//     } else {
//         QMessageBox::warning(this, "Błąd", "Błędna nazwa użytkownika lub hasło.");
//     }
// }
