#include "rewriteinfo.h"
#include "ui_rewriteinfo.h"

rewriteinfo::rewriteinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rewriteinfo)
{
    ui->setupUi(this);
    ui->sureBtn->setEnabled(false);

}

rewriteinfo::~rewriteinfo()
{
    delete ui;
}

void rewriteinfo::getclass(goods &fileclasss,QString name, QVector<goodsVector> &shopList, goodsVector &changeclasss)
{
    namec = name;
    shopListc = &shopList;
    changeclass = &changeclasss;
    fileclass = &fileclasss;
    int ret = changeclasss.locaGoods(name);
    ui->nameEdit->setText(name);
    QVector <goodsVector>::iterator iter;
    iter = shopListc->begin();
    ui->typeEdit->setText(iter[ret].type);
    ui->costEdit->setText(iter[ret].cost);
    ui->priceEdit->setText(iter[ret].price);
    ui->stockEdit->setText(iter[ret].stock);



}

void rewriteinfo::on_nameEdit_textChanged(const QString &arg1)
{
    if(ui->nameEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }

    if(ui->nameEdit->text() != namec)

    {
        QMessageBox::warning(this,"Woring","不想你修改名字");

        int ret = changeclass->locaGoods(namec);
        ui->nameEdit->setText(namec);
        QVector <goodsVector>::iterator iter;
        iter = shopListc->begin();
        ui->typeEdit->setText(iter[ret].type);
        return;
    }
    return;
}

void rewriteinfo::on_typeEdit_textChanged(const QString &arg1)
{
    if(ui->nameEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }

    int ret = changeclass->locaGoods(namec);
    QVector <goodsVector>::iterator iter;
    iter = shopListc->begin();
    if(ui->typeEdit->text() != iter[ret].type)

    {
        QMessageBox::warning(this,"Woring","不想你修改种类");


        ui->nameEdit->setText(namec);

        ui->typeEdit->setText(iter[ret].type);
        return;
    }



}

void rewriteinfo::on_costEdit_textChanged(const QString &arg1)
{
    if(ui->nameEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void rewriteinfo::on_priceEdit_textChanged(const QString &arg1)
{
    if(ui->nameEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void rewriteinfo::on_stockEdit_textChanged(const QString &arg1)
{
    if(ui->nameEdit->text() != "" &&
            ui->costEdit->text() != "" &&
            ui->typeEdit->text() != "" &&
            ui->priceEdit->text() != "" &&
            ui->stockEdit->text() != "")
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void rewriteinfo::on_sureBtn_clicked()
{
    changeclass->changeTcok(namec,ui->stockEdit->text().toInt());
    changeclass->changeCost(namec,ui->costEdit->text().toDouble());
    changeclass->changePrice(namec,ui->priceEdit->text().toDouble());
    fileclass->rewriteGoodsToFile(changeclass->shopList);
    fileclass->getGoodsData(changeclass->shopList);
    emit sendreloda();
    this->close();
}

void rewriteinfo::on_cancleBtn_clicked()
{
    this->close();
}
