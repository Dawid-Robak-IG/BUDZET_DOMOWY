#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDate>

class DatabaseManager : public QObject
{
    Q_OBJECT
    int logged_user_ID;
    double whole_budzet;
public:
    void set_logged_user(int ID);
    int get_user_ID();

    explicit DatabaseManager(QObject *parent = nullptr);
      ~DatabaseManager();

    bool openConnection();
    void closeConnection();

    QSqlDatabase getDatabase() const {return m_db;}
    QStringList getAllKategorie();

    //zarządzanie tablicami bazy danych
    bool addWydatek(const QString &email, double amount, const QDate &date, const QString &note, const QString &category);
    bool addPrzychod(const QString &email, double amount, const QDate &date, const QString &note, const QString &category);
    bool addKategoria(const QString &email, const QString &nowaKategoria);

    bool addCykliczny(double amount, const QDate &date, const QString &note, const QString &frequency, const QString &category);
    bool changeCykliczny(int ID_cykl,double amount, const QDate &date, const QString &note, const QString &frequency, const QString &category);
    bool changePassword(const QString &newPass);
    bool changeStatusUser(int ID_user);
    bool generateReport();
    bool amI_admin();
    bool deleteCykliczny(int ID);
    void reload_whole_budzet();
    double get_whole_budzet();
    QDate get_update_Date();
    bool addRelation(int IDchild, int IDparent1, int IDparent2);
    bool addFirstParent(int IDchild, int IDparent1);
    bool addSecondParent(int IDchild, int IDparent2);
    bool update_Children();
    bool deleteCategory(const QString &nazwa);


    bool amIChild();
    float get_kieszonkowe();
    float get_saldo();
    
    QPair<QVector<QDate>, QVector<double>> getBudzetData(const QDate& startDate, const QDate& endDate);

signals:
    void nowaKategoriaDodana();

private:
     QSqlDatabase m_db;

    bool update_budzet_domowy(int ID_operacji, double kwota);
};

#endif // DATABASEMANAGER_HPP
