#ifndef TAB_CYKLICZNEW_HPP
#define TAB_CYKLICZNEW_HPP

#include "DatabaseManager.hpp"
#include "ComboBoxDelegate.hpp"

#include <QComboBox>
#include <QDateEdit>
#include <QDebug>
#include <QDoubleSpinBox>
#include <QHeaderView>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QStackedWidget>
#include <QTableView>
#include <QVariant>
#include <QWidget>

class Tab_CykliczneW : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_CykliczneW(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
    void showTable();
    void goToStartPage();
    void setTableStrategy();
signals:

private slots:
    void DodajCW_Clicked();
    // void EdytujCW_Clicked();
    void UsunCW_Clicked();

private:
    QString m_userEmail;

    QStackedWidget *stacked = nullptr;
    QTableView *cykliczneWTable = nullptr;
    // QPushButton *edytujCW_Button;
    QPushButton *nowyCW_Button = nullptr;
    QPushButton *usunCW_Button = nullptr;
    QComboBox *kategoriaCombo = nullptr;
    QComboBox *czestotliwoscCombo = nullptr;
    QDateEdit *startCW_Data = nullptr;
    QDoubleSpinBox *kwotaCW = nullptr;
    QPushButton *powrotCW_Button = nullptr;
    QPushButton *dodajCW_Button = nullptr;
    QLineEdit *notatkaCW_LineEdit = nullptr;

    QSqlRelationalTableModel *modelUsers = nullptr; //potrzebne do tabelki
    DatabaseManager* m_dbManager = nullptr;
    void loadKategorie();
    void reset_Tab();
};

#endif // TAB_CYKLICZNEW_HPP
