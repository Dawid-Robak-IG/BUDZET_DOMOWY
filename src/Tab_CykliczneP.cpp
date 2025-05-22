#include "../inc/Tab_CykliczneP.hpp"

Tab_CykliczneP::Tab_CykliczneP(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    stacked= root->findChild<QStackedWidget*>("stackedWidget_CykliczneP");
    cyklicznePTable =root->findChild<QTableView*>("tableView_listaCP");
    edytujCP_Button= root->findChild<QPushButton*>("pushButton_edytujCP");
    nowyCP_Button= root->findChild<QPushButton*>("pushButton_nowyCP");
    usunCP_Button= root->findChild<QPushButton*>("pushButton_usunCP");
    //zeby dodać nowy:
    kategoriaCombo= root->findChild<QComboBox*>("comboBox_kategoriaCP");
    czestotliwoscCombo =root->findChild<QComboBox*>("comboBox_czestotliwoscCP");
    startCP_Data = root->findChild<QDateEdit*>("dateEdit_CP");
    kwotaCP= root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaCP");
    notatkaCP_LineEdit= root->findChild<QLineEdit*>("lineEdit_notatkaCP");
    powrotCP_Button= root->findChild<QPushButton*>("pushButton_powrotCP");
    dodajCP_Button= root->findChild<QPushButton*>("pushButton_dodajCP");

    //podłączenie do konkretnych elementów
    if(dodajCP_Button){
        connect(dodajCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::DodajCP_Clicked);
    }

    if(edytujCP_Button){
        connect(edytujCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::EdytujCP_Clicked);
    }

    if(usunCP_Button){
        connect(usunCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::UsunCP_Clicked);
    }

    connect(nowyCP_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(1);
    });

    connect(powrotCP_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(0);
    });

}
void Tab_CykliczneP::DodajCP_Clicked(){ //toDo
    qDebug()<<"Tutaj będzie dodawanie cyklicznego przychodu";
}
void Tab_CykliczneP::EdytujCP_Clicked(){//toDo
qDebug()<<"Tutaj będzie edytowanie cyklicznego przychodu";
}
void Tab_CykliczneP::UsunCP_Clicked(){//toDo
qDebug()<<"Tutaj będzie usuwanie cyklicznego przychodu";
}


void Tab_CykliczneP::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();

showTable();

}

void Tab_CykliczneP::showTable(){
    if (!cyklicznePTable) {
        qDebug() << "Brak cyklicznePTable - nie można ustawić modelu";
        return;
    }

    modelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    modelUsers->setTable("Operacja cykliczna");  // toDo trzeba dać tylko przychody cykliczne tutaj
     if (!modelUsers->select()) {
        qDebug() << "Błąd ładowania danych:" << modelUsers->lastError().text();
    }

   cyklicznePTable->setModel(modelUsers);
    cyklicznePTable->resizeColumnsToContents();
}



void Tab_CykliczneP::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}
