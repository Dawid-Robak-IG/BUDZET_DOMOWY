#ifndef TAB_CYKLICZNEP_HPP
#define TAB_CYKLICZNEP_HPP

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
    void EdytujCP_Clicked();
    void UsunCP_Clicked();

private:
    QString m_userEmail;

    QStackedWidget *stacked;
    QTableView *cyklicznePTable;
    //  QPushButton *edytujCP_Button;
    QPushButton *nowyCP_Button;
    QPushButton *usunCP_Button;
    QComboBox *kategoriaCombo;
    QComboBox *czestotliwoscCombo;
    QDateEdit *startCP_Data;
    QDoubleSpinBox *kwotaCP;
    QPushButton *powrotCP_Button;
    QPushButton *dodajCP_Button;
    QLineEdit *notatkaCP_LineEdit;

    QSqlTableModel* modelUsers; //potrzebne do tabelki
    DatabaseManager* m_dbManager = nullptr;

    void loadKategorie();
    void reset_Tab();
};


#endif // TAB_CYKLICZNEP_HPP
