#ifndef BLOCKEDDELEGATE_HPP
#define BLOCKEDDELEGATE_HPP

#include <QStyledItemDelegate>

class BlockedDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    QString displayText(const QVariant &value, const QLocale &locale) const override;
};

#endif // BLOCKEDDELEGATE_HPP
