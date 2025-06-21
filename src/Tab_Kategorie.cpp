#include "../inc/Tab_Kategorie.hpp"

Tab_Kategorie::Tab_Kategorie(const QString& userEmail,QWidget *root, QWidget *parent)
                             : QWidget{parent},m_userEmail(userEmail)
{

    nowaKategoriaLineEdit = root->findChild<QLineEdit*>("lineEdit_nowaKategoria");
    dodajKategorieButton = root->findChild<QPushButton*>("pushButton_dodajKategorie");
    usunKategorieButton=root->findChild<QPushButton*>("pushButton_usunKategorie");
    kategoriaCombo = root->findChild<QComboBox*>("comboBox_dostepneKategorie");

 // tabelaKategorie = root->findChild<QTableView*>("tableView_Kategorie");

    //podłączenie do konkretnych elementów
        if( dodajKategorieButton){
        connect( dodajKategorieButton, &QPushButton::clicked, this, &Tab_Kategorie::DodajKategorieClicked);
    }
        if(usunKategorieButton){
            connect( usunKategorieButton, &QPushButton::clicked, this, &Tab_Kategorie::UsunKategorieClicked);
        }


        if(!usunKategorieButton)
        qDebug()<<"Nie ma";

}



void Tab_Kategorie::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();
   //showTable();

    usunKategorieButton->setVisible( m_dbManager->amI_admin());
    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_Kategorie::loadKategorie);

}


// void Tab_Kategorie::showTable(){
//     if (!tabelaKategorie) {
//       qDebug() << "Brak cyklicznePTable - nie można ustawić modelu";
//         return;
//     }
//     setTableStrategy();



//     tabelaKategorie->resizeColumnsToContents();
// }


// void Tab_Kategorie::setTableStrategy(){
//     if(!modelUsersX){
//         modelUsersX = new QSqlTableModel(this, m_dbManager->getDatabase());
//     }
//     modelUsersX->setTable("`Operacja cykliczna`");
//     modelUsersX->setEditStrategy(QSqlTableModel::OnFieldChange);

//     QString filter = "`Kwota` < 0";

//     if(!m_dbManager->amI_admin()){
//         filter += QString(" AND `Uzytkownik zalogowanyID` = %1").arg(m_dbManager->get_user_ID());
//     }

//     modelUsersX->setFilter(filter);

//     modelUsersX->select();

//     tabelaKategorie->setModel(modelUsersX);
//     tabelaKategorie->hideColumn(modelUsersX->fieldIndex("ID"));
//     //cykliczneWTable->hideColumn(modelUsers->fieldIndex("Uzytkownik zalogowanyID"));

//    tabelaKategorie->setEditTriggers(QAbstractItemView::NoEditTriggers);

//     connect(tabelaKategorie, &QTableView::doubleClicked, this, [=](const QModelIndex &index){
//         QString colName = modelUsersX->headerData(index.column(), Qt::Horizontal).toString();

//         if (colName == "Uzytkownik zalogowanyID") {
//             qDebug() << "Edycja zabroniona dla kolumny:" << colName;
//             return;
//         }

//         tabelaKategorie->edit(index);
//     });
// }

void Tab_Kategorie::DodajKategorieClicked(){
    if (!m_dbManager){
        qWarning() << "Nie ustawiono DatabaseManager!";
        return;}
    if(!m_dbManager->amI_admin()){
        QMessageBox::warning(this, "Błąd", "Tylko admin może dodawać nowe kategorie!");
        return; 
    }
    if ( m_dbManager->addKategoria(m_userEmail, nowaKategoriaLineEdit->text())) {
        QMessageBox::information(this, "Sukces", "Kategoria została dodana!");
       //showTable();
    } else {
        QMessageBox::warning(
            this, "Błąd", "Nie udało się dodać kategorii.\n Brak wpisanej nazwy nowej kategorii.");
    }
    nowaKategoriaLineEdit->clear();
}



void Tab_Kategorie::UsunKategorieClicked(){
    qDebug() << "Usuwanie kategorii";

QString wybranaKategoria = kategoriaCombo->currentText();

QMessageBox msgBox;
msgBox.setWindowTitle("Potwierdzenie usunięcia");
msgBox.setText("Czy na pewno chcesz usunąć kategorię?");
msgBox.setIcon(QMessageBox::Question);

// Dodaj przyciski standardowe
msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

// Ustaw własne teksty przycisków
msgBox.button(QMessageBox::Yes)->setText("Tak");
msgBox.button(QMessageBox::No)->setText("Nie");

// Wyświetl i sprawdź odpowiedź
QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());

if (reply == QMessageBox::Yes) {
    if (m_dbManager->deleteCategory(wybranaKategoria)) {
        QMessageBox::information(this, "Sukces", "Usunięto kategorię.");
        //            modelUsers->select();
    } else {
        QMessageBox::warning(this,
                             "Błąd",
                             "Nie można usuwać kategorii dla których istnieją wpisy do budżetu");
    }
}
}

void Tab_Kategorie::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}


