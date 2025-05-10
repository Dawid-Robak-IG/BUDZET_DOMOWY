#include <iostream>
#include <QApplication>
#include <QMessageBox>

#include "MainWindow.hpp"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();

    return app.exec();
}