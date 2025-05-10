#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), stackedWidget(new QStackedWidget(this)) {\
    setWindowTitle("Budzet domowy");

    logRegScreen = new LogReg();
    mainMenu = new MainMenu();

    stackedWidget->addWidget(logRegScreen);
    stackedWidget->addWidget(mainMenu);

    setCentralWidget(stackedWidget);

    stackedWidget->setCurrentWidget(logRegScreen);

    connect(logRegScreen, &LogReg::loginSuccessful, this, [=](const QString &username) {
        mainMenu->setUser(username); 
        stackedWidget->setCurrentWidget(mainMenu);
    });

    connect(mainMenu, &MainMenu::logoutRequested, this, [=]() {
        stackedWidget->setCurrentWidget(logRegScreen);
    });
}

MainWindow::~MainWindow() {
}