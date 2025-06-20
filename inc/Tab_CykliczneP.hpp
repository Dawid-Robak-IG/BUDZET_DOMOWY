#ifndef TAB_CYKLICZNEP_HPP
#define TAB_CYKLICZNEP_HPP

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

class Tab_CykliczneP : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_CykliczneP(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
    void showTable();
    void goToStartPage();
    void setTableStrategy();
signals:

private slots:
    void DodajCP_Clicked();
    //void EdytujCP_Clicked();
    void UsunCP_Clicked();

private:
    QString m_userEmail;

    QStackedWidget *stacked = nullptr;
    QTableView *cyklicznePTable = nullptr;
    //  QPushButton *edytujCP_Button;
    QPushButton *nowyCP_Button = nullptr;
    QPushButton *usunCP_Button = nullptr;
    QComboBox *kategoriaCombo = nullptr;
    QComboBox *czestotliwoscCombo = nullptr;
    QDateEdit *startCP_Data = nullptr;
    QDoubleSpinBox *kwotaCP = nullptr;
    QPushButton *powrotCP_Button = nullptr;
    QPushButton *dodajCP_Button = nullptr;
    QLineEdit *notatkaCP_LineEdit = nullptr;

    QSqlRelationalTableModel *modelUsers = nullptr; //potrzebne do tabelki
    DatabaseManager* m_dbManager = nullptr;

    void loadKategorie();
    void reset_Tab();
};


#endif // TAB_CYKLICZNEP_HPP
