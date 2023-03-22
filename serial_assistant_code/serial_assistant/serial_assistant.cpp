#include "serial_assistant.h"
#include "qmessagebox.h"

serial_assistant::serial_assistant(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //定义端口号变量
    //QStringList serialNamePort = QStringList();

    //关联接收区，接收数据显示
    connect(serialport, SIGNAL(readyRead()), this, SLOT(recevie_plainTextEdit_data()));
    //关联定时器，刷新串口
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTime()));

    //开启定时器,500ms刷新一次
    timer->start(Refresh_Time);
    
    //寻找Windows可用端口
    //foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    //{
    //    //得到串口端口名
    //    serialNamePort << info.portName();
    //}

    //将端口号显示到ui上
    //ui.port_comboBox->addItems(serialNamePort);
}

serial_assistant::~serial_assistant()
{}


//定时器函数
void serial_assistant::slotTime(void)
{
    //定义端口号变量
    static QStringList serialNamePort = QStringList();
    //定义中间变量，来记录端口号
    static QStringList currentport = QStringList();
    //定义变量存储端口显示号
    static QString lastport = QString();

    //寻找Windows可用端口
    foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
    {
        //载入到stringlist
        currentport << info.portName();
    }

    //记录上一次的端口号
    lastport = ui.port_comboBox->currentText();

    //判断端口是否变化
    if (currentport != serialNamePort)
    {
        //重新载入端口号
        serialNamePort = currentport;
        //清空combox
        ui.port_comboBox->clear();
        //显示端口号
        ui.port_comboBox->addItems(serialNamePort);
    }

    //清空一下currentport，当变换串口号时，重新赋值
    currentport.clear();

    //如果连接突然断开
    if (!serialNamePort.contains(lastport) && serialport->isOpen())
    {
        //关闭串口
        serialport->close();
        //关闭串口后，恢复串口可修改属性
        ui.BaudRate_comboBox->setEnabled(true);
        ui.port_comboBox->setEnabled(true);
        ui.stop_comboBox->setEnabled(true);
        ui.verify_comboBox->setEnabled(true);
        ui.data_comboBox->setEnabled(true);
        //更改open_and_close_button状态
        ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        //将状态量改为关闭状态
        state = 0;
        //显示错误信息
        QMessageBox::warning(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\350\277\236\346\216\245\351\224\231\350\257\257", nullptr), QMessageBox::Ok, QMessageBox::Ok);
    }
}

//点击按钮Open_close_Button，关联的槽函数
void serial_assistant::Open_close_Button_Clicked()
{
    ////定义静态状态量，判断串口是否打开
    //static bool state = 0;   //默认串口为关闭状态

    //如上一次的串口状态量是关闭，点击信号进来后，进行打开操作
    if (state == 0)
    {
        //定义波特率枚举变量
        QSerialPort::BaudRate baudrate = QSerialPort::BaudRate();
        //定义数据位枚举变量
        QSerialPort::DataBits databits = QSerialPort::DataBits();
        //定义停止位枚举变量
        QSerialPort::StopBits stopbits = QSerialPort::StopBits();
        //定义校验位枚举变量
        QSerialPort::Parity checkbits = QSerialPort::Parity();


        //获取ui中的波特率设置并初始化串口波特率
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

        //获取ui中的数据位设置并初始化串口数据位
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

        //获取ui中的停止位位设置并初始化串口停止位
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

        //获取ui中的校验位位设置并初始化串口校验位
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

        //设置串口端口号
        serialport->setPortName(ui.port_comboBox->currentText());
        //设置波特率
        serialport->setBaudRate(baudrate);
        //设置数据位
        serialport->setDataBits(databits);
        //设置停止位
        serialport->setStopBits(stopbits);
        //设置校验位
        serialport->setParity(checkbits);

        if (serialport->open(QIODevice::ReadWrite) == true)
        {
            //创建提示窗口
            QMessageBox::information(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243\346\210\220\345\212\237\357\274\201", nullptr), QMessageBox::Yes, QMessageBox::Yes);
            //打开串口后，该按钮变为“关闭串口”
            ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
            //将串口状态量设置为打开
            state = 1;
            //打开串口后，把配置串口的bobox全部设置为不可修改状态
            ui.BaudRate_comboBox->setEnabled(false);
            ui.port_comboBox->setEnabled(false);
            ui.stop_comboBox->setEnabled(false);
            ui.verify_comboBox->setEnabled(false);
            ui.data_comboBox->setEnabled(false);
        }
        else
        {
            //创建错误窗口
            QMessageBox::warning(this, QCoreApplication::translate("serial_assistantClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243\345\244\261\350\264\245\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else if (state == 1)
    {
        //上一次串口状态为打开，再次点击关闭串口
        serialport->close();
        //将串口转台改为关闭
        state = 0;
        //将按钮名称改变为打开串口
        ui.open_close_Button->setText(QCoreApplication::translate("serial_assistantClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        //关闭串口后，恢复串口可修改属性
        ui.BaudRate_comboBox->setEnabled(true);
        ui.port_comboBox->setEnabled(true);
        ui.stop_comboBox->setEnabled(true);
        ui.verify_comboBox->setEnabled(true);
        ui.data_comboBox->setEnabled(true);
    }
}

//串口接收槽函数
void serial_assistant::recevie_plainTextEdit_data(void)
{
    //定义接收变量
    QString recevie_data_buff = "";

    //获取接收数据
    recevie_data_buff = QString(serialport->readAll());

    //显示接收数据
    ui.recevie_plainTextEdit->appendPlainText(recevie_data_buff);
}

//点击发送信息槽函数
void serial_assistant::send_data_button_clicked(void)
{
    //将文本框内的数据转换，发送数据
    serialport->write(ui.send_plainTextEdit->toPlainText().toLocal8Bit().data());
}

//点击清除发送区槽函数
void serial_assistant::clean_send_area(void)
{
    //清空发送区
    ui.send_plainTextEdit->clear();
}

//点击清除接收区槽函数
void serial_assistant::clean_recevie_area(void)
{
    //清空接收区
    ui.recevie_plainTextEdit->clear();
}

