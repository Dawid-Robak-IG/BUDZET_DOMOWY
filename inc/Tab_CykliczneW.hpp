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
    void EdytujCW_Clicked();
    void UsunCW_Clicked();

private:
    QString m_userEmail;

    QStackedWidget *stacked;
    QTableView *cykliczneWTable;
    QPushButton *edytujCW_Button;
    QPushButton *nowyCW_Button;
    QPushButton *usunCW_Button;
    QComboBox *kategoriaCombo;
    QComboBox *czestotliwoscCombo;
    QDateEdit *startCW_Data;
    QDoubleSpinBox *kwotaCW;
    QPushButton *powrotCW_Button;
    QPushButton *dodajCW_Button;
    QLineEdit *notatkaCW_LineEdit;

    QSqlTableModel* modelUsers; //potrzebne do tabelki
    DatabaseManager* m_dbManager = nullptr;
    void loadKategorie();
    void reset_Tab();
};

#endif // TAB_CYKLICZNEW_HPP
