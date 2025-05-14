#ifndef START_LOG_REG_HPP
#define START_LOG_REG_HPP

#include <QWidget>

namespace Ui {
class Start_Log_Reg;
}

class Start_Log_Reg : public QWidget
{
    Q_OBJECT

public:
    explicit Start_Log_Reg(QWidget *parent = nullptr);
    ~Start_Log_Reg();

private:
    Ui::Start_Log_Reg *ui;
};

#endif // START_LOG_REG_HPP
