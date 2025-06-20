/********************************************************************************
** Form generated from reading UI file 'Start_Log_Reg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_LOG_REG_H
#define UI_START_LOG_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start_Log_Reg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QStackedWidget *stackedWidget;
    QWidget *Start_page;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Zarejestruj;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Zaloguj;
    QSpacerItem *horizontalSpacer_16;
    QWidget *Login_page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_emailLog;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_passwordLog;
    QCheckBox *checkBox_showPasswordLog;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_zalogujSie;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_powrotLog;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_9;
    QWidget *Register_page;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QLineEdit *lineEdit_emailReg;
    QLabel *label_7;
    QLineEdit *lineEdit_firstNameReg;
    QLabel *label_8;
    QLineEdit *lineEdit_lastNameReg;
    QLabel *label_9;
    QDateEdit *dateEdit_DOB_Reg;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_passwordReg;
    QCheckBox *checkBox_showPasswordReg;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_zarejestrujSie;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_powrotReg;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *Start_Log_Reg)
    {
        if (Start_Log_Reg->objectName().isEmpty())
            Start_Log_Reg->setObjectName(QString::fromUtf8("Start_Log_Reg"));
        Start_Log_Reg->resize(1100, 461);
        Start_Log_Reg->setAutoFillBackground(false);
        Start_Log_Reg->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(Start_Log_Reg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(Start_Log_Reg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(Start_Log_Reg);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        Start_page = new QWidget();
        Start_page->setObjectName(QString::fromUtf8("Start_page"));
        horizontalLayout_4 = new QHBoxLayout(Start_page);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(600, -1, 100, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_Zarejestruj = new QPushButton(Start_page);
        pushButton_Zarejestruj->setObjectName(QString::fromUtf8("pushButton_Zarejestruj"));

        horizontalLayout_3->addWidget(pushButton_Zarejestruj);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        pushButton_Zaloguj = new QPushButton(Start_page);
        pushButton_Zaloguj->setObjectName(QString::fromUtf8("pushButton_Zaloguj"));

        horizontalLayout_10->addWidget(pushButton_Zaloguj);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);


        verticalLayout_4->addLayout(horizontalLayout_10);


        horizontalLayout_4->addLayout(verticalLayout_4);

        stackedWidget->addWidget(Start_page);
        Login_page = new QWidget();
        Login_page->setObjectName(QString::fromUtf8("Login_page"));
        verticalLayout_2 = new QVBoxLayout(Login_page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(Login_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(Login_page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        lineEdit_emailLog = new QLineEdit(Login_page);
        lineEdit_emailLog->setObjectName(QString::fromUtf8("lineEdit_emailLog"));

        horizontalLayout_6->addWidget(lineEdit_emailLog);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        label_4 = new QLabel(Login_page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, -1);
        lineEdit_passwordLog = new QLineEdit(Login_page);
        lineEdit_passwordLog->setObjectName(QString::fromUtf8("lineEdit_passwordLog"));
        lineEdit_passwordLog->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(lineEdit_passwordLog);

        checkBox_showPasswordLog = new QCheckBox(Login_page);
        checkBox_showPasswordLog->setObjectName(QString::fromUtf8("checkBox_showPasswordLog"));

        horizontalLayout_7->addWidget(checkBox_showPasswordLog);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButton_zalogujSie = new QPushButton(Login_page);
        pushButton_zalogujSie->setObjectName(QString::fromUtf8("pushButton_zalogujSie"));

        horizontalLayout_8->addWidget(pushButton_zalogujSie);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        pushButton_powrotLog = new QPushButton(Login_page);
        pushButton_powrotLog->setObjectName(QString::fromUtf8("pushButton_powrotLog"));

        horizontalLayout_8->addWidget(pushButton_powrotLog);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(Login_page);
        Register_page = new QWidget();
        Register_page->setObjectName(QString::fromUtf8("Register_page"));
        verticalLayout_3 = new QVBoxLayout(Register_page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(Register_page);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        label_6 = new QLabel(Register_page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        lineEdit_emailReg = new QLineEdit(Register_page);
        lineEdit_emailReg->setObjectName(QString::fromUtf8("lineEdit_emailReg"));
        lineEdit_emailReg->setMaximumSize(QSize(500, 16777215));

        verticalLayout_3->addWidget(lineEdit_emailReg);

        label_7 = new QLabel(Register_page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        lineEdit_firstNameReg = new QLineEdit(Register_page);
        lineEdit_firstNameReg->setObjectName(QString::fromUtf8("lineEdit_firstNameReg"));
        lineEdit_firstNameReg->setMaximumSize(QSize(500, 16777215));

        verticalLayout_3->addWidget(lineEdit_firstNameReg);

        label_8 = new QLabel(Register_page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        lineEdit_lastNameReg = new QLineEdit(Register_page);
        lineEdit_lastNameReg->setObjectName(QString::fromUtf8("lineEdit_lastNameReg"));
        lineEdit_lastNameReg->setMaximumSize(QSize(500, 16777215));

        verticalLayout_3->addWidget(lineEdit_lastNameReg);

        label_9 = new QLabel(Register_page);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        dateEdit_DOB_Reg = new QDateEdit(Register_page);
        dateEdit_DOB_Reg->setObjectName(QString::fromUtf8("dateEdit_DOB_Reg"));
        dateEdit_DOB_Reg->setMaximumSize(QSize(200, 16777215));
        dateEdit_DOB_Reg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateEdit_DOB_Reg->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateEdit_DOB_Reg);

        label_10 = new QLabel(Register_page);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_3->addWidget(label_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 20, -1, -1);
        lineEdit_passwordReg = new QLineEdit(Register_page);
        lineEdit_passwordReg->setObjectName(QString::fromUtf8("lineEdit_passwordReg"));
        lineEdit_passwordReg->setMaximumSize(QSize(500, 16777215));
        lineEdit_passwordReg->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(lineEdit_passwordReg);

        checkBox_showPasswordReg = new QCheckBox(Register_page);
        checkBox_showPasswordReg->setObjectName(QString::fromUtf8("checkBox_showPasswordReg"));

        horizontalLayout_5->addWidget(checkBox_showPasswordReg);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);

        pushButton_zarejestrujSie = new QPushButton(Register_page);
        pushButton_zarejestrujSie->setObjectName(QString::fromUtf8("pushButton_zarejestrujSie"));

        horizontalLayout_9->addWidget(pushButton_zarejestrujSie);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);

        pushButton_powrotReg = new QPushButton(Register_page);
        pushButton_powrotReg->setObjectName(QString::fromUtf8("pushButton_powrotReg"));

        horizontalLayout_9->addWidget(pushButton_powrotReg);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);


        verticalLayout_3->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(Register_page);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Start_Log_Reg);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Start_Log_Reg);
    } // setupUi

    void retranslateUi(QWidget *Start_Log_Reg)
    {
        Start_Log_Reg->setWindowTitle(QCoreApplication::translate("Start_Log_Reg", "Form", nullptr));
        label->setText(QCoreApplication::translate("Start_Log_Reg", "Bud\305\274et domowy", nullptr));
        pushButton_Zarejestruj->setText(QCoreApplication::translate("Start_Log_Reg", "Zarejestruj", nullptr));
        pushButton_Zaloguj->setText(QCoreApplication::translate("Start_Log_Reg", "Zaloguj", nullptr));
        label_2->setText(QCoreApplication::translate("Start_Log_Reg", "Logowanie", nullptr));
        label_3->setText(QCoreApplication::translate("Start_Log_Reg", "E-mail", nullptr));
        label_4->setText(QCoreApplication::translate("Start_Log_Reg", "Has\305\202o", nullptr));
        checkBox_showPasswordLog->setText(QCoreApplication::translate("Start_Log_Reg", "Poka\305\274 has\305\202o", nullptr));
        pushButton_zalogujSie->setText(QCoreApplication::translate("Start_Log_Reg", "Zaloguj si\304\231", nullptr));
        pushButton_powrotLog->setText(QCoreApplication::translate("Start_Log_Reg", "Powr\303\263t", nullptr));
        label_5->setText(QCoreApplication::translate("Start_Log_Reg", "Rejestracja", nullptr));
        label_6->setText(QCoreApplication::translate("Start_Log_Reg", "E-mail", nullptr));
        label_7->setText(QCoreApplication::translate("Start_Log_Reg", "Imi\304\231", nullptr));
        label_8->setText(QCoreApplication::translate("Start_Log_Reg", "Nazwisko", nullptr));
        label_9->setText(QCoreApplication::translate("Start_Log_Reg", "Data urodzenia", nullptr));
        label_10->setText(QCoreApplication::translate("Start_Log_Reg", "Has\305\202o", nullptr));
        checkBox_showPasswordReg->setText(QCoreApplication::translate("Start_Log_Reg", "Poka\305\274 has\305\202o", nullptr));
        pushButton_zarejestrujSie->setText(QCoreApplication::translate("Start_Log_Reg", "Zarejestruj", nullptr));
        pushButton_powrotReg->setText(QCoreApplication::translate("Start_Log_Reg", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start_Log_Reg: public Ui_Start_Log_Reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_LOG_REG_H
