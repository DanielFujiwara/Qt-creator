#include "repairectrl.h"
#include "ui_repairectrl.h"
#include "orderstatus.h"
static int flagdele = 0;
repairectrl::repairectrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::repairectrl)
{
    ui->setupUi(this);
    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    //连接添加信号槽
    connect(this,&repairectrl::sendAddInfo,this,&repairectrl::addNewInfo);

    //给数据库定义一个名称，后缀 .db
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("account.db");


    if(! database.open())
    {
        qDebug()<<"open failed"<<database.lastError();
    }
//    qDebug()<<"database";
    QSqlQuery sqlQuery1;
    sqlQuery = sqlQuery1;

    // 初始化按钮
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
    this->showStatus();

}

repairectrl::~repairectrl()
{
    database.close();
    sqlQuery.clear();
    printf("~repairectrl\n");
    delete ui;
}

void repairectrl::showStatus()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
    // 设置表头
    QStringList header;
      header<<tr("申请人")<<tr("申请时间")<<tr("报修内容")<<tr("订单状态");
      ui->tableWidget->setHorizontalHeaderLabels(header);

      // 数据库读取载入
    QString sqlorder = "SELECT * FROM management;";

    if(!sqlQuery.exec(sqlorder))
    {
          qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else {
         qDebug() << "success";
    }
    int i = 0;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    qDebug() << "success while";
    while( sqlQuery.next())
    {
//        qDebug()<<sqlQuery.value(0)<<sqlQuery.value(1)
//               <<sqlQuery.value(2)<<sqlQuery.value(3)<<sqlQuery.value(4);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(sqlQuery.value(1).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(sqlQuery.value(2).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(sqlQuery.value(3).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(sqlQuery.value(4).toString()));
        ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        i++;
    }
}

void repairectrl::deleTableItem()
{
    if(flagdele == 0)
    {
        return;
    }

    QString deleorder = QString("DELETE FROM management WHERE time = '%1' and info = '").arg(deleinfo.at(0));
    deleorder += deleinfo.at(1);
    deleorder += "';";
//    qDebug()<<deleorder;
//    for(int i = 0;i<deleinfo.size();i++)
//    {
//        qDebug()<<deleinfo.at(i)<<i;
//    }
    if(!sqlQuery.exec(deleorder))
    {
          qDebug() << "Error:Failed to delete record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    flagdele = 0;
    ui->pushButton_3->setEnabled(false);
    deleinfo.clear();
    this->showStatus();
}

void repairectrl::addNewInfo(QString info)
{
    qDebug()<<"called";
//    QString addorder = QString("insert into management(name,time,info,status) values('%1','%2','%3','待接单');").arg(userName).arg(timenew).arg(info);
//    qDebug()<<addorder;
    QString sqlUpdata = QString("UPDATE management SET status ='%1' WHERE time = '%2' and info = '%3';").arg(info).arg(deleinfo.at(0)).arg(deleinfo.at(1));
    qDebug()<<sqlUpdata;
    if(!sqlQuery.exec(sqlUpdata))
    {
          qDebug() << "Error:Failed to add record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    this->showStatus();
}

void repairectrl::on_pushButton_2_clicked()
{
//    addnewrepair *addnew = new addnewrepair(this);
//    addnew->show();
    orderstatus *addnew = new orderstatus(this);
    addnew->show();
}

void repairectrl::on_pushButton_3_clicked()
{


    int ret = QMessageBox::warning(this,"确认","是否删除当前报修申请",QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        this->deleTableItem();
    }
    else {
        deleinfo.clear();
        ui->pushButton_3->setEnabled(false);
        return;
    }
}

void repairectrl::on_pushButton_clicked()
{
//    userwindow *userw = new userwindow;
//    userw->show();
//    connect(userw,&userwindow::sendUserName,userw,&userwindow::setUserName);
//    emit userw->sendUserName(userName);
//    disconnect(weatherman->mTimer,&QTimer::timeout,weatherman,&weatherclock::screenshow);

//    weatherman->close();
//    delete weatherman;
    this->close();
    return;
}

void repairectrl::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    deleinfo.clear();
//    qDebug()<<item->row();
//    QStringList a;
    QString date = ui->tableWidget->item(item->row(),1)->text();
    deleinfo<<date;
    QString info = ui->tableWidget->item(item->row(),2)->text();
    deleinfo<<info;
    QString status = ui->tableWidget->item(item->row(),3)->text();
    deleinfo<<status;
    flagdele = 1;
    ui->pushButton_3->setEnabled(true);
     ui->pushButton_2->setEnabled(true);
}
