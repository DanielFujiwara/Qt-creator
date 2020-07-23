/********************************************************************************
** Form generated from reading UI file 'simplecasherctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLECASHERCTRL_H
#define UI_SIMPLECASHERCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simplecasherctrl
{
public:
    QWidget *centralwidget;
    QPushButton *reduceBtn;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *addBtn;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *idLabel;
    QLabel *moneyLabel;
    QLabel *dataLabel;
    QLabel *timeLabel;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *simplecasherctrl)
    {
        if (simplecasherctrl->objectName().isEmpty())
            simplecasherctrl->setObjectName(QString::fromUtf8("simplecasherctrl"));
        simplecasherctrl->resize(930, 534);
        centralwidget = new QWidget(simplecasherctrl);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        reduceBtn = new QPushButton(centralwidget);
        reduceBtn->setObjectName(QString::fromUtf8("reduceBtn"));
        reduceBtn->setGeometry(QRect(430, 250, 71, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(790, 470, 71, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Arabic\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 71, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Arabic\";"));
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(430, 150, 71, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 470, 71, 41));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Adobe Arabic\";"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(440, 200, 51, 31));
        spinBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        idLabel = new QLabel(centralwidget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setGeometry(QRect(80, 10, 51, 41));
        idLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe Arabic\";"));
        idLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        moneyLabel = new QLabel(centralwidget);
        moneyLabel->setObjectName(QString::fromUtf8("moneyLabel"));
        moneyLabel->setGeometry(QRect(720, 470, 61, 41));
        moneyLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Adobe Arabic\";"));
        moneyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dataLabel = new QLabel(centralwidget);
        dataLabel->setObjectName(QString::fromUtf8("dataLabel"));
        dataLabel->setGeometry(QRect(620, 10, 141, 41));
        dataLabel->setStyleSheet(QString::fromUtf8("font: 15pt \"Adobe Arabic\";"));
        dataLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(770, 10, 61, 41));
        timeLabel->setStyleSheet(QString::fromUtf8("font: 15pt \"Adobe Arabic\";"));
        timeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 50, 401, 360));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(510, 50, 401, 360));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 430, 291, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        simplecasherctrl->setCentralWidget(centralwidget);

        retranslateUi(simplecasherctrl);

        QMetaObject::connectSlotsByName(simplecasherctrl);
    } // setupUi

    void retranslateUi(QMainWindow *simplecasherctrl)
    {
        simplecasherctrl->setWindowTitle(QCoreApplication::translate("simplecasherctrl", "MainWindow", nullptr));
        reduceBtn->setText(QCoreApplication::translate("simplecasherctrl", "\343\200\212\343\200\212\343\200\212", nullptr));
        label_3->setText(QCoreApplication::translate("simplecasherctrl", "\345\205\203", nullptr));
        label_2->setText(QCoreApplication::translate("simplecasherctrl", "\345\267\245\345\217\267 \357\274\232", nullptr));
        addBtn->setText(QCoreApplication::translate("simplecasherctrl", "\343\200\213\343\200\213\343\200\213", nullptr));
        label->setText(QCoreApplication::translate("simplecasherctrl", "\345\220\210\350\256\241 \357\274\232", nullptr));
        idLabel->setText(QCoreApplication::translate("simplecasherctrl", "0000", nullptr));
        moneyLabel->setText(QCoreApplication::translate("simplecasherctrl", "0.00", nullptr));
        dataLabel->setText(QCoreApplication::translate("simplecasherctrl", "yy-mm-dd", nullptr));
        timeLabel->setText(QCoreApplication::translate("simplecasherctrl", "00:00:00", nullptr));
        pushButton->setText(QCoreApplication::translate("simplecasherctrl", "\347\273\223\347\256\227", nullptr));
        pushButton_3->setText(QCoreApplication::translate("simplecasherctrl", "\346\270\205\347\251\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("simplecasherctrl", "\346\263\250\351\224\200", nullptr));
        pushButton_4->setText(QCoreApplication::translate("simplecasherctrl", "\344\270\213\347\217\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simplecasherctrl: public Ui_simplecasherctrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLECASHERCTRL_H
