#ifndef INCOMEFORM_H
#define INCOMEFORM_H

#include <QObject>

class IncomeForm : public QObject
{
    Q_OBJECT
public:
    explicit IncomeForm(QObject *parent = nullptr);

signals:
};

#endif // INCOMEFORM_H
