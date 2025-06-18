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

    if(amIChild()){
        if(update_my_saldo(-amount)){
            qDebug() << "Zaaktualizowano saldo dla zalogwanego dziecka";
        } else{
            qDebug() << "Nie udało się zaaktualizować salda dla zalogwanego dziecka";
        }
        return true;
    } // żeby nie dodawać do budzetu domowego już

    int operacjaID = query.lastInsertId().toLongLong();

    create_new_Budzet_Domowy(operacjaID,-amount);
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

    if(amIChild()){
        if(update_my_saldo(amount)){
            qDebug() << "Zaaktualizowano saldo dla zalogwanego dziecka";
        } else{
            qDebug() << "Nie udało się zaaktualizować salda dla zalogwanego dziecka";
        }
        return true;
    } // żeby nie dodawać do budzetu domowego już

    int operacjaID = query.lastInsertId().toLongLong();

    create_new_Budzet_Domowy(operacjaID,amount);
    return true;
}
bool DatabaseManager::create_new_Budzet_Domowy(int operacjaID, double amount){
    if (!update_budzet_domowy(operacjaID, amount)) {
        qDebug() << "Błąd dodawania wpisu do budżetu domowego.";
        return false;
    }
    return true;
}

bool DatabaseManager::update_budzet_domowy(int ID_operacji, double kwota) {
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

    QDate dataKolejna = date;
    if (frequency == "Codziennie")
        dataKolejna = date.addDays(1);
    else if (frequency == "Co tydzień")
        dataKolejna = date.addDays(7);
    else if (frequency == "Co miesiąc")
        dataKolejna = date.addMonths(1);
    else if (frequency == "Co rok")
        dataKolejna = date.addYears(1);
    else {
        qDebug() << "Nieznana częstotliwość:" << frequency;
        return false;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO `Operacja cykliczna` 
        (Kwota, Data,DataKolejna, Notatka, Czestotliwosc, `Uzytkownik zalogowanyID`, `Kategoria`)
        VALUES (:kwota, :data,:datKolejna ,:notatka, :czestotliwosc, :uzytkownikID, :kategoria)
    )");

    query.bindValue(":kwota", amount);
    query.bindValue(":data", date);
    query.bindValue(":notatka", note);
    query.bindValue(":czestotliwosc", frequency);
    query.bindValue(":uzytkownikID", logged_user_ID);
    query.bindValue(":kategoria", category);
    query.bindValue(":datKolejna", dataKolejna);

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
QDate DatabaseManager::get_my_last_update_Date() {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return QDate();
    }

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT o.Data 
        FROM `Operacja` o
        WHERE `Uzytkownik zalogowanyID` = :id
    )");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania get_update_Date:" << query.lastError().text();
        return QDate();
    }

    if (query.next()) {
        return query.value(0).toDate();
    }

    return QDate(); // pusty obiekt jeśli brak wyniku
}
bool DatabaseManager::addRelation(int IDchild, int IDparent1, int IDparent2){
    bool success = false;
    if(IDparent1!=-1){
        if(addFirstParent(IDchild,IDparent1)){
            qDebug()<< "Dodano pierwszego rodzica";
            success = true;
        }
    }
    if(IDparent2!=-1){
        if(addSecondParent(IDchild,IDparent2)){
            qDebug()<< "Dodano drugiego rodzica";
            success = true;
        }
    }
    return success;
}
bool DatabaseManager::addFirstParent(int IDchild, int IDparent1) {
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare(R"(
        UPDATE Dziecko
        SET ID_Rodzic1 = :id_rodzica
        WHERE `Uzytkownik zalogowanyID` = :id_dziecka
    )");

    query.bindValue(":id_rodzica", IDparent1);
    query.bindValue(":id_dziecka", IDchild);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania Rodzica1:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::addSecondParent(int IDchild, int IDparent2) {
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare(R"(
        UPDATE Dziecko
        SET ID_Rodzic2 = :id_rodzica
        WHERE `Uzytkownik zalogowanyID` = :id_dziecka
    )");

    query.bindValue(":id_rodzica", IDparent2);
    query.bindValue(":id_dziecka", IDchild);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania Rodzica2:" << query.lastError().text();
        return false;
    }

    return true;
}
bool DatabaseManager::update_Children() {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return false;
    }

    QSqlQuery selectQuery(m_db);
    selectQuery.prepare(R"(
        SELECT ID FROM `Uzytkownik zalogowany`
        WHERE Rola = 'Dziecko' AND ID NOT IN (
            SELECT `Uzytkownik zalogowanyID` FROM Dziecko
        )
    )");

    if (!selectQuery.exec()) {
        qDebug() << "Błąd pobierania dzieci do dodania:" << selectQuery.lastError().text();
        return false;
    }

    QSqlQuery insertQuery(m_db);
    int dodano = 0;

    while (selectQuery.next()) {
        int userId = selectQuery.value(0).toInt();

        QDate today = QDate::currentDate();
        QDate nextPocketMoneyDate = QDate(today.year(), today.month(), 1).addMonths(1);

        insertQuery.prepare(R"(
            INSERT INTO Dziecko (`Uzytkownik zalogowanyID`,Saldo,Kieszonkowe,DataKolejnaKieszonkowego)
            VALUES (:id,:saldo,:kiesz,:datKol)
        )");
        insertQuery.bindValue(":id", userId);
        insertQuery.bindValue(":saldo", 0);
        insertQuery.bindValue(":kiesz", 0);
        insertQuery.bindValue(":datKol", nextPocketMoneyDate);

        if (!insertQuery.exec()) {
            qDebug() << "Błąd dodawania dziecka (ID:" << userId << "):" << insertQuery.lastError().text();
            continue;
        }
        ++dodano;
    }

    qDebug() << "Dodano nowych dzieci:" << dodano;
    return true;
}

bool DatabaseManager::amIChild() {
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd sprawdzania roli:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString role = query.value(0).toString();
        if(role == "Admin" || role=="Rodzic" || role=="Dorosly"){
            return false;
        } else{
            return true;
        }
    }

    return false;
}
bool DatabaseManager::amI_Noone(){
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd sprawdzania roli:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString role = query.value(0).toString();
        if(role == "Admin" || role=="Rodzic" || role=="Dorosly" || role=="Dziecko"){
            return false;
        } else{
            return true;
        }
    }

    return false;
}
float DatabaseManager::get_kieszonkowe(int child_ID) {
    if (!m_db.isOpen()) return -1.0f;

    QSqlQuery query(m_db);
    query.prepare("SELECT kieszonkowe FROM Dziecko WHERE `Uzytkownik zalogowanyID` = :id");
    query.bindValue(":id", child_ID);

    if (!query.exec()) {
        qDebug() << "Błąd pobierania kieszonkowego:" << query.lastError().text();
        return -1.0f;
    }

    if (query.next()) {
        return query.value(0).toFloat();
    }
    return -1.0f;
}
float DatabaseManager::get_saldo(int child_ID) {
    if (!m_db.isOpen()) return -1.0f;

    QSqlQuery query(m_db);
    query.prepare("SELECT Saldo FROM Dziecko WHERE `Uzytkownik zalogowanyID` = :id");
    query.bindValue(":id", child_ID);

    if (!query.exec()) {
        qDebug() << "Błąd pobierania kieszonkowego:" << query.lastError().text();
        return -1.0f;
    }

    if (query.next()) {
        return query.value(0).toFloat();
    }
    return -1.0f;
}

QDate DatabaseManager::get_date_next_kieszonkowe(int child_ID)
{
    if (!m_db.isOpen())
        return QDate();

    QSqlQuery query(m_db);
    query.prepare(
        "SELECT DataKolejnaKieszonkowego FROM Dziecko WHERE `Uzytkownik zalogowanyID` = :id");
    query.bindValue(":id", child_ID);

    if (!query.exec()) {
        qDebug() << "Błąd pobierania kieszonkowego:" << query.lastError().text();
        return QDate();
    }

    if (query.next()) {
        return query.value(0).toDate();
    }

    return QDate();
}

QPair<QVector<QDate>, QVector<double>> DatabaseManager::getBudzetData(const QDate& startDate, const QDate& endDate, const QString& category) {
    QVector<QDate> dates;
    QVector<double> values;

    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return {dates, values};
    }

    QString queryStr = R"(
    SELECT Data, `Budzet domowy`.Kwota 
    FROM `Budzet domowy`
    JOIN Operacja ON `Budzet domowy`.OperacjaID = Operacja.ID
    WHERE Data BETWEEN :startDate AND :endDate
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += " ORDER BY Data ASC";

    QSqlQuery query(m_db);
    query.prepare(queryStr);

    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);
    if (!category.isEmpty()) {
        query.bindValue(":cat", category);
    }

    if (!query.exec()) {
        qDebug() << "Błąd pobierania danych budzet domowy:" << query.lastError().text();
        return {dates, values};
    }

    while (query.next()) {
        dates.append(query.value(0).toDate());
        values.append(query.value(1).toDouble());
    }

    return {dates, values};
}
bool DatabaseManager::deleteCategory(const QString &nazwa) {
    if (!m_db.isOpen()) {
        qWarning() << "Baza danych nie jest otwarta!";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare("DELETE FROM Kategoria WHERE Nazwa = :nazwa");
    query.bindValue(":nazwa", nazwa);

    if (!query.exec()) {
        qWarning() << "Błąd usuwania kategorii:" << query.lastError().text();
        return false;
    }
    emit nowaKategoriaDodana();
    return query.numRowsAffected() > 0;
}
bool DatabaseManager::update_my_saldo(double amount) {
    if (!m_db.isOpen()) {
        qWarning() << "Baza danych nie jest otwarta!";
        return false;
    }

    if (logged_user_ID == -1) {
        qWarning() << "Brak ID zalogowanego użytkownika!";
        return false;
    }

    QSqlQuery query(m_db);
    query.prepare(R"(
        UPDATE Dziecko
        SET Saldo = Saldo + :amount
        WHERE `Uzytkownik zalogowanyID` = :id
    )");

    query.bindValue(":amount", amount);
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qWarning() << "Błąd aktualizacji salda:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}
bool DatabaseManager::change_kieszonkowe(int child_ID, float new_kieszonkowe) {
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare(R"(
        UPDATE Dziecko
        SET Kieszonkowe = :kieszonkowe
        WHERE `Uzytkownik zalogowanyID` = :id
    )");

    query.bindValue(":kieszonkowe", new_kieszonkowe);
    query.bindValue(":id", child_ID);

    return query.exec();
}

bool DatabaseManager::amIParent()
{
    if (!m_db.isOpen())
        return false;

    QSqlQuery query(m_db);
    query.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qDebug() << "Błąd sprawdzania roli:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString role = query.value(0).toString();
        if (role == "Rodzic") {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool DatabaseManager::generujZCyklicznych() {
    qDebug()<<"Generuje przychody i wydatki z cyklicznych";
    if (!m_db.isOpen()) return false;

    QSqlQuery select(m_db);
    select.prepare(R"(
        SELECT ID, `Uzytkownik zalogowanyID`, Kwota, Notatka, Czestotliwosc, Kategoria, DataKolejna
        FROM `Operacja cykliczna`
        WHERE DataKolejna <= CURDATE()
    )");

    if (!select.exec()) {
        qDebug() << "Błąd SELECT cyklicznych operacji:" << select.lastError().text();
        return false;
    }

    QSqlQuery insert(m_db);
    QSqlQuery updateCykliczna(m_db);

    while (select.next()) {
        int id = select.value("ID").toInt();
        int userId = select.value("Uzytkownik zalogowanyID").toInt();
        double kwota = select.value("Kwota").toDouble();
        QString opis = select.value("Notatka").toString();
        QString czest = select.value("Czestotliwosc").toString();
        QDate dataKolejna = select.value("DataKolejna").toDate();
        QString kategoria = select.value("Kategoria").toString();

        QDate dzis = QDate::currentDate();

        while (dataKolejna <= dzis) {
            insert.prepare(R"(
                INSERT INTO Operacja (`Uzytkownik zalogowanyID`, Kwota, Notatka, Data, czy_z_cyklicznego, `Operacja cyklicznaID`, `Kategoria Nazwa`)
                VALUES (:uid, :kwota, :opis, :data, :czy_cykl, :ID_cykl, :kat)
            )");
            insert.bindValue(":uid", userId);
            insert.bindValue(":kwota", kwota);
            insert.bindValue(":opis", opis);
            insert.bindValue(":data", dataKolejna); 
            insert.bindValue(":czy_cykl", 1);
            insert.bindValue(":ID_cykl", id);
            insert.bindValue(":kat", kategoria);

            if (!insert.exec()) {
                qDebug() << "Błąd dodawania operacji:" << insert.lastError().text();
                break; 
            }

            int operacjaID = insert.lastInsertId().toLongLong();
            if (!create_new_Budzet_Domowy(operacjaID, kwota)) {
                qDebug() << "Błąd tworzenia wpisu w budżecie domowym";
            }

            // Aktualizujemy dataKolejna o kolejny okres:
            if (czest == "Codziennie")
                dataKolejna = dataKolejna.addDays(1);
            else if (czest == "Co tydzien")
                dataKolejna = dataKolejna.addDays(7);
            else if (czest == "Co miesiąc")
                dataKolejna = dataKolejna.addMonths(1);
            else if (czest == "Co rok")
                dataKolejna = dataKolejna.addYears(1);
            else {
                qDebug() << "Nieznana częstotliwość:" << czest;
                break;
            }
        }

        updateCykliczna.prepare(R"(
            UPDATE `Operacja cykliczna` SET DataKolejna = :nowa WHERE ID = :id
        )");
        updateCykliczna.bindValue(":nowa", dataKolejna);
        updateCykliczna.bindValue(":id", id);
        if (!updateCykliczna.exec()) {
            qDebug() << "Błąd aktualizacji daty cyklicznej:" << updateCykliczna.lastError().text();
        }
    }

    qDebug()<<"Zakończono proces obsługi cyklicznych operacji";
    return true;
}
bool DatabaseManager::generujKieszonkoweDlaDzieci() {
    qDebug() << "Generuję kieszonkowe dla dzieci";

    if (!m_db.isOpen()) return false;

    QSqlQuery select(m_db);
    select.prepare(R"(
        SELECT `Uzytkownik zalogowanyID`, Kieszonkowe, DataKolejnaKieszonkowego
        FROM Dziecko
        WHERE DataKolejnaKieszonkowego IS NOT NULL AND DataKolejnaKieszonkowego <= CURDATE()
    )");

    if (!select.exec()) {
        qDebug() << "Błąd SELECT kieszonkowego dzieci:" << select.lastError().text();
        return false;
    }

    QSqlQuery update(m_db);
    QDate dzis = QDate::currentDate();

    while (select.next()) {
        int dzieckoId = select.value("Uzytkownik zalogowanyID").toInt();
        double kwota = select.value("Kieszonkowe").toDouble();
        QDate dataKolejna = select.value("DataKolejnaKieszonkowego").toDate();

        while (dataKolejna <= dzis) {
            if (!zwiekszSaldoDziecka(dzieckoId, kwota)) {
                qDebug() << "Błąd aktualizacji salda dziecka ID:" << dzieckoId;
                break;
            }
            dataKolejna = dataKolejna.addMonths(1);
        }

        update.prepare(R"(
            UPDATE Dziecko SET DataKolejnaKieszonkowego = :nowa WHERE `Uzytkownik zalogowanyID` = :id
        )");
        update.bindValue(":nowa", dataKolejna);
        update.bindValue(":id", dzieckoId);

        if (!update.exec()) {
            qDebug() << "Błąd aktualizacji daty kieszonkowego dziecka:" << update.lastError().text();
        }
    }

    qDebug() << "Zakończono proces generowania kieszonkowego dla dzieci";
    return true;
}
bool DatabaseManager::zwiekszSaldoDziecka(int dzieckoID, double kwota) {
    QSqlQuery query(m_db);
    query.prepare("UPDATE Dziecko SET Saldo = Saldo + :kwota WHERE `Uzytkownik zalogowanyID` = :id");
    query.bindValue(":kwota", kwota);
    query.bindValue(":id", dzieckoID);

    if (!query.exec()) {
        qDebug() << "Błąd aktualizacji salda dziecka:" << query.lastError().text();
        return false;
    }
    return true;
}
bool DatabaseManager::startSystemCykl(){
    if(generujZCyklicznych() && generujKieszonkoweDlaDzieci()){
        return true;
    }
    return false;
}
QPair<QVector<QDate>, QVector<double>> DatabaseManager::getMyBudzetData(const QDate& startDate, const QDate& endDate, int user_ID, const QString& category) {
    QPair<QVector<QDate>, QVector<double>> result;

    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return result;
    }

    QString queryStr = R"(
        SELECT Data, Kwota
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :userId
          AND Data BETWEEN :start AND :end
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += " ORDER BY Data ASC";

    QSqlQuery query(m_db);
    query.prepare(queryStr);

    query.bindValue(":userId", user_ID);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);
    if(!category.isEmpty()){
        query.bindValue(":cat",category);
    }

    if (!query.exec()) {
        qDebug() << "Błąd SELECT budżetu użytkownika:" << query.lastError().text();
        return result;
    }

    QMap<QDate, double> sumaDzienna;

    while (query.next()) {
        QDate data = query.value("Data").toDate();
        double kwota = query.value("Kwota").toDouble();
        sumaDzienna[data] += kwota;
    }

    // Oblicz sumę skumulowaną
    double suma = 0.0;
    for (const QDate& data : sumaDzienna.keys()) {
        suma += sumaDzienna[data];
        result.first.append(data);
        result.second.append(suma);
    }

    return result;
}
QPair<QVector<QDate>, QVector<double>> DatabaseManager::getMyPrzychody(const QDate& startDate, const QDate& endDate, int user_ID, const QString& category) {
    QPair<QVector<QDate>, QVector<double>> result;

    if (!m_db.isOpen()) return result;

    QString queryStr = R"(
        SELECT Data, SUM(Kwota)
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :uid
          AND Kwota > 0
          AND Data BETWEEN :start AND :end
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += R"(
        GROUP BY Data
        ORDER BY Data ASC
    )";
    

    QSqlQuery query(m_db);
    query.prepare(queryStr);
    query.bindValue(":uid", user_ID);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);
    if(!category.isEmpty()){
        query.bindValue(":cat",category);
    }

    if (query.exec()) {
        while (query.next()) {
            result.first.append(query.value(0).toDate());
            result.second.append(query.value(1).toDouble());
        }
    }

    return result;
}
QPair<QVector<QDate>, QVector<double>> DatabaseManager::getMyWydatki(const QDate& startDate, const QDate& endDate, int user_ID, const QString& category) {
    QPair<QVector<QDate>, QVector<double>> result;

    if (!m_db.isOpen()) return result;

    QString queryStr = R"(
        SELECT Data, SUM(Kwota)
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :uid
          AND Kwota < 0
          AND Data BETWEEN :start AND :end
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += R"(
        GROUP BY Data
        ORDER BY Data ASC
    )";

    QSqlQuery query(m_db);
    query.prepare(queryStr);
    query.bindValue(":uid", user_ID);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);
    if(!category.isEmpty()){
        query.bindValue(":cat",category);
    }

    if (query.exec()) {
        while (query.next()) {
            result.first.append(query.value(0).toDate());
            result.second.append(-1.0*query.value(1).toDouble());
        }
    }

    return result;
}
QPair<QVector<QDate>, QVector<double>> DatabaseManager::getBudzetPrzychody(const QDate& startDate, const QDate& endDate, const QString& category) {
    QPair<QVector<QDate>, QVector<double>> result;

    if (!m_db.isOpen()) return result;

    QString queryStr = R"(
        SELECT o.Data, SUM(o.Kwota)
        FROM Operacja o
        JOIN `Budzet domowy` b ON o.ID = b.OperacjaID
        WHERE o.Kwota > 0
          AND o.Data BETWEEN :start AND :end
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie dla przychodow budzetu: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += R"(
        GROUP BY o.Data
        ORDER BY o.Data ASC
    )";

    QSqlQuery query(m_db);
    query.prepare(queryStr);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);
    if(!category.isEmpty()){
        query.bindValue(":cat",category);
    }

    if (query.exec()) {
        while (query.next()) {
            result.first.append(query.value(0).toDate());
            result.second.append(query.value(1).toDouble());
        }
    } else {
        qDebug() << "Błąd zapytania getBudzetPrzychody:" << query.lastError().text();
    }

    return result;
}
QPair<QVector<QDate>, QVector<double>> DatabaseManager::getBudzetWydatki(const QDate& startDate, const QDate& endDate, const QString& category){
    QPair<QVector<QDate>, QVector<double>> result;

    if (!m_db.isOpen()) return result;

    QString queryStr = R"(
    SELECT o.Data, SUM(o.Kwota)
        FROM Operacja o
        JOIN `Budzet domowy` b ON o.ID = b.OperacjaID
        WHERE o.Kwota < 0
          AND o.Data BETWEEN :start AND :end
    )";

    if (!category.isEmpty()) {
        qDebug()<<"wykryto kategorie dla wydatkow budzetu: " <<category;
        queryStr += " AND `Kategoria Nazwa` = :cat";
    }

    queryStr += R"(
        GROUP BY o.Data
        ORDER BY o.Data 
    )";

    QSqlQuery query(m_db);
    query.prepare(queryStr);
    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);
    if(!category.isEmpty()){
        query.bindValue(":cat",category);
    }

    if (query.exec()) {
        while (query.next()) {
            result.first.append(query.value(0).toDate());
            result.second.append(-1.0*query.value(1).toDouble());
        }
    } else {
        qDebug() << "Błąd zapytania getBudzetPrzychody:" << query.lastError().text();
    }

    return result;
}
int DatabaseManager::get_ID_by_mail(QString mail) {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return -1;
    }

    QSqlQuery query(m_db);
    query.prepare(R"(
        SELECT ID FROM `Uzytkownik zalogowany`
        WHERE Email = :mail
    )");
    query.bindValue(":mail", mail);

    if (!query.exec()) {
        qDebug() << "Błąd zapytania get_ID_by_mail:" << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Nie znaleziono użytkownika o mailu:" << mail;
        return -1;
    }
}
double DatabaseManager::user_future_Budzet(int user_ID, QDate future_Date) {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return 0.0;
    }

    // 🔹 Krok 1: znajdź najstarszą datę operacji użytkownika
    QSqlQuery minDateQuery(m_db);
    minDateQuery.prepare(R"(
        SELECT MIN(Data)
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :userID
    )");
    minDateQuery.bindValue(":userID", user_ID);

    QDate historyStart;
    if (minDateQuery.exec() && minDateQuery.next()) {
        historyStart = minDateQuery.value(0).toDate();
        if (!historyStart.isValid()) {
            qDebug() << "Brak danych dla użytkownika.";
            return 0.0;
        }
    } else {
        qDebug() << "Błąd przy pobieraniu najstarszej daty operacji:" << minDateQuery.lastError().text();
        return 0.0;
    }
    qDebug()<<"Dla przewidywanego budzetu uzytkownika pierwszy znaleziony wpis (data): "<< historyStart;

    QDate today = QDate::currentDate();

    // 🔹 Krok 2: oblicz sumę i liczbę miesięcy
    QSqlQuery historyQuery(m_db);
    historyQuery.prepare(R"(
        SELECT Kwota
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :userID
          AND Data BETWEEN :startDate AND :endDate
    )");

    historyQuery.bindValue(":userID", user_ID);
    historyQuery.bindValue(":startDate", historyStart);
    historyQuery.bindValue(":endDate", today);

    if (!historyQuery.exec()) {
        qDebug() << "Błąd pobierania historii operacji:" << historyQuery.lastError().text();
        return 0.0;
    }

    double historySum = 0.0;
    while (historyQuery.next()) {
        historySum += historyQuery.value(0).toDouble();
    }

    int months = static_cast<int>(historyStart.daysTo(today) / 30)+1;
    qDebug()<<"Dla przewidywanego budzetu uzytkownika liczba miesiecy: "<< months;
    double monthlyAverage = historySum / months;
    qDebug()<<"Dla przewidywanego budzetu uzytkownika sredni zarobek na miesiac: "<< monthlyAverage;

    QSqlQuery currentQuery(m_db);
    currentQuery.prepare(R"(
        SELECT SUM(Kwota)
        FROM Operacja
        WHERE `Uzytkownik zalogowanyID` = :userID
          AND Data <= :today
    )");

    currentQuery.bindValue(":userID", user_ID);
    currentQuery.bindValue(":today", today);

    double currentBalance = 0.0;
    if (currentQuery.exec() && currentQuery.next()) {
        currentBalance = currentQuery.value(0).toDouble();
    }

    // 🔹 Krok 4: prognoza
    int futureMonths = (today.year() - future_Date.year()) * 12 + (future_Date.month() - today.month());
    futureMonths = std::max(0, futureMonths);  // zabezpieczenie przed ujemną wartością

    double futureDelta = monthlyAverage * futureMonths;
    qDebug()<<"Dla przewidywanego budzetu uzytkownika przewidywany zarobek: "<< futureDelta;

    return currentBalance + futureDelta;
}
double DatabaseManager::whole_future_Budzet(QDate future_Date) {
    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return 0.0;
    }

    QDate today = QDate::currentDate();
    QDate historyStart = today.addMonths(-6);

    QSqlQuery historyQuery(m_db);
    historyQuery.prepare(R"(
        SELECT o.Kwota
        FROM Operacja o
        JOIN `Budzet domowy` b ON o.ID = b.OperacjaID
        WHERE o.Data BETWEEN :startDate AND :endDate
    )");

    historyQuery.bindValue(":startDate", historyStart);
    historyQuery.bindValue(":endDate", today);

    if (!historyQuery.exec()) {
        qDebug() << "Błąd pobierania historii operacji (budżet domowy):" << historyQuery.lastError().text();
        return 0.0;
    }

    double historySum = 0.0;
    int count = 0;

    while (historyQuery.next()) {
        historySum += historyQuery.value(0).toDouble();
        ++count;
    }

    int months = static_cast<int>(historyStart.daysTo(today) / 30) +1;
    double monthlyAverage = historySum / months;

    QSqlQuery currentQuery(m_db);
    currentQuery.prepare(R"(
        SELECT SUM(o.Kwota)
        FROM Operacja o
        JOIN `Budzet domowy` b ON o.ID = b.OperacjaID
        WHERE o.Data <= :today
    )");

    currentQuery.bindValue(":today", today);

    double currentBalance = 0.0;
    if (currentQuery.exec() && currentQuery.next()) {
        currentBalance = currentQuery.value(0).toDouble();
    } else {
        qDebug() << "Błąd pobierania bieżącego salda (budżet domowy):" << currentQuery.lastError().text();
    }

    // Krok 3: Oszacuj przyszły budżet
    int futureMonths = (today.year() - future_Date.year()) * 12 + (future_Date.month() - today.month());
    futureMonths = std::max(0, futureMonths);

    double futureDelta = monthlyAverage * futureMonths;

    return currentBalance + futureDelta;
}


QStringList DatabaseManager::getAllUsers() {
    QStringList userEmails;

    if (!m_db.isOpen()) {
        qDebug() << "Baza danych nie jest otwarta!";
        return userEmails;
    }

    QSqlQuery query("SELECT Email FROM `Uzytkownik zalogowany`", m_db);

    if (query.exec()) {
        while (query.next()) {
            userEmails << query.value(0).toString();
        }
    } else {
        qDebug() << "Błąd pobierania email:" << query.lastError().text();
    }

    return userEmails;
}

QString DatabaseManager::get_mail() {
    if (!m_db.isOpen()) {
        qWarning() << "Baza danych nie jest otwarta!";
        return "!BD";
    }

    QSqlQuery query(m_db);
    query.prepare("SELECT Email FROM `Uzytkownik zalogowany` WHERE ID = :id");
    query.bindValue(":id", logged_user_ID);

    if (!query.exec()) {
        qWarning() << "Błąd pobierania maila:" << query.lastError().text();
        return "!BD";
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        qWarning() << "Nie znaleziono użytkownika o ID:" << logged_user_ID;
        return "!BD";
    }
}