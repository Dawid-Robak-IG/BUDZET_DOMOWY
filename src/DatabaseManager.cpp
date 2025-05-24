#include "../inc/DatabaseManager.hpp"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

DatabaseManager::DatabaseManager(QObject *parent) : QObject{parent}{
    if (!openConnection()) {
        QMessageBox::warning(nullptr, "Uwaga", "Nie udało się połączyć z bazą danych. Niektóre funkcje mogą nie działać poprawnie.");
    }
    logged_user_ID = -1;

    reload_whole_budzet();
}

DatabaseManager::~DatabaseManager() {
    closeConnection();
}


bool DatabaseManager::openConnection() {
    if (QSqlDatabase::contains("main_connection")) {
        m_db = QSqlDatabase::database("main_connection");
        if (m_db.isOpen()) {
            qDebug() << "Połączenie już otwarte.";
            return true;
        }
    } else{
        m_db = QSqlDatabase::addDatabase("QMYSQL","main_connection");
        m_db.setHostName("localhost");
        m_db.setDatabaseName("BUDZET_DOMOWY");
        m_db.setUserName("root");
        m_db.setPassword("admin");
    }
    if (!m_db.open()) {
        qWarning() << "Couldn't connect to database:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Połączono z bazą danych.";
    return true;
}


void DatabaseManager::closeConnection() {
    if (m_db.isOpen()) {
        m_db.close();
    }


    // UWAGA: To musi być wywołane tylko raz po zamknięciu połączenia!
    // QSqlDatabase::removeDatabase("main_connection");
}

bool DatabaseManager::addWydatek(const QString &email, double amount, const QDate &date, const QString &note, const QString &category){
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO Operacja (Kwota, Data, Notatka, `Uzytkownik zalogowanyID`, `Kategoria Nazwa`, czy_z_cyklicznego)
        SELECT :kwota, :data, :notatka, ID, :kategoria, 0
        FROM `Uzytkownik zalogowany`
        WHERE Email = :email
    )");

    query.bindValue(":kwota", -amount);
    query.bindValue(":data", date);
    query.bindValue(":notatka", note.isEmpty() ? QVariant(QVariant::String) : note);
    query.bindValue(":kategoria", category);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania wydatku:" << query.lastError().text();
        return false;
    }

    QSqlQuery idQuery(m_db);
    if (!idQuery.exec("SELECT LAST_INSERT_ID();")) {
        qDebug() << "Błąd pobierania ID ostatniej operacji:" << idQuery.lastError().text();
        return false;
    }
    int operacjaID = -1;
    if (idQuery.next()) {
        operacjaID = idQuery.value(0).toInt();
    }
    if (operacjaID == -1) {
        qDebug() << "Nie udało się pobrać ID nowej operacji.";
    }
    if (!update_budzet_domowy(operacjaID,-amount)) {
        qDebug() << "Błąd dodawania wpisu do budżetu domowego.";
    }
    return true;
}
bool DatabaseManager::addPrzychod(const QString &email, double amount, const QDate &date, const QString &note, const QString &category)
{
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO Operacja (Kwota, Data, Notatka, `Uzytkownik zalogowanyID`, `Kategoria Nazwa`, czy_z_cyklicznego)
        SELECT :kwota, :data, :notatka, ID, :kategoria, 0
        FROM `Uzytkownik zalogowany`
        WHERE Email = :email
    )");

    query.bindValue(":kwota", amount);
    query.bindValue(":data", date);
    query.bindValue(":notatka", note.isEmpty() ? QVariant(QVariant::String) : note);
    query.bindValue(":kategoria", category);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania przychodu:" << query.lastError().text();
        return false;
    }

    QSqlQuery idQuery(m_db);
    if (!idQuery.exec("SELECT LAST_INSERT_ID();")) {
        qDebug() << "Błąd pobierania ID ostatniej operacji:" << idQuery.lastError().text();
        return false;
    }
    int operacjaID = -1;
    if (idQuery.next()) {
        operacjaID = idQuery.value(0).toInt();
    }
    if (operacjaID == -1) {
        qDebug() << "Nie udało się pobrać ID nowej operacji.";
    }
    if (!update_budzet_domowy(operacjaID,amount)) {
        qDebug() << "Błąd dodawania wpisu do budżetu domowego.";
    }
    return true;
}


bool DatabaseManager::addKategoria(const QString &email, const QString &nowaKategoria){
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    if (nowaKategoria.trimmed().isEmpty()) {
        qDebug() << "Nazwa kategorii jest pusta!";
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO Kategoria (Nazwa, `Uzytkownik zalogowanyID`)
        SELECT :nazwa, ID
        FROM `Uzytkownik zalogowany`
        WHERE Email = :email
    )");

    query.bindValue(":nazwa", nowaKategoria);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania kategorii:" << query.lastError().text();
        return false;
    }

    emit nowaKategoriaDodana();  // rozesłanie informacji, żeby listy się zaktualizowały
    return true;

}

QStringList DatabaseManager::getAllKategorie() {
    QStringList kategorie;

    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return kategorie;
    }

    QSqlQuery query("SELECT Nazwa FROM Kategoria", m_db);

    if (query.exec()) {
        while (query.next()) {
            kategorie << query.value(0).toString();
        }
    } else {
        qDebug() << "Błąd pobierania kategorii:" << query.lastError().text();
    }

    return kategorie;
}
bool DatabaseManager::addCykliczny(double amount, const QDate &date, const QString &note,const QString &frequency, const QString &category){
    qDebug() << "Rozpoczęcie procesu nowego przychodu cyklicznego";
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }
    if(amount==0){
        qDebug() << "Nie można dodać zerowej wartości\n";
        return false;
    }
    if(frequency.isEmpty()){
        qDebug()<< "Brak częstotliwości";
    }
    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO `Operacja cykliczna` 
        (Kwota, Data, Notatka, Czestotliwosc, `Uzytkownik zalogowanyID`, `Kategoria Nazwa`)
        VALUES (:kwota, :data, :notatka, :czestotliwosc, :uzytkownikID, :kategoria)
    )");

    query.bindValue(":kwota", amount);
    query.bindValue(":data", date);
    query.bindValue(":notatka", note);
    query.bindValue(":czestotliwosc", frequency);
    query.bindValue(":uzytkownikID", logged_user_ID);
    query.bindValue(":kategoria", category);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania operacji cyklicznej:" << query.lastError().text();
        return false;
    }
    return true;
}   
bool DatabaseManager::changeCykliczny(int ID_cykl,double amount, const QDate &date, const QString &note, const QString &frequency,const QString &category){
    return true;
}
bool DatabaseManager::changePassword(const QString &newPass) {
    if (!m_db.isOpen()) {
        qDebug() << "Baza nie jest otwarta!";
        return false;
    }
    QSqlQuery query(m_db);
    query.prepare("UPDATE `Uzytkownik zalogowany` SET Haslo = :newPass WHERE ID = :userID");
    query.bindValue(":newPass", newPass);
    query.bindValue(":userID", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd podczas zmiany hasła:" << query.lastError().text();
        return false;
    }

    return true;
}
bool DatabaseManager::changeStatusUser(int ID_user) {
    if (!m_db.isOpen()) {
        qDebug() << "Baza nie jest otwarta!";
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare("SELECT `Czy_zablokowany` FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", ID_user);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania SELECT:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        qDebug() << "Nie znaleziono użytkownika o ID:" << ID_user;
        return false;
    }

    int currentStatus = query.value(0).toInt();
    qDebug()<< "Stary status zablokowania: "<<currentStatus;
    int newStatus = (currentStatus == 0) ? 1 : 0;
    qDebug()<< "Próba nowego statusu zablokowania: "<<newStatus;

    query.prepare("UPDATE `Uzytkownik zalogowany` SET `Czy_zablokowany` = :newStatus WHERE ID = :id");
    query.bindValue(":newStatus", newStatus);
    query.bindValue(":id", ID_user);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania UPDATE:" << query.lastError().text();
        return false;
    }

    return true;
}
bool DatabaseManager::generateReport(){
    return true;
}
void DatabaseManager::set_logged_user(int ID){
    logged_user_ID = ID;
}
int DatabaseManager::get_user_ID(){
    return logged_user_ID;
}
bool DatabaseManager::amI_admin(){
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    if (logged_user_ID <= 0) {
        qDebug() << "Nieprawidłowy ID użytkownika!";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania SQL:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString rola = query.value("Rola").toString().toLower();
        return (rola == "admin");
    }

    qDebug()<<"User not admin";
    return false;
}
bool DatabaseManager::deleteCykliczny(int ID){
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("DELETE FROM `Operacja cykliczna` WHERE ID = :id");
    query.bindValue(":id", ID);

    if (!query.exec()) {
        qDebug() << "Błąd usuwania operacji cyklicznej:" << query.lastError().text();
        return false;
    }
    return true;
}
void DatabaseManager::reload_whole_budzet() {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return;
    }
    QSqlQuery query(m_db);

    query.prepare("SELECT `Kwota` FROM `Budzet domowy` ORDER BY `ID` DESC LIMIT 1");

    if (!query.exec()) {
        qDebug() << "Błąd zapytania SELECT:" << query.lastError().text();
        return;
    }
    if (query.next()) {
        whole_budzet = query.value(0).toDouble();
        qDebug() << "Najnowsza kwota budżetu domowego:" << whole_budzet;
    } else {
        whole_budzet=0;
        qDebug() << "Brak wpisów w tabeli 'Budzet domowy'";
    }
}
double DatabaseManager::get_whole_budzet(){
    return whole_budzet;
}
bool DatabaseManager::update_budzet_domowy(int ID_operacji, double kwota){
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }
    double nowaKwota = whole_budzet + kwota; 

    QSqlQuery insertQuery(m_db);
    insertQuery.prepare(R"(
        INSERT INTO `Budzet domowy` (`Kwota`, `OperacjaID`)
        VALUES (:kwota, :operacjaID)
    )");
    insertQuery.bindValue(":kwota", nowaKwota);
    insertQuery.bindValue(":operacjaID", ID_operacji);

    if (!insertQuery.exec()) {
        qDebug() << "Błąd podczas dodawania wpisu do Budzet domowy:" << insertQuery.lastError().text();
        return false;
    }
    reload_whole_budzet();
    return true;
}
QDate DatabaseManager::get_update_Date() {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return QDate();
    }

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT o.Data 
        FROM `Budzet domowy` b
        JOIN `Operacja` o ON b.OperacjaID = o.ID
        ORDER BY b.ID DESC
        LIMIT 1
    )");

    if (!query.exec()) {
        qDebug() << "Błąd zapytania get_update_Date:" << query.lastError().text();
        return QDate();
    }

    if (query.next()) {
        return query.value(0).toDate();
    }

    return QDate(); // pusty obiekt jeśli brak wyniku
}