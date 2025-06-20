#include <iostream>
#include <QApplication>
#include <QMessageBox>

#include "MainWindow.hpp"

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QFontDatabase fontDB;
    int id = fontDB.addApplicationFont(":/Font/Lato_Font/Lato-Regular.ttf");
    QString family = fontDB.applicationFontFamilies(id).at(0);
    QFont latoFont(family, 14);
    QApplication::setFont(latoFont);

    QLocale polish(QLocale::Polish, QLocale::Poland);
    QLocale::setDefault(polish);

    MainWindow mainwindow;
    mainwindow.resize(1200, 700);
    mainwindow.show();

    return app.exec();
}
