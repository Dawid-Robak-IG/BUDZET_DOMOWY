#ifndef TAB_BUDZET_HPP
#define TAB_BUDZET_HPP

#include "CyklicznyDelegate.hpp"
#include "DatabaseManager.hpp"
#include "KwotaColorDelegate.hpp"

#include <QDebug>
#include <QHeaderView>
#include <QLineEdit>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>

class Tab_Budzet : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Budzet(QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
    void loadOperacjeTable();
signals:

public slots:
    void refresh();

private:
    QLineEdit *dataBudzet = nullptr;
    QLineEdit *kwotaBudzet = nullptr;
    QTableView *tabelaOperacje = nullptr;
    QSqlRelationalTableModel *modelOperacje = nullptr;

    DatabaseManager* m_dbManager = nullptr;
};

#endif // TAB_BUDZET_HPP
