#include "MainWindow.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    m_dbManager = new DatabaseManager(this);
    m_dbManager->openConnection();

    setWindowTitle("Budzet domowy");

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    logRegScreen = new Start_Log_Reg();
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

    if (!m_userPanel) {
        m_userPanel = new User_Panel(email,this);
        m_userPanel->setDatabaseManager(m_dbManager);

        stackedWidget->addWidget(m_userPanel);
        connect(m_userPanel, &User_Panel::logoutRequested, this, &MainWindow::handleLogout);

    } else {
        m_userPanel->setUserEmail(email); // Jeśli userPanel już istnieje, tylko aktualizujemy email
        m_userPanel->displayUserData(email);      // I przeładowujemy rolę
    }


    stackedWidget->setCurrentWidget(m_userPanel);
}


void MainWindow::handleLogout() {
    qDebug() << "Wylogowywanie...";
    logRegScreen->goToStartPage();
    stackedWidget->setCurrentWidget(logRegScreen);
}
