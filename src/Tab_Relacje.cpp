#include "../inc/Tab_Relacje.hpp"

Tab_Relacje::Tab_Relacje(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{
    dzieciTable=root->findChild<QTableView*>("tableView_dzieciRelacje");
    rodziceTable=root->findChild<QTableView*>("tableView_rodziceRelacje");


    dodajRelacjeButton=root->findChild<QPushButton*>("pushButton_przypiszRodzica");
    dodaj2RelacjeButton=root->findChild<QPushButton*>("pushButton_przypisz2Rodzica");
    if(dodajRelacjeButton){
        connect(dodajRelacjeButton, &QPushButton::clicked, this, &Tab_Relacje::PrzypiszRodzicaClicked);
    }

    if(dodaj2RelacjeButton){
        connect(dodaj2RelacjeButton, &QPushButton::clicked, this, &Tab_Relacje::Przypisz2RodzicaClicked);
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
    int dzieckoID = dzieciModelUsers
                        ->data(dzieciModelUsers->index(dzieckoIndex.row(),
                                                       dzieciModelUsers->fieldIndex(
                                                           "Uzytkownik zalogowanyID")))
                        .toInt();
    //  int dzieckoID = dzieciModelUsers->data(dzieciModelUsers->index(dzieckoIndex.row(), dzieciModelUsers->fieldIndex("ID"))).toInt();
    int rodzicID = rodziceModelUsers->data(rodziceModelUsers->index(rodzicIndex.row(), rodziceModelUsers->fieldIndex("ID"))).toInt();

    qDebug()<<"Wybrano dziecko: "<<dzieckoID<<" | oraz Rodzica: "<<rodzicID;

    if (m_dbManager->addRelation(dzieckoID, rodzicID, -1)) {
        QMessageBox::information(this, "Sukces", "Relacja została dodana.");
        dzieciModelUsers->select();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać relacji.");
    }
}


void Tab_Relacje::Przypisz2RodzicaClicked() {
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

    int dzieckoID = dzieciModelUsers
                        ->data(dzieciModelUsers->index(dzieckoIndex.row(),
                                                       dzieciModelUsers->fieldIndex(
                                                           "Uzytkownik zalogowanyID")))
                        .toInt();
    int rodzicID = rodziceModelUsers->data(rodziceModelUsers->index(rodzicIndex.row(), rodziceModelUsers->fieldIndex("ID"))).toInt();

    qDebug()<<"Wybrano dziecko: "<<dzieckoID<<" | oraz Rodzica: "<<rodzicID;

    if (m_dbManager->addRelation(dzieckoID, -1,rodzicID)) {
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

void Tab_Relacje::showTables()
{
    //Tablica dzieci

    dzieciModelUsers = new QSqlRelationalTableModel(this, m_dbManager->getDatabase());
    dzieciModelUsers->setTable("Dziecko");
    dzieciModelUsers->setRelation(
        dzieciModelUsers->fieldIndex("Uzytkownik zalogowanyID"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );
    dzieciModelUsers->setHeaderData(
        dzieciModelUsers->fieldIndex("ImieNazwisko"),
        Qt::Horizontal,
        "Dziecko"
    );

    dzieciModelUsers->setRelation(
        dzieciModelUsers->fieldIndex("ID_Rodzic1"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );
    dzieciModelUsers->setHeaderData(
        dzieciModelUsers->fieldIndex("ImieNazwisko"),
        Qt::Horizontal,
        "Rodzic 1"
    );

    dzieciModelUsers->setRelation(
        dzieciModelUsers->fieldIndex("ID_Rodzic2"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );
    dzieciModelUsers->setHeaderData(
        dzieciModelUsers->fieldIndex("ImieNazwisko"),
        Qt::Horizontal,
        "Rodzic 2"
    );


    if (!dzieciModelUsers->select()) {
        qDebug() << "Błąd ładowania danych dzieci:" << dzieciModelUsers->lastError().text();
    }

    dzieciTable->setModel(dzieciModelUsers);
    dzieciTable->resizeColumnsToContents();
    dzieciTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    dzieciTable->hideColumn(dzieciModelUsers->fieldIndex("saldo"));
    dzieciTable->hideColumn(dzieciModelUsers->fieldIndex("kieszonkowe"));
    dzieciTable->hideColumn(dzieciModelUsers->fieldIndex("DataKolejnaKieszonkowego"));

    // Opcjonalnie zmień nagłówki innych kolumn:
    dzieciModelUsers->setHeaderData(0, Qt::Horizontal, "Imię");
    dzieciModelUsers->setHeaderData(3, Qt::Horizontal, "Rodzic 1");
    dzieciModelUsers->setHeaderData(4, Qt::Horizontal, "Rodzic 2");

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

    rodziceModelUsers->setHeaderData(1, Qt::Horizontal, "Imię");
}
