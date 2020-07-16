#include "billwindow.h"
#include "ui_billwindow.h"
#include <QTextCodec>
void billwindow::getMylist(QVector<shopcar> & shopCarList,QString ids)
{
    shopitemlist *shopgoodscar = new shopitemlist;
    QListWidgetItem *itemcar = new QListWidgetItem();
    itemcar->setSizeHint(QSize(300,40));
    ui->listWidget->addItem(itemcar);
    ui->listWidget->setItemWidget(itemcar,shopgoodscar);
    itemcar->setFlags(itemcar->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
      connect(shopgoodscar,&shopitemlist::sendData,shopgoodscar,&shopitemlist::setData);
      emit shopgoodscar->sendData("名称","数量","单价","合计");
// ///////////////////////////////////////////////////////////////////////// ///

      double mixprice = 0;
    QVector <shopcar>::iterator iter;
    for (iter=shopCarList.begin();iter!=shopCarList.end();iter++)
       {
        shopitemlist *shopgoods = new shopitemlist;
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(400,40));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,shopgoods);

        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
          connect(shopgoods,&shopitemlist::sendData,shopgoods,&shopitemlist::setData);
          emit shopgoods->setData(iter->name,QString::number(iter->num),QString::number(iter->price),QString::number(iter->pPrice));
             mixprice += iter->pPrice;
    }
    ui->moneyLabel->setText(QString::number(mixprice));

    QFile file;
    file.setFileName("../sold.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text)) {
            qDebug() << "File open error";
        } else {
            qDebug() <<"File open!";
        }
    QString casher = "工号：";
    casher += ids;

    QTime tm = QTime::currentTime();
    QDateTime td = QDateTime::currentDateTime();
    QString opo = QString("%1 \n日期：%2 %3\n").arg(casher).arg(td.toString("yyyy-MM-dd")).arg(tm.toString("hh:mm:ss"));
    file.write(opo.toUtf8());

//    QTextStream out(&file);
//    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
//    out.setCodec(codec);
//    out <<endl;
    for (iter=shopCarList.begin();iter!=shopCarList.end();iter++)
       {
//        out<< iter->name<<" 数量："<<iter->num<<" 小计："<<iter->pPrice<<"元"<<endl;
        QString str = QString("%1 数量：%2 小计: %3 元\n").arg(iter->name).arg(iter->num).arg(iter->pPrice);
          file.write(str.toUtf8());
    }
//    out<<""<<mixprice<<""<<endl<<endl;
       QString mix = QString("合计：%1 元\n\n").arg(mixprice);
       file.write(mix.toUtf8());
    file.close();
    qDebug()<<"sold file wrote";


}

billwindow::billwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::billwindow)
{
    ui->setupUi(this);
}

billwindow::~billwindow()
{
    delete ui;
}

void billwindow::on_pushButton_clicked()
{
    this->close();
}
