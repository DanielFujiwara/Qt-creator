#include "addnewrepair.h"
#include "ui_addnewrepair.h"
#include "user_management.h"
addnewrepair::addnewrepair(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addnewrepair)
{
    ui->setupUi(this);
}

addnewrepair::~addnewrepair()
{
    printf("~addnewrepair\n");
    delete ui;
}

void addnewrepair::on_pushButton_clicked()
{
     user_management*ptr;
    ptr =  static_cast<user_management*>(this->parent());

    emit ptr->sendAddInfo(ui->comboBox->currentText());
    this->close();
    return;
}

void addnewrepair::on_pushButton_2_clicked()
{
    this->close();
    return;
}
