#ifndef GOODS_H
#define GOODS_H
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
//#include <QDateTime>
//#include <QDir>
#include <QVector>
//#include "simplecasherctrl.h"

//管理商品列表
class goodsVector :public QVector<goodsVector>{

public:

    goodsVector(QString name=nullptr,QString cost=nullptr,QString price=nullptr,QString type=nullptr,QString stock=nullptr):
        name(name),cost(cost),price(price),type(type),stock(stock){qDebug()<<"goods push";}
    void showShopList();//展示
    //增加商品
    void apendNewGoods(QString name=nullptr,QString cost=nullptr,QString price=nullptr,QString type=nullptr,QString stock=nullptr);
    int locaGoods(QString name);//查找商品所在位置
    int removeGoods(int i);//删除商品
    int soldTock(QString name,int sold);//卖出库存修改
    int changeTcok(QString name,int t);//修改库存
    int changeCost(QString name,double t);//修改成本
    int changePrice(QString name,double t);//修改售价
    ~goodsVector(){
        qDebug()<<"goodsVector~";
    }
    QVector<goodsVector> shopList;

//private:
    QString name;
    QString cost;
    QString price;
    QString type;
    QString stock;


};
//管理商品Json文件

class goods
{
public:
    goods();
    void getGoodsData(QVector<goodsVector>& shopList);
    void rewriteGoodsToFile(QVector<goodsVector>& shopList);
private:

    QJsonDocument fileJDdata;
    QJsonObject fileJOdata;
    QJsonArray goodsArray;

};

#endif // GOODS_H
