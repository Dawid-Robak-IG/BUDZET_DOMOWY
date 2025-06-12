#ifndef KWOTACOLORDELEGATE_HPP
#define KWOTACOLORDELEGATE_HPP

#include <QStyledItemDelegate>

class KwotaColorDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    KwotaColorDelegate(QObject *parent = nullptr)
        : QStyledItemDelegate(parent)
    {}

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
};

#endif // KWOTACOLORDELEGATE_HPP
