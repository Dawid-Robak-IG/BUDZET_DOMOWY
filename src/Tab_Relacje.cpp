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


void Tab_Relacje::PrzypiszRodzicaClicked() {
    QModelIndex dzieckoIndex = dzieciTable->currentIndex();
    QModelIndex rodzicIndex = rodziceTable->currentIndex();

    if(!m_dbManager->amI_admin()){
        QMessageBox::warning(this, "Błąd", "Tylko admin może przypisywać rodziców do dzieci");
        return;
    }

    if (!dzieckoIndex.isValid() || !rodzicIndex.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz dziecko i rodzica.");
        return;
    }

    int dzieckoID = dzieciModelUsers->data(dzieciModelUsers->index(dzieckoIndex.row(), dzieciModelUsers->fieldIndex("ID"))).toInt();
    int rodzicID = rodziceModelUsers->data(rodziceModelUsers->index(rodzicIndex.row(), rodziceModelUsers->fieldIndex("ID"))).toInt();

    qDebug()<<"Wybrano dziecko: "<<dzieckoID<<" | oraz Rodzica: "<<rodzicID;

    if (m_dbManager->addRelation(dzieckoID, rodzicID, -1)) {
        QMessageBox::information(this, "Sukces", "Relacja została dodana.");
        dzieciModelUsers->select();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać relacji.");
    }
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
