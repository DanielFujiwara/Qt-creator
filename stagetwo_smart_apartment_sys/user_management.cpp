#include "user_management.h"
#include "ui_user_management.h"
#include <QDate>
#include <QTime>
#include "addnewrepair.h"
#include "userwindow.h"
static int flagdele = 0;
user_management::user_management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user_management)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QSQLITE");

    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    //连接添加信号槽
    connect(this,&user_management::sendAddInfo,this,&user_management::addNewInfo);

    //给数据库定义一个名称，后缀 .db
    database.setDatabaseName("account.db");

    if(! database.open())
    {
        qDebug()<<"open failed"<<database.lastError();
    }
//    qDebug()<<"database";
    QSqlQuery sqlQuery1;
    sqlQuery = sqlQuery1;

    //天气模块
    weatherman = new weatherclock(this);
    weatherman->move(600,0);
    weatherman->show();
    weatherman->whatTime();
    connect(weatherman->mTimer,&QTimer::timeout,weatherman,&weatherclock::screenshow);

    // 初始化按钮
        ui->pushButton_3->setEnabled(false);

}

user_management::~user_management()
{
    database.close();
    sqlQuery.clear();
    printf("~user_management\n");
    delete ui;
}

void user_management::showStatus()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
    // 设置表头
    QStringList header;
      header<<tr("申请人")<<tr("申请时间")<<tr("报修内容")<<tr("订单状态");
      ui->tableWidget->setHorizontalHeaderLabels(header);

      // 数据库读取载入
    QString sqlorder = QString("SELECT * FROM management where name = '%1';").arg(userName);

    if(!sqlQuery.exec(sqlorder))
    {
          qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    int i = 0;
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
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

void user_management::setMyUserName(QString name)
{
    userName = name;
//    qDebug()<<userName<<"here";
    this->showStatus();
}

void user_management::deleTableItem()
{
    if(flagdele == 0)
    {
        return;
    }

    QString deleorder = QString("DELETE FROM management WHERE name = '%1' "
                                "and time = '%2' and info = '").arg(userName).arg(deleinfo.at(0));
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

void user_management::addNewInfo(QString info)
{
    QDate daten=QDate::currentDate();
    QString timenew = daten.toString("yyyy-MM-dd");
    QTime timen = QTime::currentTime();
    timenew += " ";
    timenew += timen.toString("hh:mm:ss");
//    qDebug()<<timenew;
    // 拼接添加命令
    QString addorder = QString("insert into management(name,time,info,status) values('%1','%2','%3','待接单');").arg(userName).arg(timenew).arg(info);
//    qDebug()<<addorder;

    if(!sqlQuery.exec(addorder))
    {
          qDebug() << "Error:Failed to add record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    this->showStatus();

}

void user_management::on_tableWidget_itemClicked(QTableWidgetItem *item)
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

}

void user_management::on_pushButton_3_clicked()
{
    if(deleinfo.at(2) != "待接单")
        {
        QMessageBox::warning(this,"提醒","当前订单已接单，暂时无法取消！");
        flagdele = 0;
        deleinfo.clear();
        ui->pushButton_3->setEnabled(false);
        return;
    }

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

void user_management::on_pushButton_2_clicked()
{
//    this->addNewInfo("灯");
    addnewrepair *addnew = new addnewrepair(this);
    addnew->show();
}

void user_management::on_pushButton_clicked()
{
    userwindow *userw = new userwindow;
    userw->show();
    connect(userw,&userwindow::sendUserName,userw,&userwindow::setUserName);
    emit userw->sendUserName(userName);
    disconnect(weatherman->mTimer,&QTimer::timeout,weatherman,&weatherclock::screenshow);

//    weatherman->close();
//    delete weatherman;
    this->close();
    return;
}
