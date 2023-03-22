#pragma once

#include <QtWidgets/QWidget>
#include "ui_serial_assistant.h"
#include <QtSerialPort/qserialportinfo>
#include <QtSerialPort/qserialport>
#include <qstring>
#include <QTimer>

//宏定义刷新时长500ms
#define Refresh_Time    500
//定义静态状态量，判断串口是否打开
static bool state = 0;   //默认串口为关闭状态

class serial_assistant : public QWidget
{
    Q_OBJECT

public:
    serial_assistant(QWidget *parent = nullptr);
    ~serial_assistant();

    //在serial_assistant类里定义一个串口端类指针
    QSerialPort* serialport  = new QSerialPort;

    //定时扫描
    QTimer *timer = new QTimer();

private slots:
    //声明点击打开串口关联槽函数
    void Open_close_Button_Clicked(void);

    //声明显示串口接收信息槽函数
    void recevie_plainTextEdit_data(void);

    //声明点击发送信息槽函数
    void send_data_button_clicked(void);

    //声明点击清除发送区槽函数
    void clean_send_area(void);

    //声明点击清除接收区槽函数
    void clean_recevie_area(void);

    //声明定时器函数
    void slotTime(void);

private:
    Ui::serial_assistantClass ui;
};
