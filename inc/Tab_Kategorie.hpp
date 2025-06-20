#ifndef TAB_KATEGORIE_HPP
#define TAB_KATEGORIE_HPP

#include "DatabaseManager.hpp"


#include <QWidget>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QMessageBox>
#include <QTableView>
#include <QSqlTableModel>


class Tab_Kategorie : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Kategorie(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

 // void setTableStrategy();
 // void showTable();

private slots:
    void DodajKategorieClicked();
    void UsunKategorieClicked();

private:
    QString m_userEmail;

   // QTableView *tabelaKategorie;
   // QSqlTableModel* modelUsersX;

    QLineEdit *nowaKategoriaLineEdit = nullptr;
    QPushButton *dodajKategorieButton = nullptr;
    QPushButton *usunKategorieButton = nullptr;
    QComboBox *kategoriaCombo = nullptr;

    DatabaseManager* m_dbManager = nullptr;

    void loadKategorie();

};

#endif // TAB_KATEGORIE_HPP
