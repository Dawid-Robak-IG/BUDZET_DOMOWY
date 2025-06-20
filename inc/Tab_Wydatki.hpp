#ifndef TAB_WYDATKI_HPP
#define TAB_WYDATKI_HPP
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

class Tab_Wydatki : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Wydatki(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

signals:
    void daneZmienione();

private slots:
    void DodajWydatekClicked();

private:
    QString m_userEmail;

    QDoubleSpinBox *kwotaSpinBox = nullptr;
    QLineEdit *opisLineEdit = nullptr;
    QDateEdit *dataEdit = nullptr;
    QComboBox *kategoriaCombo = nullptr;
    QPushButton *dodajWydatekButton = nullptr;

    DatabaseManager* m_dbManager = nullptr;

    void loadKategorie();
};

#endif // TAB_WYDATKI_HPP
