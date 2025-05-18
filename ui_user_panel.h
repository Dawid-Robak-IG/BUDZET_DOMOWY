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
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_nameUD;
    QLabel *label_9;
    QLineEdit *lineEdit_surnameUD;
    QLabel *label_10;
    QDateEdit *dateEdit_DOB_UD;
    QLabel *label_11;
    QLineEdit *lineEdit_emailUD;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_hasloUD;
    QPushButton *pushButton_zmienHaslo;
    QSpacerItem *horizontalSpacer_4;
    QWidget *Przychody;
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
    QWidget *tab_Wydatki;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *doubleSpinBox_kwotaWydatek;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox_kategoriaWydatek;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_9;
    QDateEdit *dateEdit_dataWydatek;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_17;
    QLineEdit *lineEdit_notatkaWydatek;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_dodajWydatek;
    QWidget *Kategorie;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_nowaKategoriaPrzychod;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_dodajKategoriePrzychod;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;

    void setupUi(QWidget *User_Panel)
    {
        if (User_Panel->objectName().isEmpty())
            User_Panel->setObjectName(QString::fromUtf8("User_Panel"));
        User_Panel->resize(1100, 527);
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
        verticalLayout_4 = new QVBoxLayout(user_data);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_8 = new QLabel(user_data);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        lineEdit_nameUD = new QLineEdit(user_data);
        lineEdit_nameUD->setObjectName(QString::fromUtf8("lineEdit_nameUD"));
        lineEdit_nameUD->setReadOnly(true);

        verticalLayout_4->addWidget(lineEdit_nameUD);

        label_9 = new QLabel(user_data);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        lineEdit_surnameUD = new QLineEdit(user_data);
        lineEdit_surnameUD->setObjectName(QString::fromUtf8("lineEdit_surnameUD"));
        lineEdit_surnameUD->setReadOnly(true);

        verticalLayout_4->addWidget(lineEdit_surnameUD);

        label_10 = new QLabel(user_data);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        dateEdit_DOB_UD = new QDateEdit(user_data);
        dateEdit_DOB_UD->setObjectName(QString::fromUtf8("dateEdit_DOB_UD"));
        dateEdit_DOB_UD->setReadOnly(true);

        verticalLayout_4->addWidget(dateEdit_DOB_UD);

        label_11 = new QLabel(user_data);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        lineEdit_emailUD = new QLineEdit(user_data);
        lineEdit_emailUD->setObjectName(QString::fromUtf8("lineEdit_emailUD"));
        lineEdit_emailUD->setReadOnly(true);

        verticalLayout_4->addWidget(lineEdit_emailUD);

        label_12 = new QLabel(user_data);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_hasloUD = new QLineEdit(user_data);
        lineEdit_hasloUD->setObjectName(QString::fromUtf8("lineEdit_hasloUD"));
        lineEdit_hasloUD->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_hasloUD);

        pushButton_zmienHaslo = new QPushButton(user_data);
        pushButton_zmienHaslo->setObjectName(QString::fromUtf8("pushButton_zmienHaslo"));

        horizontalLayout_6->addWidget(pushButton_zmienHaslo);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tabWidget->addTab(user_data, QString());
        Przychody = new QWidget();
        Przychody->setObjectName(QString::fromUtf8("Przychody"));
        verticalLayout_2 = new QVBoxLayout(Przychody);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(Przychody);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_kwotaPrzychod = new QDoubleSpinBox(Przychody);
        doubleSpinBox_kwotaPrzychod->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaPrzychod"));
        doubleSpinBox_kwotaPrzychod->setMinimumSize(QSize(150, 0));
        doubleSpinBox_kwotaPrzychod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_kwotaPrzychod->setMaximum(999999.989999999990687);

        horizontalLayout_2->addWidget(doubleSpinBox_kwotaPrzychod);

        label_6 = new QLabel(Przychody);
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

        label_3 = new QLabel(Przychody);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_kategoriaPrzychod = new QComboBox(Przychody);
        comboBox_kategoriaPrzychod->setObjectName(QString::fromUtf8("comboBox_kategoriaPrzychod"));
        comboBox_kategoriaPrzychod->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(comboBox_kategoriaPrzychod);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_4 = new QLabel(Przychody);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateEdit_dataPrzychod = new QDateEdit(Przychody);
        dateEdit_dataPrzychod->setObjectName(QString::fromUtf8("dateEdit_dataPrzychod"));
        dateEdit_dataPrzychod->setMinimumSize(QSize(150, 0));
        dateEdit_dataPrzychod->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dateEdit_dataPrzychod);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_5 = new QLabel(Przychody);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        lineEdit_Notatka = new QLineEdit(Przychody);
        lineEdit_Notatka->setObjectName(QString::fromUtf8("lineEdit_Notatka"));
        lineEdit_Notatka->setMinimumSize(QSize(300, 100));
        lineEdit_Notatka->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(lineEdit_Notatka);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(Przychody);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        tabWidget->addTab(Przychody, QString());
        tab_Wydatki = new QWidget();
        tab_Wydatki->setObjectName(QString::fromUtf8("tab_Wydatki"));
        verticalLayout_5 = new QVBoxLayout(tab_Wydatki);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_13 = new QLabel(tab_Wydatki);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        doubleSpinBox_kwotaWydatek = new QDoubleSpinBox(tab_Wydatki);
        doubleSpinBox_kwotaWydatek->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaWydatek"));
        doubleSpinBox_kwotaWydatek->setMinimumSize(QSize(150, 0));
        doubleSpinBox_kwotaWydatek->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_kwotaWydatek->setMaximum(999999.989999999990687);

        horizontalLayout_7->addWidget(doubleSpinBox_kwotaWydatek);

        label_14 = new QLabel(tab_Wydatki);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_7->addWidget(label_14);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_7);

        label_15 = new QLabel(tab_Wydatki);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_5->addWidget(label_15);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        comboBox_kategoriaWydatek = new QComboBox(tab_Wydatki);
        comboBox_kategoriaWydatek->setObjectName(QString::fromUtf8("comboBox_kategoriaWydatek"));
        comboBox_kategoriaWydatek->setMinimumSize(QSize(150, 0));

        horizontalLayout_8->addWidget(comboBox_kategoriaWydatek);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_8);

        label_16 = new QLabel(tab_Wydatki);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_5->addWidget(label_16);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        dateEdit_dataWydatek = new QDateEdit(tab_Wydatki);
        dateEdit_dataWydatek->setObjectName(QString::fromUtf8("dateEdit_dataWydatek"));
        dateEdit_dataWydatek->setMinimumSize(QSize(150, 0));

        horizontalLayout_9->addWidget(dateEdit_dataWydatek);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_9);

        label_17 = new QLabel(tab_Wydatki);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_5->addWidget(label_17);

        lineEdit_notatkaWydatek = new QLineEdit(tab_Wydatki);
        lineEdit_notatkaWydatek->setObjectName(QString::fromUtf8("lineEdit_notatkaWydatek"));
        lineEdit_notatkaWydatek->setMinimumSize(QSize(300, 100));
        lineEdit_notatkaWydatek->setMaximumSize(QSize(400, 16777215));

        verticalLayout_5->addWidget(lineEdit_notatkaWydatek);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        pushButton_dodajWydatek = new QPushButton(tab_Wydatki);
        pushButton_dodajWydatek->setObjectName(QString::fromUtf8("pushButton_dodajWydatek"));

        verticalLayout_5->addWidget(pushButton_dodajWydatek);

        tabWidget->addTab(tab_Wydatki, QString());
        Kategorie = new QWidget();
        Kategorie->setObjectName(QString::fromUtf8("Kategorie"));
        horizontalLayout_5 = new QHBoxLayout(Kategorie);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(Kategorie);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        lineEdit_nowaKategoriaPrzychod = new QLineEdit(Kategorie);
        lineEdit_nowaKategoriaPrzychod->setObjectName(QString::fromUtf8("lineEdit_nowaKategoriaPrzychod"));

        verticalLayout_3->addWidget(lineEdit_nowaKategoriaPrzychod);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        pushButton_dodajKategoriePrzychod = new QPushButton(Kategorie);
        pushButton_dodajKategoriePrzychod->setObjectName(QString::fromUtf8("pushButton_dodajKategoriePrzychod"));

        verticalLayout_3->addWidget(pushButton_dodajKategoriePrzychod);


        horizontalLayout_5->addLayout(verticalLayout_3);

        tabWidget->addTab(Kategorie, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(User_Panel);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(User_Panel);
    } // setupUi

    void retranslateUi(QWidget *User_Panel)
    {
        User_Panel->setWindowTitle(QCoreApplication::translate("User_Panel", "Form", nullptr));
        label->setText(QCoreApplication::translate("User_Panel", "Panel u\305\274ytkownika", nullptr));
        label_name->setText(QCoreApplication::translate("User_Panel", "\"ROLA\"", nullptr));
        label_role->setText(QCoreApplication::translate("User_Panel", "\"IMI\304\230 NAZWISKO\"", nullptr));
        button_logout->setText(QCoreApplication::translate("User_Panel", "WYLOGUJ", nullptr));
        label_8->setText(QCoreApplication::translate("User_Panel", "Imi\304\231", nullptr));
        label_9->setText(QCoreApplication::translate("User_Panel", "Nazwisko", nullptr));
        label_10->setText(QCoreApplication::translate("User_Panel", "Data urodzenia", nullptr));
        label_11->setText(QCoreApplication::translate("User_Panel", "E-mail", nullptr));
        label_12->setText(QCoreApplication::translate("User_Panel", "Has\305\202o", nullptr));
        pushButton_zmienHaslo->setText(QCoreApplication::translate("User_Panel", "Zmie\305\204 has\305\202o", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user_data), QCoreApplication::translate("User_Panel", "Dane u\305\274ytkownika", nullptr));
        label_2->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_6->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("User_Panel", "Kategoria przychodu", nullptr));
        label_4->setText(QCoreApplication::translate("User_Panel", "Data", nullptr));
        label_5->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalne)", nullptr));
        pushButton->setText(QCoreApplication::translate("User_Panel", "Dodaj przych\303\263d", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Przychody), QCoreApplication::translate("User_Panel", "Przychody", nullptr));
        label_13->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_14->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_15->setText(QCoreApplication::translate("User_Panel", "Kategoria wydatku", nullptr));
        label_16->setText(QCoreApplication::translate("User_Panel", "Data", nullptr));
        label_17->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalnie)", nullptr));
        pushButton_dodajWydatek->setText(QCoreApplication::translate("User_Panel", "Dodaj wydatek", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Wydatki), QCoreApplication::translate("User_Panel", "Wydatki", nullptr));
        label_7->setText(QCoreApplication::translate("User_Panel", "Nowa kategoria:", nullptr));
        pushButton_dodajKategoriePrzychod->setText(QCoreApplication::translate("User_Panel", "Dodaj kategori\304\231", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Kategorie), QCoreApplication::translate("User_Panel", "Dodaj kategorie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("User_Panel", "Cykliczne przychody", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("User_Panel", "Cykliczne wydatki", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("User_Panel", "Raporty", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("User_Panel", "U\305\274ytkownicy", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("User_Panel", "Dzieci", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("User_Panel", "Relacje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_Panel: public Ui_User_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_PANEL_H
