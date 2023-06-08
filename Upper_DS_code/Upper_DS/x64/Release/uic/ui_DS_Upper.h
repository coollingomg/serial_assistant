/********************************************************************************
** Form generated from reading UI file 'DS_Upper.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DS_UPPER_H
#define UI_DS_UPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DS_UpperClass
{
public:
    QGridLayout *gridLayout_13;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout;
    QLabel *label_9;
    QComboBox *port_comboBox;
    QLabel *label_10;
    QComboBox *BaudRate_comboBox;
    QLabel *label_13;
    QComboBox *data_comboBox;
    QLabel *label_14;
    QComboBox *stop_comboBox;
    QLabel *label_8;
    QComboBox *verify_comboBox;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *open_close_Button;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_12;
    QWidget *send_2;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_21;
    QDoubleSpinBox *time_set_box;
    QLabel *label_21;
    QComboBox *measure_groupNum;
    QLabel *label_22;
    QSpinBox *cycle_index_box;
    QSpacerItem *horizontalSpacer_22;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_10;
    QLabel *label_23;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_24;
    QComboBox *load_pattern_box1;
    QDoubleSpinBox *output_voltage_box1;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_8;
    QLabel *label_17;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_20;
    QComboBox *load_pattern_box2;
    QDoubleSpinBox *output_voltage_box2;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_12;
    QLabel *label_27;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *horizontalSpacer_30;
    QComboBox *load_pattern_box4;
    QDoubleSpinBox *output_voltage_box4;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_11;
    QLabel *label_25;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *horizontalSpacer_28;
    QComboBox *load_pattern_box3;
    QDoubleSpinBox *output_voltage_box3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_19;
    QPushButton *send_data_button;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_26;
    QWidget *recevie_2;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *load_voltage_lable1;
    QLabel *label_37;
    QLabel *load_electricity_lable1;
    QLabel *label_29;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *load_voltage_lable2;
    QLabel *label_38;
    QLabel *load_electricity_lable2;
    QLabel *label_30;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *load_voltage_lable3;
    QLabel *label_39;
    QLabel *load_electricity_lable3;
    QLabel *label_31;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *load_voltage_lable4;
    QLabel *label_40;
    QLabel *load_electricity_lable4;
    QLabel *label_32;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_11;

    void setupUi(QWidget *DS_UpperClass)
    {
        if (DS_UpperClass->objectName().isEmpty())
            DS_UpperClass->setObjectName(QStringLiteral("DS_UpperClass"));
        DS_UpperClass->resize(550, 355);
        DS_UpperClass->setMinimumSize(QSize(550, 350));
        DS_UpperClass->setMaximumSize(QSize(600, 400));
        gridLayout_13 = new QGridLayout(DS_UpperClass);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        tabWidget = new QTabWidget(DS_UpperClass);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMouseTracking(false);
        tabWidget->setMovable(false);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        formLayout = new QFormLayout(groupBox_5);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        port_comboBox = new QComboBox(groupBox_5);
        port_comboBox->setObjectName(QStringLiteral("port_comboBox"));
        port_comboBox->setMinimumSize(QSize(75, 25));

        formLayout->setWidget(0, QFormLayout::FieldRole, port_comboBox);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        BaudRate_comboBox = new QComboBox(groupBox_5);
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->addItem(QString());
        BaudRate_comboBox->setObjectName(QStringLiteral("BaudRate_comboBox"));
        BaudRate_comboBox->setMinimumSize(QSize(75, 25));

        formLayout->setWidget(1, QFormLayout::FieldRole, BaudRate_comboBox);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        data_comboBox = new QComboBox(groupBox_5);
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->addItem(QString());
        data_comboBox->setObjectName(QStringLiteral("data_comboBox"));
        data_comboBox->setMinimumSize(QSize(75, 25));

        formLayout->setWidget(2, QFormLayout::FieldRole, data_comboBox);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_14);

        stop_comboBox = new QComboBox(groupBox_5);
        stop_comboBox->addItem(QString());
        stop_comboBox->addItem(QString());
        stop_comboBox->addItem(QString());
        stop_comboBox->setObjectName(QStringLiteral("stop_comboBox"));
        stop_comboBox->setMinimumSize(QSize(75, 25));

        formLayout->setWidget(3, QFormLayout::FieldRole, stop_comboBox);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        verify_comboBox = new QComboBox(groupBox_5);
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->addItem(QString());
        verify_comboBox->setObjectName(QStringLiteral("verify_comboBox"));
        verify_comboBox->setMinimumSize(QSize(75, 25));
        verify_comboBox->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, verify_comboBox);


        gridLayout_6->addWidget(groupBox_5, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 3, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 3, 0, 1, 1);

        open_close_Button = new QPushButton(tab_2);
        open_close_Button->setObjectName(QStringLiteral("open_close_Button"));

        gridLayout_6->addWidget(open_close_Button, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_12, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        send_2 = new QWidget();
        send_2->setObjectName(QStringLiteral("send_2"));
        gridLayout_7 = new QGridLayout(send_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_7 = new QGroupBox(send_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_9 = new QGridLayout(groupBox_7);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_7);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_9->addWidget(label_20, 0, 0, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_21, 1, 1, 1, 1);

        time_set_box = new QDoubleSpinBox(groupBox_7);
        time_set_box->setObjectName(QStringLiteral("time_set_box"));
        time_set_box->setFrame(true);

        gridLayout_9->addWidget(time_set_box, 1, 2, 1, 1);

        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_9->addWidget(label_21, 1, 0, 1, 1);

        measure_groupNum = new QComboBox(groupBox_7);
        measure_groupNum->addItem(QString());
        measure_groupNum->addItem(QString());
        measure_groupNum->addItem(QString());
        measure_groupNum->addItem(QString());
        measure_groupNum->setObjectName(QStringLiteral("measure_groupNum"));

        gridLayout_9->addWidget(measure_groupNum, 0, 2, 1, 1);

        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_9->addWidget(label_22, 2, 0, 1, 1);

        cycle_index_box = new QSpinBox(groupBox_7);
        cycle_index_box->setObjectName(QStringLiteral("cycle_index_box"));
        cycle_index_box->setTabletTracking(false);
        cycle_index_box->setFocusPolicy(Qt::WheelFocus);
        cycle_index_box->setWrapping(false);
        cycle_index_box->setProperty("showGroupSeparator", QVariant(false));

        gridLayout_9->addWidget(cycle_index_box, 2, 2, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_22, 2, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_7, 2, 0, 2, 1);

        groupBox_8 = new QGroupBox(send_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_10 = new QGridLayout(groupBox_8);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_10->addWidget(label_23, 0, 0, 1, 1);

        label_24 = new QLabel(groupBox_8);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_10->addWidget(label_24, 4, 0, 1, 1);

        horizontalSpacer_23 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_23, 4, 1, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_24, 0, 1, 1, 1);

        load_pattern_box1 = new QComboBox(groupBox_8);
        load_pattern_box1->addItem(QString());
        load_pattern_box1->addItem(QString());
        load_pattern_box1->addItem(QString());
        load_pattern_box1->setObjectName(QStringLiteral("load_pattern_box1"));

        gridLayout_10->addWidget(load_pattern_box1, 4, 2, 1, 1);

        output_voltage_box1 = new QDoubleSpinBox(groupBox_8);
        output_voltage_box1->setObjectName(QStringLiteral("output_voltage_box1"));

        gridLayout_10->addWidget(output_voltage_box1, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_8, 2, 1, 1, 1);

        groupBox_6 = new QGroupBox(send_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_8 = new QGridLayout(groupBox_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_8->addWidget(label_18, 4, 0, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_16, 4, 1, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_20, 0, 1, 1, 1);

        load_pattern_box2 = new QComboBox(groupBox_6);
        load_pattern_box2->addItem(QString());
        load_pattern_box2->addItem(QString());
        load_pattern_box2->addItem(QString());
        load_pattern_box2->setObjectName(QStringLiteral("load_pattern_box2"));

        gridLayout_8->addWidget(load_pattern_box2, 4, 2, 1, 1);

        output_voltage_box2 = new QDoubleSpinBox(groupBox_6);
        output_voltage_box2->setObjectName(QStringLiteral("output_voltage_box2"));

        gridLayout_8->addWidget(output_voltage_box2, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 2, 2, 1, 1);

        groupBox_10 = new QGroupBox(send_2);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_12 = new QGridLayout(groupBox_10);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_27 = new QLabel(groupBox_10);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_12->addWidget(label_27, 0, 0, 1, 1);

        label_28 = new QLabel(groupBox_10);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_12->addWidget(label_28, 4, 0, 1, 1);

        horizontalSpacer_29 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_29, 4, 1, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_30, 0, 1, 1, 1);

        load_pattern_box4 = new QComboBox(groupBox_10);
        load_pattern_box4->addItem(QString());
        load_pattern_box4->addItem(QString());
        load_pattern_box4->addItem(QString());
        load_pattern_box4->setObjectName(QStringLiteral("load_pattern_box4"));

        gridLayout_12->addWidget(load_pattern_box4, 4, 2, 1, 1);

        output_voltage_box4 = new QDoubleSpinBox(groupBox_10);
        output_voltage_box4->setObjectName(QStringLiteral("output_voltage_box4"));

        gridLayout_12->addWidget(output_voltage_box4, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_10, 3, 2, 1, 1);

        groupBox_9 = new QGroupBox(send_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_11 = new QGridLayout(groupBox_9);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_25 = new QLabel(groupBox_9);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_11->addWidget(label_25, 0, 0, 1, 1);

        label_26 = new QLabel(groupBox_9);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_11->addWidget(label_26, 4, 0, 1, 1);

        horizontalSpacer_27 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_27, 4, 1, 1, 1);

        horizontalSpacer_28 = new QSpacerItem(157, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_28, 0, 1, 1, 1);

        load_pattern_box3 = new QComboBox(groupBox_9);
        load_pattern_box3->addItem(QString());
        load_pattern_box3->addItem(QString());
        load_pattern_box3->addItem(QString());
        load_pattern_box3->setObjectName(QStringLiteral("load_pattern_box3"));

        gridLayout_11->addWidget(load_pattern_box3, 4, 2, 1, 1);

        output_voltage_box3 = new QDoubleSpinBox(groupBox_9);
        output_voltage_box3->setObjectName(QStringLiteral("output_voltage_box3"));

        gridLayout_11->addWidget(output_voltage_box3, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_9, 3, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_4, 1, 1, 1, 1);

        label_19 = new QLabel(send_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_19, 0, 1, 1, 1);

        send_data_button = new QPushButton(send_2);
        send_data_button->setObjectName(QStringLiteral("send_data_button"));

        gridLayout_7->addWidget(send_data_button, 5, 1, 1, 1);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_32, 5, 2, 1, 1);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_31, 5, 0, 1, 1);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_25, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 4, 1, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_26, 0, 0, 1, 1);

        tabWidget->addTab(send_2, QString());
        recevie_2 = new QWidget();
        recevie_2->setObjectName(QStringLiteral("recevie_2"));
        gridLayout_2 = new QGridLayout(recevie_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(recevie_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(130, 180));
        groupBox->setMaximumSize(QSize(130, 180));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        load_voltage_lable1 = new QLabel(groupBox);
        load_voltage_lable1->setObjectName(QStringLiteral("load_voltage_lable1"));
        load_voltage_lable1->setMinimumSize(QSize(110, 40));
        load_voltage_lable1->setMaximumSize(QSize(110, 40));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        load_voltage_lable1->setFont(font);
        load_voltage_lable1->setFrameShape(QFrame::NoFrame);
        load_voltage_lable1->setFrameShadow(QFrame::Plain);
        load_voltage_lable1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(load_voltage_lable1, 0, 0, 1, 1);

        label_37 = new QLabel(groupBox);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setMinimumSize(QSize(110, 0));
        label_37->setMaximumSize(QSize(150, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font1.setPointSize(9);
        label_37->setFont(font1);
        label_37->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_37, 3, 0, 1, 1);

        load_electricity_lable1 = new QLabel(groupBox);
        load_electricity_lable1->setObjectName(QStringLiteral("load_electricity_lable1"));
        load_electricity_lable1->setMinimumSize(QSize(110, 40));
        load_electricity_lable1->setMaximumSize(QSize(110, 40));
        load_electricity_lable1->setFont(font);
        load_electricity_lable1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(load_electricity_lable1, 2, 0, 1, 1);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMinimumSize(QSize(110, 0));
        label_29->setMaximumSize(QSize(110, 16777215));
        label_29->setFont(font1);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_29, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(recevie_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(130, 180));
        groupBox_2->setMaximumSize(QSize(130, 180));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        load_voltage_lable2 = new QLabel(groupBox_2);
        load_voltage_lable2->setObjectName(QStringLiteral("load_voltage_lable2"));
        load_voltage_lable2->setMinimumSize(QSize(110, 40));
        load_voltage_lable2->setMaximumSize(QSize(110, 40));
        load_voltage_lable2->setFont(font);
        load_voltage_lable2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(load_voltage_lable2, 0, 0, 1, 1);

        label_38 = new QLabel(groupBox_2);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setMinimumSize(QSize(110, 0));
        label_38->setMaximumSize(QSize(150, 16777215));
        label_38->setFont(font1);
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_38, 3, 0, 1, 1);

        load_electricity_lable2 = new QLabel(groupBox_2);
        load_electricity_lable2->setObjectName(QStringLiteral("load_electricity_lable2"));
        load_electricity_lable2->setMinimumSize(QSize(110, 40));
        load_electricity_lable2->setMaximumSize(QSize(110, 40));
        load_electricity_lable2->setFont(font);
        load_electricity_lable2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(load_electricity_lable2, 2, 0, 1, 1);

        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(110, 0));
        label_30->setMaximumSize(QSize(110, 16777215));
        label_30->setFont(font1);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_30, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(recevie_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(130, 180));
        groupBox_3->setMaximumSize(QSize(130, 180));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        load_voltage_lable3 = new QLabel(groupBox_3);
        load_voltage_lable3->setObjectName(QStringLiteral("load_voltage_lable3"));
        load_voltage_lable3->setMinimumSize(QSize(110, 40));
        load_voltage_lable3->setMaximumSize(QSize(110, 40));
        load_voltage_lable3->setFont(font);
        load_voltage_lable3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(load_voltage_lable3, 0, 0, 1, 1);

        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(110, 0));
        label_39->setMaximumSize(QSize(150, 16777215));
        label_39->setFont(font1);
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_39, 3, 0, 1, 1);

        load_electricity_lable3 = new QLabel(groupBox_3);
        load_electricity_lable3->setObjectName(QStringLiteral("load_electricity_lable3"));
        load_electricity_lable3->setMinimumSize(QSize(110, 40));
        load_electricity_lable3->setMaximumSize(QSize(110, 40));
        load_electricity_lable3->setFont(font);
        load_electricity_lable3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(load_electricity_lable3, 2, 0, 1, 1);

        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(110, 0));
        label_31->setMaximumSize(QSize(110, 16777215));
        label_31->setFont(font1);
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_31, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 1, 2, 1, 1);

        groupBox_4 = new QGroupBox(recevie_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(130, 180));
        groupBox_4->setMaximumSize(QSize(130, 180));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        load_voltage_lable4 = new QLabel(groupBox_4);
        load_voltage_lable4->setObjectName(QStringLiteral("load_voltage_lable4"));
        load_voltage_lable4->setMinimumSize(QSize(110, 40));
        load_voltage_lable4->setMaximumSize(QSize(110, 40));
        load_voltage_lable4->setFont(font);
        load_voltage_lable4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(load_voltage_lable4, 0, 0, 1, 1);

        label_40 = new QLabel(groupBox_4);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setMinimumSize(QSize(110, 0));
        label_40->setMaximumSize(QSize(150, 16777215));
        label_40->setFont(font1);
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_40, 3, 0, 1, 1);

        load_electricity_lable4 = new QLabel(groupBox_4);
        load_electricity_lable4->setObjectName(QStringLiteral("load_electricity_lable4"));
        load_electricity_lable4->setMinimumSize(QSize(110, 40));
        load_electricity_lable4->setMaximumSize(QSize(110, 40));
        load_electricity_lable4->setFont(font);
        load_electricity_lable4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(load_electricity_lable4, 2, 0, 1, 1);

        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMinimumSize(QSize(110, 0));
        label_32->setMaximumSize(QSize(110, 16777215));
        label_32->setFont(font1);
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_32, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 1, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 2, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 0, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 2, 2, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_10, 0, 3, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_11, 2, 3, 1, 1);

        tabWidget->addTab(recevie_2, QString());

        gridLayout_13->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(DS_UpperClass);
        QObject::connect(open_close_Button, SIGNAL(clicked()), DS_UpperClass, SLOT(Open_close_Button_Clicked()));
        QObject::connect(send_data_button, SIGNAL(clicked()), DS_UpperClass, SLOT(send_data_button_clicked()));

        tabWidget->setCurrentIndex(0);
        BaudRate_comboBox->setCurrentIndex(3);
        data_comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(DS_UpperClass);
    } // setupUi

    void retranslateUi(QWidget *DS_UpperClass)
    {
        DS_UpperClass->setWindowTitle(QApplication::translate("DS_UpperClass", "DS_Upper", nullptr));
        groupBox_5->setTitle(QApplication::translate("DS_UpperClass", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label_9->setText(QApplication::translate("DS_UpperClass", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_10->setText(QApplication::translate("DS_UpperClass", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        BaudRate_comboBox->setItemText(0, QApplication::translate("DS_UpperClass", "1200", nullptr));
        BaudRate_comboBox->setItemText(1, QApplication::translate("DS_UpperClass", "2400", nullptr));
        BaudRate_comboBox->setItemText(2, QApplication::translate("DS_UpperClass", "4800", nullptr));
        BaudRate_comboBox->setItemText(3, QApplication::translate("DS_UpperClass", "9600", nullptr));
        BaudRate_comboBox->setItemText(4, QApplication::translate("DS_UpperClass", "19200", nullptr));
        BaudRate_comboBox->setItemText(5, QApplication::translate("DS_UpperClass", "38400", nullptr));
        BaudRate_comboBox->setItemText(6, QApplication::translate("DS_UpperClass", "57600", nullptr));
        BaudRate_comboBox->setItemText(7, QApplication::translate("DS_UpperClass", "115200", nullptr));

        label_13->setText(QApplication::translate("DS_UpperClass", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        data_comboBox->setItemText(0, QApplication::translate("DS_UpperClass", "5", nullptr));
        data_comboBox->setItemText(1, QApplication::translate("DS_UpperClass", "6", nullptr));
        data_comboBox->setItemText(2, QApplication::translate("DS_UpperClass", "7", nullptr));
        data_comboBox->setItemText(3, QApplication::translate("DS_UpperClass", "8", nullptr));

        label_14->setText(QApplication::translate("DS_UpperClass", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stop_comboBox->setItemText(0, QApplication::translate("DS_UpperClass", "1", nullptr));
        stop_comboBox->setItemText(1, QApplication::translate("DS_UpperClass", "1.5", nullptr));
        stop_comboBox->setItemText(2, QApplication::translate("DS_UpperClass", "2", nullptr));

        label_8->setText(QApplication::translate("DS_UpperClass", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        verify_comboBox->setItemText(0, QApplication::translate("DS_UpperClass", "\346\227\240", nullptr));
        verify_comboBox->setItemText(1, QApplication::translate("DS_UpperClass", "\345\245\207\346\240\241\351\252\214", nullptr));
        verify_comboBox->setItemText(2, QApplication::translate("DS_UpperClass", "\345\201\266\346\240\241\351\252\214", nullptr));
        verify_comboBox->setItemText(3, QApplication::translate("DS_UpperClass", "MarkParity", nullptr));
        verify_comboBox->setItemText(4, QApplication::translate("DS_UpperClass", "SpaceParity", nullptr));

        open_close_Button->setText(QApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DS_UpperClass", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        groupBox_7->setTitle(QApplication::translate("DS_UpperClass", "public", nullptr));
        label_20->setText(QApplication::translate("DS_UpperClass", "\346\265\213\350\257\225\347\273\204\346\225\260\357\274\232", nullptr));
        label_21->setText(QApplication::translate("DS_UpperClass", "\346\265\213\350\257\225\346\227\266\351\227\264\357\274\210s\357\274\211\357\274\232", nullptr));
        measure_groupNum->setItemText(0, QApplication::translate("DS_UpperClass", "1", nullptr));
        measure_groupNum->setItemText(1, QApplication::translate("DS_UpperClass", "2", nullptr));
        measure_groupNum->setItemText(2, QApplication::translate("DS_UpperClass", "3", nullptr));
        measure_groupNum->setItemText(3, QApplication::translate("DS_UpperClass", "4", nullptr));

        label_22->setText(QApplication::translate("DS_UpperClass", "\345\276\252\347\216\257\346\254\241\346\225\260\357\274\232", nullptr));
        groupBox_8->setTitle(QApplication::translate("DS_UpperClass", "group-1", nullptr));
        label_23->setText(QApplication::translate("DS_UpperClass", "\350\276\223\345\207\272\347\224\265\345\216\213-1", nullptr));
        label_24->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\346\250\241\345\274\217-1", nullptr));
        load_pattern_box1->setItemText(0, QApplication::translate("DS_UpperClass", "\346\201\222\345\216\213", nullptr));
        load_pattern_box1->setItemText(1, QApplication::translate("DS_UpperClass", "\346\201\222\346\265\201", nullptr));
        load_pattern_box1->setItemText(2, QApplication::translate("DS_UpperClass", "\346\201\222\347\224\265\351\230\273", nullptr));

        groupBox_6->setTitle(QApplication::translate("DS_UpperClass", "group-2", nullptr));
        label_17->setText(QApplication::translate("DS_UpperClass", "\350\276\223\345\207\272\347\224\265\345\216\213-2", nullptr));
        label_18->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\346\250\241\345\274\217-2", nullptr));
        load_pattern_box2->setItemText(0, QApplication::translate("DS_UpperClass", "\346\201\222\345\216\213", nullptr));
        load_pattern_box2->setItemText(1, QApplication::translate("DS_UpperClass", "\346\201\222\346\265\201", nullptr));
        load_pattern_box2->setItemText(2, QApplication::translate("DS_UpperClass", "\346\201\222\347\224\265\351\230\273", nullptr));

        groupBox_10->setTitle(QApplication::translate("DS_UpperClass", "group-4", nullptr));
        label_27->setText(QApplication::translate("DS_UpperClass", "\350\276\223\345\207\272\347\224\265\345\216\213-4", nullptr));
        label_28->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\346\250\241\345\274\217-4", nullptr));
        load_pattern_box4->setItemText(0, QApplication::translate("DS_UpperClass", "\346\201\222\345\216\213", nullptr));
        load_pattern_box4->setItemText(1, QApplication::translate("DS_UpperClass", "\346\201\222\346\265\201", nullptr));
        load_pattern_box4->setItemText(2, QApplication::translate("DS_UpperClass", "\346\201\222\347\224\265\351\230\273", nullptr));

        groupBox_9->setTitle(QApplication::translate("DS_UpperClass", "group-3", nullptr));
        label_25->setText(QApplication::translate("DS_UpperClass", "\350\276\223\345\207\272\347\224\265\345\216\213-3", nullptr));
        label_26->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\346\250\241\345\274\217-3", nullptr));
        load_pattern_box3->setItemText(0, QApplication::translate("DS_UpperClass", "\346\201\222\345\216\213", nullptr));
        load_pattern_box3->setItemText(1, QApplication::translate("DS_UpperClass", "\346\201\222\346\265\201", nullptr));
        load_pattern_box3->setItemText(2, QApplication::translate("DS_UpperClass", "\346\201\222\347\224\265\351\230\273", nullptr));

        label_19->setText(QApplication::translate("DS_UpperClass", "\350\200\201\345\214\226\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        send_data_button->setText(QApplication::translate("DS_UpperClass", "\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(send_2), QApplication::translate("DS_UpperClass", "\350\256\276\347\275\256\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QApplication::translate("DS_UpperClass", "Group1", nullptr));
        load_voltage_lable1->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_37->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\346\265\201", nullptr));
        load_electricity_lable1->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_29->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\345\216\213", nullptr));
        groupBox_2->setTitle(QApplication::translate("DS_UpperClass", "Group2", nullptr));
        load_voltage_lable2->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_38->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\346\265\201", nullptr));
        load_electricity_lable2->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_30->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\345\216\213", nullptr));
        groupBox_3->setTitle(QApplication::translate("DS_UpperClass", "Group3", nullptr));
        load_voltage_lable3->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_39->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\346\265\201", nullptr));
        load_electricity_lable3->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_31->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\345\216\213", nullptr));
        groupBox_4->setTitle(QApplication::translate("DS_UpperClass", "Group4", nullptr));
        load_voltage_lable4->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_40->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\346\265\201", nullptr));
        load_electricity_lable4->setText(QApplication::translate("DS_UpperClass", "0.00", nullptr));
        label_32->setText(QApplication::translate("DS_UpperClass", "\350\264\237\350\275\275\347\224\265\345\216\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(recevie_2), QApplication::translate("DS_UpperClass", "\346\225\260\346\215\256\346\216\245\345\217\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DS_UpperClass: public Ui_DS_UpperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DS_UPPER_H
