/********************************************************************************
** Form generated from reading UI file 'start_log_reg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_LOG_REG_H
#define UI_START_LOG_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Start_Log_Reg)
    {
        if (Start_Log_Reg->objectName().isEmpty())
            Start_Log_Reg->setObjectName(QString::fromUtf8("Start_Log_Reg"));
        Start_Log_Reg->resize(400, 300);
        verticalLayout = new QVBoxLayout(Start_Log_Reg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(Start_Log_Reg);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(Start_Log_Reg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(Start_Log_Reg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Start_Log_Reg);

        QMetaObject::connectSlotsByName(Start_Log_Reg);
    } // setupUi

    void retranslateUi(QWidget *Start_Log_Reg)
    {
        Start_Log_Reg->setWindowTitle(QCoreApplication::translate("Start_Log_Reg", "Form", nullptr));
        label->setText(QCoreApplication::translate("Start_Log_Reg", "Bud\305\274et domowy", nullptr));
        pushButton->setText(QCoreApplication::translate("Start_Log_Reg", "Zaloguj", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Start_Log_Reg", "Zarejestruj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start_Log_Reg: public Ui_Start_Log_Reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_LOG_REG_H
