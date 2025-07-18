#include "../inc/Tab_Uzytkownicy.hpp"

Tab_Uzytkownicy::Tab_Uzytkownicy(QWidget *root,QWidget *parent): QWidget{parent}{

    tabelaTableView = root->findChild<QTableView*>("tableView_uzytkownicy");
   stacked= root->findChild<QStackedWidget*>("stackedWidget_uzytkownicy");

    blokadaButton= root->findChild<QPushButton*>("pushButton_zablokuj_odblokuj");
    // edytujButton= root->findChild<QPushButton*>("pushButton_edytujDane");
    powrotButton= root->findChild<QPushButton*>("pushButton_powrotE");
    zapiszZmianyButton= root->findChild<QPushButton*>("pushButton_zapiszE");
    rolaCombo= root->findChild<QComboBox*>("comboBox_rolaE");
    imie = root->findChild<QLineEdit*>("lineEdit_imieE");
    nazwisko = root->findChild<QLineEdit*>("lineEdit_nazwiskoE");
    mail = root->findChild<QLineEdit*>("lineEdit_mailE");
    checkBox_pokazHasla=root->findChild<QCheckBox*>("checkBox_pokazHasla");

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
    if(!m_dbManager->amI_admin()){
        QMessageBox::warning(this, "Błąd", "Tylko admin może blokować/odblokowywać użytkowników");
        return; 
    }
    qDebug() << "Blokowanie/Odblokowywanie";

    QModelIndex index = tabelaTableView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Brak wyboru", "Wybierz użytkownika do Odblokowania/Zablokowania");
        return;
    }
    int row = index.row();
    int id = modelUsers->data(modelUsers->index(row, 0)).toInt();

    if (m_dbManager->changeStatusUser(id)) {
        QMessageBox::information(this, "Sukces", "Zablokowano/Odblokowano użytkownika");
        modelUsers->select();
    } else {
        QMessageBox::warning(this, "Błąd", "Akcja nie powiodła się");
    }
}


void Tab_Uzytkownicy::setDatabaseManager(DatabaseManager* dbManager){
     m_dbManager = dbManager;

    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        qDebug() << "Baza danych nie jest otwarta lub m_dbManager jest nullptr";
        return;
    }

    if (!tabelaTableView) {
        qDebug() << "Brak tableView_uzytkownicy - nie można ustawić modelu";
        return;
    }

    bool children = (m_dbManager->amIChild() && !m_dbManager->amI_Noone());

    setTableStrategy();

    blokadaButton->setVisible(m_dbManager->amI_admin());
    checkBox_pokazHasla->setVisible(m_dbManager->amI_admin());
}

void Tab_Uzytkownicy::goToStartPage() {
    stacked->setCurrentIndex(0);
}
void Tab_Uzytkownicy::setTableStrategy(){
    if(!modelUsers)modelUsers = new QSqlTableModel(this, m_dbManager->getDatabase());
    modelUsers->setTable("Uzytkownik zalogowany");
    if (!modelUsers->select()) {
        qDebug() << "Błąd ładowania danych:" << modelUsers->lastError().text();
    }

    tabelaTableView->setModel(modelUsers);
    tabelaTableView->resizeColumnsToContents();

    int kolumnaHasla = modelUsers->fieldIndex("Haslo");

    connect(checkBox_pokazHasla, &QCheckBox::toggled, this, [=](bool zaznaczone) {
        if (zaznaczone) {
            tabelaTableView->setItemDelegateForColumn(kolumnaHasla, nullptr); // Pokazuje normalnie
        } else {
            tabelaTableView->setItemDelegateForColumn(kolumnaHasla, new PasswordDelegate(this)); // Ukrywa hasła
        }
    });

    tabelaTableView->setSortingEnabled(true);
    tabelaTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabelaTableView->hideColumn(modelUsers->fieldIndex("Haslo"));
    tabelaTableView->hideColumn(modelUsers->fieldIndex("ID"));
    tabelaTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // Odłącz poprzednie połączenia (zapobiega pozostaniu trybu edycji po zmianie użytkownika)
    disconnect(tabelaTableView, &QTableView::doubleClicked, nullptr, nullptr);

    if (m_dbManager->amI_admin()) {
        tabelaTableView->showColumn(modelUsers->fieldIndex("Haslo"));
        // tabelaTableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

        QStringList role = {"Admin", "Rodzic", "Dorosły", "Dziecko", "Użytkownik"};
        int rolaCol = modelUsers->fieldIndex("Rola");
        tabelaTableView->setItemDelegateForColumn(rolaCol, new ComboBoxDelegate(role, this));

        connect(tabelaTableView, &QTableView::doubleClicked, this, [=](const QModelIndex &index){
            QString colName = modelUsers->headerData(index.column(), Qt::Horizontal).toString();

            if (colName == "ID" || colName == "Data urodzenia") {
                qDebug() << "Edycja zabroniona dla kolumny:" << colName;
                return;
            }
            if (colName == "Rola") {
                QString rolaUzytkownika = modelUsers->data(modelUsers->index(index.row(), modelUsers->fieldIndex("Rola"))).toString();
                int idUzytkownika = modelUsers->data(modelUsers->index(index.row(), modelUsers->fieldIndex("ID"))).toInt();
                int mojeId = m_dbManager->get_user_ID(); 

                if (rolaUzytkownika == "Admin" && idUzytkownika != mojeId) {
                    QMessageBox::warning(this, "Zabronione", "Nie można zmienić roli innemu administratorowi");
                    return;
                }
                if(rolaUzytkownika == "Admin" && m_dbManager->how_many_admins()<2){
                    QMessageBox::warning(this, "Zabronione", "W systemie musi istnieć co najmniej jeden admin");
                    return;
                }
            }
            tabelaTableView->edit(index);
        });
    }

    modelUsers->setHeaderData(1, Qt::Horizontal, "Imię");
    modelUsers->setHeaderData(4, Qt::Horizontal, "Hasło");
    tabelaTableView->setItemDelegateForColumn(kolumnaHasla, new PasswordDelegate(this));
    int kolumnaZablokowany = modelUsers->fieldIndex("Czy_zablokowany");
    modelUsers->setHeaderData(5, Qt::Horizontal, "Status");
    tabelaTableView->setItemDelegateForColumn(kolumnaZablokowany, new BlockedDelegate(this));

    blokadaButton->setVisible(m_dbManager->amI_admin());
    checkBox_pokazHasla->setVisible(m_dbManager->amI_admin());
}
