#include "start_log_reg.hpp"
#include "ui_start_log_reg.h"

Start_Log_Reg::Start_Log_Reg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Start_Log_Reg)
{
    ui->setupUi(this);
}

Start_Log_Reg::~Start_Log_Reg()
{
    delete ui;
}
