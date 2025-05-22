#include "../inc/Tab_Raporty.hpp"

Tab_Raporty::Tab_Raporty(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{


    startDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Od");
    stopDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Do");
    generujRaportButton= root->findChild<QPushButton*>("pushButton_generujRaport");

    if(generujRaportButton){
        connect(generujRaportButton, &QPushButton::clicked, this, &Tab_Raporty::GenerujRaportClicked);
    }


     startDataEdit->setDate(QDate::currentDate());
     stopDataEdit->setDate(QDate::currentDate());



}

void Tab_Raporty::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;

}


void Tab_Raporty::GenerujRaportClicked(){ //toDo
    qDebug()<<"Tutaj będzie generowanie raportu";
}
