#include "../inc/DatabaseManager.hpp"
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject{parent}
{
    if (!openConnection()) {
        QMessageBox::warning(nullptr, "Uwaga", "Nie udało się połączyć z bazą danych. Niektóre funkcje mogą nie działać poprawnie.");

    }
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

bool DatabaseManager::addWydatek(const QString &email, double amount, const QDate &date, const QString &note, const QString &category)
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

    query.bindValue(":kwota", -amount);
    query.bindValue(":data", date);
    query.bindValue(":notatka", note.isEmpty() ? QVariant(QVariant::String) : note);
    query.bindValue(":kategoria", category);
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Błąd dodawania wydatku:" << query.lastError().text();
        return false;
    }

    return true;}


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

    return true;}


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
