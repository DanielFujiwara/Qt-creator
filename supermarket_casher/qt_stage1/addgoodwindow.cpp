#include "addgoodwindow.h"
#include "ui_addgoodwindow.h"

addgoodwindow::addgoodwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addgoodwindow)
{
    ui->setupUi(this);
    ui->sureBtn->setEnabled(false);
}

addgoodwindow::~addgoodwindow()
{
    delete ui;
}
void addgoodwindow::getclass(QVector<goodsVector> &shopList,goodsVector &changeclasss)
{

    shopListnew = &shopList;
    changeclass = &changeclasss;
}


void addgoodwindow::on_userEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addgoodwindow::on_typeEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addgoodwindow::on_costEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addgoodwindow::on_priceEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addgoodwindow::on_stockEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}



void addgoodwindow::on_sureBtn_clicked()
{
    QString name = ui->userEdit->text();
    QString cost = ui->costEdit->text();
    QString price = ui->priceEdit->text();
    QString stock = ui->stockEdit->text();
    QString type = ui->typeEdit->text();
   int ret =  changeclass->locaGoods(name);
   if(ret != -1)
   {
       QMessageBox::warning(this,"Woring","已经存在此商品");
       return;
   }

   changeclass->apendNewGoods(name,cost,price,type,stock);
    emit this->sendreshow();
   this->close();


}

void addgoodwindow::on_cancleBtn_clicked()
{
    this->close();
}
