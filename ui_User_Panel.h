/********************************************************************************
** Form generated from reading UI file 'User_Panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_PANEL_H
#define UI_USER_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QWidget *tab_DaneUzytkownika;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_nameUD;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *lineEdit_surnameUD;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_10;
    QDateEdit *dateEdit_DOB_UD;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_roleUD;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEdit_emailUD;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_passwordUD;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *checkBox_showPassword;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_zmienHaslo;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_kieszonkowe;
    QHBoxLayout *horizontalLayout_41;
    QLineEdit *lineEdit_kieszonkoweDU;
    QLabel *label_zl1;
    QSpacerItem *horizontalSpacer_35;
    QLabel *label_saldo;
    QHBoxLayout *horizontalLayout_42;
    QLineEdit *lineEdit_saldoDU;
    QLabel *label_zl2;
    QSpacerItem *horizontalSpacer_36;
    QWidget *tab_Budzet;
    QHBoxLayout *horizontalLayout_38;
    QHBoxLayout *horizontalLayout_37;
    QVBoxLayout *verticalLayout_21;
    QSpacerItem *verticalSpacer_14;
    QLabel *label_49;
    QHBoxLayout *horizontalLayout_39;
    QLineEdit *lineEdit_stanBudzet;
    QLabel *label_50;
    QSpacerItem *horizontalSpacer_33;
    QLabel *label_51;
    QHBoxLayout *horizontalLayout_40;
    QLineEdit *lineEdit_dataBudzet;
    QSpacerItem *horizontalSpacer_34;
    QSpacerItem *verticalSpacer_13;
    QTableView *tableView_budzet;
    QHBoxLayout *horizontalLayout_36;
    QWidget *tab_Przychody;
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
    QLineEdit *lineEdit_notatkaPrzychod;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_dodajPrzychod;
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
    QWidget *tab_Kategorie;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_nowaKategoria;
    QPushButton *pushButton_dodajKategorie;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_26;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_46;
    QComboBox *comboBox_dostepneKategorie;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_32;
    QVBoxLayout *verticalLayout_20;
    QPushButton *pushButton_usunKategorie;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_27;
    QTableView *tableView_Kategorie;
    QWidget *tab_CykliczneP;
    QHBoxLayout *horizontalLayout_15;
    QStackedWidget *stackedWidget_CykliczneP;
    QWidget *page_CP_lista;
    QHBoxLayout *horizontalLayout_21;
    QTableView *tableView_listaCP;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pushButton_edytujCP;
    QPushButton *pushButton_usunCP;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_nowyCP;
    QWidget *page_nowyCP;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *pushButton_powrotCP;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_32;
    QDoubleSpinBox *doubleSpinBox_kwotaCP;
    QLabel *label_47;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_31;
    QComboBox *comboBox_kategoriaCP;
    QLabel *label_28;
    QDateEdit *dateEdit_CP;
    QLabel *label_29;
    QComboBox *comboBox_czestotliwoscCP;
    QLabel *label_30;
    QLineEdit *lineEdit_notatkaCP;
    QPushButton *pushButton_dodajCP;
    QWidget *tab_CykliczneW;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_17;
    QStackedWidget *stackedWidget_CykliczneW;
    QWidget *page_CW_lista;
    QHBoxLayout *horizontalLayout_18;
    QTableView *tableView_listaCW;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_edytujCW;
    QPushButton *pushButton_usunCW;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_nowyCW;
    QWidget *page_CW_nowy;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_powrotCW;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_20;
    QDoubleSpinBox *doubleSpinBox_kwotaCW;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_21;
    QComboBox *comboBox_kategoriaCW;
    QLabel *label_22;
    QDateEdit *dateEdit_CW;
    QLabel *label_23;
    QComboBox *comboBox_czestotliwoscCW;
    QLabel *label_24;
    QLineEdit *lineEdit_notatkaCW;
    QPushButton *pushButton_dodajCW;
    QWidget *tab_Raporty;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_43;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_29;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_44;
    QDateEdit *dateEdit_R_Od;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_45;
    QDateEdit *dateEdit_R_Do;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *pushButton_generujRaport;
    QSpacerItem *horizontalSpacer_24;
    QHBoxLayout *horizontalLayout_33;
    QPushButton *pushButton_generujRaportOsobisty;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *horizontalLayout_43;
    QCheckBox *checkBox_tylkoKategoria;
    QComboBox *comboBox_kategoriaRaport;
    QSpacerItem *horizontalSpacer_37;
    QHBoxLayout *horizontalLayout_44;
    QPushButton *pushButton_adminRaportOneUser;
    QComboBox *comboBox_adminRaportOneUser;
    QSpacerItem *horizontalSpacer_38;
    QSpacerItem *verticalSpacer_10;
    QWidget *tab_Uzytkownicy;
    QHBoxLayout *horizontalLayout_10;
    QStackedWidget *stackedWidget_uzytkownicy;
    QWidget *page;
    QHBoxLayout *horizontalLayout_23;
    QTableView *tableView_uzytkownicy;
    QVBoxLayout *verticalLayout_11;
    QPushButton *pushButton_edytujDane;
    QCheckBox *checkBox_pokazHasla;
    QPushButton *pushButton_zablokuj_odblokuj;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButton_powrotE;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_33;
    QLineEdit *lineEdit_imieE;
    QLabel *label_34;
    QLineEdit *lineEdit_nazwiskoE;
    QLabel *label_35;
    QLineEdit *lineEdit_mailE;
    QLabel *label_36;
    QComboBox *comboBox_rolaE;
    QHBoxLayout *horizontalLayout_25;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_zapiszE;
    QSpacerItem *horizontalSpacer_21;
    QWidget *tab_Dzieci;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_39;
    QHBoxLayout *horizontalLayout_35;
    QComboBox *comboBox_dzieciLista;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_40;
    QHBoxLayout *horizontalLayout_34;
    QLineEdit *lineEdit_aktualneKieszonkoweKwota;
    QLabel *label_48;
    QSpacerItem *horizontalSpacer_25;
    QLabel *label_41;
    QHBoxLayout *horizontalLayout_28;
    QLineEdit *lineEdit_aktualneSaldo;
    QLabel *label_42;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *verticalSpacer_8;
    QFrame *line;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_zmienKieszonkowe;
    QPushButton *pushButton_generujRaportD;
    QWidget *tab_Relacje;
    QHBoxLayout *horizontalLayout_26;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_37;
    QTableView *tableView_dzieciRelacje;
    QLabel *label_38;
    QTableView *tableView_rodziceRelacje;
    QVBoxLayout *verticalLayout_22;
    QSpacerItem *verticalSpacer_15;
    QPushButton *pushButton_przypiszRodzica;
    QPushButton *pushButton_przypisz2Rodzica;
    QSpacerItem *verticalSpacer_16;

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
        tab_DaneUzytkownika = new QWidget();
        tab_DaneUzytkownika->setObjectName(QString::fromUtf8("tab_DaneUzytkownika"));
        verticalLayout_4 = new QVBoxLayout(tab_DaneUzytkownika);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 6);
        label_8 = new QLabel(tab_DaneUzytkownika);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lineEdit_nameUD = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_nameUD->setObjectName(QString::fromUtf8("lineEdit_nameUD"));
        lineEdit_nameUD->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit_nameUD);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        verticalLayout_4->addLayout(horizontalLayout_11);

        label_9 = new QLabel(tab_DaneUzytkownika);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lineEdit_surnameUD = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_surnameUD->setObjectName(QString::fromUtf8("lineEdit_surnameUD"));
        lineEdit_surnameUD->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_surnameUD);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_12);

        label_10 = new QLabel(tab_DaneUzytkownika);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        dateEdit_DOB_UD = new QDateEdit(tab_DaneUzytkownika);
        dateEdit_DOB_UD->setObjectName(QString::fromUtf8("dateEdit_DOB_UD"));
        dateEdit_DOB_UD->setMaximumSize(QSize(100, 16777215));
        dateEdit_DOB_UD->setReadOnly(true);

        verticalLayout_4->addWidget(dateEdit_DOB_UD);

        label_18 = new QLabel(tab_DaneUzytkownika);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_4->addWidget(label_18);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit_roleUD = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_roleUD->setObjectName(QString::fromUtf8("lineEdit_roleUD"));
        lineEdit_roleUD->setReadOnly(true);

        horizontalLayout_13->addWidget(lineEdit_roleUD);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_13);

        label_11 = new QLabel(tab_DaneUzytkownika);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        lineEdit_emailUD = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_emailUD->setObjectName(QString::fromUtf8("lineEdit_emailUD"));
        lineEdit_emailUD->setReadOnly(true);

        horizontalLayout_14->addWidget(lineEdit_emailUD);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_13);


        verticalLayout_4->addLayout(horizontalLayout_14);

        label_12 = new QLabel(tab_DaneUzytkownika);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_passwordUD = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_passwordUD->setObjectName(QString::fromUtf8("lineEdit_passwordUD"));
        lineEdit_passwordUD->setEchoMode(QLineEdit::Password);
        lineEdit_passwordUD->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_passwordUD);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        checkBox_showPassword = new QCheckBox(tab_DaneUzytkownika);
        checkBox_showPassword->setObjectName(QString::fromUtf8("checkBox_showPassword"));

        horizontalLayout_6->addWidget(checkBox_showPassword);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        pushButton_zmienHaslo = new QPushButton(tab_DaneUzytkownika);
        pushButton_zmienHaslo->setObjectName(QString::fromUtf8("pushButton_zmienHaslo"));

        horizontalLayout_6->addWidget(pushButton_zmienHaslo);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_6);

        label_kieszonkowe = new QLabel(tab_DaneUzytkownika);
        label_kieszonkowe->setObjectName(QString::fromUtf8("label_kieszonkowe"));

        verticalLayout_4->addWidget(label_kieszonkowe);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        lineEdit_kieszonkoweDU = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_kieszonkoweDU->setObjectName(QString::fromUtf8("lineEdit_kieszonkoweDU"));
        lineEdit_kieszonkoweDU->setMaximumSize(QSize(200, 16777215));
        lineEdit_kieszonkoweDU->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_kieszonkoweDU->setReadOnly(true);

        horizontalLayout_41->addWidget(lineEdit_kieszonkoweDU);

        label_zl1 = new QLabel(tab_DaneUzytkownika);
        label_zl1->setObjectName(QString::fromUtf8("label_zl1"));

        horizontalLayout_41->addWidget(label_zl1);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_35);


        verticalLayout_4->addLayout(horizontalLayout_41);

        label_saldo = new QLabel(tab_DaneUzytkownika);
        label_saldo->setObjectName(QString::fromUtf8("label_saldo"));

        verticalLayout_4->addWidget(label_saldo);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        horizontalLayout_42->setContentsMargins(-1, 0, 0, -1);
        lineEdit_saldoDU = new QLineEdit(tab_DaneUzytkownika);
        lineEdit_saldoDU->setObjectName(QString::fromUtf8("lineEdit_saldoDU"));
        lineEdit_saldoDU->setMaximumSize(QSize(200, 16777215));
        lineEdit_saldoDU->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_saldoDU->setReadOnly(true);

        horizontalLayout_42->addWidget(lineEdit_saldoDU);

        label_zl2 = new QLabel(tab_DaneUzytkownika);
        label_zl2->setObjectName(QString::fromUtf8("label_zl2"));

        horizontalLayout_42->addWidget(label_zl2);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_36);


        verticalLayout_4->addLayout(horizontalLayout_42);

        tabWidget->addTab(tab_DaneUzytkownika, QString());
        tab_Budzet = new QWidget();
        tab_Budzet->setObjectName(QString::fromUtf8("tab_Budzet"));
        horizontalLayout_38 = new QHBoxLayout(tab_Budzet);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, -1, -1, 0);
        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_14);

        label_49 = new QLabel(tab_Budzet);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        verticalLayout_21->addWidget(label_49);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        lineEdit_stanBudzet = new QLineEdit(tab_Budzet);
        lineEdit_stanBudzet->setObjectName(QString::fromUtf8("lineEdit_stanBudzet"));
        lineEdit_stanBudzet->setMaximumSize(QSize(200, 16777215));
        lineEdit_stanBudzet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_stanBudzet->setReadOnly(true);

        horizontalLayout_39->addWidget(lineEdit_stanBudzet);

        label_50 = new QLabel(tab_Budzet);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        horizontalLayout_39->addWidget(label_50);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_33);


        verticalLayout_21->addLayout(horizontalLayout_39);

        label_51 = new QLabel(tab_Budzet);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        verticalLayout_21->addWidget(label_51);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        lineEdit_dataBudzet = new QLineEdit(tab_Budzet);
        lineEdit_dataBudzet->setObjectName(QString::fromUtf8("lineEdit_dataBudzet"));
        lineEdit_dataBudzet->setMaximumSize(QSize(200, 16777215));
        lineEdit_dataBudzet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_dataBudzet->setReadOnly(true);

        horizontalLayout_40->addWidget(lineEdit_dataBudzet);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_34);


        verticalLayout_21->addLayout(horizontalLayout_40);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_13);


        horizontalLayout_37->addLayout(verticalLayout_21);

        tableView_budzet = new QTableView(tab_Budzet);
        tableView_budzet->setObjectName(QString::fromUtf8("tableView_budzet"));

        horizontalLayout_37->addWidget(tableView_budzet);


        horizontalLayout_38->addLayout(horizontalLayout_37);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));

        horizontalLayout_38->addLayout(horizontalLayout_36);

        tabWidget->addTab(tab_Budzet, QString());
        tab_Przychody = new QWidget();
        tab_Przychody->setObjectName(QString::fromUtf8("tab_Przychody"));
        verticalLayout_2 = new QVBoxLayout(tab_Przychody);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(tab_Przychody);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBox_kwotaPrzychod = new QDoubleSpinBox(tab_Przychody);
        doubleSpinBox_kwotaPrzychod->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaPrzychod"));
        doubleSpinBox_kwotaPrzychod->setMinimumSize(QSize(150, 0));
        doubleSpinBox_kwotaPrzychod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_kwotaPrzychod->setMaximum(999999.989999999990687);

        horizontalLayout_2->addWidget(doubleSpinBox_kwotaPrzychod);

        label_6 = new QLabel(tab_Przychody);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(tab_Przychody);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_kategoriaPrzychod = new QComboBox(tab_Przychody);
        comboBox_kategoriaPrzychod->setObjectName(QString::fromUtf8("comboBox_kategoriaPrzychod"));
        comboBox_kategoriaPrzychod->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(comboBox_kategoriaPrzychod);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_4 = new QLabel(tab_Przychody);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dateEdit_dataPrzychod = new QDateEdit(tab_Przychody);
        dateEdit_dataPrzychod->setObjectName(QString::fromUtf8("dateEdit_dataPrzychod"));
        dateEdit_dataPrzychod->setMinimumSize(QSize(150, 0));
        dateEdit_dataPrzychod->setCalendarPopup(true);

        horizontalLayout_4->addWidget(dateEdit_dataPrzychod);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label_5 = new QLabel(tab_Przychody);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        lineEdit_notatkaPrzychod = new QLineEdit(tab_Przychody);
        lineEdit_notatkaPrzychod->setObjectName(QString::fromUtf8("lineEdit_notatkaPrzychod"));
        lineEdit_notatkaPrzychod->setMinimumSize(QSize(300, 100));
        lineEdit_notatkaPrzychod->setMaximumSize(QSize(400, 16777215));

        verticalLayout_2->addWidget(lineEdit_notatkaPrzychod);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_dodajPrzychod = new QPushButton(tab_Przychody);
        pushButton_dodajPrzychod->setObjectName(QString::fromUtf8("pushButton_dodajPrzychod"));

        verticalLayout_2->addWidget(pushButton_dodajPrzychod);

        tabWidget->addTab(tab_Przychody, QString());
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
        dateEdit_dataWydatek->setCalendarPopup(true);

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
        tab_Kategorie = new QWidget();
        tab_Kategorie->setObjectName(QString::fromUtf8("tab_Kategorie"));
        horizontalLayout_5 = new QHBoxLayout(tab_Kategorie);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(-1, 9, 0, -1);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_7 = new QLabel(tab_Kategorie);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        lineEdit_nowaKategoria = new QLineEdit(tab_Kategorie);
        lineEdit_nowaKategoria->setObjectName(QString::fromUtf8("lineEdit_nowaKategoria"));

        verticalLayout_8->addWidget(lineEdit_nowaKategoria);

        pushButton_dodajKategorie = new QPushButton(tab_Kategorie);
        pushButton_dodajKategorie->setObjectName(QString::fromUtf8("pushButton_dodajKategorie"));

        verticalLayout_8->addWidget(pushButton_dodajKategorie);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_9);


        horizontalLayout_31->addLayout(verticalLayout_8);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_26);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, -1, -1, -1);
        label_46 = new QLabel(tab_Kategorie);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        verticalLayout_19->addWidget(label_46);

        comboBox_dostepneKategorie = new QComboBox(tab_Kategorie);
        comboBox_dostepneKategorie->setObjectName(QString::fromUtf8("comboBox_dostepneKategorie"));

        verticalLayout_19->addWidget(comboBox_dostepneKategorie);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_19->addItem(verticalSpacer_2);


        horizontalLayout_31->addLayout(verticalLayout_19);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_32);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(-1, -1, 0, -1);
        pushButton_usunKategorie = new QPushButton(tab_Kategorie);
        pushButton_usunKategorie->setObjectName(QString::fromUtf8("pushButton_usunKategorie"));

        verticalLayout_20->addWidget(pushButton_usunKategorie);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_12);


        horizontalLayout_31->addLayout(verticalLayout_20);


        verticalLayout_3->addLayout(horizontalLayout_31);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_27);

        tableView_Kategorie = new QTableView(tab_Kategorie);
        tableView_Kategorie->setObjectName(QString::fromUtf8("tableView_Kategorie"));

        horizontalLayout_5->addWidget(tableView_Kategorie);

        tabWidget->addTab(tab_Kategorie, QString());
        tab_CykliczneP = new QWidget();
        tab_CykliczneP->setObjectName(QString::fromUtf8("tab_CykliczneP"));
        horizontalLayout_15 = new QHBoxLayout(tab_CykliczneP);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        stackedWidget_CykliczneP = new QStackedWidget(tab_CykliczneP);
        stackedWidget_CykliczneP->setObjectName(QString::fromUtf8("stackedWidget_CykliczneP"));
        page_CP_lista = new QWidget();
        page_CP_lista->setObjectName(QString::fromUtf8("page_CP_lista"));
        horizontalLayout_21 = new QHBoxLayout(page_CP_lista);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        tableView_listaCP = new QTableView(page_CP_lista);
        tableView_listaCP->setObjectName(QString::fromUtf8("tableView_listaCP"));

        horizontalLayout_21->addWidget(tableView_listaCP);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, -1, -1, -1);
        pushButton_edytujCP = new QPushButton(page_CP_lista);
        pushButton_edytujCP->setObjectName(QString::fromUtf8("pushButton_edytujCP"));

        verticalLayout_10->addWidget(pushButton_edytujCP);

        pushButton_usunCP = new QPushButton(page_CP_lista);
        pushButton_usunCP->setObjectName(QString::fromUtf8("pushButton_usunCP"));

        verticalLayout_10->addWidget(pushButton_usunCP);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);

        pushButton_nowyCP = new QPushButton(page_CP_lista);
        pushButton_nowyCP->setObjectName(QString::fromUtf8("pushButton_nowyCP"));

        verticalLayout_10->addWidget(pushButton_nowyCP);


        horizontalLayout_21->addLayout(verticalLayout_10);

        stackedWidget_CykliczneP->addWidget(page_CP_lista);
        page_nowyCP = new QWidget();
        page_nowyCP->setObjectName(QString::fromUtf8("page_nowyCP"));
        verticalLayout_6 = new QVBoxLayout(page_nowyCP);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        pushButton_powrotCP = new QPushButton(page_nowyCP);
        pushButton_powrotCP->setObjectName(QString::fromUtf8("pushButton_powrotCP"));

        horizontalLayout_22->addWidget(pushButton_powrotCP);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_17);

        label_26 = new QLabel(page_nowyCP);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QFont font;
        font.setPointSize(15);
        label_26->setFont(font);

        horizontalLayout_22->addWidget(label_26);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_18);


        verticalLayout_6->addLayout(horizontalLayout_22);

        label_27 = new QLabel(page_nowyCP);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_6->addWidget(label_27);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        doubleSpinBox_kwotaCP = new QDoubleSpinBox(page_nowyCP);
        doubleSpinBox_kwotaCP->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaCP"));
        doubleSpinBox_kwotaCP->setMaximum(999999.989999999990687);

        horizontalLayout_32->addWidget(doubleSpinBox_kwotaCP);

        label_47 = new QLabel(page_nowyCP);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        horizontalLayout_32->addWidget(label_47);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_28);


        verticalLayout_6->addLayout(horizontalLayout_32);

        label_31 = new QLabel(page_nowyCP);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        verticalLayout_6->addWidget(label_31);

        comboBox_kategoriaCP = new QComboBox(page_nowyCP);
        comboBox_kategoriaCP->addItem(QString());
        comboBox_kategoriaCP->addItem(QString());
        comboBox_kategoriaCP->addItem(QString());
        comboBox_kategoriaCP->addItem(QString());
        comboBox_kategoriaCP->setObjectName(QString::fromUtf8("comboBox_kategoriaCP"));

        verticalLayout_6->addWidget(comboBox_kategoriaCP);

        label_28 = new QLabel(page_nowyCP);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_6->addWidget(label_28);

        dateEdit_CP = new QDateEdit(page_nowyCP);
        dateEdit_CP->setObjectName(QString::fromUtf8("dateEdit_CP"));
        dateEdit_CP->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEdit_CP);

        label_29 = new QLabel(page_nowyCP);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        verticalLayout_6->addWidget(label_29);

        comboBox_czestotliwoscCP = new QComboBox(page_nowyCP);
        comboBox_czestotliwoscCP->setObjectName(QString::fromUtf8("comboBox_czestotliwoscCP"));

        verticalLayout_6->addWidget(comboBox_czestotliwoscCP);

        label_30 = new QLabel(page_nowyCP);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        verticalLayout_6->addWidget(label_30);

        lineEdit_notatkaCP = new QLineEdit(page_nowyCP);
        lineEdit_notatkaCP->setObjectName(QString::fromUtf8("lineEdit_notatkaCP"));

        verticalLayout_6->addWidget(lineEdit_notatkaCP);

        pushButton_dodajCP = new QPushButton(page_nowyCP);
        pushButton_dodajCP->setObjectName(QString::fromUtf8("pushButton_dodajCP"));

        verticalLayout_6->addWidget(pushButton_dodajCP);

        stackedWidget_CykliczneP->addWidget(page_nowyCP);

        horizontalLayout_15->addWidget(stackedWidget_CykliczneP);

        tabWidget->addTab(tab_CykliczneP, QString());
        tab_CykliczneW = new QWidget();
        tab_CykliczneW->setObjectName(QString::fromUtf8("tab_CykliczneW"));
        horizontalLayout_16 = new QHBoxLayout(tab_CykliczneW);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        stackedWidget_CykliczneW = new QStackedWidget(tab_CykliczneW);
        stackedWidget_CykliczneW->setObjectName(QString::fromUtf8("stackedWidget_CykliczneW"));
        page_CW_lista = new QWidget();
        page_CW_lista->setObjectName(QString::fromUtf8("page_CW_lista"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(page_CW_lista->sizePolicy().hasHeightForWidth());
        page_CW_lista->setSizePolicy(sizePolicy1);
        page_CW_lista->setMinimumSize(QSize(200, 200));
        horizontalLayout_18 = new QHBoxLayout(page_CW_lista);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        tableView_listaCW = new QTableView(page_CW_lista);
        tableView_listaCW->setObjectName(QString::fromUtf8("tableView_listaCW"));

        horizontalLayout_18->addWidget(tableView_listaCW);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, -1, -1, -1);
        pushButton_edytujCW = new QPushButton(page_CW_lista);
        pushButton_edytujCW->setObjectName(QString::fromUtf8("pushButton_edytujCW"));

        verticalLayout_7->addWidget(pushButton_edytujCW);

        pushButton_usunCW = new QPushButton(page_CW_lista);
        pushButton_usunCW->setObjectName(QString::fromUtf8("pushButton_usunCW"));

        verticalLayout_7->addWidget(pushButton_usunCW);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        pushButton_nowyCW = new QPushButton(page_CW_lista);
        pushButton_nowyCW->setObjectName(QString::fromUtf8("pushButton_nowyCW"));

        verticalLayout_7->addWidget(pushButton_nowyCW);


        horizontalLayout_18->addLayout(verticalLayout_7);

        stackedWidget_CykliczneW->addWidget(page_CW_lista);
        page_CW_nowy = new QWidget();
        page_CW_nowy->setObjectName(QString::fromUtf8("page_CW_nowy"));
        verticalLayout_9 = new QVBoxLayout(page_CW_nowy);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        pushButton_powrotCW = new QPushButton(page_CW_nowy);
        pushButton_powrotCW->setObjectName(QString::fromUtf8("pushButton_powrotCW"));

        horizontalLayout_19->addWidget(pushButton_powrotCW);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_14);

        label_25 = new QLabel(page_CW_nowy);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font);
        label_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_25);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_16);


        verticalLayout_9->addLayout(horizontalLayout_19);

        label_19 = new QLabel(page_CW_nowy);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_9->addWidget(label_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        doubleSpinBox_kwotaCW = new QDoubleSpinBox(page_CW_nowy);
        doubleSpinBox_kwotaCW->setObjectName(QString::fromUtf8("doubleSpinBox_kwotaCW"));
        doubleSpinBox_kwotaCW->setMaximum(999999.989999999990687);

        horizontalLayout_20->addWidget(doubleSpinBox_kwotaCW);

        label_20 = new QLabel(page_CW_nowy);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_20->addWidget(label_20);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_15);


        verticalLayout_9->addLayout(horizontalLayout_20);

        label_21 = new QLabel(page_CW_nowy);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_9->addWidget(label_21);

        comboBox_kategoriaCW = new QComboBox(page_CW_nowy);
        comboBox_kategoriaCW->addItem(QString());
        comboBox_kategoriaCW->addItem(QString());
        comboBox_kategoriaCW->addItem(QString());
        comboBox_kategoriaCW->addItem(QString());
        comboBox_kategoriaCW->setObjectName(QString::fromUtf8("comboBox_kategoriaCW"));

        verticalLayout_9->addWidget(comboBox_kategoriaCW);

        label_22 = new QLabel(page_CW_nowy);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_9->addWidget(label_22);

        dateEdit_CW = new QDateEdit(page_CW_nowy);
        dateEdit_CW->setObjectName(QString::fromUtf8("dateEdit_CW"));
        dateEdit_CW->setCalendarPopup(true);

        verticalLayout_9->addWidget(dateEdit_CW);

        label_23 = new QLabel(page_CW_nowy);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_9->addWidget(label_23);

        comboBox_czestotliwoscCW = new QComboBox(page_CW_nowy);
        comboBox_czestotliwoscCW->setObjectName(QString::fromUtf8("comboBox_czestotliwoscCW"));

        verticalLayout_9->addWidget(comboBox_czestotliwoscCW);

        label_24 = new QLabel(page_CW_nowy);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_9->addWidget(label_24);

        lineEdit_notatkaCW = new QLineEdit(page_CW_nowy);
        lineEdit_notatkaCW->setObjectName(QString::fromUtf8("lineEdit_notatkaCW"));

        verticalLayout_9->addWidget(lineEdit_notatkaCW);

        pushButton_dodajCW = new QPushButton(page_CW_nowy);
        pushButton_dodajCW->setObjectName(QString::fromUtf8("pushButton_dodajCW"));

        verticalLayout_9->addWidget(pushButton_dodajCW);

        stackedWidget_CykliczneW->addWidget(page_CW_nowy);

        horizontalLayout_17->addWidget(stackedWidget_CykliczneW);


        horizontalLayout_16->addLayout(horizontalLayout_17);

        tabWidget->addTab(tab_CykliczneW, QString());
        tab_Raporty = new QWidget();
        tab_Raporty->setObjectName(QString::fromUtf8("tab_Raporty"));
        verticalLayout_16 = new QVBoxLayout(tab_Raporty);
        verticalLayout_16->setSpacing(20);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        label_43 = new QLabel(tab_Raporty);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        QFont font1;
        font1.setPointSize(14);
        label_43->setFont(font1);
        label_43->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_43);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_7);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_44 = new QLabel(tab_Raporty);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        verticalLayout_17->addWidget(label_44);

        dateEdit_R_Od = new QDateEdit(tab_Raporty);
        dateEdit_R_Od->setObjectName(QString::fromUtf8("dateEdit_R_Od"));

        verticalLayout_17->addWidget(dateEdit_R_Od);


        horizontalLayout_29->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_45 = new QLabel(tab_Raporty);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        verticalLayout_18->addWidget(label_45);

        dateEdit_R_Do = new QDateEdit(tab_Raporty);
        dateEdit_R_Do->setObjectName(QString::fromUtf8("dateEdit_R_Do"));

        verticalLayout_18->addWidget(dateEdit_R_Do);


        horizontalLayout_29->addLayout(verticalLayout_18);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_31);


        verticalLayout_16->addLayout(horizontalLayout_29);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_6);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        pushButton_generujRaport = new QPushButton(tab_Raporty);
        pushButton_generujRaport->setObjectName(QString::fromUtf8("pushButton_generujRaport"));

        horizontalLayout_30->addWidget(pushButton_generujRaport);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_24);


        verticalLayout_16->addLayout(horizontalLayout_30);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        horizontalLayout_33->setContentsMargins(-1, 0, -1, -1);
        pushButton_generujRaportOsobisty = new QPushButton(tab_Raporty);
        pushButton_generujRaportOsobisty->setObjectName(QString::fromUtf8("pushButton_generujRaportOsobisty"));

        horizontalLayout_33->addWidget(pushButton_generujRaportOsobisty);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_30);


        verticalLayout_16->addLayout(horizontalLayout_33);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalLayout_43->setContentsMargins(-1, 0, -1, -1);
        checkBox_tylkoKategoria = new QCheckBox(tab_Raporty);
        checkBox_tylkoKategoria->setObjectName(QString::fromUtf8("checkBox_tylkoKategoria"));

        horizontalLayout_43->addWidget(checkBox_tylkoKategoria);

        comboBox_kategoriaRaport = new QComboBox(tab_Raporty);
        comboBox_kategoriaRaport->setObjectName(QString::fromUtf8("comboBox_kategoriaRaport"));

        horizontalLayout_43->addWidget(comboBox_kategoriaRaport);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_43->addItem(horizontalSpacer_37);


        verticalLayout_16->addLayout(horizontalLayout_43);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_44->setContentsMargins(-1, 0, -1, -1);
        pushButton_adminRaportOneUser = new QPushButton(tab_Raporty);
        pushButton_adminRaportOneUser->setObjectName(QString::fromUtf8("pushButton_adminRaportOneUser"));

        horizontalLayout_44->addWidget(pushButton_adminRaportOneUser);

        comboBox_adminRaportOneUser = new QComboBox(tab_Raporty);
        comboBox_adminRaportOneUser->setObjectName(QString::fromUtf8("comboBox_adminRaportOneUser"));

        horizontalLayout_44->addWidget(comboBox_adminRaportOneUser);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_38);


        verticalLayout_16->addLayout(horizontalLayout_44);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_10);

        tabWidget->addTab(tab_Raporty, QString());
        tab_Uzytkownicy = new QWidget();
        tab_Uzytkownicy->setObjectName(QString::fromUtf8("tab_Uzytkownicy"));
        horizontalLayout_10 = new QHBoxLayout(tab_Uzytkownicy);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        stackedWidget_uzytkownicy = new QStackedWidget(tab_Uzytkownicy);
        stackedWidget_uzytkownicy->setObjectName(QString::fromUtf8("stackedWidget_uzytkownicy"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_23 = new QHBoxLayout(page);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        tableView_uzytkownicy = new QTableView(page);
        tableView_uzytkownicy->setObjectName(QString::fromUtf8("tableView_uzytkownicy"));
        tableView_uzytkownicy->setMinimumSize(QSize(0, 0));

        horizontalLayout_23->addWidget(tableView_uzytkownicy);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, -1, -1, -1);
        pushButton_edytujDane = new QPushButton(page);
        pushButton_edytujDane->setObjectName(QString::fromUtf8("pushButton_edytujDane"));

        verticalLayout_11->addWidget(pushButton_edytujDane);

        checkBox_pokazHasla = new QCheckBox(page);
        checkBox_pokazHasla->setObjectName(QString::fromUtf8("checkBox_pokazHasla"));

        verticalLayout_11->addWidget(checkBox_pokazHasla);

        pushButton_zablokuj_odblokuj = new QPushButton(page);
        pushButton_zablokuj_odblokuj->setObjectName(QString::fromUtf8("pushButton_zablokuj_odblokuj"));

        verticalLayout_11->addWidget(pushButton_zablokuj_odblokuj);


        horizontalLayout_23->addLayout(verticalLayout_11);

        stackedWidget_uzytkownicy->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_12 = new QVBoxLayout(page_3);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        pushButton_powrotE = new QPushButton(page_3);
        pushButton_powrotE->setObjectName(QString::fromUtf8("pushButton_powrotE"));

        horizontalLayout_24->addWidget(pushButton_powrotE);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_19);

        label_32 = new QLabel(page_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_24->addWidget(label_32);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_22);


        verticalLayout_12->addLayout(horizontalLayout_24);

        label_33 = new QLabel(page_3);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        verticalLayout_12->addWidget(label_33);

        lineEdit_imieE = new QLineEdit(page_3);
        lineEdit_imieE->setObjectName(QString::fromUtf8("lineEdit_imieE"));

        verticalLayout_12->addWidget(lineEdit_imieE);

        label_34 = new QLabel(page_3);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        verticalLayout_12->addWidget(label_34);

        lineEdit_nazwiskoE = new QLineEdit(page_3);
        lineEdit_nazwiskoE->setObjectName(QString::fromUtf8("lineEdit_nazwiskoE"));

        verticalLayout_12->addWidget(lineEdit_nazwiskoE);

        label_35 = new QLabel(page_3);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        verticalLayout_12->addWidget(label_35);

        lineEdit_mailE = new QLineEdit(page_3);
        lineEdit_mailE->setObjectName(QString::fromUtf8("lineEdit_mailE"));

        verticalLayout_12->addWidget(lineEdit_mailE);

        label_36 = new QLabel(page_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        verticalLayout_12->addWidget(label_36);

        comboBox_rolaE = new QComboBox(page_3);
        comboBox_rolaE->setObjectName(QString::fromUtf8("comboBox_rolaE"));

        verticalLayout_12->addWidget(comboBox_rolaE);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_20);

        pushButton_zapiszE = new QPushButton(page_3);
        pushButton_zapiszE->setObjectName(QString::fromUtf8("pushButton_zapiszE"));

        horizontalLayout_25->addWidget(pushButton_zapiszE);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_21);


        verticalLayout_12->addLayout(horizontalLayout_25);

        stackedWidget_uzytkownicy->addWidget(page_3);

        horizontalLayout_10->addWidget(stackedWidget_uzytkownicy);

        tabWidget->addTab(tab_Uzytkownicy, QString());
        tab_Dzieci = new QWidget();
        tab_Dzieci->setObjectName(QString::fromUtf8("tab_Dzieci"));
        horizontalLayout_27 = new QHBoxLayout(tab_Dzieci);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(-1, 20, -1, -1);
        label_39 = new QLabel(tab_Dzieci);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        verticalLayout_15->addWidget(label_39);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(-1, 0, -1, -1);
        comboBox_dzieciLista = new QComboBox(tab_Dzieci);
        comboBox_dzieciLista->setObjectName(QString::fromUtf8("comboBox_dzieciLista"));

        horizontalLayout_35->addWidget(comboBox_dzieciLista);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_29);


        verticalLayout_15->addLayout(horizontalLayout_35);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_11);

        label_40 = new QLabel(tab_Dzieci);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        verticalLayout_15->addWidget(label_40);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        lineEdit_aktualneKieszonkoweKwota = new QLineEdit(tab_Dzieci);
        lineEdit_aktualneKieszonkoweKwota->setObjectName(QString::fromUtf8("lineEdit_aktualneKieszonkoweKwota"));
        lineEdit_aktualneKieszonkoweKwota->setMaximumSize(QSize(200, 16777215));
        lineEdit_aktualneKieszonkoweKwota->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_34->addWidget(lineEdit_aktualneKieszonkoweKwota);

        label_48 = new QLabel(tab_Dzieci);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        horizontalLayout_34->addWidget(label_48);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_25);


        verticalLayout_15->addLayout(horizontalLayout_34);

        label_41 = new QLabel(tab_Dzieci);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        verticalLayout_15->addWidget(label_41);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(-1, 9, -1, -1);
        lineEdit_aktualneSaldo = new QLineEdit(tab_Dzieci);
        lineEdit_aktualneSaldo->setObjectName(QString::fromUtf8("lineEdit_aktualneSaldo"));
        lineEdit_aktualneSaldo->setMaximumSize(QSize(200, 16777215));
        lineEdit_aktualneSaldo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_28->addWidget(lineEdit_aktualneSaldo);

        label_42 = new QLabel(tab_Dzieci);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        horizontalLayout_28->addWidget(label_42);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_23);


        verticalLayout_15->addLayout(horizontalLayout_28);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_8);


        horizontalLayout_27->addLayout(verticalLayout_15);

        line = new QFrame(tab_Dzieci);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_27->addWidget(line);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        pushButton_zmienKieszonkowe = new QPushButton(tab_Dzieci);
        pushButton_zmienKieszonkowe->setObjectName(QString::fromUtf8("pushButton_zmienKieszonkowe"));

        verticalLayout_14->addWidget(pushButton_zmienKieszonkowe);

        pushButton_generujRaportD = new QPushButton(tab_Dzieci);
        pushButton_generujRaportD->setObjectName(QString::fromUtf8("pushButton_generujRaportD"));

        verticalLayout_14->addWidget(pushButton_generujRaportD);


        horizontalLayout_27->addLayout(verticalLayout_14);

        tabWidget->addTab(tab_Dzieci, QString());
        tab_Relacje = new QWidget();
        tab_Relacje->setObjectName(QString::fromUtf8("tab_Relacje"));
        horizontalLayout_26 = new QHBoxLayout(tab_Relacje);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_37 = new QLabel(tab_Relacje);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        verticalLayout_13->addWidget(label_37);

        tableView_dzieciRelacje = new QTableView(tab_Relacje);
        tableView_dzieciRelacje->setObjectName(QString::fromUtf8("tableView_dzieciRelacje"));

        verticalLayout_13->addWidget(tableView_dzieciRelacje);

        label_38 = new QLabel(tab_Relacje);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        verticalLayout_13->addWidget(label_38);

        tableView_rodziceRelacje = new QTableView(tab_Relacje);
        tableView_rodziceRelacje->setObjectName(QString::fromUtf8("tableView_rodziceRelacje"));

        verticalLayout_13->addWidget(tableView_rodziceRelacje);


        horizontalLayout_26->addLayout(verticalLayout_13);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(50);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(0, -1, -1, -1);
        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_22->addItem(verticalSpacer_15);

        pushButton_przypiszRodzica = new QPushButton(tab_Relacje);
        pushButton_przypiszRodzica->setObjectName(QString::fromUtf8("pushButton_przypiszRodzica"));

        verticalLayout_22->addWidget(pushButton_przypiszRodzica);

        pushButton_przypisz2Rodzica = new QPushButton(tab_Relacje);
        pushButton_przypisz2Rodzica->setObjectName(QString::fromUtf8("pushButton_przypisz2Rodzica"));

        verticalLayout_22->addWidget(pushButton_przypisz2Rodzica);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_22->addItem(verticalSpacer_16);


        horizontalLayout_26->addLayout(verticalLayout_22);

        tabWidget->addTab(tab_Relacje, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(User_Panel);

        tabWidget->setCurrentIndex(7);
        stackedWidget_CykliczneP->setCurrentIndex(0);
        stackedWidget_CykliczneW->setCurrentIndex(1);
        stackedWidget_uzytkownicy->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(User_Panel);
    } // setupUi

    void retranslateUi(QWidget *User_Panel)
    {
        User_Panel->setWindowTitle(QCoreApplication::translate("User_Panel", "Form", nullptr));
        label->setText(QCoreApplication::translate("User_Panel", "Panel u\305\274ytkownika", nullptr));
        label_name->setText(QCoreApplication::translate("User_Panel", "\"IMI\304\230 I NAZWISKO\"", nullptr));
        label_role->setText(QCoreApplication::translate("User_Panel", "\"ROLA\"", nullptr));
        button_logout->setText(QCoreApplication::translate("User_Panel", "WYLOGUJ", nullptr));
        label_8->setText(QCoreApplication::translate("User_Panel", "Imi\304\231", nullptr));
        label_9->setText(QCoreApplication::translate("User_Panel", "Nazwisko", nullptr));
        label_10->setText(QCoreApplication::translate("User_Panel", "Data urodzenia", nullptr));
        label_18->setText(QCoreApplication::translate("User_Panel", "Rola", nullptr));
        label_11->setText(QCoreApplication::translate("User_Panel", "E-mail", nullptr));
        label_12->setText(QCoreApplication::translate("User_Panel", "Has\305\202o", nullptr));
        checkBox_showPassword->setText(QCoreApplication::translate("User_Panel", "Poka\305\274 has\305\202o", nullptr));
        pushButton_zmienHaslo->setText(QCoreApplication::translate("User_Panel", "Zmie\305\204 has\305\202o", nullptr));
        label_kieszonkowe->setText(QCoreApplication::translate("User_Panel", "Kieszonkowe:", nullptr));
        label_zl1->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_saldo->setText(QCoreApplication::translate("User_Panel", "Saldo:", nullptr));
        label_zl2->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_DaneUzytkownika), QCoreApplication::translate("User_Panel", "Dane u\305\274ytkownika", nullptr));
        label_49->setText(QCoreApplication::translate("User_Panel", "Aktualny stan bud\305\274etu:", nullptr));
        label_50->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_51->setText(QCoreApplication::translate("User_Panel", "Data ostatniej aktualizacji:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Budzet), QCoreApplication::translate("User_Panel", "Bud\305\274et", nullptr));
        label_2->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_6->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_3->setText(QCoreApplication::translate("User_Panel", "Kategoria", nullptr));
        label_4->setText(QCoreApplication::translate("User_Panel", "Data", nullptr));
        label_5->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalnie)", nullptr));
        pushButton_dodajPrzychod->setText(QCoreApplication::translate("User_Panel", "Dodaj przych\303\263d", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Przychody), QCoreApplication::translate("User_Panel", "Przychody", nullptr));
        label_13->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_14->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_15->setText(QCoreApplication::translate("User_Panel", "Kategoria", nullptr));
        label_16->setText(QCoreApplication::translate("User_Panel", "Data", nullptr));
        label_17->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalnie)", nullptr));
        pushButton_dodajWydatek->setText(QCoreApplication::translate("User_Panel", "Dodaj wydatek", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Wydatki), QCoreApplication::translate("User_Panel", "Wydatki", nullptr));
        label_7->setText(QCoreApplication::translate("User_Panel", "Nowa kategoria:", nullptr));
        pushButton_dodajKategorie->setText(QCoreApplication::translate("User_Panel", "Dodaj kategori\304\231", nullptr));
        label_46->setText(QCoreApplication::translate("User_Panel", "Dost\304\231pne kategorie", nullptr));
        pushButton_usunKategorie->setText(QCoreApplication::translate("User_Panel", "Usu\305\204 kategori\304\231", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Kategorie), QCoreApplication::translate("User_Panel", "Dodaj kategorie", nullptr));
        pushButton_edytujCP->setText(QCoreApplication::translate("User_Panel", "Edytuj", nullptr));
        pushButton_usunCP->setText(QCoreApplication::translate("User_Panel", "Usu\305\204", nullptr));
        pushButton_nowyCP->setText(QCoreApplication::translate("User_Panel", "Dodaj nowy przych\303\263d cykliczny", nullptr));
        pushButton_powrotCP->setText(QCoreApplication::translate("User_Panel", "Powr\303\263t", nullptr));
        label_26->setText(QCoreApplication::translate("User_Panel", "Nowy przych\303\263d cykliczny", nullptr));
        label_27->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_47->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_31->setText(QCoreApplication::translate("User_Panel", "Kategoria", nullptr));
        comboBox_kategoriaCP->setItemText(0, QCoreApplication::translate("User_Panel", "codziennie", nullptr));
        comboBox_kategoriaCP->setItemText(1, QCoreApplication::translate("User_Panel", "co tydzie\305\204", nullptr));
        comboBox_kategoriaCP->setItemText(2, QCoreApplication::translate("User_Panel", "co miesi\304\205c", nullptr));
        comboBox_kategoriaCP->setItemText(3, QCoreApplication::translate("User_Panel", "co rok", nullptr));

        label_28->setText(QCoreApplication::translate("User_Panel", "Data rozpocz\304\231cia", nullptr));
        label_29->setText(QCoreApplication::translate("User_Panel", "Cz\304\231stotliwo\305\233\304\207", nullptr));
        label_30->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalnie)", nullptr));
        pushButton_dodajCP->setText(QCoreApplication::translate("User_Panel", "Dodaj przych\303\263d cykliczny", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_CykliczneP), QCoreApplication::translate("User_Panel", "Cykliczne przychody", nullptr));
        pushButton_edytujCW->setText(QCoreApplication::translate("User_Panel", "Edytuj", nullptr));
        pushButton_usunCW->setText(QCoreApplication::translate("User_Panel", "Usu\305\204", nullptr));
        pushButton_nowyCW->setText(QCoreApplication::translate("User_Panel", "Dodaj nowy wydatek cykliczny", nullptr));
        pushButton_powrotCW->setText(QCoreApplication::translate("User_Panel", "Powr\303\263t", nullptr));
        label_25->setText(QCoreApplication::translate("User_Panel", "Nowy wydatek cykliczny", nullptr));
        label_19->setText(QCoreApplication::translate("User_Panel", "Kwota", nullptr));
        label_20->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_21->setText(QCoreApplication::translate("User_Panel", "Kategoria", nullptr));
        comboBox_kategoriaCW->setItemText(0, QCoreApplication::translate("User_Panel", "codziennie", nullptr));
        comboBox_kategoriaCW->setItemText(1, QCoreApplication::translate("User_Panel", "co tydzie\305\204", nullptr));
        comboBox_kategoriaCW->setItemText(2, QCoreApplication::translate("User_Panel", "co miesi\304\205c", nullptr));
        comboBox_kategoriaCW->setItemText(3, QCoreApplication::translate("User_Panel", "co rok", nullptr));

        label_22->setText(QCoreApplication::translate("User_Panel", "Data rozpocz\304\231cia", nullptr));
        label_23->setText(QCoreApplication::translate("User_Panel", "Cz\304\231stotliwo\305\233\304\207", nullptr));
        label_24->setText(QCoreApplication::translate("User_Panel", "Notatka (opcjonalnie)", nullptr));
        pushButton_dodajCW->setText(QCoreApplication::translate("User_Panel", "Dodaj wydatek cykliczny", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_CykliczneW), QCoreApplication::translate("User_Panel", "Cykliczne wydatki", nullptr));
        label_43->setText(QCoreApplication::translate("User_Panel", "Generuj raport", nullptr));
        label_44->setText(QCoreApplication::translate("User_Panel", "Od:", nullptr));
        label_45->setText(QCoreApplication::translate("User_Panel", "Do:", nullptr));
        pushButton_generujRaport->setText(QCoreApplication::translate("User_Panel", "Generuj raport dla ca\305\202ego bud\305\274etu", nullptr));
        pushButton_generujRaportOsobisty->setText(QCoreApplication::translate("User_Panel", "Generuj raport osobisty", nullptr));
        checkBox_tylkoKategoria->setText(QCoreApplication::translate("User_Panel", "Tylko dla wybranej kategorii:", nullptr));
        pushButton_adminRaportOneUser->setText(QCoreApplication::translate("User_Panel", "Generuj raport dla u\305\274ytkownika:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Raporty), QCoreApplication::translate("User_Panel", "Raporty", nullptr));
        pushButton_edytujDane->setText(QCoreApplication::translate("User_Panel", "Edytuj dane", nullptr));
        checkBox_pokazHasla->setText(QCoreApplication::translate("User_Panel", "Poka\305\274 has\305\202a", nullptr));
        pushButton_zablokuj_odblokuj->setText(QCoreApplication::translate("User_Panel", "Zablokuj/odblokuj", nullptr));
        pushButton_powrotE->setText(QCoreApplication::translate("User_Panel", "Powr\303\263t", nullptr));
        label_32->setText(QCoreApplication::translate("User_Panel", "Edytuj dane", nullptr));
        label_33->setText(QCoreApplication::translate("User_Panel", "Imi\304\231", nullptr));
        label_34->setText(QCoreApplication::translate("User_Panel", "Nazwisko", nullptr));
        label_35->setText(QCoreApplication::translate("User_Panel", "E-mail", nullptr));
        label_36->setText(QCoreApplication::translate("User_Panel", "Rola", nullptr));
        pushButton_zapiszE->setText(QCoreApplication::translate("User_Panel", "Zapisz zmiany", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Uzytkownicy), QCoreApplication::translate("User_Panel", "U\305\274ytkownicy", nullptr));
        label_39->setText(QCoreApplication::translate("User_Panel", "Wybierz dziecko:", nullptr));
        label_40->setText(QCoreApplication::translate("User_Panel", "Aktualne kieszonkowe:", nullptr));
        label_48->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        label_41->setText(QCoreApplication::translate("User_Panel", "Aktualne saldo:", nullptr));
        label_42->setText(QCoreApplication::translate("User_Panel", "z\305\202", nullptr));
        pushButton_zmienKieszonkowe->setText(QCoreApplication::translate("User_Panel", "Zmie\305\204 kieszonkowe", nullptr));
        pushButton_generujRaportD->setText(QCoreApplication::translate("User_Panel", "Generuj raport", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Dzieci), QCoreApplication::translate("User_Panel", "Dzieci", nullptr));
        label_37->setText(QCoreApplication::translate("User_Panel", "Dzieci", nullptr));
        label_38->setText(QCoreApplication::translate("User_Panel", "Rodzice", nullptr));
        pushButton_przypiszRodzica->setText(QCoreApplication::translate("User_Panel", "Przypisz 1. rodzica", nullptr));
        pushButton_przypisz2Rodzica->setText(QCoreApplication::translate("User_Panel", "Przypisz 2. rodzica", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Relacje), QCoreApplication::translate("User_Panel", "Relacje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User_Panel: public Ui_User_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_PANEL_H
