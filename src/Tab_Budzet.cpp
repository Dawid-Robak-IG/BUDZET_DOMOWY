#include "../inc/Tab_Budzet.hpp"

Tab_Budzet::Tab_Budzet(QWidget *root,QWidget *parent)
    : QWidget{parent}
{


    dataBudzet=root->findChild<QLineEdit*>("lineEdit_dataBudzet");
    kwotaBudzet=root->findChild<QLineEdit*>("lineEdit_stanBudzet");
    tabelaOperacje=root->findChild<QTableView*>("tableView_budzet");

    if(!dataBudzet || !kwotaBudzet || !tabelaOperacje)
    {
        qDebug()<<"cos niepoprawnie przypisne";

    }
}

void Tab_Budzet::setDatabaseManager(DatabaseManager* dbManager) {
    m_dbManager = dbManager;


    kwotaBudzet->setText(QString::number(m_dbManager->get_whole_budzet(), 'f', 2));
    QDate data = m_dbManager->get_update_Date();
    dataBudzet->setText(data.toString("yyyy-MM-dd"));

loadOperacjeTable();
}

void Tab_Budzet::loadOperacjeTable() {
    if (!m_dbManager) return;

    if (modelOperacje) {
        delete modelOperacje;
    }

    modelOperacje = new QSqlTableModel(this, m_dbManager->getDatabase());
    modelOperacje->setTable("Operacja");
    modelOperacje->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelOperacje->select();

    tabelaOperacje->setModel(modelOperacje);
    tabelaOperacje->resizeColumnsToContents();
    //tabelaOperacje->horizontalHeader()->setStretchLastSection(true);
    tabelaOperacje->setEditTriggers(QAbstractItemView::NoEditTriggers); // tylko do odczytu

    tabelaOperacje->hideColumn(0);
    tabelaOperacje->hideColumn(7);

}
