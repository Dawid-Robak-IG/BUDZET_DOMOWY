#include "../inc/Tab_CykliczneW.hpp"

Tab_CykliczneW::Tab_CykliczneW(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    stacked= root->findChild<QStackedWidget*>("stackedWidget_CykliczneW");
    cykliczneWTable =root->findChild<QTableView*>("tableView_listaCW");
    edytujCW_Button= root->findChild<QPushButton*>("pushButton_edytujCW");
    nowyCW_Button= root->findChild<QPushButton*>("pushButton_nowyCW");
    usunCW_Button= root->findChild<QPushButton*>("pushButton_usunCW");
    //zeby dodać nowy:
    kategoriaCombo= root->findChild<QComboBox*>("comboBox_kategoriaCW");
    czestotliwoscCombo =root->findChild<QComboBox*>("comboBox_czestotliwoscCW");
    startCW_Data = root->findChild<QDateEdit*>("dateEdit_CW");
    kwotaCW= root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaCW");
    notatkaCW_LineEdit= root->findChild<QLineEdit*>("lineEdit_notatkaCW");
    powrotCW_Button= root->findChild<QPushButton*>("pushButton_powrotCW");
    dodajCW_Button= root->findChild<QPushButton*>("pushButton_dodajCW");

    //podłączenie do konkretnych elementów
    if(dodajCW_Button){
        connect(dodajCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::DodajCW_Clicked);
    }

    if(edytujCW_Button){
        connect(edytujCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::EdytujCW_Clicked);
    }

    if(usunCW_Button){
        connect(usunCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::UsunCW_Clicked);
    }

    connect(nowyCW_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(1);
    });

    connect(powrotCW_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(0);
    });

}
void Tab_CykliczneW::DodajCW_Clicked(){ //toDo
    qDebug()<<"Tutaj będzie dodawanie cyklicznego wydatku";
}
void Tab_CykliczneW::EdytujCW_Clicked(){//toDo
    qDebug()<<"Tutaj będzie edytowanie cyklicznego wydatku";
}
void Tab_CykliczneW::UsunCW_Clicked(){//toDo
    qDebug()<<"Tutaj będzie usuwanie cyklicznego wydatku";
}


void Tab_CykliczneW::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();

    showTable();

}

void Tab_CykliczneW::showTable(){
    if (!cykliczneWTable) {
        qDebug() << "Brak cyklicznePTable - nie można ustawić modelu";
        return;
    }

    modelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    modelUsers->setTable("Operacja cykliczna");  // toDo trzeba dać tylko przychody cykliczne tutaj
    if (!modelUsers->select()) {
        qDebug() << "Błąd ładowania danych:" << modelUsers->lastError().text();
    }

    cykliczneWTable->setModel(modelUsers);
    cykliczneWTable->resizeColumnsToContents();
}



void Tab_CykliczneW::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}
