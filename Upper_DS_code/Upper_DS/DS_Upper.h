#pragma once

#include <QtWidgets/QWidget>
#include "ui_DS_Upper.h"

#include <QtSerialPort/qserialportinfo>
#include <QtSerialPort/qserialport>
#include <qstring>
#include <QTimer>

//���徲̬״̬�����жϴ����Ƿ��
static bool state = 0;   //Ĭ�ϴ���Ϊ�ر�״̬

class DS_Upper : public QWidget
{
    Q_OBJECT

public:
    DS_Upper(QWidget *parent = nullptr);
    ~DS_Upper();

    ////��serial_assistant���ﶨ��һ�����ڶ���ָ��
    QSerialPort* serialport = new QSerialPort;

    // ��ʱɨ��1�����ڴ���״̬ˢ��
    QTimer* timer = new QTimer();
    // ��ʱɨ��2�����ڴ��ڽ������ݽ��
    QTimer* timer2 = new QTimer();

private slots:
    //���ض�ʱ����Ŀ����
    void timerEvent(QTimerEvent* event) Q_DECL_OVERRIDE;

private:
    // ��Ҫ�õ��Ķ�ʱ��
    int Timer1;
    int Timer2;

private slots:
    //��������򿪴��ڹ����ۺ���
    void Open_close_Button_Clicked(void);

    //������ʾ���ڽ�����Ϣ�ۺ���
    void recevie_data_Function(void);

    //�������������Ϣ�ۺ���
    void send_data_button_clicked(void);

    // USBͨ�Ŵ�����
    void USB_Handle(void);

private:
    // ����ͨ����غ궨��
    #define USB_FRAME_HEAD				 0x42				 	//USBͨ������֡ͷ
    #define USB_FRAME_LENMIN  			 12					 	//USBͨ�������ֽ���̳���
    #define USB_FRAME_LENMAX		 	 36					 	//USBͨ�������ֽ������

    #define USB_ADDR_GROUP1              0x01                   //һ������ݵ�ַ
    #define USB_ADDR_GROUP2              0x02                   //��������ݵ�ַ
    #define USB_ADDR_GROUP3     	     0x03                   //��������ݵ�ַ
    #define USB_ADDR_GROUP4              0x04                   //��������ݵ�ַ

    //�����壬����4�ֽڵ�����ת��
    typedef union
    {
        uchar           U8_Buff[4];
        float           Float;
        uint32_t        U32;
    }Byte4_Union;

    // ͨ�Žṹ��
    typedef struct
    {
        bool 		receiveStart;                           // ���ݽ��ܿ�ʼ
        uint8_t 	receiveIndex;							// ��������					
        bool 		receiveFinished;                        // ���ݶ��н��ܲ�У�����
        uint8_t 	receiveBuff[USB_FRAME_LENMAX];          // USB���ܶ��У���ʱ����
        uint8_t 	receiveBuffFinished[USB_FRAME_LENMAX];  // USB���ܶ��У�У��ɹ�
    }UsbStruct;

    // ͨ�����ݽṹ��
    typedef struct
    {
        float 		load_electricity_1;											//��1���ص���
        float 	    load_voltage_1;	              								//��1���ص�ѹ
        float 		load_electricity_2;											//��2���ص���
        float 	    load_voltage_2;	              								//��2���ص�ѹ
        float 		load_electricity_3;											//��3���ص���
        float 	    load_voltage_3;	              								//��3���ص�ѹ
        float 		load_electricity_4;											//��4���ص���
        float 	    load_voltage_4;	              								//��4���ص�ѹ
    }DataStruct;

    // ����ͨ�Žṹ��
    UsbStruct usbStr;
    // �������ݽṹ��
    DataStruct dataStr;

private:
    Ui::DS_UpperClass ui;
};

