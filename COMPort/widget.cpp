#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->Port_pushButton->setText(portButtonTextOn);

    buildBaudRateMap();
    baudRate = BaudRate_default;

    pCOMCore = new COM_core(this);
    connect(pCOMCore, &COM_core::readyRead, this, &Widget::readyRead);

    pTimerUpdate = new QTimer(this);
    pTimerUpdate->setInterval(UpdateInterval_ms);
    connect(pTimerUpdate, SIGNAL(timeout()), this, SLOT(timeoutTimerHandler()));
    pTimerUpdate->start();


}

Widget::~Widget()
{
    delete ui;
}


void Widget::buildBaudRateMap()
{
    QStringList BaudRatelist;
    BaudRatelist.push_back("1200");
    baudRateMap.insert(BaudRatelist.last(), 1200);
    BaudRatelist.push_back("2400");
    baudRateMap.insert(BaudRatelist.last(), 2400);
    BaudRatelist.push_back("4800");
    baudRateMap.insert(BaudRatelist.last(), 4800);
    BaudRatelist.push_back("9600");
    baudRateMap.insert(BaudRatelist.last(), 9600);
    BaudRatelist.push_back("19200");
    baudRateMap.insert(BaudRatelist.last(), 19200);
    BaudRatelist.push_back("38400");
    baudRateMap.insert(BaudRatelist.last(), 38400);
    BaudRatelist.push_back("57600");
    baudRateMap.insert(BaudRatelist.last(), 57600);
    BaudRatelist.push_back("115200");
    baudRateMap.insert(BaudRatelist.last(), 115200);

    ui->BaudRate_comboBox->addItems(BaudRatelist);
    ui->BaudRate_comboBox->setCurrentIndex(3);
}

void Widget::timeoutTimerHandler()
{
    ui->PortInfo_plainTextEdit->clear();
    QStringList     bufPortList;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString s = QObject::tr("Port: ") + info.portName() + "\n"
                    + QObject::tr("Location: ") + info.systemLocation() + "\n"
                    + QObject::tr("Description: ") + info.description() + "\n"
                    + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
                    + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
                    + QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
                    + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

        ui->PortInfo_plainTextEdit->appendPlainText(s);
        bufPortList.push_back(info.portName());
    }

    if (portList != bufPortList)
    {
        portList = bufPortList;
        //qDebug() << "port list: " << portList << "\tport: " << port;
        if(!portList.contains(port)) {
            //qDebug() << "disconnect";
            disconnectPort();
        }
        ui->Port_comboBox->clear();
        ui->Port_comboBox->addItems(portList);       
    }
}

void Widget::on_BaudRate_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.isEmpty()){
        //qDebug() << "Incorrect baud rate";
        return;
    }
    baudRate = baudRateMap[arg1];
    qDebug() << "Baud rate: " << baudRate;
}

void Widget::on_Port_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1.isEmpty()){
        //qDebug() << "Incorrect port";
        return;
    }
    port = arg1;
    qDebug() << "Port: " << port;
}

void Widget::connectPort()
{
    ui->Port_pushButton->setText(portButtonTextOff);
    pCOMCore->initialization(port, baudRate);
    pCOMCore->open(QIODevice::ReadOnly);
}

void Widget::disconnectPort()
{
    ui->Port_pushButton->setText(portButtonTextOn);
    pCOMCore->close();
}

void Widget::on_Port_pushButton_clicked()
{
    if (ui->Port_pushButton->isChecked())
    {
        connectPort();
    } else {
        disconnectPort();
    }
}

void Widget::readyRead(QByteArray &data)
{
    qDebug() << data;
    RAWdataOut(data);

    int position = -1;
    for (int i = 0; i < data.length(); i++)
    {
        if (data.at(i) == prefix)
        {
            position = i + 1;
            break;
        }
    }
    if (position > 0)
    {
        x = byteArrayToFloat(data.mid(position, sizeFloat));
        position += sizeFloat;
        y = byteArrayToFloat(data.mid(position, sizeFloat));
        position += sizeFloat;
        z = byteArrayToFloat(data.mid(position, sizeFloat));
        position += sizeFloat;
        w = byteArrayToFloat(data.mid(position, sizeFloat));
        updateText();
    }
}

float Widget::byteArrayToFloat(const QByteArray &array)
{
    for (int i = 0; i < sizeFloat; i++){
            converter._char[i] = array.at(i);
    }

    return converter._float;
}

void Widget::updateText()
{
    ui->RX_plainTextEdit->clear();
    ui->RX_plainTextEdit->appendPlainText("x = " + QString::number(double(x), 'f', 5));
    ui->RX_plainTextEdit->appendPlainText("y = " + QString::number(double(y), 'f', 5));
    ui->RX_plainTextEdit->appendPlainText("z = " + QString::number(double(z), 'f', 5));
    ui->RX_plainTextEdit->appendPlainText("w = " + QString::number(double(w), 'f', 5));
}

void Widget::RAWdataOut(const QByteArray &data, const int str_length)
{
    QString str;
    for (int i = 0; i < data.length(); i++){
        if ((i % str_length == 0) && (i != 0))
        {
            qDebug() << str;
            str.clear();
        }
        str.push_back(QString("%1 ").arg(quint8(data.at(i)), 2, 16, QChar('0')));
    }
    if (!str.isEmpty())
        qDebug() << str;
}
