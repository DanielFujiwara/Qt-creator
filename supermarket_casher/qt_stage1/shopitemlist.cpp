#include "shopitemlist.h"
#include "ui_shopitemlist.h"

shopitemlist::shopitemlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shopitemlist)
{
    ui->setupUi(this);
}

shopitemlist::~shopitemlist()
{
    delete ui;
}

void shopitemlist::setData(QString name,QString type, QString price, QString stock)
{
    qDebug()<<"set";
    ui->nameLabel->setText(name);
    ui->typeLabel->setText(type);
    ui->priceLabel->setText(price);
    ui->stockLabel->setText(stock);

}
