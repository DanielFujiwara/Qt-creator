#include "ctrlwidgets.h"
#include "ui_ctrlwidgets.h"

ctrlwidgets::ctrlwidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ctrlwidgets)
{
    ui->setupUi(this);
}

ctrlwidgets::~ctrlwidgets()
{
    delete ui;
}

void ctrlwidgets::setData(QString num1, QString num2, QString num3, QString num4, QString num5)
{
    ui->label_1->setText(num1);
    ui->label_2->setText(num2);
    ui->label_3->setText(num3);
    ui->label_4->setText(num4);
    ui->label_5->setText(num5);


}
