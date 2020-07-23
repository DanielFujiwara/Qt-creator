/********************************************************************************
** Form generated from reading UI file 'rewriteinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REWRITEINFO_H
#define UI_REWRITEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rewriteinfo
{
public:
    QWidget *centralwidget;
    QLabel *label_6;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *typeEdit;
    QLabel *label_3;
    QLineEdit *costEdit;
    QLabel *label_4;
    QLineEdit *priceEdit;
    QLabel *label_5;
    QLineEdit *stockEdit;
    QPushButton *cancleBtn;
    QPushButton *sureBtn;

    void setupUi(QMainWindow *rewriteinfo)
    {
        if (rewriteinfo->objectName().isEmpty())
            rewriteinfo->setObjectName(QString::fromUtf8("rewriteinfo"));
        rewriteinfo->resize(410, 350);
        centralwidget = new QWidget(rewriteinfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 40, 88, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 90, 291, 156));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        typeEdit = new QLineEdit(layoutWidget);
        typeEdit->setObjectName(QString::fromUtf8("typeEdit"));
        typeEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(typeEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        costEdit = new QLineEdit(layoutWidget);
        costEdit->setObjectName(QString::fromUtf8("costEdit"));
        costEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(costEdit, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        priceEdit = new QLineEdit(layoutWidget);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));
        priceEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(priceEdit, 3, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        stockEdit = new QLineEdit(layoutWidget);
        stockEdit->setObjectName(QString::fromUtf8("stockEdit"));
        stockEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(stockEdit, 4, 1, 1, 1);

        cancleBtn = new QPushButton(centralwidget);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setGeometry(QRect(120, 270, 75, 23));
        sureBtn = new QPushButton(centralwidget);
        sureBtn->setObjectName(QString::fromUtf8("sureBtn"));
        sureBtn->setGeometry(QRect(240, 270, 75, 23));
        rewriteinfo->setCentralWidget(centralwidget);

        retranslateUi(rewriteinfo);

        QMetaObject::connectSlotsByName(rewriteinfo);
    } // setupUi

    void retranslateUi(QMainWindow *rewriteinfo)
    {
        rewriteinfo->setWindowTitle(QCoreApplication::translate("rewriteinfo", "MainWindow", nullptr));
        label_6->setText(QCoreApplication::translate("rewriteinfo", "\344\277\256\346\224\271\345\225\206\345\223\201", nullptr));
        label->setText(QCoreApplication::translate("rewriteinfo", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("rewriteinfo", "\347\247\215\347\261\273\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("rewriteinfo", "\346\210\220\346\234\254\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("rewriteinfo", "\345\224\256\344\273\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("rewriteinfo", "\345\272\223\345\255\230\357\274\232", nullptr));
        cancleBtn->setText(QCoreApplication::translate("rewriteinfo", "\345\217\226\346\266\210", nullptr));
        sureBtn->setText(QCoreApplication::translate("rewriteinfo", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rewriteinfo: public Ui_rewriteinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REWRITEINFO_H
