#ifndef TAB_UZYTKOWNICY_HPP
#define TAB_UZYTKOWNICY_HPP

#include "BlockedDelegate.hpp"
#include "ComboBoxDelegate.hpp"
#include "DatabaseManager.hpp"
#include "PasswordDelegate.hpp"

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
#include <QCheckBox>

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
