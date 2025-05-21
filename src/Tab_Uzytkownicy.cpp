#include "../inc/Tab_Uzytkownicy.hpp"

Tab_Uzytkownicy::Tab_Uzytkownicy(QWidget *root,QWidget *parent)
    : QWidget{parent}
{

    tabelaTableView = root->findChild<QTableView*>("tableView_uzytkownicy");

    if (!tabelaTableView) {
        qDebug() << "Nie znaleziono tableView_uzytkownicy!";
        return;
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
    modelUsers->setTable("Uzytkownik zalogowany");
    if (!modelUsers->select()) {
        qDebug() << "Błąd ładowania danych:" << modelUsers->lastError().text();
    }

    tabelaTableView->setModel(modelUsers);
    tabelaTableView->resizeColumnsToContents();

}
