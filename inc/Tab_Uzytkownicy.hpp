#ifndef TAB_UZYTKOWNICY_HPP
#define TAB_UZYTKOWNICY_HPP

#include "BlockedDelegate.hpp"
#include "ComboBoxDelegate.hpp"
#include "DatabaseManager.hpp"
#include "PasswordDelegate.hpp"

#include <QCheckBox>
#include <QComboBox>
#include <QDebug>
#include <QHeaderView>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlError>
#include <QSqlTableModel>
#include <QStackedWidget>
#include <QTableView>
#include <QWidget>

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
    QTableView *tabelaTableView = nullptr;
    QSqlTableModel *modelUsers = nullptr;
    QStackedWidget *stacked = nullptr;

    QCheckBox *checkBox_pokazHasla = nullptr;
    QPushButton *blokadaButton = nullptr;
    QPushButton *edytujButton = nullptr;
    QPushButton *powrotButton = nullptr;
    QPushButton *zapiszZmianyButton = nullptr;
    QComboBox *rolaCombo = nullptr;
    QLineEdit *imie = nullptr;
    QLineEdit *nazwisko = nullptr;
    QLineEdit *mail = nullptr;

    DatabaseManager *m_dbManager = nullptr;

    void setupModel();
};

#endif // TAB_UZYTKOWNICY_HPP
