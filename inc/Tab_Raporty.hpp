#ifndef TAB_RAPORTY_HPP
#define TAB_RAPORTY_HPP

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

#include "../inc/RaportWindow.hpp"


class Tab_Raporty : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Raporty(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);
signals:

private slots:
    void GenerujRaportClicked();
    void GenerujMyRaportClicked();

private:
    QString m_userEmail;

    QDateEdit *startDataEdit;
    QDateEdit *stopDataEdit;
    QPushButton *generujRaportButton;

    DatabaseManager* m_dbManager = nullptr;
};

#endif // TAB_RAPORTY_HPP
