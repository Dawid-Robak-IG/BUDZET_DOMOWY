#ifndef STARTLOGREG_H
#define STARTLOGREG_H

#include <QWidget>
#include <QSqlDatabase>
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
    ~Start_Log_Reg();

    void setDatabaseManager(DatabaseManager* dbManager) { m_dbManager = dbManager; }
    DatabaseManager* getDatabaseManager() const { return m_dbManager; }

private:
    Ui::Start_Log_Reg *ui;
    // QSqlDatabase m_db;
    DatabaseManager* m_dbManager = nullptr;

    //void connectToDatabase();
    bool isValidReg();
    void clear_reg();
    // void displayUserData(const QString &email);

};

#endif // STARTLOGREG_H
