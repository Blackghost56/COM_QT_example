#include "com_core.h"

COM_core::COM_core(QObject *parent) : QObject(parent)
{
    connect(&serialPort, &QSerialPort::readyRead, this, &COM_core::handleReadyRead);
    connect(&serialPort, &QSerialPort::errorOccurred, this, &COM_core::handleError);
}

void COM_core::initialization(const QString portName, const qint32 baudRate, const QSerialPort::DataBits dataBits, const QSerialPort::StopBits stopBits, const QSerialPort::Parity parity)
{
    if (!serialPort.isOpen())
    {
       serialPort.setPortName(portName);
       serialPort.setBaudRate(baudRate);
       serialPort.setDataBits(dataBits);
       serialPort.setStopBits(stopBits);
       serialPort.setParity(parity);
    }
}

bool COM_core::open(QIODevice::OpenMode mode)
{
    bool state = serialPort.open(mode);
    if (!state)
        qDebug() << "Failed to open port";

    return state;
}

void COM_core::close()
{
    serialPort.close();
}

void COM_core::handleReadyRead()
{
    QByteArray data = serialPort.readAll();

    emit readyRead(data);
    //qDebug() <<  "handleReadyRead, data:" << serialPort.readAll();
}

void COM_core::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        qDebug() << tr("An I/O error occurred while reading the data from port %1, error: %2").arg(serialPort.portName()).arg(serialPort.errorString());
    }
}
