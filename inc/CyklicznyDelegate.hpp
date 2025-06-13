#ifndef CYKLICZNOSCDELEGATE_HPP
#define CYKLICZNOSCDELEGATE_HPP

#include <QStyledItemDelegate>

class CyklicznyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    QString displayText(const QVariant &value, const QLocale &locale) const override;
};

#endif // CYKLICZNOSCDELEGATE_HPP
