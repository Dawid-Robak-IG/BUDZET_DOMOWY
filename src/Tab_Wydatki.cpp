#include "../inc/Tab_Wydatki.hpp"

Tab_Wydatki::Tab_Wydatki(const QString& userEmail,QWidget *root, QWidget *parent): QWidget{parent},m_userEmail(userEmail){

    kwotaSpinBox = root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaWydatek");
    opisLineEdit = root->findChild<QLineEdit*>("lineEdit_notatkaWydatek");
    dataEdit     = root->findChild<QDateEdit*>("dateEdit_dataWydatek");
    kategoriaCombo = root->findChild<QComboBox*>("comboBox_kategoriaWydatek");
    dodajWydatekButton = root->findChild<QPushButton*>("pushButton_dodajWydatek");

    //podłączenie do konkretnych elementów

    if(dodajWydatekButton){
        connect(dodajWydatekButton, &QPushButton::clicked, this, &Tab_Wydatki::DodajWydatekClicked);
    }

    dataEdit->setDate(QDate::currentDate());
}


void Tab_Wydatki::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();


    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Wydatki::loadKategorie);
}


void Tab_Wydatki::DodajWydatekClicked() {
    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }
    if(kwotaSpinBox->value()<=0){
        qWarning() << "Wstawiono złą kwotę";
        QMessageBox::warning(this, "Błąd", "Wstawiono kwotę <=0");
        return;
    }

    if (m_dbManager->addWydatek(m_userEmail, kwotaSpinBox->value(), dataEdit->date(), opisLineEdit->text(), kategoriaCombo->currentText())) {
        QMessageBox::information(this, "Sukces", "Wydatek został dodany!");
        emit daneZmienione();
        // Czyść formularz
        kwotaSpinBox->setValue(0.00);
        opisLineEdit->clear();
        dataEdit->setDate(QDate::currentDate());
        kategoriaCombo->setCurrentIndex(0);
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać wydatku.");
    }
}

void Tab_Wydatki::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}
