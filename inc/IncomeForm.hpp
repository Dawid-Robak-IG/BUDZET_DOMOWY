#ifndef INCOMEFORM_H
#define INCOMEFORM_H

#include <QObject>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>

class IncomeForm : public QObject
{
    Q_OBJECT
public:
    explicit IncomeForm(QDoubleSpinBox* kwotaLineEdit,
                        QComboBox* kategoriaComboBox,
                        QDateEdit* dataDateEdit,
                        QLineEdit* notatkaLineEdit,
                        const QString& userEmail,
                        QObject *parent = nullptr);

    ~IncomeForm()override;

public slots:
    void addIncome();

private:
   QDoubleSpinBox* m_kwotaLineEdit;
    QComboBox* m_kategoriaComboBox;
    QDateEdit* m_dataDateEdit;
    QLineEdit* m_notatkaLineEdit;
    QString m_userEmail;

    bool validateInput() const;
    QString getSelectedCategoryName() const;




};

#endif // INCOMEFORM_H
