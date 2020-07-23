/********************************************************************************
** Form generated from reading UI file 'adminctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCTRL_H
#define UI_ADMINCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminctrl
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *lodingBtn;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *adminctrl)
    {
        if (adminctrl->objectName().isEmpty())
            adminctrl->setObjectName(QString::fromUtf8("adminctrl"));
        adminctrl->resize(840, 530);
        centralwidget = new QWidget(adminctrl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 800, 411));
        lodingBtn = new QPushButton(centralwidget);
        lodingBtn->setObjectName(QString::fromUtf8("lodingBtn"));
        lodingBtn->setGeometry(QRect(20, 480, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 480, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 480, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(350, 480, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 10, 191, 31));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 480, 93, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 470, 171, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 490, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 480, 93, 28));
        adminctrl->setCentralWidget(centralwidget);

        retranslateUi(adminctrl);

        QMetaObject::connectSlotsByName(adminctrl);
    } // setupUi

    void retranslateUi(QMainWindow *adminctrl)
    {
        adminctrl->setWindowTitle(QCoreApplication::translate("adminctrl", "MainWindow", nullptr));
        lodingBtn->setText(QCoreApplication::translate("adminctrl", "\350\264\246\346\210\267\347\256\241\347\220\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adminctrl", "\351\200\200\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("adminctrl", "\345\210\240\351\231\244", nullptr));
        pushButton_4->setText(QCoreApplication::translate("adminctrl", "\346\267\273\345\212\240", nullptr));
        label->setText(QCoreApplication::translate("adminctrl", "\347\256\241\347\220\206\346\216\247\345\210\266\345\217\260", nullptr));
        pushButton->setText(QCoreApplication::translate("adminctrl", "\351\224\200\345\224\256\350\256\260\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("adminctrl", "2020-07-16", nullptr));
        label_3->setText(QCoreApplication::translate("adminctrl", "00:00:00", nullptr));
        pushButton_5->setText(QCoreApplication::translate("adminctrl", "\346\263\250\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminctrl: public Ui_adminctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCTRL_H
