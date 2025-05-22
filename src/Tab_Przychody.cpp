#include "../inc/Tab_Przychody.hpp"

Tab_Przychody::Tab_Przychody(const QString& userEmail,QWidget *root, QWidget *parent)
                             : QWidget{parent},m_userEmail(userEmail)
{


    kwotaSpinBox = root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaPrzychod");
    opisLineEdit = root->findChild<QLineEdit*>("lineEdit_notatkaPrzychod");
    dataEdit     = root->findChild<QDateEdit*>("dateEdit_dataPrzychod");
    kategoriaCombo = root->findChild<QComboBox*>("comboBox_kategoriaPrzychod");
    dodajPrzychodButton = root->findChild<QPushButton*>("pushButton_dodajPrzychod");

    //podłączenie do konkretnych elementów

    if(dodajPrzychodButton){
        connect(dodajPrzychodButton, &QPushButton::clicked, this, &Tab_Przychody::DodajPrzychodClicked);
    }

   dataEdit->setDate(QDate::currentDate());

}


void Tab_Przychody::setDatabaseManager(DatabaseManager* dbManager){
    m_dbManager = dbManager;
    loadKategorie();


    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Przychody::loadKategorie);
}


void Tab_Przychody::DodajPrzychodClicked(){

    if (!m_dbManager){
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;}


    if ( m_dbManager->addPrzychod(m_userEmail,kwotaSpinBox->value(),dataEdit->date(),opisLineEdit->text(),kategoriaCombo->currentText())) {
        QMessageBox::information(this, "Sukces", "Przychód został dodany!");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać przychodu.");
    }


}


void Tab_Przychody::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}

