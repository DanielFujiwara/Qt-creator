#include "adminctrl.h"
#include "ui_adminctrl.h"
#include "goods.h"
#include "filejson.h"
#include "ctrlwidgets.h"
#include "addgoodwindow.h"
#include "addnewuserwindow.h"
#include "billcheck.h"
#include "rewriteinfo.h"
#include "userchangeinfo.h"
//shopcar shopCarcalss;
goods fileGoodsa;
goodsVector listGoodsa;
fileJson userjson;
static int btnmodel = 0;
static int flag = 0;
static int clickflag = 0;

adminctrl::adminctrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminctrl)
{
    ui->setupUi(this);
    fileGoodsa.getGoodsData(listGoodsa.shopList);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
//    listGoods.showShopList();
//    setListWidgets(listGoods.shopList);
    workTime = QTime::currentTime();
    ui->label_3->setText(workTime.toString("hh:mm:ss"));
    timecount = new QTimer(this);
    connect(timecount,&QTimer::timeout,this,&adminctrl::screenshowTime);
    timecount->setInterval(1000);
    timecount->start();
    QDateTime workData = QDateTime::currentDateTime();
    ui->label_2->setText(workData.toString("yyyy-MM-dd"));
    connect(ui->listWidget,&QListWidget::itemDoubleClicked,this,&adminctrl::DoubleClicked);
}

adminctrl::~adminctrl()
{
    delete ui;
}

void adminctrl::showGOODStoWi()
{
    ui->listWidget->clear();
    // ////
    ctrlwidgets *shopgoodslist = new ctrlwidgets;
    QListWidgetItem *itemgood = new QListWidgetItem();
    itemgood->setSizeHint(QSize(750,60));
    ui->listWidget->addItem(itemgood);
    ui->listWidget->setItemWidget(itemgood,shopgoodslist);
//    itemgood->setFlags(itemgood->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoodslist,&ctrlwidgets::sendData,shopgoodslist,&ctrlwidgets::setData);
      emit shopgoodslist->sendData("名称","种类","成本","单价","库存");

      QVector <goodsVector>::iterator iter;
      for (iter=listGoodsa.shopList.begin();iter!=listGoodsa.shopList.end();iter++)
         {
          ctrlwidgets *shopgoodslist = new ctrlwidgets;
          QListWidgetItem *itemgood = new QListWidgetItem();
          itemgood->setSizeHint(QSize(750,60));
          ui->listWidget->addItem(itemgood);
          ui->listWidget->setItemWidget(itemgood,shopgoodslist);

//          itemgood->setFlags(itemgood->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
            connect(shopgoodslist,&ctrlwidgets::sendData,shopgoodslist,&ctrlwidgets::setData);
            emit shopgoodslist->sendData(iter->name,iter->type,iter->cost,iter->price,iter->stock);
      }




}

void adminctrl::showUSERStoWi()
{
    ui->listWidget->clear();
    // ////
    ctrlwidgets *shopgoodslist = new ctrlwidgets;
    QListWidgetItem *itemgood = new QListWidgetItem();
    itemgood->setSizeHint(QSize(750,60));
    ui->listWidget->addItem(itemgood);
    ui->listWidget->setItemWidget(itemgood,shopgoodslist);
//    itemgood->setFlags(itemgood->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoodslist,&ctrlwidgets::sendData,shopgoodslist,&ctrlwidgets::setData);
      emit shopgoodslist->sendData("户名","身份","ID","密码","");

      userjson.reloadJDOdata();
      QJsonArray userdata = userjson.fileJOdata.value("userdata").toArray();
      for(int i = 0 ;i<userdata.size();i++)
      {
          QJsonObject nameInside = userdata.at(i).toObject();
          QString namea = nameInside.value("name").toString();
          QString flaga = nameInside.value("flag").toString();
          QString ida = nameInside.value("id").toString();
          QString passworka = nameInside.value("passwork").toString();

          ctrlwidgets *shopgoodslist = new ctrlwidgets;
          QListWidgetItem *itemgood = new QListWidgetItem();
          itemgood->setSizeHint(QSize(750,60));
          ui->listWidget->addItem(itemgood);
          ui->listWidget->setItemWidget(itemgood,shopgoodslist);
      //    itemgood->setFlags(itemgood->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
            connect(shopgoodslist,&ctrlwidgets::sendData,shopgoodslist,&ctrlwidgets::setData);
            emit shopgoodslist->sendData(namea,flaga,ida,passworka,"");
      }


}

void adminctrl::setreshow()
{
    if(btnmodel == 0)
    {

        qDebug()<<"刷新商品";



        fileGoodsa.rewriteGoodsToFile(listGoodsa.shopList);
        fileGoodsa.getGoodsData(listGoodsa.shopList);
        showGOODStoWi();


    }
    else {

            qDebug()<<"刷新员工";
            showUSERStoWi();
    }
}

void adminctrl::screenshowTime()
{
    workTime = QTime::currentTime();
    ui->label_3->setText(workTime.toString("hh:mm:ss"));
}

void adminctrl::on_lodingBtn_clicked()
{
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);

    flag++;
    btnmodel = flag%2;
    if(btnmodel == 0)
    {
        showGOODStoWi();
        ui->lodingBtn->setText("账户管理");
    }
    else{
        showUSERStoWi();
        ui->lodingBtn->setText("商品管理");
    }
}

void adminctrl::DoubleClicked(QListWidgetItem *item)
{
    qDebug()<<btnmodel;
    if(btnmodel == 0)
    {
        QWidget* pwig = ui->listWidget->itemWidget(item);
        namelabel = pwig->findChild<QLabel*>("label_1");
        typelabel = pwig->findChild<QLabel*>("label_2");
        costlabel = pwig->findChild<QLabel*>("label_3");
        pricelabel = pwig->findChild<QLabel*>("label_4");
        stocklabel = pwig->findChild<QLabel*>("label_5");
        qDebug()<<namelabel->text()<<typelabel->text()<<
                  costlabel->text()<<pricelabel->text()<<stocklabel->text();
        rewriteinfo *cnew = new rewriteinfo(this);
        connect(cnew,&rewriteinfo::sendclass,cnew,&rewriteinfo::getclass);
        connect(cnew,&rewriteinfo::sendreloda,this,&adminctrl::setreshow);
        emit cnew->sendclass(fileGoodsa,namelabel->text(),listGoodsa.shopList,listGoodsa);
        cnew->show();

    }
    else {
            QWidget* pwig = ui->listWidget->itemWidget(item);
            unamelabel = pwig->findChild<QLabel*>("label_1");
            flaglabel = pwig->findChild<QLabel*>("label_2");
            idlabel = pwig->findChild<QLabel*>("label_3");
             passworklabel = pwig->findChild<QLabel*>("label_4");
             qDebug()<<unamelabel->text()<<flaglabel->text()<<
                       idlabel->text()<<passworklabel->text();

             userchangeinfo *cnew = new userchangeinfo(this);

             connect(cnew,&userchangeinfo::sendclasstome,cnew,&userchangeinfo::setclasstome);
             connect(cnew,&userchangeinfo::sendreshow,this,&adminctrl::setreshow);

             emit cnew->sendclasstome(unamelabel->text());


             cnew->show();
    }
}


void adminctrl::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug()<<"clicked";
    if(btnmodel == 0)
    {
        QWidget* pwig = ui->listWidget->itemWidget(item);
        namelabel = pwig->findChild<QLabel*>("label_1");
        typelabel = pwig->findChild<QLabel*>("label_2");
        costlabel = pwig->findChild<QLabel*>("label_3");
        pricelabel = pwig->findChild<QLabel*>("label_4");
        stocklabel = pwig->findChild<QLabel*>("label_5");
        qDebug()<<namelabel->text()<<typelabel->text()<<
                  costlabel->text()<<pricelabel->text()<<stocklabel->text();
    }
    else {
            QWidget* pwig = ui->listWidget->itemWidget(item);
            unamelabel = pwig->findChild<QLabel*>("label_1");
            flaglabel = pwig->findChild<QLabel*>("label_2");
            idlabel = pwig->findChild<QLabel*>("label_3");
             passworklabel = pwig->findChild<QLabel*>("label_4");
             qDebug()<<unamelabel->text()<<flaglabel->text()<<
                       idlabel->text()<<passworklabel->text();
    }
    clickflag = 1;
}

void adminctrl::on_pushButton_3_clicked()
{
   if(clickflag == 0)
   {
       qDebug()<<"nothing ";
        clickflag = 0;
       return;
   }

    if(btnmodel == 0)
    {
        if(namelabel->text() == "名称")
            {
            qDebug()<<"can't delete title";
             clickflag = 0;
            return;
        }

        int ret = listGoodsa.locaGoods(namelabel->text());
        listGoodsa.removeGoods(ret);
        fileGoodsa.rewriteGoodsToFile(listGoodsa.shopList);
        showGOODStoWi();
        fileGoodsa.getGoodsData(listGoodsa.shopList);
        clickflag = 0;



    }
    else {

        if(unamelabel->text() == "户名")
            {
            qDebug()<<"can't delete title";
            clickflag = 0;
            return;
        }

//        int ret = userjson.locaUsername(unamelabel->text());
        userjson.deletAcount(unamelabel->text());
        showUSERStoWi();
        clickflag = 0;


    }
}

void adminctrl::on_pushButton_4_clicked()
{
    if(btnmodel == 0)
    {

        qDebug()<<"添加商品";


        addgoodwindow *addnew = new addgoodwindow(this);
        connect(addnew,&addgoodwindow::sendclass,addnew,&addgoodwindow::getclass);
        connect(addnew,&addgoodwindow::sendreshow,this,&adminctrl::setreshow);
        emit addnew->sendclass(listGoodsa.shopList,listGoodsa);

        addnew->show();



    }
    else {

            qDebug()<<"添加员工";
            addnewuserwindow *addnew = new addnewuserwindow(this);
            connect(addnew,&addnewuserwindow::sendclasstome,addnew,&addnewuserwindow::setclasstome);
            connect(addnew,&addnewuserwindow::sendreshow,this,&adminctrl::setreshow);
            emit addnew->sendclasstome(userjson);
            addnew->show();
        }

}

void adminctrl::on_pushButton_2_clicked()
{
    exit(0);
}

void adminctrl::on_pushButton_clicked()
{
    billcheck *newbill = new billcheck(this);
    newbill->show();
    return;
}

void adminctrl::on_pushButton_5_clicked()
{
    this->close();
    this->parentWidget()->show();
}
