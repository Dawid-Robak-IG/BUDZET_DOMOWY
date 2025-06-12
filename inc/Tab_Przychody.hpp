#ifndef TAB_PRZYCHODY_HPP
#define TAB_PRZYCHODY_HPP

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


class Tab_Przychody : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Przychody(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
    void setDatabaseManager(DatabaseManager* dbManager);

signals:
    void daneZmienione();

private slots:
    void DodajPrzychodClicked();

private:
    QString m_userEmail;

    QDoubleSpinBox *kwotaSpinBox;
    QLineEdit *opisLineEdit;
    QDateEdit *dataEdit;
    QComboBox *kategoriaCombo;
    QPushButton *dodajPrzychodButton;

    DatabaseManager* m_dbManager = nullptr;
    void loadKategorie();
};

#endif // TAB_PRZYCHODY_HPP
