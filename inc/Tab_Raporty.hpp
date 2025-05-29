#ifndef TAB_RAPORTY_HPP
#define TAB_RAPORTY_HPP

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
#include <QCheckBox>

#include "../inc/RaportWindow.hpp"


class Tab_Raporty : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Raporty(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
signals:

private slots:
    void GenerujRaportClicked();
    void GenerujMyRaportClicked();
    void GenerujRaportOsobistyAdminClicked();

private:
    QString m_userEmail;

    QDateEdit *startDataEdit;
    QDateEdit *stopDataEdit;
    QPushButton *generujRaportButton;
    QPushButton *generujRaportOsobisty;

    QPushButton *generujRaportOsobistyAdmin;
    QComboBox *comboKategoriaRaport;
    QCheckBox* checkBoxKategoria;
    QComboBox * comboUserAdminRaport;
    DatabaseManager* m_dbManager = nullptr;

    void loadUżytkownicy();
    void loadKategorie();
};

#endif // TAB_RAPORTY_HPP
