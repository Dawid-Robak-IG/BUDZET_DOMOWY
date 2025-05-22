#include "../inc/Tab_Dzieci.hpp"

Tab_Dzieci::Tab_Dzieci(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    kieszonkoweTable=root->findChild<QTableView*>("tableView_aktualneKieszonkowe");

    aktualneSaldoLineEdit= root->findChild<QLineEdit*>("lineEdit_aktualneSaldo");
    generujRaportButton= root->findChild<QPushButton*>("pushButton_generujRaportD");
    zmienKieszonkoweButton= root->findChild<QPushButton*>("pushButton_zmienKieszonkowe");
    listaDzieciCombo=root->findChild<QComboBox*>("comboBox_dzieciLista");


    if(generujRaportButton){
        connect(generujRaportButton, &QPushButton::clicked, this, &Tab_Dzieci::GenerujRaportClicked);
    }

    if(zmienKieszonkoweButton){
        connect(zmienKieszonkoweButton, &QPushButton::clicked, this, &Tab_Dzieci::ZmienKieszonkoweClicked);
    }


}

void Tab_Dzieci::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadDzieciListComboBox();
    showTable();
}


void Tab_Dzieci::GenerujRaportClicked(){ //toDo
    qDebug()<<"Tu będzie generowanie raportu dla dziecka";
}

void Tab_Dzieci::ZmienKieszonkoweClicked(){ //toDo
    qDebug()<<"Tu będzie zmiana kieszonkowego";
}


void Tab_Dzieci::showTable(){ //toDo wyświetlenie konkretnego wpisu z cyklicznych opercji dla tego dziecka jego kieszonkowe

}

void Tab_Dzieci::loadDzieciListComboBox(){

    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        qDebug() << "Baza danych nie jest dostępna!";
        return;
    }

    if (!listaDzieciCombo) {
        qDebug() << "listaDzieciCombo nie została znaleziona (nullptr)!";
        return;
    }
    listaDzieciCombo->clear();  // Wyczyść przed dodaniem

    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Imie, Nazwisko FROM `Uzytkownik zalogowany` WHERE Rola = 'Dziecko'");

    if (!query.exec()) {
        qDebug() << "Błąd przy pobieraniu dzieci:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString imie = query.value("Imie").toString();
        QString nazwisko = query.value("Nazwisko").toString();
        QString pelneImie = imie + " " + nazwisko;
        listaDzieciCombo->addItem(pelneImie);
    }

    if (listaDzieciCombo->count() == 0) {
        listaDzieciCombo->addItem("Brak dzieci w bazie");
    }

}
