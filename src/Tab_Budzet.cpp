#include "../inc/Tab_Budzet.hpp"

Tab_Budzet::Tab_Budzet(QWidget *root,QWidget *parent) : QWidget{parent}{
    dataBudzet=root->findChild<QLineEdit*>("lineEdit_dataBudzet");
    kwotaBudzet=root->findChild<QLineEdit*>("lineEdit_stanBudzet");
    tabelaOperacje=root->findChild<QTableView*>("tableView_budzet");

    if(!dataBudzet || !kwotaBudzet || !tabelaOperacje)
    {
        qDebug()<<"cos niepoprawnie przypisne";

    }

    modelOperacje = nullptr;
}

void Tab_Budzet::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;
    qDebug()<<"BUDZET: ustawiono dbManager";

    kwotaBudzet->setText(QString::number(m_dbManager->get_whole_budzet(), 'f', 2));
    QDate data = m_dbManager->get_update_Date();
    qDebug()<<"BUDZET: Nowa data";
    dataBudzet->setText(data.toString("dd-MM-yyyy"));
    qDebug()<<"BUDZET: format daty";
    loadOperacjeTable();
    qDebug()<<"BUDZET: Zakonczono loadOperacjeTable";

    refresh();
}

void Tab_Budzet::loadOperacjeTable() {
    if (!m_dbManager) return;

    if(modelOperacje){
        delete modelOperacje;
    }

    modelOperacje = new QSqlRelationalTableModel(this, m_dbManager->getDatabase());
    qDebug()<<"BUDZET: nowy model Table";
    modelOperacje->setTable("Operacja");
    modelOperacje->setEditStrategy(QSqlTableModel::OnManualSubmit);
    qDebug()<<"BUDZET: Zakonczono setEdutTable";

    int kolumnaCykliczne = modelOperacje->fieldIndex("czy_z_cyklicznego");
    modelOperacje->setHeaderData(kolumnaCykliczne, Qt::Horizontal, "Rodzaj operacji");

    modelOperacje->setRelation(
        modelOperacje->fieldIndex("Uzytkownik zalogowanyID"),
        QSqlRelation("V_UzytkownikWidoczny", "ID", "ImieNazwisko")
    );

    if (m_dbManager->amIChild()) {
        int userId = m_dbManager->get_user_ID();
        modelOperacje->setFilter(QString("`Uzytkownik zalogowanyID` = %1").arg(userId));
    }

    modelOperacje->select();
    tabelaOperacje->setModel(modelOperacje);

    //  tabelaOperacje->resizeColumnsToContents();
    tabelaOperacje->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tabelaOperacje->horizontalHeader()->setStretchLastSection(true);
    tabelaOperacje->setEditTriggers(QAbstractItemView::NoEditTriggers); // tylko do odczytu

    tabelaOperacje->hideColumn(modelOperacje->fieldIndex("ID"));
    tabelaOperacje->hideColumn(modelOperacje->fieldIndex("Uzytkownik zalogowanyID"));
    tabelaOperacje->hideColumn(modelOperacje->fieldIndex("Operacja cyklicznaID"));

    int kolumnaKwota = modelOperacje->fieldIndex("Kwota");
    tabelaOperacje->setItemDelegateForColumn(kolumnaKwota, new KwotaColorDelegate(this));
    tabelaOperacje->setItemDelegateForColumn(kolumnaCykliczne, new CyklicznyDelegate(this));

    modelOperacje->setHeaderData(4, Qt::Horizontal, "Imię i nazwisko");
    modelOperacje->setHeaderData(5, Qt::Horizontal, "Kategoria");

    refresh();
}

void Tab_Budzet::refresh()
{
    if (modelOperacje) {
        modelOperacje->select(); // odśwież dane z tabeli Operacja
    }
    
    if(m_dbManager->amIChild()){
        kwotaBudzet->setText(QString::number(m_dbManager->get_saldo(m_dbManager->get_user_ID()), 'f', 2));
        dataBudzet->setText(m_dbManager->get_my_last_update_Date().toString("dd-MM-yyyy")); 
    }
    else{
        kwotaBudzet->setText(QString::number(m_dbManager->get_whole_budzet(), 'f', 2));
        dataBudzet->setText(m_dbManager->get_update_Date().toString("dd-MM-yyyy")); 
    }
    qDebug() << "Tab_Budzet: odświeżono dane.";
}
