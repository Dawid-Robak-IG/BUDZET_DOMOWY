#include "../inc/IncomeForm.hpp"
#include<QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

IncomeForm::IncomeForm(QDoubleSpinBox* kwotaLineEdit,
                       QComboBox* kategoriaComboBox,
                       QDateEdit* dataDateEdit,
                       QLineEdit* notatkaLineEdit,
                       const QString& userEmail,
                       QObject* parent)
    : QObject(parent),
    m_kwotaLineEdit(kwotaLineEdit),
    m_kategoriaComboBox(kategoriaComboBox),
    m_dataDateEdit(dataDateEdit),
    m_notatkaLineEdit(notatkaLineEdit),
    m_userEmail(userEmail)
{}


IncomeForm::~IncomeForm(){}


void IncomeForm::addIncome()
{
    if (!validateInput()) {
        return;
    }

    double kwotaDouble = m_kwotaLineEdit->value();
    int kwotaInt = qRound(kwotaDouble); // Zaokrąglij do najbliższej liczby całkowitej


    QString kategoriaNazwa = getSelectedCategoryName();
    QDate data = m_dataDateEdit->date();
    QString notatka = m_notatkaLineEdit->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Operacja (Kwota, Data, Notatka, `Uzytkownik zalogowanyID`, `Kategoria Nazwa`, czy_z_cyklicznego) "
                  "SELECT :kwota, :data, :notatka, (SELECT ID FROM `Uzytkownik zalogowany` WHERE Email = :email), :kategoriaNazwa, 0");
    query.bindValue(":kwota", kwotaInt);
    query.bindValue(":data", data.toString("yyyy-MM-dd"));
    query.bindValue(":notatka", notatka.isEmpty() ? QVariant(QVariant::String) : notatka); // Wstaw NULL, jeśli puste
    query.bindValue(":email", m_userEmail);
    query.bindValue(":kategoriaNazwa", kategoriaNazwa);

    if (query.exec()) {
        QMessageBox::information(nullptr, "Sukces", "Przychód został dodany.");
        m_kwotaLineEdit->clear();
        m_notatkaLineEdit->clear();

    } else {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się dodać przychodu: " + query.lastError().text());
        qDebug() << "Błąd dodawania przychodu:" << query.lastError().text();
    }
}


bool IncomeForm::validateInput() const
{
    double kwota = m_kwotaLineEdit->value(); // Pobierz wartość z QDoubleSpinBox

    if (kwota <= 0) {
        QMessageBox::warning(nullptr, "Błąd", "Wprowadź poprawną kwotę (większą od zera).");
        return false;
    }

    if (m_kategoriaComboBox->currentIndex() < 0 || m_kategoriaComboBox->currentText().isEmpty()) {
        QMessageBox::warning(nullptr, "Błąd", "Wybierz kategorię przychodu.");
        return false;
    }

    return true;
}

QString IncomeForm::getSelectedCategoryName() const
{
    return m_kategoriaComboBox->currentText();
}
