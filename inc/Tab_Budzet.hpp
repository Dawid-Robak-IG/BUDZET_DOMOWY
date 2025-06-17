#ifndef TAB_BUDZET_HPP
#define TAB_BUDZET_HPP

#include "CyklicznyDelegate.hpp"
#include "DatabaseManager.hpp"
#include "KwotaColorDelegate.hpp"

#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRelationalTableModel>

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
    QLineEdit *dataBudzet;
    QLineEdit *kwotaBudzet;
    QTableView *tabelaOperacje;
    QSqlRelationalTableModel* modelOperacje;

    DatabaseManager* m_dbManager = nullptr;
};

#endif // TAB_BUDZET_HPP
