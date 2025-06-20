#ifndef PASSWORDDELEGATE_HPP
#define PASSWORDDELEGATE_HPP

#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>
class PasswordDelegate : public QStyledItemDelegate {
public:
    PasswordDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Zastępujemy dane "kropkami"
        QString password = index.data().toString();
        QString masked(password.length(), QChar(0x2022));

        opt.text = masked;

        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();
        style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
    }
};

#endif // PASSWORDDELEGATE_HPP
