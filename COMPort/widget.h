#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QMap>
#include <QDebug>
#include "com_core.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    const quint8            prefix = 0x40;
    const int               sizeFloat = sizeof(float);
    const qint32            BaudRate_default = 9600;
    const int               UpdateInterval_ms = 1000;
    const QString           portButtonTextOn = tr("Connected");
    const QString           portButtonTextOff = tr("Disconnect");
    QTimer                  *pTimerUpdate;
    QStringList             portList;
    QMap<QString, qint32>   baudRateMap;
    qint32                  baudRate;
    QString                 port;
    COM_core                *pCOMCore;
    float                   x;
    float                   y;
    float                   z;
    float                   w;


    void buildBaudRateMap();
    void updateText();

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
private slots:
    void timeoutTimerHandler();
    void on_BaudRate_comboBox_currentIndexChanged(const QString &arg1);
    void on_Port_comboBox_currentIndexChanged(const QString &arg1);
    void on_Port_pushButton_clicked();
    void readyRead(QByteArray &data);
};

#endif // WIDGET_H
