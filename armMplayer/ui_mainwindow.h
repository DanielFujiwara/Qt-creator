/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *datalabel;
    QLabel *label;
    QLabel *timelabel;
    QLabel *typelabel;
    QLabel *guangzhoulabel;
    QLabel *temlabel;
    QLabel *direlabel;
    QLabel *winplabel;
    QLabel *infolabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        datalabel = new QLabel(centralWidget);
        datalabel->setObjectName(QStringLiteral("datalabel"));
        datalabel->setGeometry(QRect(630, 30, 171, 41));
        datalabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\" color(255,255,255);\n"
""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 620, 413));
        label->setStyleSheet(QStringLiteral("background-color: rgb(231, 255, 202);"));
        timelabel = new QLabel(centralWidget);
        timelabel->setObjectName(QStringLiteral("timelabel"));
        timelabel->setGeometry(QRect(660, 80, 131, 41));
        timelabel->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\" color(255,255,255);\n"
""));
        typelabel = new QLabel(centralWidget);
        typelabel->setObjectName(QStringLiteral("typelabel"));
        typelabel->setGeometry(QRect(10, 420, 781, 51));
        typelabel->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        guangzhoulabel = new QLabel(centralWidget);
        guangzhoulabel->setObjectName(QStringLiteral("guangzhoulabel"));
        guangzhoulabel->setGeometry(QRect(630, 260, 71, 41));
        guangzhoulabel->setStyleSheet(QStringLiteral(""));
        temlabel = new QLabel(centralWidget);
        temlabel->setObjectName(QStringLiteral("temlabel"));
        temlabel->setGeometry(QRect(690, 300, 71, 41));
        temlabel->setStyleSheet(QStringLiteral(""));
        direlabel = new QLabel(centralWidget);
        direlabel->setObjectName(QStringLiteral("direlabel"));
        direlabel->setGeometry(QRect(690, 330, 91, 41));
        direlabel->setStyleSheet(QStringLiteral(""));
        winplabel = new QLabel(centralWidget);
        winplabel->setObjectName(QStringLiteral("winplabel"));
        winplabel->setGeometry(QRect(690, 360, 71, 41));
        winplabel->setStyleSheet(QStringLiteral(""));
        infolabel = new QLabel(centralWidget);
        infolabel->setObjectName(QStringLiteral("infolabel"));
        infolabel->setGeometry(QRect(690, 390, 71, 41));
        infolabel->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        datalabel->setText(QApplication::translate("MainWindow", "yyyy\345\271\264mm\346\234\210dd\346\227\245", 0));
        label->setText(QString());
        timelabel->setText(QApplication::translate("MainWindow", "00:00:00", 0));
        typelabel->setText(QApplication::translate("MainWindow", "\345\265\214\345\205\245\345\274\217\345\271\277\345\221\212\344\275\215\347\275\256\345\207\272\347\247\237 13249252445 \344\275\225\350\224\232", 0));
        guangzhoulabel->setText(QApplication::translate("MainWindow", "\345\271\277\345\267\236", 0));
        temlabel->setText(QApplication::translate("MainWindow", "tem", 0));
        direlabel->setText(QApplication::translate("MainWindow", "winddiret", 0));
        winplabel->setText(QApplication::translate("MainWindow", "winp", 0));
        infolabel->setText(QApplication::translate("MainWindow", "info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
