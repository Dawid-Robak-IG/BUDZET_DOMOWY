#ifndef TAB_RELACJE_HPP
#define TAB_RELACJE_HPP

#include "DatabaseManager.hpp"

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
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QVariant>
#include <QWidget>

class Tab_Relacje : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Relacje(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

signals:

    private slots:
    void PrzypiszRodzicaClicked();
    void Przypisz2RodzicaClicked();

private:
    QString m_userEmail;
    QTableView *dzieciTable = nullptr;
    QTableView *rodziceTable = nullptr;
    QSqlRelationalTableModel *dzieciModelUsers = nullptr;
    QSqlTableModel *rodziceModelUsers = nullptr;

    QPushButton *dodajRelacjeButton = nullptr;
    QPushButton *dodaj2RelacjeButton = nullptr;
    DatabaseManager *m_dbManager = nullptr;

    void showTables();
};

#endif // TAB_RELACJE_HPP
