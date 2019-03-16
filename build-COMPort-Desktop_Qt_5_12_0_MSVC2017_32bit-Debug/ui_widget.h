/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *PortInfo_groupBox;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *PortInfo_plainTextEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *Port_formLayout;
    QLabel *Port_label;
    QComboBox *Port_comboBox;
    QPushButton *Port_pushButton;
    QComboBox *BaudRate_comboBox;
    QLabel *BaudRate_label;
    QGroupBox *RX_groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *RX_plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(425, 297);
        PortInfo_groupBox = new QGroupBox(Widget);
        PortInfo_groupBox->setObjectName(QString::fromUtf8("PortInfo_groupBox"));
        PortInfo_groupBox->setGeometry(QRect(180, 0, 241, 291));
        horizontalLayout = new QHBoxLayout(PortInfo_groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PortInfo_plainTextEdit = new QPlainTextEdit(PortInfo_groupBox);
        PortInfo_plainTextEdit->setObjectName(QString::fromUtf8("PortInfo_plainTextEdit"));
        PortInfo_plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(PortInfo_plainTextEdit);

        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Port_formLayout = new QFormLayout();
        Port_formLayout->setSpacing(6);
        Port_formLayout->setObjectName(QString::fromUtf8("Port_formLayout"));
        Port_label = new QLabel(verticalLayoutWidget);
        Port_label->setObjectName(QString::fromUtf8("Port_label"));

        Port_formLayout->setWidget(0, QFormLayout::LabelRole, Port_label);

        Port_comboBox = new QComboBox(verticalLayoutWidget);
        Port_comboBox->setObjectName(QString::fromUtf8("Port_comboBox"));

        Port_formLayout->setWidget(0, QFormLayout::FieldRole, Port_comboBox);

        Port_pushButton = new QPushButton(verticalLayoutWidget);
        Port_pushButton->setObjectName(QString::fromUtf8("Port_pushButton"));
        Port_pushButton->setCheckable(true);

        Port_formLayout->setWidget(2, QFormLayout::FieldRole, Port_pushButton);

        BaudRate_comboBox = new QComboBox(verticalLayoutWidget);
        BaudRate_comboBox->setObjectName(QString::fromUtf8("BaudRate_comboBox"));

        Port_formLayout->setWidget(1, QFormLayout::FieldRole, BaudRate_comboBox);

        BaudRate_label = new QLabel(verticalLayoutWidget);
        BaudRate_label->setObjectName(QString::fromUtf8("BaudRate_label"));

        Port_formLayout->setWidget(1, QFormLayout::LabelRole, BaudRate_label);


        verticalLayout->addLayout(Port_formLayout);

        RX_groupBox = new QGroupBox(verticalLayoutWidget);
        RX_groupBox->setObjectName(QString::fromUtf8("RX_groupBox"));
        horizontalLayout_2 = new QHBoxLayout(RX_groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RX_plainTextEdit = new QPlainTextEdit(RX_groupBox);
        RX_plainTextEdit->setObjectName(QString::fromUtf8("RX_plainTextEdit"));

        horizontalLayout_2->addWidget(RX_plainTextEdit);


        verticalLayout->addWidget(RX_groupBox);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        PortInfo_groupBox->setTitle(QApplication::translate("Widget", "COM port info:", nullptr));
        Port_label->setText(QApplication::translate("Widget", "Port:", nullptr));
        Port_pushButton->setText(QApplication::translate("Widget", "Connect", nullptr));
        BaudRate_label->setText(QApplication::translate("Widget", "Baud rate:", nullptr));
        RX_groupBox->setTitle(QApplication::translate("Widget", "Received data:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
