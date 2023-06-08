#pragma once

#include <QtWidgets/QWidget>
#include "ui_DS_Upper.h"

#include <QtSerialPort/qserialportinfo>
#include <QtSerialPort/qserialport>
#include <qstring>
#include <QTimer>

//定义静态状态量，判断串口是否打开
static bool state = 0;   //默认串口为关闭状态

class DS_Upper : public QWidget
{
    Q_OBJECT

public:
    DS_Upper(QWidget *parent = nullptr);
    ~DS_Upper();

    ////在serial_assistant类里定义一个串口端类指针
    QSerialPort* serialport = new QSerialPort;

    // 定时扫描1，用于串口状态刷新
    QTimer* timer = new QTimer();
    // 定时扫描2，用于串口接受数据解包
    QTimer* timer2 = new QTimer();

private slots:
    //重载定时器项目函数
    void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;

private:
    // 需要用到的定时器
    int Timer1;
    int Timer2;

private slots:
    //声明点击打开串口关联槽函数
    void Open_close_Button_Clicked(void);

    //声明显示串口接收信息槽函数
    void recevie_data_Function(void);

    //声明点击发送信息槽函数
    void send_data_button_clicked(void);

    // USB通信处理函数
    void USB_Handle(void);

private:
    // 定义通信相关宏定义
    #define USB_FRAME_HEAD				 0x42				 	//USB通信序列帧头
    #define USB_FRAME_LENMIN  			 12					 	//USB通信序列字节最短长度
    #define USB_FRAME_LENMAX		 	 36					 	//USB通信序列字节最长长度

    #define USB_ADDR_GROUP1              0x01                   //一组的数据地址
    #define USB_ADDR_GROUP2              0x02                   //二组的数据地址
    #define USB_ADDR_GROUP3     	     0x03                   //三组的数据地址
    #define USB_ADDR_GROUP4              0x04                   //四组的数据地址

    //联合体，进行4字节的数据转换
    typedef union
    {
        uchar           U8_Buff[4];
        float           Float;
        uint32_t        U32;
    }Byte4_Union;

    // 通信结构体
    typedef struct
    {
        bool 		receiveStart;                           // 数据接受开始
        uint8_t 	receiveIndex;							// 接受序列					
        bool 		receiveFinished;                        // 数据队列接受并校验完成
        uint8_t 	receiveBuff[USB_FRAME_LENMAX];          // USB接受队列：临时接受
        uint8_t 	receiveBuffFinished[USB_FRAME_LENMAX];  // USB接受队列：校验成功
    }UsbStruct;

    // 通信数据结构体
    typedef struct
    {
        float 		load_electricity_1;											//组1负载电流
        float 	    load_voltage_1;	              								//组1负载电压
        float 		load_electricity_2;											//组2负载电流
        float 	    load_voltage_2;	              								//组2负载电压
        float 		load_electricity_3;											//组3负载电流
        float 	    load_voltage_3;	              								//组3负载电压
        float 		load_electricity_4;											//组4负载电流
        float 	    load_voltage_4;	              								//组4负载电压
    }DataStruct;

    // 创建通信结构体
    UsbStruct usbStr;
    // 创建数据结构体
    DataStruct dataStr;

private:
    Ui::DS_UpperClass ui;
};

