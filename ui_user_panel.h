/********************************************************************************
** Form generated from reading UI file 'user_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_PANEL_H
#define UI_USER_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User_Panel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_name;
    QLabel *label_role;
    QPushButton *button_logout;
    QTabWidget *tabWidget;
    QWidget *user_data;
    QWidget *income_expensies;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_kwotaPrzychod;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_kategoriaPrzychod;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QDateEdit *dateEdit_dataPrzychod;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLineEdit *lineEdit_Notatka;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QWidget *Wydatki;

    void setupUi(QWidget *User_Panel)
    {
        if (User_Panel->objectName().isEmpty())
            User_Panel->setObjectName(QString::fromUtf8("User_Panel"));
        User_Panel->resize(690, 527);
        verticalLayout = new QVBoxLayout(User_Panel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(User_Panel);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_name = new QLabel(User_Panel);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout->addWidget(label_name);

        label_role = new QLabel(User_Panel);
        label_role->setObjectName(QString::fromUtf8("label_role"));

        horizontalLayout->addWidget(label_role);

        button_logout = new QPushButton(User_Panel);
        button_logout->setObjectName(QString::fromUtf8("button_logout"));

        horizontalLayout->addWidget(button_logout);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(User_Panel);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        user_data = new QWidget();
        user_data->setObjectName(QString::fromUtf8("user_data"));
        tabWidget->addTab(user_data, QString());
        income_expensies = new QWidget();
        income_expensies->setObjectName(QString::fromUtf8("income_expensies"));
        verticalLayout_2 = new QVBoxLayout(income_expensies);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(income_expensies);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_kwotaPrzychod = new QDoubleSpinBox(income_expensies);
        doubleSpinBox_kwotaPrzychod->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaPrzychod"));
        doubleSpinBox_kwotaPrzychod->setMinimumSize(QSize(150, 0));
        doubleSpinBox_kwotaPrzychod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_kwotaPrzychod->setMaximum(999999.989999999990687);

        horizontalLayout_2->addWidget(doubleSpinBox_kwotaPrzychod);

        label_6 = new QLabel(income_expensies);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(income_expensies);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_kategoriaPrzychod = new QComboBox(income_expensies);
        comboBox_kategoriaPrzychod->addItem(QString());
        comboBox_kategoriaPrzychod->addItem(QString());
        comboBox_kategoriaPrzychod->addItem(QString());
        comboBox_kategoriaPrzychod->addItem(QString());
        comboBox_kategoriaPrzychod->setObjectName(QString::fromUtf8("comboBox_kategoriaPrzychod"));
        comboBox_kategoriaPrzychod->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(comboBox_kategoriaPrzychod);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_4 = new QLabel(income_expensies);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateEdit_dataPrzychod = new QDateEdit(income_expensies);
        dateEdit_dataPrzychod->setObjectName(QString::fromUtf8("dateEdit_dataPrzychod"));
        dateEdit_dataPrzychod->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(dateEdit_dataPrzychod);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_5 = new QLabel(income_expensies);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        lineEdit_Notatka = new QLineEdit(income_expensies);
        lineEdit_Notatka->setObjectName(QString::fromUtf8("lineEdit_Notatka"));
        lineEdit_Notatka->setMinimumSize(QSize(300, 100));
        lineEdit_Notatka->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(lineEdit_Notatka);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(income_expensies);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        tabWidget->addTab(income_expensies, QString());
        Wydatki = new QWidget();
        Wydatki->setObjectName(QString::fromUtf8("Wydatki"));
        tabWidget->addTab(Wydatki, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(User_Panel);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(User_Panel);
    } // setupUi

    void retranslateUi(QWidget *User_Panel)
    {
        User_Panel->setWindowTitle(QCoreApplication::translate("User_Panel", "Form", nullptr));
        label->setText(QCoreApplication::translate("User_Panel", "Panel u\305\274ytkownika", nullptr));
        label_name->setText(QCoreApplication::translate("User_Panel", "\"ROLA\"", nullptr));
        label_role->setText(QCoreApplication::translate("User_Panel", "\"IMI\304\230 NAZWISKO\"", nullptr));
        button_logout->setText(QCoreApplication::translate("User_Panel", "WYLOGUJ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user_data), QCoreApplication::translate("User_Panel", "Dane u\305\274ytkownika", nullptr));
        label_2->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_6->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("User_Panel", "Kategoria przychodu", nullptr));
        comboBox_kategoriaPrzychod->setItemText(0, QCoreApplication::translate("User_Panel", "Pensja", nullptr));
        comboBox_kategoriaPrzychod->setItemText(1, QCoreApplication::translate("User_Panel", "Prezent", nullptr));
        comboBox_kategoriaPrzychod->setItemText(2, QCoreApplication::translate("User_Panel", "Renta", nullptr));
        comboBox_kategoriaPrzychod->setItemText(3, QCoreApplication::translate("User_Panel", "Sprzeda\305\274", nullptr));

        label_4->setText(QCoreApplication::translate("User_Panel", "Data", nullptr));
        label_5->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalne)", nullptr));
        pushButton->setText(QCoreApplication::translate("User_Panel", "Dodaj przych\303\263d", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(income_expensies), QCoreApplication::translate("User_Panel", "Przychody", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Wydatki), QCoreApplication::translate("User_Panel", "Wydatki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_Panel: public Ui_User_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_PANEL_H
