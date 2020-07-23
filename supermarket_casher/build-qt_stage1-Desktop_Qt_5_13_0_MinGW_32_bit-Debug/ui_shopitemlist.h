/********************************************************************************
** Form generated from reading UI file 'shopitemlist.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPITEMLIST_H
#define UI_SHOPITEMLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shopitemlist
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *stockLabel;
    QLabel *nameLabel;
    QLabel *priceLabel;
    QLabel *typeLabel;

    void setupUi(QWidget *shopitemlist)
    {
        if (shopitemlist->objectName().isEmpty())
            shopitemlist->setObjectName(QString::fromUtf8("shopitemlist"));
        shopitemlist->resize(400, 40);
        layoutWidget = new QWidget(shopitemlist);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 383, 22));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stockLabel = new QLabel(layoutWidget);
        stockLabel->setObjectName(QString::fromUtf8("stockLabel"));
        stockLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        stockLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(stockLabel, 0, 3, 1, 1);

        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        nameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        priceLabel = new QLabel(layoutWidget);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        priceLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(priceLabel, 0, 2, 1, 1);

        typeLabel = new QLabel(layoutWidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        typeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(typeLabel, 0, 1, 1, 1);


        retranslateUi(shopitemlist);

        QMetaObject::connectSlotsByName(shopitemlist);
    } // setupUi

    void retranslateUi(QWidget *shopitemlist)
    {
        shopitemlist->setWindowTitle(QCoreApplication::translate("shopitemlist", "Form", nullptr));
        stockLabel->setText(QCoreApplication::translate("shopitemlist", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("shopitemlist", "TextLabel", nullptr));
        priceLabel->setText(QCoreApplication::translate("shopitemlist", "TextLabel", nullptr));
        typeLabel->setText(QCoreApplication::translate("shopitemlist", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shopitemlist: public Ui_shopitemlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPITEMLIST_H
