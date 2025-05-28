#include "ComboBoxDelegate.hpp"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(const QStringList &items, QObject *parent)
    : QStyledItemDelegate(parent), m_items(items) {}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,
                                        const QModelIndex &) const {
    auto *comboBox = new QComboBox(parent);
    comboBox->addItems(m_items);
    return comboBox;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    auto *comboBox = qobject_cast<QComboBox *>(editor);
    if (comboBox) {
        int idx = comboBox->findText(index.data().toString());
        comboBox->setCurrentIndex(idx >= 0 ? idx : 0);
    }
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const {
    auto *comboBox = qobject_cast<QComboBox *>(editor);
    if (comboBox) {
        model->setData(index, comboBox->currentText());
    }
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &) const {
    editor->setGeometry(option.rect);
}
