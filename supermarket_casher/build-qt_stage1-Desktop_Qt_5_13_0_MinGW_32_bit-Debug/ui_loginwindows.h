/********************************************************************************
** Form generated from reading UI file 'loginwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOWS_H
#define UI_LOGINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindows
{
public:
    QWidget *centralWidget;
    QPushButton *loginBtn;
    QPushButton *creatBtn;
    QLabel *label_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *userEdit;
    QLabel *label_2;
    QLineEdit *passworkEdit;
    QPushButton *pushButton;

    void setupUi(QMainWindow *loginWindows)
    {
        if (loginWindows->objectName().isEmpty())
            loginWindows->setObjectName(QString::fromUtf8("loginWindows"));
        loginWindows->resize(600, 400);
        centralWidget = new QWidget(loginWindows);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(200, 270, 93, 28));
        creatBtn = new QPushButton(centralWidget);
        creatBtn->setObjectName(QString::fromUtf8("creatBtn"));
        creatBtn->setGeometry(QRect(330, 270, 93, 28));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 50, 221, 61));
        label_3->setStyleSheet(QString::fromUtf8("font: 22pt \"Adobe \351\273\221\344\275\223 Std R\";"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 140, 301, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        userEdit = new QLineEdit(layoutWidget);
        userEdit->setObjectName(QString::fromUtf8("userEdit"));

        gridLayout->addWidget(userEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passworkEdit = new QLineEdit(layoutWidget);
        passworkEdit->setObjectName(QString::fromUtf8("passworkEdit"));
        passworkEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passworkEdit, 1, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 200, 21, 21));
        pushButton->setStyleSheet(QString::fromUtf8(""));
        loginWindows->setCentralWidget(centralWidget);

        retranslateUi(loginWindows);

        QMetaObject::connectSlotsByName(loginWindows);
    } // setupUi

    void retranslateUi(QMainWindow *loginWindows)
    {
        loginWindows->setWindowTitle(QCoreApplication::translate("loginWindows", "loginWindows", nullptr));
        loginBtn->setText(QCoreApplication::translate("loginWindows", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        loginBtn->setShortcut(QCoreApplication::translate("loginWindows", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        creatBtn->setText(QCoreApplication::translate("loginWindows", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("loginWindows", "\350\266\205\345\270\202\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("loginWindows", "\350\264\246   \345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("loginWindows", "\345\257\206   \347\240\201", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginWindows: public Ui_loginWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOWS_H
