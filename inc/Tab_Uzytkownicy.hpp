#ifndef TAB_UZYTKOWNICY_HPP
#define TAB_UZYTKOWNICY_HPP

#include "DatabaseManager.hpp"

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QPushButton>
#include <QComboBox>
#include <QStackedWidget>
#include <QLineEdit>
#include <QMessageBox>

class Tab_Uzytkownicy : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Uzytkownicy(QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
    void goToStartPage();
    void setTableStrategy();

signals:
private slots:
    void BlokadaClicked();
    void ZapiszZmianyClicked();

private:
    QTableView *tabelaTableView;
    QSqlTableModel* modelUsers;
    QStackedWidget *stacked;

    QPushButton* blokadaButton;
    QPushButton* edytujButton;
    QPushButton* powrotButton;
    QPushButton* zapiszZmianyButton;
    QComboBox* rolaCombo;
    QLineEdit* imie;
    QLineEdit* nazwisko;
    QLineEdit* mail;

    DatabaseManager* m_dbManager = nullptr;

    void setupModel();
};

#endif // TAB_UZYTKOWNICY_HPP
