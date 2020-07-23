/********************************************************************************
** Form generated from reading UI file 'userchangeinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCHANGEINFO_H
#define UI_USERCHANGEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userchangeinfo
{
public:
    QWidget *centralwidget;
    QLabel *label_6;
    QPushButton *sureBtn;
    QPushButton *cancleBtn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *ptEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *userEdit;
    QLineEdit *idEdit;
    QLineEdit *passworkEdit;
    QLabel *label;

    void setupUi(QMainWindow *userchangeinfo)
    {
        if (userchangeinfo->objectName().isEmpty())
            userchangeinfo->setObjectName(QString::fromUtf8("userchangeinfo"));
        userchangeinfo->resize(410, 350);
        centralwidget = new QWidget(userchangeinfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 30, 131, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        sureBtn = new QPushButton(centralwidget);
        sureBtn->setObjectName(QString::fromUtf8("sureBtn"));
        sureBtn->setGeometry(QRect(230, 260, 75, 23));
        cancleBtn = new QPushButton(centralwidget);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(110, 260, 75, 23));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 80, 291, 156));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ptEdit = new QLineEdit(layoutWidget);
        ptEdit->setObjectName(QString::fromUtf8("ptEdit"));
        ptEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(ptEdit, 3, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        userEdit = new QLineEdit(layoutWidget);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));
        userEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(userEdit, 0, 1, 1, 1);

        idEdit = new QLineEdit(layoutWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(idEdit, 1, 1, 1, 1);

        passworkEdit = new QLineEdit(layoutWidget);
        passworkEdit->setObjectName(QString::fromUtf8("passworkEdit"));
        passworkEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(passworkEdit, 2, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        userchangeinfo->setCentralWidget(centralwidget);

        retranslateUi(userchangeinfo);

        QMetaObject::connectSlotsByName(userchangeinfo);
    } // setupUi

    void retranslateUi(QMainWindow *userchangeinfo)
    {
        userchangeinfo->setWindowTitle(QCoreApplication::translate("userchangeinfo", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("userchangeinfo", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        sureBtn->setText(QCoreApplication::translate("userchangeinfo", "\347\241\256\350\256\244", nullptr));
        cancleBtn->setText(QCoreApplication::translate("userchangeinfo", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("userchangeinfo", "\345\267\245    \345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("userchangeinfo", "\345\257\206    \347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("userchangeinfo", "\344\272\214\346\254\241\347\241\256\350\256\244\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("userchangeinfo", "\345\220\215    \347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userchangeinfo: public Ui_userchangeinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCHANGEINFO_H
