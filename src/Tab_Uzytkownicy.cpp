#include "../inc/Tab_Uzytkownicy.hpp"

Tab_Uzytkownicy::Tab_Uzytkownicy(QWidget *root,QWidget *parent)
    : QWidget{parent}
{

    tabelaTableView = root->findChild<QTableView*>("tableView_uzytkownicy");
   stacked= root->findChild<QStackedWidget*>("stackedWidget_uzytkownicy");

    blokadaButton= root->findChild<QPushButton*>("pushButton_zablokuj_odblokuj");
    edytujButton= root->findChild<QPushButton*>("pushButton_edytujDane");
    powrotButton= root->findChild<QPushButton*>("pushButton_powrotE");
    zapiszZmianyButton= root->findChild<QPushButton*>("pushButton_zapiszE");
    rolaCombo= root->findChild<QComboBox*>("comboBox_rolaE");
    imie = root->findChild<QLineEdit*>("lineEdit_imieE");
    nazwisko = root->findChild<QLineEdit*>("lineEdit_nazwiskoE");
    mail = root->findChild<QLineEdit*>("lineEdit_mailE");


    //podłączenie do konkretnych elementów
    if(blokadaButton){
        connect(blokadaButton, &QPushButton::clicked, this, &Tab_Uzytkownicy::BlokadaClicked);
    }

    connect(edytujButton, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(1);
    });

    connect(powrotButton, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(0);
    });


    connect(zapiszZmianyButton, &QPushButton::clicked, this, &Tab_Uzytkownicy::ZapiszZmianyClicked);

stacked->setCurrentIndex(0);

}




void Tab_Uzytkownicy::ZapiszZmianyClicked(){  //toDo
    qDebug()<<"Tutaj będzie zapisanie zmian";
}

void Tab_Uzytkownicy::BlokadaClicked(){ //toDo
    qDebug()<<"Tutaj będzie blokowanie/odblokowanie użytkownika";

    QModelIndexList selected = tabelaTableView->selectionModel()->selectedRows();

    if (selected.isEmpty()) {
        qDebug() << "Nie zaznaczono żadnego użytkownika.";
        return;
    }

    qDebug() << "Zaznaczono" << selected.count() << "wiersze:";

    for (const QModelIndex &index : selected) {
        int row = index.row();
        QStringList rowData;

        for (int col = 0; col < modelUsers->columnCount(); ++col) {
            QModelIndex cellIndex = modelUsers->index(row, col);
            rowData << modelUsers->data(cellIndex).toString();
        }

        qDebug() << "->" << rowData.join(" | ");
    }
}


void Tab_Uzytkownicy::setDatabaseManager(DatabaseManager* dbManager)
{
     m_dbManager = dbManager;

    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        qDebug() << "Baza danych nie jest otwarta lub m_dbManager jest nullptr";
        return;
    }

    if (!tabelaTableView) {
        qDebug() << "Brak tableView_uzytkownicy - nie można ustawić modelu";
        return;
    }

    modelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    modelUsers->setTable("Uzytkownik zalogowany");  // toDo  trzeba wyrzucić wyświetlanie niektórych kolumn
    if (!modelUsers->select()) {
        qDebug() << "Błąd ładowania danych:" << modelUsers->lastError().text();
    }

    tabelaTableView->setModel(modelUsers);
    tabelaTableView->resizeColumnsToContents();
    tabelaTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    // Ukryj wszystkie kolumny poza Imie, Nazwisko, Email
    for (int col = 0; col < modelUsers->columnCount(); ++col) {
        QString colName = modelUsers->headerData(col, Qt::Horizontal).toString();
        if (colName != "Imie" && colName != "Nazwisko" && colName != "Email") {
            tabelaTableView->hideColumn(col);
        }
    }
}

void Tab_Uzytkownicy::goToStartPage() {
    stacked->setCurrentIndex(0);
}
