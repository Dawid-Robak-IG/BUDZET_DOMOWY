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
#include <QtWidgets/QFrame>
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
    QSpacerItem *verticalSpacer_9;
    QStackedWidget *stackedWidget;
    QWidget *Start_page;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Zaloguj;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Zarejestruj;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *infoButton;
    QWidget *Login_page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_3;
    QLineEdit *lineEdit_emailLog;
    QLabel *label_4;
    QLineEdit *lineEdit_passwordLog;
    QCheckBox *checkBox_showPasswordLog;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_zalogujSie;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_powrotLog;
    QSpacerItem *horizontalSpacer_12;
    QWidget *Register_page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_10;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_11;
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
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_zarejestrujSie;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_powrotReg;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *Start_Log_Reg)
    {
        if (Start_Log_Reg->objectName().isEmpty())
            Start_Log_Reg->setObjectName(QString::fromUtf8("Start_Log_Reg"));
        Start_Log_Reg->resize(1142, 676);
        Start_Log_Reg->setAutoFillBackground(false);
        Start_Log_Reg->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(Start_Log_Reg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 30, 50, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(Start_Log_Reg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        stackedWidget = new QStackedWidget(Start_Log_Reg);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        Start_page = new QWidget();
        Start_page->setObjectName(QString::fromUtf8("Start_page"));
        horizontalLayout_4 = new QHBoxLayout(Start_page);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(700, -1, 100, -1);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        frame = new QFrame(Start_page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(300, 300));
        frame->setMaximumSize(QSize(500, 16777215));
        frame->setStyleSheet(QString::fromUtf8(" background-color: rgba(255, 255, 255, 180); border-radius: 15px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        pushButton_Zaloguj = new QPushButton(frame);
        pushButton_Zaloguj->setObjectName(QString::fromUtf8("pushButton_Zaloguj"));
        pushButton_Zaloguj->setMinimumSize(QSize(150, 50));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        pushButton_Zaloguj->setFont(font1);
        pushButton_Zaloguj->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 194, 199, 255);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 194, 199, 200);\n"
"}\n"
"\n"
""));

        horizontalLayout_11->addWidget(pushButton_Zaloguj);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        pushButton_Zarejestruj = new QPushButton(frame);
        pushButton_Zarejestruj->setObjectName(QString::fromUtf8("pushButton_Zarejestruj"));
        pushButton_Zarejestruj->setMinimumSize(QSize(150, 50));
        pushButton_Zarejestruj->setFont(font1);
        pushButton_Zarejestruj->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 59, 91, 255);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 59, 91, 200);   \n"
"}\n"
"\n"
""));

        horizontalLayout_12->addWidget(pushButton_Zarejestruj);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_16);


        verticalLayout_7->addLayout(horizontalLayout_12);


        verticalLayout_4->addWidget(frame);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        infoButton = new QPushButton(Start_page);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setMinimumSize(QSize(50, 50));
        infoButton->setMaximumSize(QSize(50, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Sans"));
        font2.setPointSize(30);
        font2.setBold(true);
        infoButton->setFont(font2);
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgba(0, 59, 91, 255);\n"
"    color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 59, 91, 200);   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(0, 59, 91, 150);   \n"
"}\n"
""));

        horizontalLayout_3->addWidget(infoButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_4);

        stackedWidget->addWidget(Start_page);
        Login_page = new QWidget();
        Login_page->setObjectName(QString::fromUtf8("Login_page"));
        verticalLayout_2 = new QVBoxLayout(Login_page);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(800, -1, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        frame_2 = new QFrame(Login_page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
" background-color: rgba(255, 255, 255, 180); border-radius: 15px;}\n"
"\n"
"QLabel{\n"
" background-color: rgba(255, 255, 255,0); }"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(20, 20, -1, 20);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        label_2->setFont(font3);

        verticalLayout_5->addWidget(label_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        lineEdit_emailLog = new QLineEdit(frame_2);
        lineEdit_emailLog->setObjectName(QString::fromUtf8("lineEdit_emailLog"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_emailLog->sizePolicy().hasHeightForWidth());
        lineEdit_emailLog->setSizePolicy(sizePolicy);
        lineEdit_emailLog->setMinimumSize(QSize(400, 40));
        lineEdit_emailLog->setMaximumSize(QSize(400, 16777215));
        lineEdit_emailLog->setStyleSheet(QString::fromUtf8("padding-left: 8px;"));

        verticalLayout_5->addWidget(lineEdit_emailLog);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        lineEdit_passwordLog = new QLineEdit(frame_2);
        lineEdit_passwordLog->setObjectName(QString::fromUtf8("lineEdit_passwordLog"));
        lineEdit_passwordLog->setMinimumSize(QSize(400, 40));
        lineEdit_passwordLog->setMaximumSize(QSize(400, 16777215));
        lineEdit_passwordLog->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(lineEdit_passwordLog);

        checkBox_showPasswordLog = new QCheckBox(frame_2);
        checkBox_showPasswordLog->setObjectName(QString::fromUtf8("checkBox_showPasswordLog"));

        verticalLayout_5->addWidget(checkBox_showPasswordLog);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        pushButton_zalogujSie = new QPushButton(frame_2);
        pushButton_zalogujSie->setObjectName(QString::fromUtf8("pushButton_zalogujSie"));
        pushButton_zalogujSie->setMaximumSize(QSize(250, 16777215));

        verticalLayout_5->addWidget(pushButton_zalogujSie);


        verticalLayout_2->addWidget(frame_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, -1);
        pushButton_powrotLog = new QPushButton(Login_page);
        pushButton_powrotLog->setObjectName(QString::fromUtf8("pushButton_powrotLog"));

        horizontalLayout_8->addWidget(pushButton_powrotLog);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(Login_page);
        Register_page = new QWidget();
        Register_page->setObjectName(QString::fromUtf8("Register_page"));
        verticalLayout_3 = new QVBoxLayout(Register_page);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(800, -1, -1, -1);
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_10);

        frame_3 = new QFrame(Register_page);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame{\n"
" background-color: rgba(255, 255, 255, 180); border-radius: 15px;}\n"
"\n"
"QLabel{\n"
" background-color: rgba(255, 255, 255,0); }"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);

        verticalLayout_6->addWidget(label_5);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_11);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_6->addWidget(label_6);

        lineEdit_emailReg = new QLineEdit(frame_3);
        lineEdit_emailReg->setObjectName(QString::fromUtf8("lineEdit_emailReg"));
        lineEdit_emailReg->setMaximumSize(QSize(400, 16777215));

        verticalLayout_6->addWidget(lineEdit_emailReg);

        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        lineEdit_firstNameReg = new QLineEdit(frame_3);
        lineEdit_firstNameReg->setObjectName(QString::fromUtf8("lineEdit_firstNameReg"));
        lineEdit_firstNameReg->setMaximumSize(QSize(400, 16777215));

        verticalLayout_6->addWidget(lineEdit_firstNameReg);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_6->addWidget(label_8);

        lineEdit_lastNameReg = new QLineEdit(frame_3);
        lineEdit_lastNameReg->setObjectName(QString::fromUtf8("lineEdit_lastNameReg"));
        lineEdit_lastNameReg->setMaximumSize(QSize(400, 16777215));

        verticalLayout_6->addWidget(lineEdit_lastNameReg);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_6->addWidget(label_9);

        dateEdit_DOB_Reg = new QDateEdit(frame_3);
        dateEdit_DOB_Reg->setObjectName(QString::fromUtf8("dateEdit_DOB_Reg"));
        dateEdit_DOB_Reg->setMaximumSize(QSize(200, 16777215));
        dateEdit_DOB_Reg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dateEdit_DOB_Reg->setCalendarPopup(true);

        verticalLayout_6->addWidget(dateEdit_DOB_Reg);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_6->addWidget(label_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        lineEdit_passwordReg = new QLineEdit(frame_3);
        lineEdit_passwordReg->setObjectName(QString::fromUtf8("lineEdit_passwordReg"));
        lineEdit_passwordReg->setMaximumSize(QSize(500, 16777215));
        lineEdit_passwordReg->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(lineEdit_passwordReg);

        checkBox_showPasswordReg = new QCheckBox(frame_3);
        checkBox_showPasswordReg->setObjectName(QString::fromUtf8("checkBox_showPasswordReg"));

        horizontalLayout_5->addWidget(checkBox_showPasswordReg);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        pushButton_zarejestrujSie = new QPushButton(frame_3);
        pushButton_zarejestrujSie->setObjectName(QString::fromUtf8("pushButton_zarejestrujSie"));
        pushButton_zarejestrujSie->setMaximumSize(QSize(400, 16777215));

        verticalLayout_6->addWidget(pushButton_zarejestrujSie);


        verticalLayout_3->addWidget(frame_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        pushButton_powrotReg = new QPushButton(Register_page);
        pushButton_powrotReg->setObjectName(QString::fromUtf8("pushButton_powrotReg"));

        horizontalLayout_9->addWidget(pushButton_powrotReg);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout_3->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(Register_page);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Start_Log_Reg);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Start_Log_Reg);
    } // setupUi

    void retranslateUi(QWidget *Start_Log_Reg)
    {
        Start_Log_Reg->setWindowTitle(QCoreApplication::translate("Start_Log_Reg", "Form", nullptr));
        label->setText(QCoreApplication::translate("Start_Log_Reg", "Bud\305\274et domowy", nullptr));
        pushButton_Zaloguj->setText(QCoreApplication::translate("Start_Log_Reg", "ZALOGUJ", nullptr));
        pushButton_Zarejestruj->setText(QCoreApplication::translate("Start_Log_Reg", "ZAREJESTRUJ", nullptr));
        infoButton->setText(QCoreApplication::translate("Start_Log_Reg", "i", nullptr));
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
