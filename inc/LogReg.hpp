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

class LogReg : public QWidget {
    Q_OBJECT

public:
    LogReg(QWidget *parent = nullptr);

// private slots:
//     void registerUser();  // Slot do rejestracji
//     void loginUser();     // Slot do logowania

private:
    QLineEdit *logMail;
    QLineEdit *logPass;

    QLineEdit *regMail;
    QLineEdit


    QPushButton *registerButton;
    QPushButton *loginButton;
    QSqlDatabase db;  // Obiekt bazy danych MySQL
    // bool connectToDatabase();  // Funkcja do połączenia z bazą danych
};