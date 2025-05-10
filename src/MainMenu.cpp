#include "MainMenu.hpp"

MainMenu::MainMenu(QWidget *parent): QWidget(parent){
    userMail = new QLabel("Zalogowany jako: ", this);
    logoutButton = new QPushButton("Wyloguj", this);

    layout = new QVBoxLayout(this);
    layout->addWidget(userMail);
    layout->addWidget(logoutButton);
    setLayout(layout);

    connect(logoutButton, &QPushButton::clicked, this, &MainMenu::logoutRequested);
}
void MainMenu::setUser(const QString &userMail){
    this->userMail->setText("Zalogowany jako: " + userMail);
}