#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateEdit>
#include <iostream>

class LogReg : public QWidget {
    Q_OBJECT
    QLineEdit *logMail;
    QLineEdit *logPass;
    QPushButton *logButton;
    QVBoxLayout *logLayout;

    QLineEdit *regMail;
    QLineEdit *regName;
    QLineEdit *regSurrname;
    QDateEdit *regDate;
    QLineEdit *regPass;
    QPushButton *regButton;
    QVBoxLayout *regLayout;

    QHBoxLayout *layout;


    QSqlDatabase db; 
public:
    LogReg(QWidget *parent = nullptr);

private slots:
    void registerUser();  
    // void loginUser(); 

private:
    void connectToDatabase(); 
    void setLogin();
    void setRegistration();
    bool isValidReg();
};