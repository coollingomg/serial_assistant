#pragma once

#include <QtWidgets/QWidget>
#include "ui_serial_assistant.h"
#include <QtSerialPort/qserialportinfo>
#include <QtSerialPort/qserialport>
#include <qstring>
#include <QTimer>

//�궨��ˢ��ʱ��500ms
#define Refresh_Time    500
//���徲̬״̬�����жϴ����Ƿ��
static bool state = 0;   //Ĭ�ϴ���Ϊ�ر�״̬

class serial_assistant : public QWidget
{
    Q_OBJECT

public:
    serial_assistant(QWidget *parent = nullptr);
    ~serial_assistant();

    //��serial_assistant���ﶨ��һ�����ڶ���ָ��
    QSerialPort* serialport  = new QSerialPort;

    //��ʱɨ��
    QTimer *timer = new QTimer();

private slots:
    //��������򿪴��ڹ����ۺ���
    void Open_close_Button_Clicked(void);

    //������ʾ���ڽ�����Ϣ�ۺ���
    void recevie_plainTextEdit_data(void);

    //�������������Ϣ�ۺ���
    void send_data_button_clicked(void);

    //�����������������ۺ���
    void clean_send_area(void);

    //�����������������ۺ���
    void clean_recevie_area(void);

    //������ʱ������
    void slotTime(void);

private:
    Ui::serial_assistantClass ui;
};
