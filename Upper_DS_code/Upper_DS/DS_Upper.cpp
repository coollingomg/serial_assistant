#include "DS_Upper.h"
#include "qmessagebox.h"

DS_Upper::DS_Upper(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //�������գ�����������ʾ
    connect(serialport, SIGNAL(readyRead()), this, SLOT(recevie_data_Function()));

    //���ö�ʱ��
    Timer1 = startTimer(200);
    Timer2 = startTimer(20);
}

DS_Upper::~DS_Upper()
{}

//��ʱ�����ƺ���
void DS_Upper::timerEvent(QTimerEvent* event) 
{

    if (event->timerId() == Timer1) 
    {
        //����˿ںű���
        static QStringList serialNamePort = QStringList();
        //�����м����������¼�˿ں�
        static QStringList currentport = QStringList();
        //��������洢�˿���ʾ��
        static QString lastport = QString();

        //Ѱ��Windows���ö˿�
        foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
        {
            //���뵽stringlist
            currentport << info.portName();
        }

        //��¼��һ�εĶ˿ں�
        lastport = ui.port_comboBox->currentText();

        //�ж϶˿��Ƿ�仯
        if (currentport != serialNamePort)
        {
            //��������˿ں�
            serialNamePort = currentport;
            //���combox
            ui.port_comboBox->clear();
            //��ʾ�˿ں�
            ui.port_comboBox->addItems(serialNamePort);
        }

        //���һ��currentport�����任���ں�ʱ�����¸�ֵ
        currentport.clear();

        //�������ͻȻ�Ͽ�
        if (!serialNamePort.contains(lastport) && serialport->isOpen())
        {
            //�رմ���
            serialport->close();
            //�رմ��ں󣬻ָ����ڿ��޸�����
            ui.BaudRate_comboBox->setEnabled(true);
            ui.port_comboBox->setEnabled(true);
            ui.stop_comboBox->setEnabled(true);
            ui.verify_comboBox->setEnabled(true);
            ui.data_comboBox->setEnabled(true);
            //����open_and_close_button״̬
            ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
            //��״̬����Ϊ�ر�״̬
            state = 0;
            //��ʾ������Ϣ
            QMessageBox::warning(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\350\277\236\346\216\245\351\224\231\350\257\257", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    if (event->timerId() == Timer2) 
    {
        // ���ݴ���״̬ȫ�ֱ������ж��Ƿ���
        if (state == 1)
        {
            // ÿһ��ʱ������ˢ�´��ڽ�������
            USB_Handle();
            // ��ʾ��������ݵ�ui��
            if (usbStr.receiveBuffFinished[1] == 0x01)
            {
                ui.load_electricity_lable1->setNum((double)dataStr.load_electricity_1);     // ��ʾ��1����
                ui.load_voltage_lable1->setNum((double)dataStr.load_voltage_1);             // ��ʾ��1��ѹ
            }
            else if (usbStr.receiveBuffFinished[1] == 0x02)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // ��ʾ��1����
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // ��ʾ��1��ѹ
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // ��ʾ��2����
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // ��ʾ��2��ѹ
            }
            else if (usbStr.receiveBuffFinished[1] == 0x03)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // ��ʾ��1����
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // ��ʾ��1��ѹ
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // ��ʾ��2����
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // ��ʾ��2��ѹ
                ui.load_electricity_lable3->setNum(dataStr.load_electricity_3);     // ��ʾ��3����
                ui.load_voltage_lable3->setNum(dataStr.load_voltage_3);             // ��ʾ��3��ѹ
            }
            else if (usbStr.receiveBuffFinished[1] == 0x04)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // ��ʾ��1����
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // ��ʾ��1��ѹ
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // ��ʾ��2����
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // ��ʾ��2��ѹ
                ui.load_electricity_lable3->setNum(dataStr.load_electricity_3);     // ��ʾ��3����
                ui.load_voltage_lable3->setNum(dataStr.load_voltage_3);             // ��ʾ��3��ѹ
                ui.load_electricity_lable4->setNum(dataStr.load_electricity_4);     // ��ʾ��4����
                ui.load_voltage_lable4->setNum(dataStr.load_voltage_4);             // ��ʾ��4��ѹ
            }
        }
    }
}


//�����ťOpen_close_Button�������Ĳۺ���
void DS_Upper::Open_close_Button_Clicked()
{
    //����һ�εĴ���״̬���ǹرգ�����źŽ����󣬽��д򿪲���
    if (state == 0)
    {
        //���岨����ö�ٱ���
        QSerialPort::BaudRate baudrate = QSerialPort::BaudRate();
        //��������λö�ٱ���
        QSerialPort::DataBits databits = QSerialPort::DataBits();
        //����ֹͣλö�ٱ���
        QSerialPort::StopBits stopbits = QSerialPort::StopBits();
        //����У��λö�ٱ���
        QSerialPort::Parity checkbits = QSerialPort::Parity();

        //��ȡui�еĲ��������ò���ʼ�����ڲ�����
        if (ui.BaudRate_comboBox->currentText() == "1200")
        {
            baudrate = QSerialPort::Baud1200;
        }
        else if (ui.BaudRate_comboBox->currentText() == "2400")
        {
            baudrate = QSerialPort::Baud2400;
        }
        else if (ui.BaudRate_comboBox->currentText() == "4800")
        {
            baudrate = QSerialPort::Baud4800;
        }
        else if (ui.BaudRate_comboBox->currentText() == "9600")
        {
            baudrate = QSerialPort::Baud9600;
        }
        else if (ui.BaudRate_comboBox->currentText() == "19200")
        {
            baudrate = QSerialPort::Baud19200;
        }
        else if (ui.BaudRate_comboBox->currentText() == "38400")
        {
            baudrate = QSerialPort::Baud38400;
        }
        else if (ui.BaudRate_comboBox->currentText() == "57600")
        {
            baudrate = QSerialPort::Baud57600;
        }
        else if (ui.BaudRate_comboBox->currentText() == "115200")
        {
            baudrate = QSerialPort::Baud115200;
        }

        //��ȡui�е�����λ���ò���ʼ����������λ
        if (ui.data_comboBox->currentText() == "5")
        {
            databits = QSerialPort::Data5;
        }
        else if (ui.data_comboBox->currentText() == "6")
        {
            databits = QSerialPort::Data6;
        }
        else if (ui.data_comboBox->currentText() == "7")
        {
            databits = QSerialPort::Data7;
        }
        else if (ui.data_comboBox->currentText() == "8")
        {
            databits = QSerialPort::Data8;
        }

        //��ȡui�е�ֹͣλλ���ò���ʼ������ֹͣλ
        if (ui.stop_comboBox->currentText() == "1")
        {
            stopbits = QSerialPort::OneStop;
        }
        else if (ui.stop_comboBox->currentText() == "1.5")
        {
            stopbits = QSerialPort::OneAndHalfStop;
        }
        else if (ui.stop_comboBox->currentText() == "2")
        {
            stopbits = QSerialPort::TwoStop;
        }

        //��ȡui�е�У��λλ���ò���ʼ������У��λ
        if (ui.verify_comboBox->currentIndex() == 0)
        {
            checkbits = QSerialPort::NoParity;
        }
        else if (ui.stop_comboBox->currentIndex() == 1)
        {
            checkbits = QSerialPort::OddParity;
        }
        else if (ui.stop_comboBox->currentIndex() == 2)
        {
            checkbits = QSerialPort::EvenParity;
        }
        else if (ui.stop_comboBox->currentIndex() == 3)
        {
            checkbits = QSerialPort::MarkParity;
        }
        else if (ui.stop_comboBox->currentIndex() == 4)
        {
            checkbits = QSerialPort::SpaceParity;
        }

        //���ô��ڶ˿ں�
        serialport->setPortName(ui.port_comboBox->currentText());
        //���ò�����
        serialport->setBaudRate(baudrate);
        //��������λ
        serialport->setDataBits(databits);
        //����ֹͣλ
        serialport->setStopBits(stopbits);
        //����У��λ
        serialport->setParity(checkbits);

        if (serialport->open(QIODevice::ReadWrite) == true)
        {
            //������ʾ����
            QMessageBox::information(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243\346\210\220\345\212\237\357\274\201", nullptr), QMessageBox::Yes, QMessageBox::Yes);
            //�򿪴��ں󣬸ð�ť��Ϊ���رմ��ڡ�
            ui.open_close_Button->setText(QCoreApplication::translate("DS_UpperClass", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
            //������״̬������Ϊ��
            state = 1;
            //�򿪴��ں󣬰����ô��ڵ�boboxȫ������Ϊ�����޸�״̬
            ui.BaudRate_comboBox->setEnabled(false);
            ui.port_comboBox->setEnabled(false);
            ui.stop_comboBox->setEnabled(false);
            ui.verify_comboBox->setEnabled(false);
            ui.data_comboBox->setEnabled(false);
        }
        else
        {
            //�������󴰿�
            QMessageBox::warning(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243\345\244\261\350\264\245\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else if (state == 1)
    {
        //��һ�δ���״̬Ϊ�򿪣��ٴε���رմ���
        serialport->close();
        //������ת̨��Ϊ�ر�
        state = 0;
        //����ť���Ƹı�Ϊ�򿪴���
        ui.open_close_Button->setText(QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        //�رմ��ں󣬻ָ����ڿ��޸�����
        ui.BaudRate_comboBox->setEnabled(true);
        ui.port_comboBox->setEnabled(true);
        ui.stop_comboBox->setEnabled(true);
        ui.verify_comboBox->setEnabled(true);
        ui.data_comboBox->setEnabled(true);
    }
}

//���������Ϣ�ۺ���
void DS_Upper::send_data_button_clicked(void)
{
    // �жϴ����Ƿ�򿪣�δ���򾯱����˳����κ���
    if (state == 0)
    {
        // ������ʾ����
        QMessageBox::warning(this, QCoreApplication::translate("DS_UpperClass", "\351\224\231\350\257\257", nullptr), QCoreApplication::translate("DS_UpperClass", "\344\270\262\345\217\243\346\234\252\346\211\223\345\274\200\357\274\201\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        // �˳����κ���
        return;
    }

    // ����ͨ��Э���ʽ
    uchar head_frame = 0x42;                                    // ����֡ͷ
    uchar Addr_frame = 0x01;                                    // ���ݵ�ַ��"1-4" -> ����������飬Ĭ��һ��
    uchar Length_frame = 15;                                    // ���ݳ���
    uchar Check_frame = 0x00;                                   // ��У��λ

    // �����������ȡ���洢Ҫ���͵�����
    float time_set = ui.time_set_box->value();                  // �ϻ�����������ʱ�䣨s��
    uchar cycle_index = ui.cycle_index_box->value();            // �ϻ��������ã�ѭ������
    uchar measure_group = 1;                                    // �ϻ��������ã���������

    // ������������ת����������
    Byte4_Union byte4_union;

    if (ui.measure_groupNum->currentText() == "1")
    {
        // Ҫ�������ݵ�����
        uchar SendData[15] = { 0 };

        // ������������
        measure_group = 1;
        // ��ȡÿ��Ĳ�������
        float output_voltage_1 = ui.output_voltage_box1->value();       // �����ѹ
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // ����ģʽ
        Addr_frame = 0x01;                                              // ��ַ����
        Length_frame = 15;                                              // ���ݰ���������

        //֡ͷ
        SendData[0] = head_frame;
        //��ַ
        SendData[1] = Addr_frame;
        //֡��
        SendData[2] = Length_frame;
        //��������д��
        SendData[3] = measure_group;
        //����ʱ������ת����д��
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //ѭ����������д��
        SendData[8] = cycle_index;

        //group1�����ѹ����ת����д��
        byte4_union.Float = output_voltage_1;
        SendData[9] = byte4_union.U8_Buff[0];
        SendData[10] = byte4_union.U8_Buff[1];
        SendData[11] = byte4_union.U8_Buff[2];
        SendData[12] = byte4_union.U8_Buff[3];
        //group1����ģʽ����д��
        SendData[13] = load_pattern_1;

        //���к�У��
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //д���У������
        SendData[14] = Check_frame;

        //����qtָ�������ݽṹ��ʽ����д������
        QByteArray bytearray;
        for (int i = 0; i < 15; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // ���ݷ���
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "2")
    {
        // Ҫ�������ݵ�����
        uchar SendData[20] = { 0 };

        // ������������
        measure_group = 2;
        // ��ȡ����
        Addr_frame = 0x02;                                              // ��ַ����
        Length_frame = 20;                                              // ���ݰ���������

        float output_voltage_1 = ui.output_voltage_box1->value();       // �����ѹ1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // ����ģʽ1

        float output_voltage_2 = ui.output_voltage_box2->value();       // �����ѹ2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // ����ģʽ2


        //֡ͷ
        SendData[0] = head_frame;
        //��ַ
        SendData[1] = Addr_frame;
        //֡��
        SendData[2] = Length_frame;
        //��������д��
        SendData[3] = measure_group;
        //����ʱ������ת����д��
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //ѭ����������д��
        SendData[8] = cycle_index;

        //group1�����ѹ����ת����д��
        byte4_union.Float = output_voltage_1;
        SendData[9] = byte4_union.U8_Buff[0];
        SendData[10] = byte4_union.U8_Buff[1];
        SendData[11] = byte4_union.U8_Buff[2];
        SendData[12] = byte4_union.U8_Buff[3];
        //group1����ģʽ����д��
        SendData[13] = load_pattern_1;

        //group2�����ѹ����ת����д��
        byte4_union.Float = output_voltage_2;
        SendData[14] = byte4_union.U8_Buff[0];
        SendData[15] = byte4_union.U8_Buff[1];
        SendData[16] = byte4_union.U8_Buff[2];
        SendData[17] = byte4_union.U8_Buff[3];
        //group2����ģʽ����д��
        SendData[18] = load_pattern_2;

        //���к�У��
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //д���У������
        SendData[19] = Check_frame;

        //����qtָ�������ݽṹ��ʽ����д������
        QByteArray bytearray;
        for (int i = 0; i < 20; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // ���ݷ���
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "3")
    {
        // Ҫ�������ݵ�����
        uchar SendData[25] = { 0 };

        // ������������
        measure_group = 3;
        // ��ȡ����
        Addr_frame = 0x03;                                              // ��ַ����
        Length_frame = 25;                                              // ���ݰ���������

        float output_voltage_1 = ui.output_voltage_box1->value();       // �����ѹ1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // ����ģʽ1

        float output_voltage_2 = ui.output_voltage_box2->value();       // �����ѹ2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // ����ģʽ2

        float output_voltage_3 = ui.output_voltage_box3->value();       // �����ѹ3
        char load_pattern_3 = ui.load_pattern_box3->currentIndex();     // ����ģʽ3

        //֡ͷ
        SendData[0] = head_frame;
        //��ַ
        SendData[1] = Addr_frame;
        //֡��
        SendData[2] = Length_frame;
        //��������д��
        SendData[3] = measure_group;
        //����ʱ������ת����д��
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //ѭ����������д��
        SendData[8] = cycle_index;

        //group1�����ѹ����ת����д��
        byte4_union.Float = output_voltage_1;
        for (int i = 0; i < 4; i++)
        {
            SendData[9 + i] = byte4_union.U8_Buff[i];
        }
        //group1����ģʽ����д��
        SendData[13] = load_pattern_1;

        //group2�����ѹ����ת����д��
        byte4_union.Float = output_voltage_2;
        for (int i = 0; i < 4; i++)
        {
            SendData[14 +i] = byte4_union.U8_Buff[i];
        }
        //group2����ģʽ����д��
        SendData[18] = load_pattern_2;

        //group3�����ѹ����ת����д��
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[19 + i] = byte4_union.U8_Buff[i];
        }
        //group3����ģʽ����д��
        SendData[23] = load_pattern_3;

        //���к�У��
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //д���У������
        SendData[24] = Check_frame;

        //����qtָ�������ݽṹ��ʽ����д������
        QByteArray bytearray;
        for (int i = 0; i < 25; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // ���ݷ���
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "4")
    {
        // Ҫ�������ݵ�����
        uchar SendData[30] = { 0 };

        // ������������
        measure_group = 4;
        // ��ȡ����
        Addr_frame = 0x04;                                              // ��ַ����
        Length_frame = 30;                                              // ���ݰ���������

        float output_voltage_1 = ui.output_voltage_box1->value();       // �����ѹ1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // ����ģʽ1

        float output_voltage_2 = ui.output_voltage_box2->value();       // �����ѹ2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // ����ģʽ2

        float output_voltage_3 = ui.output_voltage_box2->value();       // �����ѹ3
        char load_pattern_3 = ui.load_pattern_box2->currentIndex();     // ����ģʽ3

        float output_voltage_4 = ui.output_voltage_box4->value();       // �����ѹ4
        char load_pattern_4 = ui.load_pattern_box4->currentIndex();     // ����ģʽ4

        //֡ͷ
        SendData[0] = head_frame;
        //��ַ
        SendData[1] = Addr_frame;
        //֡��
        SendData[2] = Length_frame;
        //��������д��
        SendData[3] = measure_group;
        //����ʱ������ת����д��
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //ѭ����������д��
        SendData[8] = cycle_index;

        //group1�����ѹ����ת����д��
        byte4_union.Float = output_voltage_1;
        for (int i = 0; i < 4; i++)
        {
            SendData[9 + i] = byte4_union.U8_Buff[i];
        }
        //group1����ģʽ����д��
        SendData[13] = load_pattern_1;

        //group2�����ѹ����ת����д��
        byte4_union.Float = output_voltage_2;
        for (int i = 0; i < 4; i++)
        {
            SendData[14 + i] = byte4_union.U8_Buff[i];
        }
        //group2����ģʽ����д��
        SendData[18] = load_pattern_2;

        //group3�����ѹ����ת����д��
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[19 + i] = byte4_union.U8_Buff[i];
        }
        //group3����ģʽ����д��
        SendData[23] = load_pattern_3;

        //group4�����ѹ����ת����д��
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[24 + i] = byte4_union.U8_Buff[i];
        }
        //group4����ģʽ����д��
        SendData[28] = load_pattern_3;

        //���к�У��
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //д���У������
        SendData[29] = Check_frame;

        //����qtָ�������ݽṹ��ʽ����д������
        QByteArray bytearray;
        for (int i = 0; i < 30; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // ���ݷ���
        serialport->write(bytearray);
    }

    //��ʾ���ݷ������
    QMessageBox::information(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\225\260\346\215\256\345\217\221\351\200\201\345\256\214\346\210\220", nullptr), QMessageBox::Ok, QMessageBox::Ok);
}


//���ڽ��ղۺ���
void DS_Upper::recevie_data_Function(void)
{
    // ��������
    char RecevieByte;
    while (serialport->read(&RecevieByte, 1))
    {
        // ��ʼ���
        if (RecevieByte == USB_FRAME_HEAD && !usbStr.receiveStart)  //��⵽֡ͷ
        {
            usbStr.receiveStart = true;
            usbStr.receiveBuff[0] = RecevieByte;
            usbStr.receiveBuff[2] = USB_FRAME_LENMIN;
            usbStr.receiveIndex = 1;
        }
        else if (usbStr.receiveIndex == 2)	//����֡����
        {
            usbStr.receiveBuff[usbStr.receiveIndex] = RecevieByte;
            usbStr.receiveIndex++;

            if (RecevieByte > USB_FRAME_LENMAX || RecevieByte < USB_FRAME_LENMIN) //֡������
            {
                usbStr.receiveBuff[2] = USB_FRAME_LENMIN;
                usbStr.receiveIndex = 0;
                usbStr.receiveStart = false;
            }
        }
        else if (usbStr.receiveStart && usbStr.receiveIndex < USB_FRAME_LENMAX)
        {
            usbStr.receiveBuff[usbStr.receiveIndex] = RecevieByte;
            usbStr.receiveIndex++;
        }

        // ����֡���
        if ((usbStr.receiveIndex >= USB_FRAME_LENMAX || usbStr.receiveIndex >= usbStr.receiveBuff[2]) && usbStr.receiveIndex > USB_FRAME_LENMIN)
        {
            uint8_t check = 0;
            uint8_t length = USB_FRAME_LENMIN;

            length = usbStr.receiveBuff[2];
            for (int i = 0; i < length - 1; i++)
                check += usbStr.receiveBuff[i];

            if (check == usbStr.receiveBuff[length - 1]) // У��λ
            {
                memcpy(usbStr.receiveBuffFinished, usbStr.receiveBuff, USB_FRAME_LENMAX);
                usbStr.receiveFinished = true;
            }

            usbStr.receiveIndex = 0;
            usbStr.receiveStart = false;
        }
    }
}


// USBͨ�Ŵ�����
void DS_Upper::USB_Handle(void)
{
    if (usbStr.receiveFinished)																// ���ݽ��ܲ�У�����
    {
        usbStr.receiveFinished = false;
        Byte4_Union bint32_Union;

        switch (usbStr.receiveBuffFinished[1])
        {
            case USB_ADDR_GROUP1:      // 1������
                //��1���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //��1���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP2:      // 2������
                //��1���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //��1���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //��2���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //��2���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP3:      // 3������
                //��1���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //��1���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //��2���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //��2���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                //��3���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[19 + i];
                dataStr.load_electricity_3 = bint32_Union.Float;
                //��3���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[23 + i];
                dataStr.load_voltage_3 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP4:      // 4������
                //��1���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //��1���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //��2���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //��2���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                //��3���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[19 + i];
                dataStr.load_electricity_3 = bint32_Union.Float;
                //��3���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[23 + i];
                dataStr.load_voltage_3 = bint32_Union.Float;
                //��4���ص���
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[27 + i];
                dataStr.load_electricity_4 = bint32_Union.Float;
                //��4���ص�ѹ
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[31 + i];
                dataStr.load_voltage_4 = bint32_Union.Float;
                break;
        }
    }
}
