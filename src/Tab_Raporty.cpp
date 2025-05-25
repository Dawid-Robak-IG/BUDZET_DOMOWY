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

void Tab_Raporty::GenerujRaportClicked() {
    GenerujMyRaportClicked();
    return;

    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }

    QDate startDate = startDataEdit->date();
    QDate endDate = stopDataEdit->date();

    auto data = m_dbManager->getBudzetData(startDate, endDate);

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->setData(data.first, data.second);
    raport->setWindowTitle("Raport budżetu domowego");
    raport->show();
}
void Tab_Raporty::GenerujMyRaportClicked() {
    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }

    QDate startDate = startDataEdit->date();
    QDate endDate = stopDataEdit->date();

    auto data = m_dbManager->getMyBudzetData(startDate, endDate);

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->setData(data.first, data.second);
    raport->setWindowTitle("Raport mojego budżetu");
    raport->show();
}