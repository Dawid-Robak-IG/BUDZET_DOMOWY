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


class Tab_Kategorie : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Kategorie(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);


private slots:
    void DodajKategorieClicked();

private:
    QString m_userEmail;

    QLineEdit *nowaKategoriaLineEdit;
    QPushButton *dodajKategorieButton;
    QComboBox *kategoriaCombo;

    DatabaseManager* m_dbManager = nullptr;

    void loadKategorie();
};

#endif // TAB_KATEGORIE_HPP
