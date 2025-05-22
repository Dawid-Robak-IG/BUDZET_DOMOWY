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


class Tab_DaneUzytkownika : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_DaneUzytkownika(const QString& userEmail,QWidget *root,QWidget *parent = nullptr);
      void setDatabaseManager(DatabaseManager* dbManager);
      void loadUserData();
signals:

  private slots:
      void ZmienHasloClicked();

  private:
      QString m_userEmail;

      QDateEdit *dataEdit;
      QLineEdit *imieLineEdit;
      QLineEdit *nazwiskoLineEdit;
      QLineEdit *rolaLineEdit;
      QLineEdit *emailLineEdit;
      QLineEdit *hasloLineEdit;
      QPushButton *zmienHasloButton;
      QCheckBox *pokazHasloCheckBox;

      DatabaseManager* m_dbManager = nullptr;


};

#endif // TAB_DANEUZYTKOWNIKA_HPP
