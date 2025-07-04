#include "MainWindow.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    m_dbManager = new DatabaseManager(this);
    m_dbManager->openConnection();

    setWindowTitle("Budzet domowy");

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    logRegScreen = new Start_Log_Reg(this);
    stackedWidget->addWidget(logRegScreen);

    m_userPanel = nullptr; // Inicjalizujemy na nullptr

    logRegScreen->setDatabaseManager(m_dbManager);

    // Łączymy sygnał logowania, żeby przełączyć na user_panel
    connect(logRegScreen, &Start_Log_Reg::loginSuccessful, this, &MainWindow::handleLogin);

}


MainWindow::~MainWindow() {
    delete m_userPanel;
    delete logRegScreen;
    delete m_dbManager;
}

void MainWindow::handleLogin(QString email) {
    if (!m_dbManager || !m_dbManager->getDatabase().isOpen()) {
        QMessageBox::critical(this, "Błąd", "Baza danych nie jest otwarta!");
        return;
    }

    m_dbManager->update_Children();
    qDebug()<<"Zakończono aktualizacje dzieci";
    m_dbManager->startSystemCykl();
    qDebug()<<"Zakończono wykonywanie cyklicznych";


    if (!m_userPanel) {

        m_userPanel = new User_Panel(email,this);
        qDebug()<<"Stworzono nowy UserPanel";

        m_userPanel->setDatabaseManager(m_dbManager);
        qDebug()<<"Nowy userPanel";
        stackedWidget->addWidget(m_userPanel);
        connect(m_userPanel, &User_Panel::logoutRequested, this, &MainWindow::handleLogout);
        qDebug()<<"Dodano UserPanel jako widget i połączono syngał wylologowania";
        m_userPanel->displayUserData(email);
        qDebug()<<"Ustanowiono wyświetlanie UserData";
        m_userPanel->goToStartPage();
        qDebug()<<"Przeniesiono do ekranu startowego";
        stackedWidget->setCurrentWidget(m_userPanel);
        m_userPanel->setTabsVisibility();
    } else {
        qDebug()<<"User Panel już istnieje, aktualizacja dla nowego użytkownika";

        m_userPanel->setUserEmail(email); // Jeśli userPanel już istnieje, tylko aktualizujemy email
        m_userPanel->displayUserData(email);      // I przeładowujemy rolę
        m_userPanel->goToStartPage();
        m_userPanel->setTablesByNewUser();
        stackedWidget->setCurrentWidget(m_userPanel);
        m_userPanel->setTabsVisibility();
    }
}


void MainWindow::handleLogout() {
    qDebug() << "Wylogowywanie... i SUPER DUPER NOWE ENCJE DZIECI ORAZ ZADZIAŁANIE SYSTEMU";
    // m_dbManager->update_Children();
    // m_dbManager->startSystemCykl();
    logRegScreen->goToStartPage();
    stackedWidget->setCurrentWidget(logRegScreen);

    qDebug()<<"Przewidywany dla uzytkownika: "<<m_dbManager->user_future_Budzet(m_dbManager->get_user_ID(),QDate::fromString("2025-07-01", "yyyy-MM-dd")) <<" zl";
    qDebug()<<"Przewidywany dla budzetu: "<<m_dbManager->user_future_Budzet(m_dbManager->get_user_ID(),QDate::fromString("2025-07-01", "yyyy-MM-dd")) <<" zl";
}
