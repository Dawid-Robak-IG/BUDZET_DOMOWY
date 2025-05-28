#include "../inc/Tab_Dzieci.hpp"

Tab_Dzieci::Tab_Dzieci(const QString& userEmail,QWidget *root, QWidget *parent)
    : QWidget{parent},m_userEmail(userEmail)
{

    //kieszonkoweTable=root->findChild<QTableView*>("tableView_aktualneKieszonkowe");

    aktualneSaldoLineEdit= root->findChild<QLineEdit*>("lineEdit_aktualneSaldo");
    aktualneKieszonkoweLineEdit = root->findChild<QLineEdit*>("lineEdit_aktualneKieszonkoweKwota");

    aktualneSaldoLineEdit->setReadOnly(true);

    generujRaportButton= root->findChild<QPushButton*>("pushButton_generujRaportD");
    zmienKieszonkoweButton= root->findChild<QPushButton*>("pushButton_zmienKieszonkowe");
    listaDzieciCombo=root->findChild<QComboBox*>("comboBox_dzieciLista");


    if(generujRaportButton){
        connect(generujRaportButton, &QPushButton::clicked, this, &Tab_Dzieci::GenerujRaportClicked);
    }

    if(zmienKieszonkoweButton){
        connect(zmienKieszonkoweButton, &QPushButton::clicked, this, &Tab_Dzieci::ZmienKieszonkoweClicked);
    }

    if (listaDzieciCombo) {
    connect(listaDzieciCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Tab_Dzieci::onDzieckoSelected);
    }
}

void Tab_Dzieci::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    loadDzieciListComboBox();
    showTable();
}


void Tab_Dzieci::GenerujRaportClicked(){ //toDo
    qDebug()<<"Tu będzie generowanie raportu dla dziecka";
}

void Tab_Dzieci::ZmienKieszonkoweClicked() {
    if (!m_dbManager) return;

    int currentIndex = listaDzieciCombo->currentIndex();
    if (currentIndex < 0) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano dziecka!");
        return;
    }

    int childID = listaDzieciCombo->itemData(currentIndex).toInt();

    bool ok;
    double newKieszonkowe = QInputDialog::getDouble(this,
                                "Nowe kieszonkowe",
                                "Podaj nową kwotę kieszonkowego:",
                                0.0, 0.0, 100000.0, 2, &ok);

    if (!ok) return;

    if (!m_dbManager->change_kieszonkowe(childID, newKieszonkowe)) {
        QMessageBox::critical(this, "Błąd", "Nie udało się zmienić kieszonkowego!");
    } else {
        QMessageBox::information(this, "Sukces", "Kieszonkowe zostało zaktualizowane.");
        updateSaldoIKieszonkoweLabel(childID);
    }
}


void Tab_Dzieci::showTable(){ //toDo wyświetlenie konkretnego wpisu z cyklicznych opercji dla tego dziecka jego kieszonkowe

}

void Tab_Dzieci::loadDzieciListComboBox() {
    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        qDebug() << "Baza danych nie jest dostępna!";
        return;
    }

    if (!listaDzieciCombo) {
        qDebug() << "listaDzieciCombo nie została znaleziona!";
        return;
    }

    listaDzieciCombo->clear();

    QSqlQuery rolaQuery(m_dbManager->getDatabase());
    rolaQuery.prepare("SELECT Rola FROM `Uzytkownik zalogowany` WHERE ID = :id");
    rolaQuery.bindValue(":id", m_dbManager->get_user_ID());

    if (!rolaQuery.exec() || !rolaQuery.next()) {
        qDebug() << "Nie udało się pobrać roli użytkownika!";
        return;
    }

    QString rola = rolaQuery.value("Rola").toString();

    QSqlQuery query(m_dbManager->getDatabase());

    if (rola == "Admin") {
        query.prepare(R"(
            SELECT uz.ID, uz.Imie, uz.Nazwisko
            FROM `Uzytkownik zalogowany` uz
            WHERE uz.Rola = 'Dziecko'
        )");
    } else {
        query.prepare(R"(
            SELECT uz.ID, uz.Imie, uz.Nazwisko
            FROM `Uzytkownik zalogowany` uz
            JOIN Dziecko d ON uz.ID = d.`Uzytkownik zalogowanyID`
            WHERE uz.Rola = 'Dziecko'
              AND (d.ID_Rodzic1 = :myID OR d.ID_Rodzic2 = :myID)
        )");
        query.bindValue(":myID", m_dbManager->get_user_ID());
    }

    if (!query.exec()) {
        qDebug() << "Błąd zapytania dzieci:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString imie = query.value("Imie").toString();
        QString nazwisko = query.value("Nazwisko").toString();
        int id = query.value("ID").toInt();
        listaDzieciCombo->addItem(imie + " " + nazwisko, id);  // dodaj ID jako userData
    }

    if (listaDzieciCombo->count() == 0) {
        listaDzieciCombo->addItem("Brak przypisanych dzieci");
    }
}
void Tab_Dzieci::onDzieckoSelected(int index) {
    if (index < 0 || !m_dbManager || !aktualneSaldoLineEdit) return;

    bool ok = false;
    int dzieckoID = listaDzieciCombo->currentData().toInt(&ok);
    if (!ok) return;

    float saldo = m_dbManager->get_saldo(dzieckoID);
    float kieszonkowe = m_dbManager->get_kieszonkowe(dzieckoID);

    // QString text = QString("Saldo: %1 zł | Kieszonkowe: %2 zł")
    //                    .arg(saldo, 0, 'f', 2)
    //                    .arg(kieszonkowe, 0, 'f', 2);
    // aktualneSaldoLineEdit->setText(text);
    aktualneKieszonkoweLineEdit->setText(QString::number(kieszonkowe, 'f', 2));
    aktualneSaldoLineEdit->setText(QString::number(saldo, 'f', 2));
}


void Tab_Dzieci::updateSaldoIKieszonkoweLabel(int childID) {
    float saldo = m_dbManager->get_saldo(childID);
    float kieszonkowe = m_dbManager->get_kieszonkowe(childID);

    if (aktualneSaldoLineEdit) {
        aktualneKieszonkoweLineEdit->setText(QString::number(kieszonkowe, 'f', 2));
        aktualneSaldoLineEdit->setText(QString::number(saldo, 'f', 2));

        // aktualneSaldoLineEdit->setText(
        //     QString("Saldo: %1 zł | Kieszonkowe: %2 zł")
        //     .arg(saldo, 0, 'f', 2)
        //     .arg(kieszonkowe, 0, 'f', 2)
        // );


    }
}
