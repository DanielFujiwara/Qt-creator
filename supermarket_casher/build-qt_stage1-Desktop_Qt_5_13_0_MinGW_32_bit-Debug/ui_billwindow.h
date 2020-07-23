/********************************************************************************
** Form generated from reading UI file 'billwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLWINDOW_H
#define UI_BILLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_billwindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *label_2;
    QLabel *moneyLabel;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QMainWindow *billwindow)
    {
        if (billwindow->objectName().isEmpty())
            billwindow->setObjectName(QString::fromUtf8("billwindow"));
        billwindow->resize(439, 513);
        centralwidget = new QWidget(billwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 0, 151, 61));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 60, 400, 360));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 430, 71, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Arabic\";"));
        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QString::fromUtf8("moneyLabel"));
        moneyLabel->setGeometry(QRect(330, 430, 61, 41));
        moneyLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe Arabic\";"));
        moneyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(400, 430, 71, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Arabic\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 470, 93, 28));
        billwindow->setCentralWidget(centralwidget);

        retranslateUi(billwindow);

        QMetaObject::connectSlotsByName(billwindow);
    } // setupUi

    void retranslateUi(QMainWindow *billwindow)
    {
        billwindow->setWindowTitle(QCoreApplication::translate("billwindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("billwindow", "\350\260\242\350\260\242\346\203\240\351\241\276\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("billwindow", "\345\220\210\350\256\241 \357\274\232", nullptr));
        moneyLabel->setText(QCoreApplication::translate("billwindow", "0.00", nullptr));
        label_3->setText(QCoreApplication::translate("billwindow", "\345\205\203", nullptr));
        pushButton->setText(QCoreApplication::translate("billwindow", "bye", nullptr));
    } // retranslateUi

};

namespace Ui {
    class billwindow: public Ui_billwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLWINDOW_H
