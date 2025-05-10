#pragma once 

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MainMenu: public QWidget{
    Q_OBJECT
    QLabel *userMail;
    QPushButton *logoutButton;
    QVBoxLayout *layout;
public:
    MainMenu(QWidget *parent =nullptr);
    void setUser(const QString &userMail);
signals:
    void logoutRequested();
};