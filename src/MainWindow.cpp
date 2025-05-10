#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), stackedWidget(new QStackedWidget(this)) {\
    setWindowTitle("Budzet domowy");

    logRegScreen = new LogReg();

    stackedWidget->addWidget(logRegScreen);

    setCentralWidget(stackedWidget);

    stackedWidget->setCurrentWidget(logRegScreen);
}

MainWindow::~MainWindow() {
}