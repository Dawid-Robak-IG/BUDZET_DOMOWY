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
    void loadUżytkownicy();
    void loadKategorie();
signals:

private slots:
    void GenerujRaportClicked();
    void GenerujMyRaportClicked();
    void GenerujRaportOsobistyAdminClicked();
    void GenerujPrognozyBudzetClicked();
    void GenerujPrognozyMyBudzetClicked();
    void GenerujPrognozyAdminClicked();

private:
    QString m_userEmail;

    QDateEdit *startDataEdit = nullptr;
    QDateEdit *stopDataEdit = nullptr;
    QPushButton *generujRaportButton = nullptr;
    QPushButton *generujRaportOsobisty = nullptr;

    QPushButton *generujRaportOsobistyAdmin = nullptr;
    QComboBox *comboKategoriaRaport = nullptr;
    QCheckBox *checkBoxKategoria = nullptr;
    QComboBox *comboUserAdminRaport = nullptr;

    QComboBox *comboPrognozyOsobiste = nullptr;
    QPushButton *generujPrognozyAdmin = nullptr;
    QPushButton *generujPrognozyBudżet = nullptr;
    QPushButton *generujMojePrognozy = nullptr;
    QDateEdit *dataPrognozy = nullptr;

    DatabaseManager* m_dbManager = nullptr;

};

#endif // TAB_RAPORTY_HPP
