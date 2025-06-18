#include "../inc/Tab_Raporty.hpp"

Tab_Raporty::Tab_Raporty(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail){
    startDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Od");
    stopDataEdit= root->findChild<QDateEdit*>("dateEdit_R_Do");
    generujRaportButton= root->findChild<QPushButton*>("pushButton_generujRaport");
    generujRaportOsobisty=root->findChild<QPushButton*>("pushButton_generujRaportOsobisty");
    generujRaportOsobistyAdmin=root->findChild<QPushButton*>("pushButton_adminRaportOneUser");
    comboKategoriaRaport=root->findChild<QComboBox*>("comboBox_kategoriaRaport");
    checkBoxKategoria=root->findChild<QCheckBox*>("checkBox_tylkoKategoria");
    comboUserAdminRaport=root->findChild<QComboBox*>("comboBox_adminRaportOneUser");
    comboPrognozyOsobiste=root->findChild<QComboBox*>("comboBox_prognozy");
    generujPrognozyAdmin=root->findChild<QPushButton*>("pushButton_adminprognozy");
    generujPrognozyBudżet=root->findChild<QPushButton*>("pushButton_prognozycaly");
    generujMojePrognozy=root->findChild<QPushButton*>("pushButton_osobistepprognozy");
    dataPrognozy= root->findChild<QDateEdit*>("dateEdit_prognozy");

    if (!comboPrognozyOsobiste) {
        qWarning() << "Nie znaleziono comboBox_prognozy";
    }
    if (!generujPrognozyAdmin) {
        qWarning() << "Nie znaleziono pushButton_adminprognozy";
    }
    if (!generujMojePrognozy) {
        qWarning() << "Nie znaleziono pushButton_generujMojePrognozy";
    }
    if (!dataPrognozy) {
        qWarning() << "Nie znaleziono dateEdit_prognozy";
    }
    if(generujRaportButton){
        connect(generujRaportButton, &QPushButton::clicked, this, &Tab_Raporty::GenerujRaportClicked);
    }

    if( generujRaportOsobisty){
        connect( generujRaportOsobisty, &QPushButton::clicked, this, &Tab_Raporty::GenerujMyRaportClicked);
    }

    if( generujRaportOsobistyAdmin){
        connect( generujRaportOsobistyAdmin, &QPushButton::clicked, this, &Tab_Raporty::GenerujRaportOsobistyAdminClicked);
    }

    if( generujPrognozyBudżet){
        connect(generujPrognozyBudżet, &QPushButton::clicked, this, &Tab_Raporty::GenerujPrognozyBudzetClicked);
    }

    if( generujPrognozyAdmin){
        connect(generujPrognozyAdmin, &QPushButton::clicked, this, &Tab_Raporty::GenerujPrognozyAdminClicked);
    }
    if( generujMojePrognozy){
        connect(generujMojePrognozy, &QPushButton::clicked, this, &Tab_Raporty::GenerujPrognozyMyBudzetClicked);
    }
    startDataEdit->setDate(QDate::currentDate());
    stopDataEdit->setDate(QDate::currentDate());
    dataPrognozy->setDate(QDate::currentDate());
}

void Tab_Raporty::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;

    generujRaportOsobistyAdmin->setVisible(m_dbManager->amI_admin());
    comboUserAdminRaport->setVisible(m_dbManager->amI_admin());
    loadKategorie();
    loadUżytkownicy();
    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Raporty::loadKategorie);

   comboPrognozyOsobiste->setVisible(m_dbManager->amI_admin());
    generujPrognozyAdmin->setVisible(m_dbManager->amI_admin());
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
    raport->addStepChart(data.first, data.second,"Budżet domowy");

    data = m_dbManager->getBudzetPrzychody(startDate, endDate); 
    raport->addBarChart(data.first, data.second,"Przychody budżetu domowego");

    data = m_dbManager->getBudzetWydatki(startDate, endDate);
    raport->addBarChart(data.first, data.second, "Wydatki Budżetu domowego");

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
    QPair<QVector<QDate>, QVector<double>> data;
    if (checkBoxKategoria ->isChecked()) {  
        data = m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID(),comboKategoriaRaport->currentText());
    }
    else{
        data = m_dbManager->getMyBudzetData(startDate, endDate, m_dbManager->get_user_ID());
    }

    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    //RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->addStepChart(data.first, data.second, "Twój budżet");

    data = m_dbManager->getMyPrzychody(startDate, endDate, m_dbManager->get_user_ID());
    raport->addBarChart(data.first, data.second, "Twoje przychody");

    data = m_dbManager->getMyWydatki(startDate, endDate, m_dbManager->get_user_ID());
    raport->addBarChart(data.first, data.second, "Twoje wydatki");

    raport->setWindowTitle("Raport dla mojego budżetu");
    raport->show();
}

void Tab_Raporty::GenerujRaportOsobistyAdminClicked(){

    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }
    if(m_dbManager->amI_admin()){
        QMessageBox::warning(this, "Błąd", "Tylko admin może generować wykresy dla wybranych użytkowników");
        return;
    }

    QDate startDate = startDataEdit->date();
    QDate endDate = stopDataEdit->date();
    int selectedUserID=m_dbManager->get_ID_by_mail(comboUserAdminRaport->currentText());
  //  qDebug()<<"Ludzik numer: "<<selectedUserID;
    RaportWindow* raport = new RaportWindow();
    QPair<QVector<QDate>, QVector<double>> data;
    if (checkBoxKategoria ->isChecked()) {  //czyli chcemy z wyborem kategorii
        data = m_dbManager->getMyBudzetData(startDate, endDate, selectedUserID,comboKategoriaRaport->currentText());// toDo -- tu trzeba dać to co wybierzemy w UI
    } else{
        data = m_dbManager->getMyBudzetData(startDate, endDate, selectedUserID);// toDo -- tu trzeba dać to co wybierzemy w UI
    }
    if (data.first.isEmpty()) {
        QMessageBox::information(this, "Brak danych", "Brak danych w podanym zakresie dat.");
        return;
    }

    //RaportWindow* raport = new RaportWindow();
    raport->setAttribute(Qt::WA_DeleteOnClose);
    raport->addStepChart(data.first, data.second, "Budżet wybranego użytkownika");

    data = m_dbManager->getMyPrzychody(startDate, endDate, selectedUserID); // toDo -- tu trzeba dać to co wybierzemy w UI
    raport->addBarChart(data.first, data.second, "Przychody wybranego użytkownika");

    data = m_dbManager->getMyWydatki(startDate, endDate,selectedUserID);// toDo -- tu trzeba dać to co wybierzemy w UI
    raport->addBarChart(data.first, data.second, "Wydatki wybranego użytkownika");


    raport->setWindowTitle("Raport budżetu dla danego użytkownika");
    raport->show();
}


void Tab_Raporty::GenerujPrognozyBudzetClicked(){

    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }
    if(m_dbManager->amIChild()){
        qDebug() << "Dziecko nie może raportu dla budżetu";
        QMessageBox::warning(this, "Błąd", "Tylko dorośli użytkownicy mogą generować raport dla całego budżetu");
        return;
    }

    QDate dateProg =  dataPrognozy->date();

    double prognoza=m_dbManager-> whole_future_Budzet(dateProg);

    qDebug()<<prognoza;

    QString message = QString("Prognoza budżetu na dzień %1: %2 zł")
                          .arg(dateProg.toString("dd-MM-yyyy"))
                          .arg(QString::number(prognoza, 'f', 2));

    QMessageBox::information(this, "Prognoza", message);
}


void Tab_Raporty::GenerujPrognozyMyBudzetClicked(){
    if (!m_dbManager) {
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;
    }

    QDate dateProg =  dataPrognozy->date();


    double prognoza=m_dbManager-> user_future_Budzet(m_dbManager->get_user_ID(), dateProg);

    qDebug()<<prognoza;

    QString message = QString("Prognoza budżetu na dzień %1: %2 zł")
                          .arg(dateProg.toString("dd-MM-yyyy"))
                          .arg(QString::number(prognoza, 'f', 2));

    QMessageBox::information(this, "Prognoza", message);

}


void Tab_Raporty::GenerujPrognozyAdminClicked(){
    int selectedUserID=m_dbManager->get_ID_by_mail(comboPrognozyOsobiste->currentText());
     QDate dateProg =  dataPrognozy->date();



    double prognoza= m_dbManager->user_future_Budzet(selectedUserID,dateProg);

    qDebug()<<prognoza;

    QString message = QString("Prognoza budżetu na dzień %1: %2 zł")
                          .arg(dateProg.toString("dd-MM-yyyy"))
                          .arg(QString::number(prognoza, 'f', 2));

    QMessageBox::information(this, "Prognoza", message);
}


void Tab_Raporty::loadUżytkownicy() {
    if (!m_dbManager) return;

    QStringList users = m_dbManager->getAllUsers();
    comboUserAdminRaport->clear();
    comboUserAdminRaport->addItems(users);

    comboPrognozyOsobiste->clear();
    comboPrognozyOsobiste->addItems(users);
}

void Tab_Raporty::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    comboKategoriaRaport->clear();
    comboKategoriaRaport->addItems(kategorie);
}
