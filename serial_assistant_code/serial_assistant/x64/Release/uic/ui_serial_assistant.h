/********************************************************************************
** Form generated from reading UI file 'serial_assistant.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_ASSISTANT_H
#define UI_SERIAL_ASSISTANT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serial_assistantClass
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *port_comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *BaudRate_comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *data_comboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *stop_comboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QComboBox *verify_comboBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *open_close_Button;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QPlainTextEdit *send_plainTextEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *send_pushButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cleansend_pushButton;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_4;
    QPlainTextEdit *recevie_plainTextEdit;
    QPushButton *cleanrecevie_pushButton;

    void setupUi(QWidget *serial_assistantClass)
    {
        if (serial_assistantClass->objectName().isEmpty())
            serial_assistantClass->setObjectName(QString::fromUtf8("serial_assistantClass"));
        serial_assistantClass->resize(650, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/serial_assistant_pic/serial_assistant_pic/exe.ico"), QSize(), QIcon::Normal, QIcon::Off);
        serial_assistantClass->setWindowIcon(icon);
        groupBox = new QGroupBox(serial_assistantClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 350, 240, 142));
        groupBox->setMinimumSize(QSize(240, 120));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 120));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/serial_assistant_pic/serial_assistant_pic/wut_Schoolbadge.jpg);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout->addWidget(label_9);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        groupBox_2 = new QGroupBox(serial_assistantClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 30, 241, 311));
        groupBox_2->setMinimumSize(QSize(240, 310));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        port_comboBox = new QComboBox(groupBox_2);
        port_comboBox->setObjectName(QString::fromUtf8("port_comboBox"));
        port_comboBox->setMinimumSize(QSize(75, 25));

        horizontalLayout_3->addWidget(port_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        BaudRate_comboBox = new QComboBox(groupBox_2);
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->setObjectName(QString::fromUtf8("BaudRate_comboBox"));
        BaudRate_comboBox->setMinimumSize(QSize(75, 25));

        horizontalLayout_4->addWidget(BaudRate_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        data_comboBox = new QComboBox(groupBox_2);
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->setObjectName(QString::fromUtf8("data_comboBox"));
        data_comboBox->setMinimumSize(QSize(75, 25));

        horizontalLayout_5->addWidget(data_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        stop_comboBox = new QComboBox(groupBox_2);
        stop_comboBox->addItem(QString());
        stop_comboBox->addItem(QString());
        stop_comboBox->addItem(QString());
        stop_comboBox->setObjectName(QString::fromUtf8("stop_comboBox"));
        stop_comboBox->setMinimumSize(QSize(75, 25));

        horizontalLayout_6->addWidget(stop_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        verify_comboBox = new QComboBox(groupBox_2);
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->setObjectName(QString::fromUtf8("verify_comboBox"));
        verify_comboBox->setMinimumSize(QSize(75, 25));
        verify_comboBox->setMaximumSize(QSize(75, 25));

        horizontalLayout_7->addWidget(verify_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        open_close_Button = new QPushButton(groupBox_2);
        open_close_Button->setObjectName(QString::fromUtf8("open_close_Button"));
        open_close_Button->setMinimumSize(QSize(75, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L")});
        font1.setPointSize(10);
        open_close_Button->setFont(font1);

        horizontalLayout_8->addWidget(open_close_Button);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        layoutWidget = new QWidget(serial_assistantClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 30, 372, 461));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(370, 160));
        send_plainTextEdit = new QPlainTextEdit(groupBox_3);
        send_plainTextEdit->setObjectName(QString::fromUtf8("send_plainTextEdit"));
        send_plainTextEdit->setGeometry(QRect(20, 20, 330, 100));
        send_plainTextEdit->setMinimumSize(QSize(330, 100));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 130, 204, 27));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        send_pushButton = new QPushButton(layoutWidget1);
        send_pushButton->setObjectName(QString::fromUtf8("send_pushButton"));
        send_pushButton->setMinimumSize(QSize(75, 25));

        horizontalLayout_10->addWidget(send_pushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        cleansend_pushButton = new QPushButton(layoutWidget1);
        cleansend_pushButton->setObjectName(QString::fromUtf8("cleansend_pushButton"));
        cleansend_pushButton->setMinimumSize(QSize(75, 25));

        horizontalLayout_10->addWidget(cleansend_pushButton);


        verticalLayout_4->addWidget(groupBox_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(370, 270));
        recevie_plainTextEdit = new QPlainTextEdit(groupBox_4);
        recevie_plainTextEdit->setObjectName(QString::fromUtf8("recevie_plainTextEdit"));
        recevie_plainTextEdit->setGeometry(QRect(20, 20, 330, 220));
        recevie_plainTextEdit->setMinimumSize(QSize(330, 220));
        recevie_plainTextEdit->setReadOnly(true);
        cleanrecevie_pushButton = new QPushButton(groupBox_4);
        cleanrecevie_pushButton->setObjectName(QString::fromUtf8("cleanrecevie_pushButton"));
        cleanrecevie_pushButton->setGeometry(QRect(150, 240, 75, 25));
        cleanrecevie_pushButton->setMinimumSize(QSize(75, 25));

        verticalLayout_4->addWidget(groupBox_4);


        retranslateUi(serial_assistantClass);
        QObject::connect(open_close_Button, SIGNAL(clicked()), serial_assistantClass, SLOT(Open_close_Button_Clicked()));
        QObject::connect(send_pushButton, SIGNAL(clicked()), serial_assistantClass, SLOT(send_data_button_clicked()));
        QObject::connect(cleansend_pushButton, SIGNAL(clicked()), serial_assistantClass, SLOT(clean_send_area()));
        QObject::connect(cleanrecevie_pushButton, SIGNAL(clicked()), serial_assistantClass, SLOT(clean_recevie_area()));

        BaudRate_comboBox->setCurrentIndex(3);
        data_comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(serial_assistantClass);
    } // setupUi

    void retranslateUi(QWidget *serial_assistantClass)
    {
        serial_assistantClass->setWindowTitle(QCoreApplication::translate("serial_assistantClass", "serial_assistant", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("serial_assistantClass", "\344\275\234\350\200\205\357\274\232wzl", nullptr));
        label_9->setText(QCoreApplication::translate("serial_assistantClass", "\347\211\210\346\234\254\357\274\232V1.2", nullptr));
        label_3->setText(QCoreApplication::translate("serial_assistantClass", "\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("serial_assistantClass", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("serial_assistantClass", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("serial_assistantClass", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudRate_comboBox->setItemText(0, QCoreApplication::translate("serial_assistantClass", "1200", nullptr));
        BaudRate_comboBox->setItemText(1, QCoreApplication::translate("serial_assistantClass", "2400", nullptr));
        BaudRate_comboBox->setItemText(2, QCoreApplication::translate("serial_assistantClass", "4800", nullptr));
        BaudRate_comboBox->setItemText(3, QCoreApplication::translate("serial_assistantClass", "9600", nullptr));
        BaudRate_comboBox->setItemText(4, QCoreApplication::translate("serial_assistantClass", "19200", nullptr));
        BaudRate_comboBox->setItemText(5, QCoreApplication::translate("serial_assistantClass", "38400", nullptr));
        BaudRate_comboBox->setItemText(6, QCoreApplication::translate("serial_assistantClass", "57600", nullptr));
        BaudRate_comboBox->setItemText(7, QCoreApplication::translate("serial_assistantClass", "115200", nullptr));

        label_6->setText(QCoreApplication::translate("serial_assistantClass", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        data_comboBox->setItemText(0, QCoreApplication::translate("serial_assistantClass", "5", nullptr));
        data_comboBox->setItemText(1, QCoreApplication::translate("serial_assistantClass", "6", nullptr));
        data_comboBox->setItemText(2, QCoreApplication::translate("serial_assistantClass", "7", nullptr));
        data_comboBox->setItemText(3, QCoreApplication::translate("serial_assistantClass", "8", nullptr));

        label_7->setText(QCoreApplication::translate("serial_assistantClass", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stop_comboBox->setItemText(0, QCoreApplication::translate("serial_assistantClass", "1", nullptr));
        stop_comboBox->setItemText(1, QCoreApplication::translate("serial_assistantClass", "1.5", nullptr));
        stop_comboBox->setItemText(2, QCoreApplication::translate("serial_assistantClass", "2", nullptr));

        label_8->setText(QCoreApplication::translate("serial_assistantClass", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        verify_comboBox->setItemText(0, QCoreApplication::translate("serial_assistantClass", "\346\227\240", nullptr));
        verify_comboBox->setItemText(1, QCoreApplication::translate("serial_assistantClass", "\345\245\207\346\240\241\351\252\214", nullptr));
        verify_comboBox->setItemText(2, QCoreApplication::translate("serial_assistantClass", "\345\201\266\346\240\241\351\252\214", nullptr));
        verify_comboBox->setItemText(3, QCoreApplication::translate("serial_assistantClass", "MarkParity", nullptr));
        verify_comboBox->setItemText(4, QCoreApplication::translate("serial_assistantClass", "SpaceParity", nullptr));

        open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("serial_assistantClass", "\345\217\221\351\200\201\345\214\272", nullptr));
        send_pushButton->setText(QCoreApplication::translate("serial_assistantClass", "\345\217\221\351\200\201", nullptr));
        cleansend_pushButton->setText(QCoreApplication::translate("serial_assistantClass", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("serial_assistantClass", "\346\216\245\346\224\266\345\214\272", nullptr));
        cleanrecevie_pushButton->setText(QCoreApplication::translate("serial_assistantClass", "\346\270\205\347\251\272\346\216\245\345\217\227\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial_assistantClass: public Ui_serial_assistantClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_ASSISTANT_H
