#include "../inc/Tab_DaneUzytkownika.hpp"

Tab_DaneUzytkownika::Tab_DaneUzytkownika(const QString& userEmail,QWidget *root,QWidget *parent) : QWidget{parent},m_userEmail(userEmail){
    dataEdit= root->findChild<QDateEdit*>("dateEdit_DOB_UD");
    imieLineEdit= root->findChild<QLineEdit*>("lineEdit_nameUD");
    nazwiskoLineEdit= root->findChild<QLineEdit*>("lineEdit_surnameUD");
    rolaLineEdit= root->findChild<QLineEdit*>("lineEdit_roleUD");
    emailLineEdit= root->findChild<QLineEdit*>("lineEdit_emailUD");
    hasloLineEdit= root->findChild<QLineEdit*>("lineEdit_passwordUD");

    zmienHasloButton=root->findChild<QPushButton*>("pushButton_zmienHaslo");
    pokazHasloCheckBox= root->findChild<QCheckBox*>("checkBox_showPassword");



    salodLabel=root->findChild<QLabel*>("label_saldo");
   kieszonkoweLabel=root->findChild<QLabel*>("label_kieszonkowe");
   kieszonkoweLineEdit= root->findChild<QLineEdit*>("lineEdit_kieszonkoweDU");
   saldoLineEdit= root->findChild<QLineEdit*>("lineEdit_saldoDU");

   zl1Label=root->findChild<QLabel*>("label_zl1");
   zl2Label=root->findChild<QLabel*>("label_zl2");
   nkLabel = root->findChild<QLabel *>("label_nk");

   nastepneKieszonkoweLineEdit = root->findChild<QLineEdit *>("lineEdit_dzieciData");

   if (pokazHasloCheckBox && hasloLineEdit) {
       // Obsługa checkboxa do widoczności hasła
       connect(pokazHasloCheckBox, &QCheckBox::toggled, this, [this](bool checked) {
           hasloLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
       });
   }

    // Obsługa kliknięcia przycisku zmiany hasła
    if (zmienHasloButton) {
        connect(zmienHasloButton, &QPushButton::clicked, this, &Tab_DaneUzytkownika::ZmienHasloClicked);
    }




}

void Tab_DaneUzytkownika::setDatabaseManager(DatabaseManager *dbManager){
    m_dbManager = dbManager;
  loadUserData();


  bool children=m_dbManager->amIChild();

  salodLabel->setVisible(children);
  kieszonkoweLabel->setVisible(children);
  kieszonkoweLineEdit->setVisible(children);
  saldoLineEdit->setVisible(children);
  zl1Label->setVisible(children);
  zl2Label->setVisible(children);
  nastepneKieszonkoweLineEdit->setVisible(children);
  nkLabel->setVisible(children);

  int myID = m_dbManager->get_user_ID();

  if(children){
      saldoLineEdit->setText(QString::number(m_dbManager->get_saldo(myID), 'f', 2));
      kieszonkoweLineEdit->setText(QString::number(m_dbManager->get_kieszonkowe(myID), 'f', 2));
      nastepneKieszonkoweLineEdit->setText(
          m_dbManager->get_date_next_kieszonkowe(myID).toString("dd-MM-yyyy"));
  }
}
void Tab_DaneUzytkownika::ZmienHasloClicked() {
    qDebug() << "Uruchamiam zmianę hasła";

    bool ok;

    QString noweHaslo = QInputDialog::getText(this, "Zmiana hasła",
        "Podaj nowe hasło:", QLineEdit::Password, "", &ok);
    if (!ok) return;
    if (noweHaslo.length() < 8) {
        QMessageBox::warning(this, "Błąd", "Hasło musi mieć co najmniej 8 znaków.");
        return;
    }
    if (m_dbManager->changePassword(noweHaslo)) {
        QMessageBox::information(this, "Sukces", "Hasło zostało zmienione.");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zmienić hasła. Sprawdź stare hasło.");
    }
}

void Tab_DaneUzytkownika::loadUserData(){
    if (!m_dbManager) {
        qDebug() << "Brak DatabaseManagera!";
        return;
    }

    if (!imieLineEdit || !nazwiskoLineEdit || !rolaLineEdit || !emailLineEdit || !hasloLineEdit || !dataEdit) {
        qDebug() << "Jeden z elementów formularza to nullptr!";
        return;
    }
    QSqlQuery query(m_dbManager->getDatabase());
    query.prepare("SELECT Imie, Nazwisko, `Data urodzenia`, Email, Rola, Haslo FROM `Uzytkownik zalogowany` WHERE Email = :email");
    query.bindValue(":email", m_userEmail);

    if (query.exec() && query.first()) {
        QString imie = query.value("Imie").toString();
        QString nazwisko = query.value("Nazwisko").toString();
        QString rola = query.value("Rola").toString();
        QString haslo = query.value("Haslo").toString();
        QDate dataUrodzenia = query.value("Data urodzenia").toDate();
        QString dbEmail = query.value("Email").toString();

        imieLineEdit->setText(imie);
        nazwiskoLineEdit->setText(nazwisko);
        rolaLineEdit->setText(rola);
        emailLineEdit->setText(dbEmail);
        hasloLineEdit->setText(haslo);
        dataEdit->setDate(dataUrodzenia);
    } else {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono danych użytkownika.");
    }
}
