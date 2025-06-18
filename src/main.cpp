#include <iostream>
#include <QApplication>
#include <QMessageBox>

#include "MainWindow.hpp"

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QLocale polish(QLocale::Polish, QLocale::Poland);
    QLocale::setDefault(polish);

    MainWindow mainwindow;
    mainwindow.resize(1100, 600);
    mainwindow.show();

    return app.exec();
}
