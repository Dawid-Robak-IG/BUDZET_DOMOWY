#ifndef STARTLOGREG_H
#define STARTLOGREG_H

#include <QWidget>
#include <QSqlDatabase>


namespace Ui {
class Start_Log_Reg;
}

class Start_Log_Reg : public QWidget
{
    Q_OBJECT

 QSqlDatabase db;
public slots:
    // void handleLogin();
  //   void handleRegister();

 void loginUser();
 void registerUser();

signals:
    void loginSuccessful(const QString &email);

public:
    explicit Start_Log_Reg(QWidget *parent = nullptr);
    ~Start_Log_Reg();


private:
    Ui::Start_Log_Reg *ui;
    void connectToDatabase();
    bool isValidReg();
    void clear_reg();

};

#endif // STARTLOGREG_H
