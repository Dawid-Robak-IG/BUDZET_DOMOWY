#include "MainWindow.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Budzet domowy");

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    logRegScreen = new LogReg();
    stackedWidget->addWidget(logRegScreen);

    userPanel = nullptr; // Inicjalizujemy na nullptr

    // Łączymy sygnał logowania
    connect(logRegScreen, &LogReg::loginSuccessful, this, &MainWindow::handleLogin);
}


MainWindow::~MainWindow() {
}

void MainWindow::handleLogin(QString email) {
    if (!userPanel) {
        userPanel = new User_Panel(email);
        stackedWidget->addWidget(userPanel);
        connect(userPanel, &User_Panel::logoutRequested, this, &MainWindow::handleLogout);
    } else {
        userPanel->setUserEmail(email); // Jeśli userPanel już istnieje, tylko aktualizujemy email
        userPanel->loadUserRole();      // I przeładowujemy rolę
    }
    stackedWidget->setCurrentIndex(WidgetIndex::UserPanelIndex);
}

void MainWindow::handleLogout() {
    qDebug() << "Wylogowywanie...";
    stackedWidget->setCurrentIndex(WidgetIndex::LogRegIndex);

    // Opcjonalnie: Możesz zdecydować, czy chcesz niszczyć userPanel po wylogowaniu
    // if (userPanel) {
    //     userPanel->deleteLater();
    //     userPanel = nullptr;
    // }
}
