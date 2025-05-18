#ifndef TAB_PRZYCHODY_HPP
#define TAB_PRZYCHODY_HPP

#include <QWidget>

namespace Ui {
class Tab_Przychody;
}

class Tab_Przychody : public QWidget
{
    Q_OBJECT
public:
    explicit Tab_Przychody(QWidget *parent = nullptr);
    ~Tab_Przychody();
signals:

private:
    Ui::Tab_Przychody *ui;

private slots:

};

#endif // TAB_PRZYCHODY_HPP
