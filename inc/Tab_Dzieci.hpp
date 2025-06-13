#ifndef TAB_DZIECI_HPP
#define TAB_DZIECI_HPP

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
#include <QTableView>
#include <QSqlTableModel>
#include <QInputDialog>

class Tab_Dzieci : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Dzieci(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

    void loadDzieciListComboBox();

signals:
private slots:
    void GenerujRaportClicked();
    void ZmienKieszonkoweClicked();

private:
    QString m_userEmail;

    // QTableView *kieszonkoweTable;
    // QSqlTableModel* modelUsers; //potrzebne do tabelki

    QLineEdit *aktualneSaldoLineEdit;
    QLineEdit *aktualneKieszonkoweLineEdit;

    QPushButton *generujRaportButton;
    QPushButton *zmienKieszonkoweButton;
    QComboBox *listaDzieciCombo;
    QLineEdit *nastepneKieszonkoweLineEdit;
    DatabaseManager* m_dbManager = nullptr;

    void showTable();

    void onDzieckoSelected(int index);
    void updateSaldoIKieszonkoweLabel(int childID);
};


#endif // TAB_DZIECI_HPP
