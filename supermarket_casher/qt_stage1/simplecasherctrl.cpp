#include "simplecasherctrl.h"
#include "ui_simplecasherctrl.h"
#include "shopitemlist.h"
#include "shopcarvector.h"
#include "billwindow.h"

shopcar shopCarcalss;
goods fileGoods;
goodsVector listGoods;
static int widgetFlag = 0;
static int carFlag = 0;

simplecasherctrl::simplecasherctrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simplecasherctrl)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    workTime = QTime::currentTime();
    ui->timeLabel->setText(workTime.toString("hh:mm:ss"));
    timecount = new QTimer(this);
    connect(timecount,&QTimer::timeout,this,&simplecasherctrl::screenshowTime);
    timecount->setInterval(1000);
    timecount->start();
    QDateTime workData = QDateTime::currentDateTime();
    ui->dataLabel->setText(workData.toString("yyyy-MM-dd"));



    //goods ctrl

    fileGoods.getGoodsData(listGoods.shopList);
//    listGoods.showShopList();
    setListWidgets(listGoods.shopList);



}

simplecasherctrl::~simplecasherctrl()
{
    delete ui;
}

void simplecasherctrl::setCarwidgets()
{
    ui->listWidget_2->clear();
    // ////
    shopitemlist *shopgoodscar = new shopitemlist;
    QListWidgetItem *itemcar = new QListWidgetItem();
    itemcar->setSizeHint(QSize(300,40));
    ui->listWidget_2->addItem(itemcar);
    ui->listWidget_2->setItemWidget(itemcar,shopgoodscar);
//    itemcar->setFlags(itemcar->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoodscar,&shopitemlist::sendData,shopgoodscar,&shopitemlist::setData);
      emit shopgoodscar->sendData("名称","数量","单价","合计");
// ///////////////////////////////////////////////////////////////////////// ///
    // //
    QVector <shopcar>::iterator iter;
    for (iter=shopCarcalss.shopCarList.begin();iter!=shopCarcalss.shopCarList.end();iter++)
       {
        shopitemlist *shopgoods = new shopitemlist;
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(400,40));
        ui->listWidget_2->addItem(item);
        ui->listWidget_2->setItemWidget(item,shopgoods);

//        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
          connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
          emit shopgoods->setData(iter->name,QString::number(iter->num),QString::number(iter->price),QString::number(iter->pPrice));

    }

    double mixprice = 0;
    for (iter=shopCarcalss.shopCarList.begin();iter!=shopCarcalss.shopCarList.end();iter++)
       {
        mixprice += iter->pPrice;

    }
    ui->moneyLabel->setText(QString::number(mixprice));
}

void simplecasherctrl::setID(QString ID)
{
    ui->idLabel->setText(ID);
    IDw = ID;
}

void simplecasherctrl::setListWidgets(QVector<goodsVector> &shopList)
{
    shopitemlist *shopgoods = new shopitemlist;
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(300,40));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,shopgoods);
//    item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
      emit shopgoods->sendData("名称","种类","价格","库存");
// /////////////////////////////////////////////////////////////////////////////
      shopitemlist *shopgoodscar = new shopitemlist;
      QListWidgetItem *itemcar = new QListWidgetItem();
      itemcar->setSizeHint(QSize(300,40));
      ui->listWidget_2->addItem(itemcar);
      ui->listWidget_2->setItemWidget(itemcar,shopgoodscar);
//      itemcar->setFlags(itemcar->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        connect(shopgoodscar,&shopitemlist::sendData,shopgoodscar,&shopitemlist::setData);
        emit shopgoodscar->sendData("名称","数量","单价","合计");
// ///////////////////////////////////////////////////////////////////////// ///
    QVector <goodsVector>::iterator iter;
    for (iter=shopList.begin();iter!=shopList.end();iter++)
       {
        shopitemlist *shopgoods = new shopitemlist;
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(400,40));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,shopgoods);

//        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
          connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
          emit shopgoods->sendData(iter->name,iter->type,iter->price,iter->stock);
    }

}

void simplecasherctrl::on_pushButton_2_clicked()
{
    if(shopCarcalss.shopCarList.isEmpty())
    {
        widgetFlag = 0;
        carFlag = 0;
        this->close();

        QMessageBox::information(this,"注销","注销成功！");
        this->parentWidget()->show();

    }
    else {
        QMessageBox::warning(this,"Woring","购物车尚未清空！");
        return;
    }


}

void simplecasherctrl::screenshowTime()
{
    workTime = QTime::currentTime();
    ui->timeLabel->setText(workTime.toString("hh:mm:ss"));
}



void simplecasherctrl::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QWidget* pwig = ui->listWidget->itemWidget(item);
    namelabel = pwig->findChild<QLabel*>("nameLabel");
    stocklabel = pwig->findChild<QLabel*>("stockLabel");
    pricelabel = pwig->findChild<QLabel*>("priceLabel");
    qDebug()<<namelabel->text();
    qDebug()<<stocklabel->text();
    qDebug()<<pricelabel->text();
//    stocklabel->setText("120");
    widgetFlag = 1;
}

void simplecasherctrl::on_addBtn_clicked()
{
    if(widgetFlag == 0)
    {
        qDebug()<<"nothing";
        return;
    }

    if(namelabel->text() == "名称" && stocklabel->text() == "库存")
    {
        qDebug()<<"wrong chioce";
        widgetFlag = 0;
        return;
    }
    int num = ui->spinBox->text().toInt();
    qDebug()<<num;
    if(num <= 0)
    {
        QMessageBox::warning(this,"Woring","不能不买东西oh");

        return;
    }

    if(num > stocklabel->text().toInt())
    {
        QMessageBox::warning(this,"Woring","没有那么多oh");
        return;
    }

    int oldstock = stocklabel->text().toInt();
    oldstock -= num;
    stocklabel->setText(QString::number(oldstock));
    listGoods.changeTcok(namelabel->text(),oldstock);
    fileGoods.rewriteGoodsToFile(listGoods.shopList);
    qDebug()<<"add file wrote";
    int carret = shopCarcalss.appendNewCargoods(namelabel->text(),num,pricelabel->text().toDouble());
    qDebug()<<"carret:"<<carret;
    setCarwidgets();
//    widgetFlag = 0;




}

void simplecasherctrl::on_pushButton_3_clicked()
{
    widgetFlag = 0;
    carFlag = 0;
    QVector <shopcar>::iterator cariter;
//    QVector<goodsVector>::iterator goodsiter;
//    cariter = shopCarcalss.shopCarList.begin();
    for (cariter =shopCarcalss.shopCarList.begin();cariter != shopCarcalss.shopCarList.end();cariter++) {
        int bougt = cariter->num;
        QString namebought = cariter->name;
        int listloc = listGoods.locaGoods(namebought);
        int stock = listGoods.shopList[listloc].stock.toInt();
        stock += bougt;
        listGoods.changeTcok(namebought,stock);
    }
    ui->listWidget_2->clear();
    ui->listWidget->clear();
    shopCarcalss.shopCarList.clear();
    setListWidgets(listGoods.shopList);
    fileGoods.rewriteGoodsToFile(listGoods.shopList);
    ui->moneyLabel->setText("00.0");
    qDebug()<<"delet all";


}

void simplecasherctrl::on_reduceBtn_clicked()
{
    if(carFlag == 0)
    {
        qDebug()<<"delet err name";
        return;
    }

    if(ui->spinBox->text().toInt() == 0)
    {
        qDebug()<<"nothing delete";
        carFlag = 0;
        return;
    }

    if(ui->spinBox->text().toInt() > numlabelCar->text().toInt())
    {
         QMessageBox::warning(this,"Woring","没有那么多可以删除oh");
         return;
    }

    if(ui->spinBox->text().toInt() < numlabelCar->text().toInt())//减少购物数
    {
       // 修改购物车列表库存以及单个商品合计价
        int old = numlabelCar->text().toInt();
        int sp = ui->spinBox->text().toInt();
        old -= ui->spinBox->text().toInt();
//        int sp = ui->spinBox->text().toInt();
        int ret = shopCarcalss.locaShopcar(namelabelCar->text());
        shopCarcalss.shopCarList[ret].num = old;
        shopCarcalss.shopCarList[ret].pPrice -= (sp * shopCarcalss.shopCarList[ret].price);
        numlabelCar->setText(QString::number(old));
        // 重新计算总价并载入
        QVector <shopcar>::iterator iter;
        double mixprice = 0;
        for (iter=shopCarcalss.shopCarList.begin();iter!=shopCarcalss.shopCarList.end();iter++)
           {
            mixprice += iter->pPrice;

        }
        ui->moneyLabel->setText(QString::number(mixprice));

        // 修改商品列表库存
        int goodsret = listGoods.locaGoods(namelabelCar->text());
        int news = listGoods.shopList[goodsret].stock.toInt();
           news += sp;
//           listGoods.shopList[goodsret].stock = QString::number(news);
        listGoods.changeTcok(namelabelCar->text(),news);

           // /重载商品列表
           QVector<goodsVector> &shopList = listGoods.shopList;
           ui->listWidget->clear();
           shopitemlist *shopgoods = new shopitemlist;
           QListWidgetItem *item = new QListWidgetItem();
           item->setSizeHint(QSize(300,40));
           ui->listWidget->addItem(item);
           ui->listWidget->setItemWidget(item,shopgoods);
//           item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
             connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
             emit shopgoods->sendData("名称","种类","价格","库存");
       // /////////////////////////////////////////////////////////////////////////////

       // ///////////////////////////////////////////////////////////////////////// ///
           QVector <goodsVector>::iterator iter1;
           for (iter1=shopList.begin();iter1 !=shopList.end();iter1++)
              {
               shopitemlist *shopgoods = new shopitemlist;
               QListWidgetItem *item = new QListWidgetItem();
               item->setSizeHint(QSize(400,40));
               ui->listWidget->addItem(item);
               ui->listWidget->setItemWidget(item,shopgoods);

//               item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
                 connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
                 emit shopgoods->sendData(iter1->name,iter1->type,iter1->price,iter1->stock);
           }
            // 写入Json
            fileGoods.rewriteGoodsToFile(listGoods.shopList);
            return;
   }

    if(ui->spinBox->text().toInt() == numlabelCar->text().toInt())//删除购物车商品
        {
        // 修改购物车列表库存以及单个商品合计价
         int sp = ui->spinBox->text().toInt();
         int cargoods = shopCarcalss.locaShopcar(namelabelCar->text());
         shopCarcalss.shopCarList.remove(cargoods);
         setCarwidgets();


         // 修改商品列表库存
         int goodsret = listGoods.locaGoods(namelabelCar->text());
         int news = listGoods.shopList[goodsret].stock.toInt();
            news += sp;
 //           listGoods.shopList[goodsret].stock = QString::number(news);
         listGoods.changeTcok(namelabelCar->text(),news);

            // /重载商品列表
            QVector<goodsVector> &shopList = listGoods.shopList;
            ui->listWidget->clear();
            shopitemlist *shopgoods = new shopitemlist;
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(300,40));
            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item,shopgoods);
//            item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
              connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
              emit shopgoods->sendData("名称","种类","价格","库存");
        // /////////////////////////////////////////////////////////////////////////////

        // ///////////////////////////////////////////////////////////////////////// ///
            QVector <goodsVector>::iterator iter1;
            for (iter1=shopList.begin();iter1 !=shopList.end();iter1++)
               {
                shopitemlist *shopgoods = new shopitemlist;
                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(400,40));
                ui->listWidget->addItem(item);
                ui->listWidget->setItemWidget(item,shopgoods);

//                item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
                  connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
                  emit shopgoods->sendData(iter1->name,iter1->type,iter1->price,iter1->stock);
            }
             // 写入Json
             fileGoods.rewriteGoodsToFile(listGoods.shopList);
             return;
    }

}

void simplecasherctrl::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    QWidget* pwig = ui->listWidget_2->itemWidget(item);
    namelabelCar = pwig->findChild<QLabel*>("nameLabel");
    ppricelabelCar = pwig->findChild<QLabel*>("stockLabel");
    pricelabelCar = pwig->findChild<QLabel*>("priceLabel");
    numlabelCar = pwig->findChild<QLabel*>("typeLabel");
    qDebug()<<namelabelCar->text();
    qDebug()<<numlabelCar->text();
    qDebug()<<ppricelabelCar->text();
    carFlag = 1;
    if(namelabelCar->text() == "名称")
    {
        carFlag = 0;
    }
    qDebug()<<carFlag;
}

void simplecasherctrl::on_pushButton_4_clicked()
{
    if(shopCarcalss.shopCarList.isEmpty())
    {
       widgetFlag = 0;
       carFlag = 0;
        this->close();
        QString off = "工号：";
        off += IDw;
        off += "  下班时间：";
        off += workTime.toString("hh:mm:ss");

        QMessageBox::information(this,"下班",off);
        this->parentWidget()->show();

    }
    else {
        QMessageBox::warning(this,"Woring","购物车尚未清空！");
        return;
    }
}

void simplecasherctrl::on_pushButton_clicked()
{
    widgetFlag = 0;
    carFlag = 0;

    if(shopCarcalss.shopCarList.isEmpty())
    {


        QMessageBox::warning(this,"wrong","购物车为空");
        return;

    }


    billwindow *bye = new billwindow(this);
    connect(bye,&billwindow::sendMylist,bye,&billwindow::getMylist);
    emit bye->sendMylist(shopCarcalss.shopCarList,IDw);
    bye->show();

    ui->listWidget_2->clear();
    shopitemlist *shopgoodscar = new shopitemlist;
    QListWidgetItem *itemcar = new QListWidgetItem();
    itemcar->setSizeHint(QSize(300,40));
    ui->listWidget_2->addItem(itemcar);
    ui->listWidget_2->setItemWidget(itemcar,shopgoodscar);
//    itemcar->setFlags(itemcar->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoodscar,&shopitemlist::sendData,shopgoodscar,&shopitemlist::setData);
      emit shopgoodscar->sendData("名称","数量","单价","合计");
      shopCarcalss.shopCarList.clear();
      ui->moneyLabel->setText("00.0");
      qDebug()<<"clear";
}
