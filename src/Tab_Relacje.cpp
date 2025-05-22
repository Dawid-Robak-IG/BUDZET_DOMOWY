#include "../inc/Tab_Relacje.hpp"

Tab_Relacje::Tab_Relacje(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{
    dzieciTable=root->findChild<QTableView*>("tableView_dzieciRelacje");
    rodziceTable=root->findChild<QTableView*>("tableView_rodziceRelacje");


    dodajRelacjeButton=root->findChild<QPushButton*>("pushButton_przypiszRodzica");

    if(dodajRelacjeButton){
        connect(dodajRelacjeButton, &QPushButton::clicked, this, &Tab_Relacje::PrzypiszRodzicaClicked);
    }

}


void Tab_Relacje::PrzypiszRodzicaClicked(){ //toDo

    qDebug()<<"Tutaj będzie dodanie relacji dziecko-rodzic";
}


void Tab_Relacje::setDatabaseManager(DatabaseManager* dbManager)
{
    m_dbManager = dbManager;
    showTables();

}

void Tab_Relacje::showTables(){
//Tablica dzieci
    if (!dzieciTable) {
        qDebug() << "Brak dzieciTable - nie można ustawić modelu";
        return;
    }

    dzieciModelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    dzieciModelUsers->setTable("Uzytkownik zalogowany");
    dzieciModelUsers->setFilter("Rola = 'Dziecko'");
    if (!dzieciModelUsers->select()) {
        qDebug() << "Błąd ładowania danych dzieci:" << dzieciModelUsers->lastError().text();
    }


    dzieciTable->setModel(dzieciModelUsers);
    dzieciTable->resizeColumnsToContents();
    dzieciTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Ukryj wszystkie inne kolumny oprócz Imie, Nazwisko, Email
    for (int col = 0; col < dzieciModelUsers->columnCount(); ++col) {
        QString colName = dzieciModelUsers->headerData(col, Qt::Horizontal).toString();
        if (colName != "Imie" && colName != "Nazwisko" && colName != "Email") {
            dzieciTable->hideColumn(col);
        }
    }


    //Tablica Rodzice
    if (!rodziceTable) {
        qDebug() << "Brak rodziceTable - nie można ustawić modelu";
        return;
    }

    rodziceModelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    rodziceModelUsers->setTable("Uzytkownik zalogowany");
    rodziceModelUsers->setFilter("Rola = 'Rodzic'");
    rodziceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if (!rodziceModelUsers->select()) {
        qDebug() << "Błąd ładowania danych rodziców:" << rodziceModelUsers->lastError().text();
    }

    rodziceTable->setModel(rodziceModelUsers);
    rodziceTable->resizeColumnsToContents();

    for (int col = 0; col < rodziceModelUsers->columnCount(); ++col) {
        QString colName = rodziceModelUsers->headerData(col, Qt::Horizontal).toString();
        if (colName != "Imie" && colName != "Nazwisko" && colName != "Email") {
            rodziceTable->hideColumn(col);
        }
    }

}
