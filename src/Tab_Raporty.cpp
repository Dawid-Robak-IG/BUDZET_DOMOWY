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
    if(m_dbManager->amIChild()){
        qDebug() << "Dziecko nie może raportu dla budżetu";
        QMessageBox::warning(this, "Błąd", "Tylko dorośli użytkownicy mogą generować raport dla całego budżetu");
        return;
    }

    QDate startDate = startDataEdit->date();
    QDate endDate = stopDataEdit->date();

    auto data = m_dbManager->getBudzetData(startDate, endDate,"Pensja");

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->addChart(data.first, data.second,"Budżet domowy");

    data = m_dbManager->getBudzetPrzychody(startDate, endDate,"Pensja"); 
    raport->addChart(data.first, data.second,"Przychody budżetu domowego");

    data = m_dbManager->getBudzetWydatki(startDate, endDate,"Pensja");
    raport->addChart(data.first, data.second, "Wydatki Budżetu domowego");

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

    auto data = m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID());// toDo -- tu trzeba dać to co wybierzemy w UI

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->addChart(data.first, data.second, "Budżet wybranego użytkownika");

    data = m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID(),"Pensja"); // toDo -- tu trzeba dać to co wybierzemy w UI
    raport->addChart(data.first, data.second, "Przychody wybranego użytkownika");

    data = m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID(),"Pensja");// toDo -- tu trzeba dać to co wybierzemy w UI
    raport->addChart(data.first, data.second, "Wydatki wybranego użytkownika");

    raport->setWindowTitle("Raport mojego budżetu");
    raport->show();
}