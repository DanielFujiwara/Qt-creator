#include "orderstatus.h"
#include "ui_orderstatus.h"
#include "repairectrl.h"
orderstatus::orderstatus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::orderstatus)
{
    ui->setupUi(this);
}

orderstatus::~orderstatus()
{
    printf("~orderstatus\n");
    delete ui;
}

void orderstatus::on_pushButton_clicked()
{
    repairectrl*ptr;
   ptr =  static_cast<repairectrl*>(this->parent());

   emit ptr->sendAddInfo(ui->comboBox->currentText());
   this->close();
   return;
}

void orderstatus::on_pushButton_2_clicked()
{
    this->close();
    return;
}
