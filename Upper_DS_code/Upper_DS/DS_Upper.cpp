#include "DS_Upper.h"
#include "qmessagebox.h"

DS_Upper::DS_Upper(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //关联接收，接收数据显示
    connect(serialport, SIGNAL(readyRead()), this, SLOT(recevie_data_Function()));

    //启用定时器
    Timer1 = startTimer(200);
    Timer2 = startTimer(20);
}

DS_Upper::~DS_Upper()
{}

//定时器控制函数
void DS_Upper::timerEvent(QTimerEvent* event) 
{

    if (event->timerId() == Timer1) 
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
    if (event->timerId() == Timer2) 
    {
        // 根据串口状态全局变量，判断是否解包
        if (state == 1)
        {
            // 每一段时间解包，刷新串口接受数据
            USB_Handle();
            // 显示解包的数据到ui上
            if (usbStr.receiveBuffFinished[1] == 0x01)
            {
                ui.load_electricity_lable1->setNum((double)dataStr.load_electricity_1);     // 显示组1电流
                ui.load_voltage_lable1->setNum((double)dataStr.load_voltage_1);             // 显示组1电压
            }
            else if (usbStr.receiveBuffFinished[1] == 0x02)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // 显示组1电流
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // 显示组1电压
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // 显示组2电流
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // 显示组2电压
            }
            else if (usbStr.receiveBuffFinished[1] == 0x03)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // 显示组1电流
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // 显示组1电压
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // 显示组2电流
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // 显示组2电压
                ui.load_electricity_lable3->setNum(dataStr.load_electricity_3);     // 显示组3电流
                ui.load_voltage_lable3->setNum(dataStr.load_voltage_3);             // 显示组3电压
            }
            else if (usbStr.receiveBuffFinished[1] == 0x04)
            {
                ui.load_electricity_lable1->setNum(dataStr.load_electricity_1);     // 显示组1电流
                ui.load_voltage_lable1->setNum(dataStr.load_voltage_1);             // 显示组1电压
                ui.load_electricity_lable2->setNum(dataStr.load_electricity_2);     // 显示组2电流
                ui.load_voltage_lable2->setNum(dataStr.load_voltage_2);             // 显示组2电压
                ui.load_electricity_lable3->setNum(dataStr.load_electricity_3);     // 显示组3电流
                ui.load_voltage_lable3->setNum(dataStr.load_voltage_3);             // 显示组3电压
                ui.load_electricity_lable4->setNum(dataStr.load_electricity_4);     // 显示组4电流
                ui.load_voltage_lable4->setNum(dataStr.load_voltage_4);             // 显示组4电压
            }
        }
    }
}


//点击按钮Open_close_Button，关联的槽函数
void DS_Upper::Open_close_Button_Clicked()
{
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
            QMessageBox::information(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243\346\210\220\345\212\237\357\274\201", nullptr), QMessageBox::Yes, QMessageBox::Yes);
            //打开串口后，该按钮变为“关闭串口”
            ui.open_close_Button->setText(QCoreApplication::translate("DS_UpperClass", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
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
            QMessageBox::warning(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243\345\244\261\350\264\245\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        }
    }
    else if (state == 1)
    {
        //上一次串口状态为打开，再次点击关闭串口
        serialport->close();
        //将串口转台改为关闭
        state = 0;
        //将按钮名称改变为打开串口
        ui.open_close_Button->setText(QCoreApplication::translate("DS_UpperClass", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        //关闭串口后，恢复串口可修改属性
        ui.BaudRate_comboBox->setEnabled(true);
        ui.port_comboBox->setEnabled(true);
        ui.stop_comboBox->setEnabled(true);
        ui.verify_comboBox->setEnabled(true);
        ui.data_comboBox->setEnabled(true);
    }
}

//点击发送信息槽函数
void DS_Upper::send_data_button_clicked(void)
{
    // 判断串口是否打开，未打开则警报并退出本次函数
    if (state == 0)
    {
        // 创建提示窗口
        QMessageBox::warning(this, QCoreApplication::translate("DS_UpperClass", "\351\224\231\350\257\257", nullptr), QCoreApplication::translate("DS_UpperClass", "\344\270\262\345\217\243\346\234\252\346\211\223\345\274\200\357\274\201\357\274\201", nullptr), QMessageBox::Ok, QMessageBox::Ok);
        // 退出本次函数
        return;
    }

    // 定义通信协议格式
    uchar head_frame = 0x42;                                    // 数据帧头
    uchar Addr_frame = 0x01;                                    // 数据地址，"1-4" -> 代表几组测试组，默认一组
    uchar Length_frame = 15;                                    // 数据长度
    uchar Check_frame = 0x00;                                   // 和校验位

    // 定义变量，获取并存储要发送的数据
    float time_set = ui.time_set_box->value();                  // 老化参数，测试时间（s）
    uchar cycle_index = ui.cycle_index_box->value();            // 老化参数设置，循环次数
    uchar measure_group = 1;                                    // 老化参数设置，测试组数

    // 用于数据类型转换的联合体
    Byte4_Union byte4_union;

    if (ui.measure_groupNum->currentText() == "1")
    {
        // 要发送数据的数组
        uchar SendData[15] = { 0 };

        // 测试组数设置
        measure_group = 1;
        // 获取每组的参数设置
        float output_voltage_1 = ui.output_voltage_box1->value();       // 输出电压
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // 负载模式
        Addr_frame = 0x01;                                              // 地址设置
        Length_frame = 15;                                              // 数据包长度设置

        //帧头
        SendData[0] = head_frame;
        //地址
        SendData[1] = Addr_frame;
        //帧长
        SendData[2] = Length_frame;
        //测试组数写入
        SendData[3] = measure_group;
        //测试时间数据转换并写入
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //循环次数数据写入
        SendData[8] = cycle_index;

        //group1输出电压数据转换并写入
        byte4_union.Float = output_voltage_1;
        SendData[9] = byte4_union.U8_Buff[0];
        SendData[10] = byte4_union.U8_Buff[1];
        SendData[11] = byte4_union.U8_Buff[2];
        SendData[12] = byte4_union.U8_Buff[3];
        //group1负载模式数据写入
        SendData[13] = load_pattern_1;

        //进行和校验
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //写入和校验数据
        SendData[14] = Check_frame;

        //定义qt指定的数据结构形式，并写入数据
        QByteArray bytearray;
        for (int i = 0; i < 15; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // 数据发送
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "2")
    {
        // 要发送数据的数组
        uchar SendData[20] = { 0 };

        // 测试组数设置
        measure_group = 2;
        // 获取参数
        Addr_frame = 0x02;                                              // 地址设置
        Length_frame = 20;                                              // 数据包长度设置

        float output_voltage_1 = ui.output_voltage_box1->value();       // 输出电压1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // 负载模式1

        float output_voltage_2 = ui.output_voltage_box2->value();       // 输出电压2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // 负载模式2


        //帧头
        SendData[0] = head_frame;
        //地址
        SendData[1] = Addr_frame;
        //帧长
        SendData[2] = Length_frame;
        //测试组数写入
        SendData[3] = measure_group;
        //测试时间数据转换并写入
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //循环次数数据写入
        SendData[8] = cycle_index;

        //group1输出电压数据转换并写入
        byte4_union.Float = output_voltage_1;
        SendData[9] = byte4_union.U8_Buff[0];
        SendData[10] = byte4_union.U8_Buff[1];
        SendData[11] = byte4_union.U8_Buff[2];
        SendData[12] = byte4_union.U8_Buff[3];
        //group1负载模式数据写入
        SendData[13] = load_pattern_1;

        //group2输出电压数据转换并写入
        byte4_union.Float = output_voltage_2;
        SendData[14] = byte4_union.U8_Buff[0];
        SendData[15] = byte4_union.U8_Buff[1];
        SendData[16] = byte4_union.U8_Buff[2];
        SendData[17] = byte4_union.U8_Buff[3];
        //group2负载模式数据写入
        SendData[18] = load_pattern_2;

        //进行和校验
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //写入和校验数据
        SendData[19] = Check_frame;

        //定义qt指定的数据结构形式，并写入数据
        QByteArray bytearray;
        for (int i = 0; i < 20; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // 数据发送
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "3")
    {
        // 要发送数据的数组
        uchar SendData[25] = { 0 };

        // 测试组数设置
        measure_group = 3;
        // 获取参数
        Addr_frame = 0x03;                                              // 地址设置
        Length_frame = 25;                                              // 数据包长度设置

        float output_voltage_1 = ui.output_voltage_box1->value();       // 输出电压1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // 负载模式1

        float output_voltage_2 = ui.output_voltage_box2->value();       // 输出电压2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // 负载模式2

        float output_voltage_3 = ui.output_voltage_box3->value();       // 输出电压3
        char load_pattern_3 = ui.load_pattern_box3->currentIndex();     // 负载模式3

        //帧头
        SendData[0] = head_frame;
        //地址
        SendData[1] = Addr_frame;
        //帧长
        SendData[2] = Length_frame;
        //测试组数写入
        SendData[3] = measure_group;
        //测试时间数据转换并写入
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //循环次数数据写入
        SendData[8] = cycle_index;

        //group1输出电压数据转换并写入
        byte4_union.Float = output_voltage_1;
        for (int i = 0; i < 4; i++)
        {
            SendData[9 + i] = byte4_union.U8_Buff[i];
        }
        //group1负载模式数据写入
        SendData[13] = load_pattern_1;

        //group2输出电压数据转换并写入
        byte4_union.Float = output_voltage_2;
        for (int i = 0; i < 4; i++)
        {
            SendData[14 +i] = byte4_union.U8_Buff[i];
        }
        //group2负载模式数据写入
        SendData[18] = load_pattern_2;

        //group3输出电压数据转换并写入
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[19 + i] = byte4_union.U8_Buff[i];
        }
        //group3负载模式数据写入
        SendData[23] = load_pattern_3;

        //进行和校验
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //写入和校验数据
        SendData[24] = Check_frame;

        //定义qt指定的数据结构形式，并写入数据
        QByteArray bytearray;
        for (int i = 0; i < 25; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // 数据发送
        serialport->write(bytearray);
    }
    else if (ui.measure_groupNum->currentText() == "4")
    {
        // 要发送数据的数组
        uchar SendData[30] = { 0 };

        // 测试组数设置
        measure_group = 4;
        // 获取参数
        Addr_frame = 0x04;                                              // 地址设置
        Length_frame = 30;                                              // 数据包长度设置

        float output_voltage_1 = ui.output_voltage_box1->value();       // 输出电压1
        char load_pattern_1 = ui.load_pattern_box1->currentIndex();     // 负载模式1

        float output_voltage_2 = ui.output_voltage_box2->value();       // 输出电压2
        char load_pattern_2 = ui.load_pattern_box2->currentIndex();     // 负载模式2

        float output_voltage_3 = ui.output_voltage_box2->value();       // 输出电压3
        char load_pattern_3 = ui.load_pattern_box2->currentIndex();     // 负载模式3

        float output_voltage_4 = ui.output_voltage_box4->value();       // 输出电压4
        char load_pattern_4 = ui.load_pattern_box4->currentIndex();     // 负载模式4

        //帧头
        SendData[0] = head_frame;
        //地址
        SendData[1] = Addr_frame;
        //帧长
        SendData[2] = Length_frame;
        //测试组数写入
        SendData[3] = measure_group;
        //测试时间数据转换并写入
        byte4_union.Float = time_set;
        SendData[4] = byte4_union.U8_Buff[0];
        SendData[5] = byte4_union.U8_Buff[1];
        SendData[6] = byte4_union.U8_Buff[2];
        SendData[7] = byte4_union.U8_Buff[3];
        //循环次数数据写入
        SendData[8] = cycle_index;

        //group1输出电压数据转换并写入
        byte4_union.Float = output_voltage_1;
        for (int i = 0; i < 4; i++)
        {
            SendData[9 + i] = byte4_union.U8_Buff[i];
        }
        //group1负载模式数据写入
        SendData[13] = load_pattern_1;

        //group2输出电压数据转换并写入
        byte4_union.Float = output_voltage_2;
        for (int i = 0; i < 4; i++)
        {
            SendData[14 + i] = byte4_union.U8_Buff[i];
        }
        //group2负载模式数据写入
        SendData[18] = load_pattern_2;

        //group3输出电压数据转换并写入
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[19 + i] = byte4_union.U8_Buff[i];
        }
        //group3负载模式数据写入
        SendData[23] = load_pattern_3;

        //group4输出电压数据转换并写入
        byte4_union.Float = output_voltage_3;
        for (int i = 0; i < 4; i++)
        {
            SendData[24 + i] = byte4_union.U8_Buff[i];
        }
        //group4负载模式数据写入
        SendData[28] = load_pattern_3;

        //进行和校验
        for (int i = 0; i < Length_frame - 1; i++)
            Check_frame += SendData[i];
        //写入和校验数据
        SendData[29] = Check_frame;

        //定义qt指定的数据结构形式，并写入数据
        QByteArray bytearray;
        for (int i = 0; i < 30; i++)
        {
            bytearray.push_back(SendData[i]);
        }

        // 数据发送
        serialport->write(bytearray);
    }

    //提示数据发送完成
    QMessageBox::information(this, QCoreApplication::translate("DS_UpperClass", "\346\217\220\347\244\272", nullptr), QCoreApplication::translate("DS_UpperClass", "\346\225\260\346\215\256\345\217\221\351\200\201\345\256\214\346\210\220", nullptr), QMessageBox::Ok, QMessageBox::Ok);
}


//串口接收槽函数
void DS_Upper::recevie_data_Function(void)
{
    // 接受数据
    char RecevieByte;
    while (serialport->read(&RecevieByte, 1))
    {
        // 开始解包
        if (RecevieByte == USB_FRAME_HEAD && !usbStr.receiveStart)  //检测到帧头
        {
            usbStr.receiveStart = true;
            usbStr.receiveBuff[0] = RecevieByte;
            usbStr.receiveBuff[2] = USB_FRAME_LENMIN;
            usbStr.receiveIndex = 1;
        }
        else if (usbStr.receiveIndex == 2)	//接受帧长度
        {
            usbStr.receiveBuff[usbStr.receiveIndex] = RecevieByte;
            usbStr.receiveIndex++;

            if (RecevieByte > USB_FRAME_LENMAX || RecevieByte < USB_FRAME_LENMIN) //帧长错误
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

        // 接受帧完毕
        if ((usbStr.receiveIndex >= USB_FRAME_LENMAX || usbStr.receiveIndex >= usbStr.receiveBuff[2]) && usbStr.receiveIndex > USB_FRAME_LENMIN)
        {
            uint8_t check = 0;
            uint8_t length = USB_FRAME_LENMIN;

            length = usbStr.receiveBuff[2];
            for (int i = 0; i < length - 1; i++)
                check += usbStr.receiveBuff[i];

            if (check == usbStr.receiveBuff[length - 1]) // 校验位
            {
                memcpy(usbStr.receiveBuffFinished, usbStr.receiveBuff, USB_FRAME_LENMAX);
                usbStr.receiveFinished = true;
            }

            usbStr.receiveIndex = 0;
            usbStr.receiveStart = false;
        }
    }
}


// USB通信处理函数
void DS_Upper::USB_Handle(void)
{
    if (usbStr.receiveFinished)																// 数据接受并校验完成
    {
        usbStr.receiveFinished = false;
        Byte4_Union bint32_Union;

        switch (usbStr.receiveBuffFinished[1])
        {
            case USB_ADDR_GROUP1:      // 1组数据
                //组1负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //组1负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP2:      // 2组数据
                //组1负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //组1负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //组2负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //组2负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP3:      // 3组数据
                //组1负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //组1负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //组2负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //组2负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                //组3负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[19 + i];
                dataStr.load_electricity_3 = bint32_Union.Float;
                //组3负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[23 + i];
                dataStr.load_voltage_3 = bint32_Union.Float;
                break;

            case USB_ADDR_GROUP4:      // 4组数据
                //组1负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[3 + i];
                dataStr.load_electricity_1 = bint32_Union.Float;
                //组1负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[7 + i];
                dataStr.load_voltage_1 = bint32_Union.Float;
                //组2负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[11 + i];
                dataStr.load_electricity_2 = bint32_Union.Float;
                //组2负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[15 + i];
                dataStr.load_voltage_2 = bint32_Union.Float;
                //组3负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[19 + i];
                dataStr.load_electricity_3 = bint32_Union.Float;
                //组3负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[23 + i];
                dataStr.load_voltage_3 = bint32_Union.Float;
                //组4负载电流
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[27 + i];
                dataStr.load_electricity_4 = bint32_Union.Float;
                //组4负载电压
                for (int i = 0; i < 4; i++)
                    bint32_Union.U8_Buff[i] = usbStr.receiveBuffFinished[31 + i];
                dataStr.load_voltage_4 = bint32_Union.Float;
                break;
        }
    }
}
