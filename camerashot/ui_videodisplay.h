/********************************************************************************
** Form generated from reading UI file 'videodisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEODISPLAY_H
#define UI_VIDEODISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videodisplay
{
public:
    QLabel *displaytLabel;
    QPushButton *startBtn;
    QPushButton *shotBtn;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *videodisplay)
    {
        if (videodisplay->objectName().isEmpty())
            videodisplay->setObjectName(QStringLiteral("videodisplay"));
        videodisplay->resize(792, 533);
        displaytLabel = new QLabel(videodisplay);
        displaytLabel->setObjectName(QStringLiteral("displaytLabel"));
        displaytLabel->setGeometry(QRect(10, 0, 640, 480));
        startBtn = new QPushButton(videodisplay);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(680, 30, 71, 61));
        shotBtn = new QPushButton(videodisplay);
        shotBtn->setObjectName(QStringLiteral("shotBtn"));
        shotBtn->setGeometry(QRect(670, 170, 93, 28));
        label = new QLabel(videodisplay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 320, 111, 91));
        pushButton = new QPushButton(videodisplay);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 220, 93, 28));

        retranslateUi(videodisplay);

        QMetaObject::connectSlotsByName(videodisplay);
    } // setupUi

    void retranslateUi(QWidget *videodisplay)
    {
        videodisplay->setWindowTitle(QApplication::translate("videodisplay", "videodisplay", 0));
        displaytLabel->setText(QApplication::translate("videodisplay", "TextLabel", 0));
        startBtn->setText(QApplication::translate("videodisplay", "\345\274\200\345\247\213", 0));
        shotBtn->setText(QApplication::translate("videodisplay", "shot", 0));
        label->setText(QApplication::translate("videodisplay", "TextLabel", 0));
        pushButton->setText(QApplication::translate("videodisplay", "view", 0));
    } // retranslateUi

};

namespace Ui {
    class videodisplay: public Ui_videodisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEODISPLAY_H
