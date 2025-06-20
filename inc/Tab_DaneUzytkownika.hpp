#ifndef TAB_DANEUZYTKOWNIKA_HPP
#define TAB_DANEUZYTKOWNIKA_HPP
#include "DatabaseManager.hpp"

#include <QWidget>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>
#include <QMessageBox>
#include <QCheckBox>
#include <QInputDialog>
#include <QLabel>


class Tab_DaneUzytkownika : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_DaneUzytkownika(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
      void setDatabaseManager(DatabaseManager* dbManager);
      void loadUserData(const QString &new_mail);
signals:

  private slots:
      void ZmienHasloClicked();

  private:
      QString m_userEmail;

      QDateEdit *dataEdit = nullptr;
      QLineEdit *imieLineEdit = nullptr;
      QLineEdit *nazwiskoLineEdit = nullptr;
      QLineEdit *rolaLineEdit = nullptr;
      QLineEdit *emailLineEdit = nullptr;
      QLineEdit *hasloLineEdit = nullptr;
      QPushButton *zmienHasloButton = nullptr;
      QCheckBox *pokazHasloCheckBox = nullptr;

      QLabel *salodLabel = nullptr;
      QLabel *kieszonkoweLabel = nullptr;
      QLabel *zl1Label = nullptr;
      QLabel *zl2Label = nullptr;
      QLabel *nkLabel = nullptr;

      QLineEdit *kieszonkoweLineEdit = nullptr;
      QLineEdit *saldoLineEdit = nullptr;
      QLineEdit *nastepneKieszonkoweLineEdit = nullptr;
      DatabaseManager* m_dbManager = nullptr;


};

#endif // TAB_DANEUZYTKOWNIKA_HPP
