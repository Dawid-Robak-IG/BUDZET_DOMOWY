#ifndef COMBOBOXDELEGATE_HPP
#define COMBOBOXDELEGATE_HPP

#include <QStyledItemDelegate>
#include <QStringList>

class ComboBoxDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    ComboBoxDelegate(const QStringList &items, QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

private:
    QStringList m_items;
};

#endif // COMBOBOXDELEGATE_HPP
