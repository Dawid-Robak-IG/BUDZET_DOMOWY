#include "../inc/tab_przychody.hpp"
#include "ui_user_panel.h"

Tab_Przychody::Tab_Przychody(QWidget *parent)
    : QWidget{parent}, ui(new Ui::Tab_Przychody)
{
    ui->setupUi(this);

    //connect

}

Tab_Przychody::~Tab_Przychody(){
    delete ui;
}
