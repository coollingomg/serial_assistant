#include "serial_assistant.h"
#include "qmessagebox.h"

serial_assistant::serial_assistant(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //����˿ںű���
    //QStringList serialNamePort = QStringList();

    //����������������������ʾ
    connect(serialport, SIGNAL(readyRead()), this, SLOT(recevie_plainTextEdit_data()));
    //������ʱ����ˢ�´���
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTime()));

    //������ʱ��,500msˢ��һ��
    timer->start(Refresh_Time);
    
    //Ѱ��Windows���ö˿�
    //foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    //{
    //    //�õ����ڶ˿���
    //    serialNamePort << info.portName();
    //}

    //���˿ں���ʾ��ui��
    //ui.port_comboBox->addItems(serialNamePort);
}

serial_assistant::~serial_assistant()
{}


//��ʱ������
void serial_assistant::slotTime(void)
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

//�����ťOpen_close_Button�������Ĳۺ���
void serial_assistant::Open_close_Button_Clicked()
{
    ////���徲̬״̬�����жϴ����Ƿ��
    //static bool state = 0;   //Ĭ�ϴ���Ϊ�ر�״̬

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
            QMessageBox::information(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243\346\210\220\345\212\237\357\274\201", nullptr), QMessageBox::Yes, QMessageBox::Yes);
            //�򿪴��ں󣬸ð�ť��Ϊ���رմ��ڡ�
            ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
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
            QMessageBox::warning(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243\345\244\261\350\264\245\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else if (state == 1)
    {
        //��һ�δ���״̬Ϊ�򿪣��ٴε���رմ���
        serialport->close();
        //������ת̨��Ϊ�ر�
        state = 0;
        //����ť���Ƹı�Ϊ�򿪴���
        ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        //�رմ��ں󣬻ָ����ڿ��޸�����
        ui.BaudRate_comboBox->setEnabled(true);
        ui.port_comboBox->setEnabled(true);
        ui.stop_comboBox->setEnabled(true);
        ui.verify_comboBox->setEnabled(true);
        ui.data_comboBox->setEnabled(true);
    }
}

//���ڽ��ղۺ���
void serial_assistant::recevie_plainTextEdit_data(void)
{
    //������ձ���
    QString recevie_data_buff = "";

    //��ȡ��������
    recevie_data_buff = QString(serialport->readAll());

    //��ʾ��������
    ui.recevie_plainTextEdit->appendPlainText(recevie_data_buff);
}

//���������Ϣ�ۺ���
void serial_assistant::send_data_button_clicked(void)
{
    //���ı����ڵ�����ת������������
    serialport->write(ui.send_plainTextEdit->toPlainText().toLocal8Bit().data());
}

//�������������ۺ���
void serial_assistant::clean_send_area(void)
{
    //��շ�����
    ui.send_plainTextEdit->clear();
}

//�������������ۺ���
void serial_assistant::clean_recevie_area(void)
{
    //��ս�����
    ui.recevie_plainTextEdit->clear();
}

