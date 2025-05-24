#include "../inc/Tab_Kategorie.hpp"

Tab_Kategorie::Tab_Kategorie(const QString& userEmail,QWidget *root, QWidget *parent)
                             : QWidget{parent},m_userEmail(userEmail)
{

    nowaKategoriaLineEdit = root->findChild<QLineEdit*>("lineEdit_nowaKategoria");
    dodajKategorieButton = root->findChild<QPushButton*>("pushButton_dodajKategorie");
    kategoriaCombo = root->findChild<QComboBox*>("comboBox_dostepneKategorie");


    //podłączenie do konkretnych elementów
        if( dodajKategorieButton){
        connect( dodajKategorieButton, &QPushButton::clicked, this, &Tab_Kategorie::DodajKategorieClicked);
    }
}



void Tab_Kategorie::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();

    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Kategorie::loadKategorie);

}

void Tab_Kategorie::DodajKategorieClicked(){
    if (!m_dbManager){
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;}
    if(!m_dbManager->amI_admin()){
        QMessageBox::warning(this, "Błąd", "Tylko admin może dodawać nowe kategorie!");
        return; 
    }
    if ( m_dbManager->addKategoria(m_userEmail, nowaKategoriaLineEdit->text())) {
        QMessageBox::information(this, "Sukces", "Kategoria została dodana!");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać kategorii.");
    }


}

void Tab_Kategorie::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}
