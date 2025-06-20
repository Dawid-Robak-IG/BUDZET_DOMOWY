#include "../inc/Tab_CykliczneP.hpp"

Tab_CykliczneP::Tab_CykliczneP(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    stacked= root->findChild<QStackedWidget*>("stackedWidget_CykliczneP");
    cyklicznePTable =root->findChild<QTableView*>("tableView_listaCP");
    // edytujCP_Button= root->findChild<QPushButton*>("pushButton_edytujCP");
    nowyCP_Button= root->findChild<QPushButton*>("pushButton_nowyCP");
    usunCP_Button= root->findChild<QPushButton*>("pushButton_usunCP");
    //zeby dodać nowy:
    kategoriaCombo= root->findChild<QComboBox*>("comboBox_kategoriaCP");
    czestotliwoscCombo =root->findChild<QComboBox*>("comboBox_czestotliwoscCP");
    if (czestotliwoscCombo) {
    czestotliwoscCombo->addItems({"Codziennie", "Co tydzień", "Co miesiąc", "Co rok"});
    }
    startCP_Data = root->findChild<QDateEdit*>("dateEdit_CP");
    kwotaCP= root->findChild<QDoubleSpinBox*>("doubleSpinBox_kwotaCP");
    notatkaCP_LineEdit= root->findChild<QLineEdit*>("lineEdit_notatkaCP");
    powrotCP_Button= root->findChild<QPushButton*>("pushButton_powrotCP");
    dodajCP_Button= root->findChild<QPushButton*>("pushButton_dodajCP");

    //podłączenie do konkretnych elementów
    if(dodajCP_Button){
        connect(dodajCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::DodajCP_Clicked);
    }

    // if(edytujCP_Button){
    //     connect(edytujCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::EdytujCP_Clicked);
    // }

    if(usunCP_Button){
        connect(usunCP_Button, &QPushButton::clicked, this, &Tab_CykliczneP::UsunCP_Clicked);
    }

    connect(nowyCP_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(1);
    });

    connect(powrotCP_Button, &QPushButton::clicked, [this](){
        stacked->setCurrentIndex(0);
    });

  startCP_Data->setDate(QDate::currentDate());
  stacked->setCurrentIndex(0);
}
void Tab_CykliczneP::DodajCP_Clicked(){
    if(m_dbManager->amIChild()){
        QMessageBox::warning(this, "Błąd", "Dzieci i niezdefiniowani użytkownicy nie mogą dodawać wydatków");
        return;
    }

    qDebug() << "Dodawanie cyklicznego przychodu";

    QString kategoria = kategoriaCombo->currentText();
    QString czestotliwosc = czestotliwoscCombo->currentText();
    QDate data = startCP_Data->date();
    double kwota = kwotaCP->value();
    QString notatka = notatkaCP_LineEdit->text();


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

// void Tab_CykliczneP::EdytujCP_Clicked(){//toDo
//     qDebug()<<"Tutaj będzie edytowanie cyklicznego przychodu";
// }

void Tab_CykliczneP::UsunCP_Clicked()
{
    qDebug() << "Usuwanie cyklicznego przychodu";

    QModelIndex index = cyklicznePTable->currentIndex();

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
void Tab_CykliczneP::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadKategorie();
    showTable();
    connect(m_dbManager, &DatabaseManager::nowaKategoriaDodana,
        this, &Tab_CykliczneP::loadKategorie);
    setTableStrategy();


    cyklicznePTable->resizeColumnsToContents();

    // Delegat dla "Częstotliwość"
    QStringList czestotliwoscList = {"Codziennie", "Co tydzień", "Co miesiąc", "Co rok"};
    int czestCol = modelUsers->fieldIndex("Czestotliwosc");
    cyklicznePTable->setItemDelegateForColumn(czestCol, new ComboBoxDelegate(czestotliwoscList, this));

    // Delegat dla "Kategoria"
    QStringList kategorie = m_dbManager->getAllKategorie();
    int katCol = modelUsers->fieldIndex("Kategoria");
    cyklicznePTable->setItemDelegateForColumn(katCol, new ComboBoxDelegate(kategorie, this));
}

void Tab_CykliczneP::showTable(){
    if (!cyklicznePTable) {
        qDebug() << "Brak cyklicznePTable - nie można ustawić modelu";
        return;
    }
    setTableStrategy();
    cyklicznePTable->resizeColumnsToContents();
}

void Tab_CykliczneP::loadKategorie() {
    if (!m_dbManager) return;

    QStringList kategorie = m_dbManager->getAllKategorie();
    kategoriaCombo->clear();
    kategoriaCombo->addItems(kategorie);
}

void Tab_CykliczneP::goToStartPage() {
   stacked->setCurrentIndex(0);
}
void Tab_CykliczneP::setTableStrategy(){
    qDebug()<<"CYKLCIZNE_P: rozpoczęcie setTabelStrategy";
    if(!modelUsers){
        modelUsers = new QSqlRelationalTableModel(this, m_dbManager->getDatabase());
        qDebug()<<"CYKLICZNE_P: stworzono nowy TableModel";
    }
    modelUsers->setTable("`Operacja cykliczna`");
    modelUsers->setEditStrategy(QSqlTableModel::OnFieldChange);

    QString filter = "`Kwota` > 0";

    if(!m_dbManager->amI_admin()){
        filter += QString(" AND `Uzytkownik zalogowanyID` = %1").arg(m_dbManager->get_user_ID());
    }

    modelUsers->setFilter(filter);
    qDebug()<<"CYKLICZNE_P: nowy filter";

    modelUsers->setRelation(
        modelUsers->fieldIndex("Uzytkownik zalogowanyID"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );
    qDebug()<<"CYKLICZNE_P: dodano kolumny z widoku"; 

    modelUsers->select(); 
    qDebug()<<"CYKLICZNE_P: odswierzono tabelke"; 

    cyklicznePTable->setModel(modelUsers);
    cyklicznePTable->hideColumn(modelUsers->fieldIndex("ID"));
    //cykliczneWTable->hideColumn(modelUsers->fieldIndex("Uzytkownik zalogowanyID"));

    cyklicznePTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cyklicznePTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(cyklicznePTable, &QTableView::doubleClicked, this, [=](const QModelIndex &index){
        QString colName = modelUsers->headerData(index.column(), Qt::Horizontal).toString();

        if (colName == "Uzytkownik zalogowanyID" or colName=="ImieNazwisko") {
            qDebug() << "Edycja zabroniona dla kolumny:" << colName;
            return;
        }

        cyklicznePTable->edit(index);
    });

    modelUsers->setHeaderData(4, Qt::Horizontal, "Częstotliwość");
    modelUsers->setHeaderData(5, Qt::Horizontal, "Imię i nazwisko");
    modelUsers->setHeaderData(7, Qt::Horizontal, "Kolejna data");
}
void Tab_CykliczneP::reset_Tab(){
    kategoriaCombo->setCurrentIndex(0);
    czestotliwoscCombo->setCurrentIndex(0);
    startCP_Data->setDate(QDate::currentDate());
    kwotaCP->setValue(0.0);
    notatkaCP_LineEdit->clear();
}
