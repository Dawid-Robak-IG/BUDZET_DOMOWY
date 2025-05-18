#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
      ~DatabaseManager();

    bool openConnection();
    void closeConnection();


    QSqlDatabase getDatabase() const {return m_db;}

    //QSqlQuery getExpenses();


    //zarządzanie tablicami bazy danych

    bool addWydatek(const QString &email, double amount, const QDate &date, const QString &note, const QString &category);
    bool addCategory(const QString &categoryName);
signals:

private:
     QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_HPP
