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

class Tab_Wydatki : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Wydatki(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);

    void setDatabaseManager(DatabaseManager* dbManager) { m_dbManager = dbManager;}
signals:

private slots:
    void KwotaChanged(double value);
    void DodajWydatekClicked();

private:
    QString m_userEmail;

    QDoubleSpinBox *kwotaSpinBox;
    QLineEdit *opisLineEdit;
    QDateEdit *dataEdit;
    QComboBox *kategoriaCombo;
    QPushButton *dodajWydatekButton;

    DatabaseManager* m_dbManager = nullptr;
};

#endif // TAB_WYDATKI_HPP
