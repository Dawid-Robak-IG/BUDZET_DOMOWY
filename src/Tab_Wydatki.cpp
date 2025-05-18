#include "../inc/Tab_Wydatki.hpp"
#include <QVariant>
#include <QSqlError>

Tab_Wydatki::Tab_Wydatki(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    kwotaSpinBox = root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaWydatek");
    opisLineEdit = root->findChild<QLineEdit*>("lineEdit_notatkaWydatek");
    dataEdit     = root->findChild<QDateEdit*>("dateEdit_dataWydatek");
    kategoriaCombo = root->findChild<QComboBox*>("comboBox_kategoriaWydatek");
    dodajWydatekButton = root->findChild<QPushButton*>("pushButton_dodajWydatek");

    //podłączenie do konkretnych elementów
    if (kwotaSpinBox) {
        connect(kwotaSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
                this, &Tab_Wydatki::KwotaChanged);
    }

    if(dodajWydatekButton){
        connect(dodajWydatekButton, &QPushButton::clicked, this, &Tab_Wydatki::DodajWydatekClicked);
    }
}


void Tab_Wydatki::KwotaChanged(double value)
{
    qDebug() << "Kwota zmieniona na:" << value;
    // Tutaj możesz zaktualizować UI, wysłać sygnał dalej itp.
}


void Tab_Wydatki::DodajWydatekClicked(){

    if (!m_dbManager){
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;}


    m_dbManager->addWydatek(m_userEmail,kwotaSpinBox->value(),dataEdit->date(),opisLineEdit->text(),kategoriaCombo->currentText());

}
