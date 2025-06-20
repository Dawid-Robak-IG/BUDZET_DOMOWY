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

    qApp->setStyleSheet("QWidget { color:#003b5b; }");
    qApp->setStyleSheet(R"(
    QPushButton {
        border-radius: 10px;
        background-color: rgba(0,59,91,255); 
        color: white;
        padding: 6px 12px;
    }

    QPushButton:hover {
        background-color: rgba(52, 152, 219, 200);  /* ten sam kolor, ale bardziej przezroczysty */
    }

    QPushButton:pressed {
        background-color: rgba(52, 152, 219, 180);  /* jeszcze ciemniejszy */
    }
)");
    MainWindow mainwindow;
    mainwindow.resize(1200, 700);
    mainwindow.show();

    return app.exec();
}
