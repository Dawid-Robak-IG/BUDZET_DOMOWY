#include "../inc/Tab_Raporty.hpp"

Tab_Raporty::Tab_Raporty(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{


    startDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Od");
    stopDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Do");
    generujRaportButton= root->findChild<QPushButton*>("pushButton_generujRaport");
    generujRaportOsobisty=root->findChild<QPushButton*>("pushButton_generujRaportOsobisty");

    generujRaportOsobistyAdmin=root->findChild<QPushButton*>("pushButton_adminRaportOneUser");
    comboKategoriaRaport=root->findChild<QComboBox*>("comboBox_kategoriaRaport");
    checkBoxKategoria=root->findChild<QCheckBox*>("checkBox_tylkoKategoria");

    comboUserAdminRaport=root->findChild<QComboBox*>("comboBox_adminRaportOneUser");

    if(generujRaportButton){
        connect(generujRaportButton, &QPushButton::clicked, this, &Tab_Raporty::GenerujRaportClicked);
    }

    if( generujRaportOsobisty){
        connect( generujRaportOsobisty, &QPushButton::clicked, this, &Tab_Raporty::GenerujMyRaportClicked);
    }

    if( generujRaportOsobistyAdmin){
        connect( generujRaportOsobistyAdmin, &QPushButton::clicked, this, &Tab_Raporty::GenerujRaportOsobistyAdminClicked);
    }


    startDataEdit->setDate(QDate::currentDate());
    stopDataEdit->setDate(QDate::currentDate());

}

void Tab_Raporty::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;

    generujRaportOsobistyAdmin->setVisible(m_dbManager->amI_admin());
    comboUserAdminRaport->setVisible(m_dbManager->amI_admin());
    loadKategorie();
    loadUżytkownicy();
    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Raporty::loadKategorie);

}

void Tab_Raporty::GenerujRaportClicked() {
    // GenerujMyRaportClicked();
    // return;
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

    auto data = m_dbManager->getBudzetData(startDate, endDate);

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->addChart(data.first, data.second,"Budżet domowy");

    data = m_dbManager->getBudzetPrzychody(startDate, endDate); 
    raport->addChart(data.first, data.second,"Przychody budżetu domowego");

    data = m_dbManager->getBudzetWydatki(startDate, endDate);
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


    RaportWindow* raport = new RaportWindow();
    if (checkBoxKategoria ->isChecked()) {  //czyli chcemy z wyborem kategorii


        auto data = m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID(),comboKategoriaRaport->currentText());// toDo -- tu trzeba dać to co wybierzemy w UI

        if (data.first.isEmpty()) {
            QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
            return;
        }

        //RaportWindow* raport = new RaportWindow();
        raport->setAttribute(Qt::WA_DeleteOnClose);
        raport->addChart(data.first, data.second, "Budżet wybranego użytkownika");

        data = m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID(),comboKategoriaRaport->currentText()); // toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Przychody wybranego użytkownika");

        data = m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID(),comboKategoriaRaport->currentText());// toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Wydatki wybranego użytkownika");}

    else{

        auto data = m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID());// toDo -- tu trzeba dać to co wybierzemy w UI

        if (data.first.isEmpty()) {
            QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
            return;
        }

        //RaportWindow* raport = new RaportWindow();
        raport->setAttribute(Qt::WA_DeleteOnClose);
        raport->addChart(data.first, data.second, "Budżet wybranego użytkownika");

        data = m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID()); // toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Przychody wybranego użytkownika");

        data = m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID());// toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Wydatki wybranego użytkownika");

    }

    raport->setWindowTitle("Raport mojego budżetu");
    raport->show();
}



void Tab_Raporty::GenerujRaportOsobistyAdminClicked(){

    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }

    QDate startDate = startDataEdit->date();
    QDate endDate = stopDataEdit->date();
    int selectedUserID=m_dbManager->get_ID_by_mail(comboUserAdminRaport->currentText());
    qDebug()<<"Ludzik numer: "<<selectedUserID;
    RaportWindow* raport = new RaportWindow();
    if (checkBoxKategoria ->isChecked()) {  //czyli chcemy z wyborem kategorii


        auto data = m_dbManager->getMyBudzetData(startDate, endDate, selectedUserID,comboKategoriaRaport->currentText());// toDo -- tu trzeba dać to co wybierzemy w UI

        if (data.first.isEmpty()) {
            QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
            return;
        }

        //RaportWindow* raport = new RaportWindow();
        raport->setAttribute(Qt::WA_DeleteOnClose);
        raport->addChart(data.first, data.second, "Budżet wybranego użytkownika");

        data = m_dbManager->getMyPrzychody(startDate, endDate, selectedUserID,comboKategoriaRaport->currentText()); // toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Przychody wybranego użytkownika");

        data = m_dbManager->getMyWydatki(startDate, endDate,selectedUserID,comboKategoriaRaport->currentText());// toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Wydatki wybranego użytkownika");
    } else{

        auto data = m_dbManager->getMyBudzetData(startDate, endDate, selectedUserID);// toDo -- tu trzeba dać to co wybierzemy w UI

        if (data.first.isEmpty()) {
            QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
            return;
        }

        //RaportWindow* raport = new RaportWindow();
        raport->setAttribute(Qt::WA_DeleteOnClose);
        raport->addChart(data.first, data.second, "Budżet wybranego użytkownika");

        data = m_dbManager->getMyPrzychody(startDate, endDate, selectedUserID); // toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Przychody wybranego użytkownika");

        data = m_dbManager->getMyWydatki(startDate, endDate,selectedUserID);// toDo -- tu trzeba dać to co wybierzemy w UI
        raport->addChart(data.first, data.second, "Wydatki wybranego użytkownika");

    }

    raport->setWindowTitle("Raport budżetu dla danego użytkownika");
    raport->show();


}





void Tab_Raporty::loadUżytkownicy() {
    if (!m_dbManager) return;

    QStringList users = m_dbManager->getAllUsers();
    comboUserAdminRaport->clear();
    comboUserAdminRaport->addItems(users);
}

void Tab_Raporty::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    comboKategoriaRaport->clear();
    comboKategoriaRaport->addItems(kategorie);
}
