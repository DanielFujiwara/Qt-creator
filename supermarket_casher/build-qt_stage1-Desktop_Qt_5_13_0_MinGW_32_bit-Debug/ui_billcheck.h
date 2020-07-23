/********************************************************************************
** Form generated from reading UI file 'billcheck.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLCHECK_H
#define UI_BILLCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_billcheck
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *billcheck)
    {
        if (billcheck->objectName().isEmpty())
            billcheck->setObjectName(QString::fromUtf8("billcheck"));
        billcheck->resize(474, 441);
        centralwidget = new QWidget(billcheck);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 40, 431, 341));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 10, 91, 21));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 400, 75, 23));
        billcheck->setCentralWidget(centralwidget);

        retranslateUi(billcheck);

        QMetaObject::connectSlotsByName(billcheck);
    } // setupUi

    void retranslateUi(QMainWindow *billcheck)
    {
        billcheck->setWindowTitle(QCoreApplication::translate("billcheck", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("billcheck", "\351\224\200\345\224\256\350\256\260\345\275\225", nullptr));
        pushButton->setText(QCoreApplication::translate("billcheck", "\345\245\275\347\232\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class billcheck: public Ui_billcheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLCHECK_H
