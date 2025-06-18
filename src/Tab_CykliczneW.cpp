#include "../inc/Tab_CykliczneW.hpp"

Tab_CykliczneW::Tab_CykliczneW(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{
    modelUsers = nullptr;

    stacked= root->findChild<QStackedWidget*>("stackedWidget_CykliczneW");
    cykliczneWTable =root->findChild<QTableView*>("tableView_listaCW");
    // edytujCW_Button= root->findChild<QPushButton*>("pushButton_edytujCW");
    nowyCW_Button= root->findChild<QPushButton*>("pushButton_nowyCW");
    usunCW_Button= root->findChild<QPushButton*>("pushButton_usunCW");
    //zeby dodać nowy:
    kategoriaCombo= root->findChild<QComboBox*>("comboBox_kategoriaCW");
    czestotliwoscCombo =root->findChild<QComboBox*>("comboBox_czestotliwoscCW");
    if (czestotliwoscCombo) {
    czestotliwoscCombo->addItems({"Codziennie", "Co tydzień", "Co miesiąc", "Co rok"});
    }
    startCW_Data = root->findChild<QDateEdit*>("dateEdit_CW");
    kwotaCW= root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaCW");
    notatkaCW_LineEdit= root->findChild<QLineEdit*>("lineEdit_notatkaCW");
    powrotCW_Button= root->findChild<QPushButton*>("pushButton_powrotCW");
    dodajCW_Button= root->findChild<QPushButton*>("pushButton_dodajCW");

    //podłączenie do konkretnych elementów
    if(dodajCW_Button){
        connect(dodajCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::DodajCW_Clicked);
    }

    // if(edytujCW_Button){
    //     connect(edytujCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::EdytujCW_Clicked);
    // }

    if(usunCW_Button){
        connect(usunCW_Button, &QPushButton::clicked, this, &Tab_CykliczneW::UsunCW_Clicked);
    }

    connect(nowyCW_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(1);
    });

    connect(powrotCW_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(0);
    });

    startCW_Data->setDate(QDate::currentDate());
    stacked->setCurrentIndex(0);
}
void Tab_CykliczneW::DodajCW_Clicked(){ 
    if(m_dbManager->amIChild()){
        QMessageBox::warning(this, "Błąd", "Dzieci i niezdefiniowani użytkownicy nie mogą dodawać wydatków");
        return;
    }

    qDebug() << "Dodawanie cyklicznego przychodu";

    QString kategoria = kategoriaCombo->currentText();
    QString czestotliwosc = czestotliwoscCombo->currentText();
    QDate data = startCW_Data->date();
    double kwota = kwotaCW->value();
    QString notatka = notatkaCW_LineEdit->text();

    kwota*=-1;


    if (m_dbManager->addCykliczny(kwota, data, notatka, czestotliwosc, kategoria)) {
        qDebug() << "Cykliczny przychód został dodany.";
        QMessageBox::information(this, "Sukces", "Cykliczny przychód został dodany pomyślnie.");
        reset_Tab();
        modelUsers->select();
    } else {
        qDebug() << "Nie udało się dodać cyklicznego przychodu.";
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać cyklicznego przychodu.");
    }
}

// void Tab_CykliczneW::EdytujCW_Clicked(){//toDo
//     qDebug()<<"Tutaj będzie edytowanie cyklicznego przychodu";
// }

void Tab_CykliczneW::UsunCW_Clicked(){
    qDebug() << "Usuwanie cyklicznego przychodu";

    QModelIndex index = cykliczneWTable->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Brak wyboru", "Wybierz pozycję do usunięcia.");
        return;
    }

    int row = index.row();
    int id = modelUsers->data(modelUsers->index(row, 0)).toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Potwierdzenie usunięcia",
        "Czy na pewno chcesz usunąć ten cykliczny przychód?",
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        if (m_dbManager->deleteCykliczny(id)) {
            QMessageBox::information(this, "Sukces", "Usunięto przychód.");
            modelUsers->select();
        } else {
            QMessageBox::warning(this, "Błąd", "Nie udało się usunąć przychodu.");
        }
    }
}


void Tab_CykliczneW::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    qDebug()<<"CYKLICZNE_W: ustatiowno dbManager";
    loadKategorie();
    qDebug()<<"CYKLICZNE_W: załadowano kategorie";
    showTable();
    qDebug()<<"CYKLICZNE_W: pokazano Table";
    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
            this, &Tab_CykliczneW::loadKategorie);
    qDebug()<<"CYKLICZNE_W: polaczono syngal dla nowej kategorii";
}

void Tab_CykliczneW::showTable(){
    if (!cykliczneWTable) {
        qDebug() << "Brak cyklicznePTable - nie można ustawić modelu";
        return;
    }
    setTableStrategy();
    qDebug()<<"CYKLICZNE_W: ustawiono strategie table";

    cykliczneWTable->resizeColumnsToContents();

    // Delegat dla "Częstotliwość"
    QStringList czestotliwoscList = {"Codziennie", "Co tydzień", "Co miesiąc", "Co rok"};
    int czestCol = modelUsers->fieldIndex("Czestotliwosc");
    cykliczneWTable->setItemDelegateForColumn(czestCol, new ComboBoxDelegate(czestotliwoscList, this));

    // Delegat dla "Kategoria" - pobieramy dynamicznie z bazy
    QStringList kategorie = m_dbManager->getAllKategorie();  // zakładam, że masz to
    int katCol = modelUsers->fieldIndex("Kategoria");
    cykliczneWTable->setItemDelegateForColumn(katCol, new ComboBoxDelegate(kategorie, this));



    cykliczneWTable->resizeColumnsToContents();
}



void Tab_CykliczneW::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}

void Tab_CykliczneW::goToStartPage() {
    stacked->setCurrentIndex(0);
}
void Tab_CykliczneW::setTableStrategy(){
    qDebug()<<"CYKLCIZNE_W: rozpoczęcie setTabelStrategy";
    if(!modelUsers){
        modelUsers = new QSqlRelationalTableModel(this, m_dbManager->getDatabase());
        qDebug()<<"CYKLICZNE_W: stworzono nowy TableModel";
    }
    modelUsers->setTable("`Operacja cykliczna`");
    modelUsers->setEditStrategy(QSqlTableModel::OnFieldChange);

    QString filter = "`Kwota` < 0";

    if(!m_dbManager->amI_admin()){
        filter += QString(" AND `Uzytkownik zalogowanyID` = %1").arg(m_dbManager->get_user_ID());
    }

    modelUsers->setFilter(filter);
    qDebug()<<"CYKLICZNE_W: nowy filter";

    modelUsers->setRelation(
        modelUsers->fieldIndex("Uzytkownik zalogowanyID"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );
    qDebug()<<"CYKLICZNE_W: dodano kolumny z widoku"; 

    modelUsers->select(); 
    qDebug()<<"CYKLICZNE_W: odswierzono tabelke"; 

    cykliczneWTable->setModel(modelUsers);
    cykliczneWTable->hideColumn(modelUsers->fieldIndex("ID"));
    //cykliczneWTable->hideColumn(modelUsers->fieldIndex("Uzytkownik zalogowanyID"));

    cykliczneWTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(cykliczneWTable, &QTableView::doubleClicked, this, [=](const QModelIndex &index){
        QString colName = modelUsers->headerData(index.column(), Qt::Horizontal).toString();

        if (colName == "Uzytkownik zalogowanyID" or colName=="ImieNazwisko") {
            qDebug() << "Edycja zabroniona dla kolumny:" << colName;
            return;
        }

        cykliczneWTable->edit(index);
    });
}
void Tab_CykliczneW::reset_Tab(){
    kategoriaCombo->setCurrentIndex(0);
    czestotliwoscCombo->setCurrentIndex(0);
    startCW_Data->setDate(QDate::currentDate());
    kwotaCW->setValue(0.0);
    notatkaCW_LineEdit->clear();
}
