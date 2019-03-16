#ifndef COM_CORE_H
#define COM_CORE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class COM_core : public QObject
{
    Q_OBJECT
private:
    QSerialPort     serialPort;

public:
    explicit COM_core(QObject *parent = nullptr);
    void initialization(const QString portName, const qint32 baudRate = QSerialPort::Baud9600, const QSerialPort::DataBits dataBits = QSerialPort::Data8,
                        const QSerialPort::StopBits stopBits = QSerialPort::OneStop, const  QSerialPort::Parity parity = QSerialPort::NoParity);
    bool open(QIODevice::OpenMode mode);
    void close();

signals:
    void readyRead(QByteArray &data);

public slots:
private slots:
    void handleReadyRead();
    void handleError(QSerialPort::SerialPortError serialPortError);
};

#endif // COM_CORE_H
