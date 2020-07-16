#ifndef SHOPCARVECTOR_H
#define SHOPCARVECTOR_H
#include <QString>
#include <QDebug>
#include <QFile>
//#include <QDateTime>
//#include <QDir>
#include <QVector>

class shopcar:public QVector<shopcar>
{
public:
    shopcar(QString name=nullptr,int num=0,double price=0);
    QVector<shopcar> shopCarList;
    int deleteShopcar(QString name,int &num,double &price,double &pPriced);//删除购物车商品
    int locaShopcar(QString name);//定位商品所在位置
    int appendNewCargoods(QString name,int num,double price);
    void showShopCar();
    ~shopcar(){
        qDebug()<<"shopcar~";
    }


    QString name;
    int num;
    double price;
    double pPrice;



};



#endif // SHOPCARVECTOR_H
