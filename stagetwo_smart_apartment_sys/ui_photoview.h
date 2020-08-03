/********************************************************************************
** Form generated from reading UI file 'photoview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOVIEW_H
#define UI_PHOTOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_photoview
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *photoview)
    {
        if (photoview->objectName().isEmpty())
            photoview->setObjectName(QStringLiteral("photoview"));
        photoview->resize(800, 480);
        centralwidget = new QWidget(photoview);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 141, 401));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 610, 450));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 430, 93, 28));
        photoview->setCentralWidget(centralwidget);

        retranslateUi(photoview);

        QMetaObject::connectSlotsByName(photoview);
    } // setupUi

    void retranslateUi(QMainWindow *photoview)
    {
        photoview->setWindowTitle(QApplication::translate("photoview", "MainWindow", 0));
        label->setText(QApplication::translate("photoview", "TextLabel", 0));
        pushButton->setText(QApplication::translate("photoview", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class photoview: public Ui_photoview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOVIEW_H
