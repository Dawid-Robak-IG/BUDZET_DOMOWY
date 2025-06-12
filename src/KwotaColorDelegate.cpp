#include "KwotaColorDelegate.hpp"
#include <QPainter>

void KwotaColorDelegate::paint(QPainter *painter,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    bool ok;
    double kwota = index.data().toDouble(&ok);

    if (ok) {
        if (kwota > 0)
            opt.palette.setColor(QPalette::Text, Qt::darkGreen);
        else if (kwota < 0)
            opt.palette.setColor(QPalette::Text, Qt::red);
    }

    QStyledItemDelegate::paint(painter, opt, index);
}
