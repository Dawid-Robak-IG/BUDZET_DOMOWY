#ifndef STARTLOGREG_H
#define STARTLOGREG_H

#include <QLabel>
#include <QSqlDatabase>
#include <QWidget>
#include "DatabaseManager.hpp"

namespace Ui {
class Start_Log_Reg;
}

class Start_Log_Reg : public QWidget
{
    Q_OBJECT

    //może raczej private slots
public slots:
              // void handleLogin();
    //   void handleRegister();

    void loginUser();
    void registerUser();

signals:
    void loginSuccessful(const QString &email);

public:
    explicit Start_Log_Reg(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event);
    ~Start_Log_Reg();

    void setDatabaseManager(DatabaseManager* dbManager) { m_dbManager = dbManager; }
    DatabaseManager* getDatabaseManager() const { return m_dbManager; }

    void goToStartPage();
private:
    Ui::Start_Log_Reg *ui = nullptr;
    QLabel *backgroundLabel = nullptr;
    DatabaseManager *m_dbManager = nullptr;
    bool isValidReg();
    void clear_reg();

    // Ustawienie indeksów stron w stackedWidget
    int startPageIndex = 0;
    int loginPageIndex = 1;    // Indeks strony Login_page
    int registerPageIndex = 2; // Indeks strony Register_page
};

#endif // STARTLOGREG_H
