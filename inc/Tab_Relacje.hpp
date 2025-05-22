#ifndef TAB_RELACJE_HPP
#define TAB_RELACJE_HPP

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

class Tab_Relacje : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Relacje(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

signals:

    private slots:
    void PrzypiszRodzicaClicked();

    private:
    QString m_userEmail;
         QTableView *dzieciTable;
        QTableView *rodziceTable;
        QSqlTableModel* dzieciModelUsers;
         QSqlTableModel* rodziceModelUsers;

         QPushButton *dodajRelacjeButton;
         DatabaseManager* m_dbManager = nullptr;

      void showTables();
};

#endif // TAB_RELACJE_HPP
