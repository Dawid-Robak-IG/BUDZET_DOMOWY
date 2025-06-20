#ifndef TAB_CYKLICZNEW_HPP
#define TAB_CYKLICZNEW_HPP

#include "DatabaseManager.hpp"
#include "ComboBoxDelegate.hpp"

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
#include <QStackedWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>

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
