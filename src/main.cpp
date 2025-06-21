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

    qApp->setStyleSheet(R"(

    QWidget {
color:#003b5b; }

QLineEdit {
    background-color: white;
    min-height: 30px;
    max-height: 30px;
    border-radius: 5px;
    padding-left: 5px;
    border: 1px solid #003b5b
}


    QPushButton {
        border-radius: 10px;
        background-color: rgba(0,59,91,255); 
        color: white;
        padding: 6px 12px;
    }

    QPushButton:hover {
        background-color: rgba(0,59,91,200); 
    }
QPushButton:focus {
    outline: none;
}
QCalendarWidget QWidget {
    background-color: white;
    color: black;
}
QCalendarWidget QAbstractItemView {
    background-color: white;
    color: black;
}


)");
    MainWindow mainwindow;
    mainwindow.resize(1300, 700);
    mainwindow.show();

    return app.exec();
}
