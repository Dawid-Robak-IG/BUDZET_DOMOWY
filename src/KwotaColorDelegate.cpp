#include "KwotaColorDelegate.hpp"
#include <QApplication>
#include <QPainter>

void KwotaColorDelegate::paint(QPainter *painter,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    // Formatowanie liczby do 2 miejsc po przecinku
    bool ok;
    double kwota = index.data().toDouble(&ok);
    if (ok) {
        // Ustaw kolor tekstu
        if (kwota > 0)
            opt.palette.setColor(QPalette::Text, Qt::darkGreen);
        else if (kwota < 0)
            opt.palette.setColor(QPalette::Text, Qt::red);

        // Ustaw tekst z formatem
        opt.text = QString::number(kwota, 'f', 2);
    }

    // Wyrównanie do prawej
    opt.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;

    const QWidget *widget = opt.widget;
    QStyle *style = widget ? widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
}
