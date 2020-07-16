#include "shopcarvector.h"



shopcar::shopcar(QString name, int num, double price):name(name),num(num),price(price)
{
    pPrice = num*price;
    qDebug()<<"shopcar push";
}

int shopcar::deleteShopcar(QString name,int &numd,double &priced,double &pPriced)
{
    int ret = locaShopcar(name);
    if(ret == -1)
    {
        qDebug()<<"delete error";
        return -1;
    }
    numd = shopCarList[ret].num;
    priced = shopCarList[ret].price;
    pPriced = shopCarList[ret].pPrice;
    shopCarList.remove(ret);
    qDebug()<<"delete successed";
    return 0;

}

int shopcar::locaShopcar(QString name)
{
    int i = 0;
    QVector <shopcar>::iterator iter;
    for (iter=shopCarList.begin();iter!=shopCarList.end();iter++)
       {
           if(iter->name == name)
           {
               qDebug()<<name<<"is located car";
               return i;
           }
           else {
               i++;
               continue;
           }
    }

    qDebug()<<"can't located car goods";
    return -1;
}

int shopcar::appendNewCargoods(QString namen, int numn, double pricen)
{
    int ret = locaShopcar(namen);
    if(ret != -1)
    {

        shopCarList[ret].num += numn;
        shopCarList[ret].pPrice = shopCarList[ret].pPrice + (numn*pricen);
        qDebug()<<"add successed";
        return 2;
    }
    else if (ret == -1) {
        shopcar buf(namen,numn,pricen);
        shopCarList.append(buf);
        qDebug()<<"push success";
        return 1;
    }

}

void shopcar::showShopCar()
{
    QVector <shopcar>::iterator iter;
    for (iter=shopCarList.begin();iter!=shopCarList.end();iter++)
       {
           qDebug()<<iter->name<<" "<<iter->pPrice;
    }
}

