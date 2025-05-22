#ifndef TAB_UZYTKOWNICY_HPP
#define TAB_UZYTKOWNICY_HPP

#include "DatabaseManager.hpp"

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>

class Tab_Uzytkownicy : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Uzytkownicy(QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
signals:

private:
    QTableView *tabelaTableView;
    QSqlTableModel* modelUsers;
    DatabaseManager* m_dbManager = nullptr;

 void setupModel();
};

#endif // TAB_UZYTKOWNICY_HPP
