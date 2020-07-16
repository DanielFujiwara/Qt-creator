#include "goods.h"
//#include "simplecasherctrl.h"

goods::goods()
{
    QFile file;
    file.setFileName("../dataJ.json");
    if(!file.open(QIODevice::ReadWrite)) {
            qDebug() << "File open error";
        } else {
            qDebug() <<"File open!";
        }
    QJsonDocument buf(QJsonDocument::fromJson(file.readAll()));
//    fileJDdata = QJsonDocument::fromJson(file.readAll());
    fileJDdata = buf;
//    fileJDdata.setObject(fileJOdata);
    file.close();
    fileJOdata = fileJDdata.object();
    goodsArray = fileJOdata.value("shoplist").toArray();
    qDebug()<<"init fileJson to doc";
    //    qDebug()<<buf;
}

void goods::getGoodsData(QVector<goodsVector> &shopList)
{
    shopList.clear();
    for (int i=0;i<goodsArray.size();i++) {
     QJsonObject bufO = goodsArray.at(i).toObject();
     QString name = bufO.value("name").toString();
     QString cost = bufO.value("cost").toString();
     QString price = bufO.value("price").toString();
     QString type = bufO.value("type").toString();
     QString stock1 = bufO.value("stock").toString();

     goodsVector bufnew(name,cost,price,type,stock1);
     shopList.append(bufnew);
    }
}

void goods::rewriteGoodsToFile(QVector<goodsVector> &shopList)
{
    QVector<goodsVector>::iterator iter;
    QJsonArray shoparray;

    iter = shopList.begin();
    for (iter=shopList.begin();iter != shopList.end();iter++) {

        QJsonObject shop;
        shop.insert("name",iter->name);
        shop.insert("cost",iter->cost);
        shop.insert("price",iter->price);
        shop.insert("type",iter->type);
        shop.insert("stock",iter->stock);
        shoparray.append(shop);
    }

    goodsArray = shoparray;
    fileJOdata.remove("shoplist");
    fileJOdata.insert("shoplist",goodsArray);

    QFile file;
    file.setFileName("../dataJ.json");
    file.remove();
    file.close();
    file.setFileName("../dataJ.json");
    if(!file.open(QIODevice::ReadWrite )) {
            qDebug() << "File open error";
            return;
        } else {
            qDebug() <<"File open!";
        }
    fileJDdata.setObject(fileJOdata);
    file.write(fileJDdata.toJson());
    file.close();
    qDebug()<<"file write success";
    //重新载入保证数据完整
    file.setFileName("../dataJ.json");
    if(!file.open(QIODevice::ReadWrite)) {
            qDebug() << "File open error";
        } else {
            qDebug() <<"File open!";
        }
    QJsonDocument buf(QJsonDocument::fromJson(file.readAll()));
//    fileJDdata = QJsonDocument::fromJson(file.readAll());
    fileJDdata = buf;
//    fileJDdata.setObject(fileJOdata);
    file.close();
    fileJOdata = fileJDdata.object();
    goodsArray = fileJOdata.value("shoplist").toArray();
    qDebug()<<"init fileJson to doc";
    //    qDebug()<<buf;




}



void goodsVector::showShopList()
{
    QVector <goodsVector>::iterator iter;
    for (iter=shopList.begin();iter!=shopList.end();iter++)
       {
           qDebug() <<"name"<<iter->name;
           qDebug() <<"cost"<<iter->cost;
           qDebug() <<"price"<<iter->price;
           qDebug() <<"type"<<iter->type;
           qDebug() <<"stock"<<iter->stock;
    }
}



void goodsVector::apendNewGoods( QString name1, QString cost1, QString price1, QString type1, QString stock1)
{
    if(locaGoods(name1) != -1)
    {
        qDebug()<<"good repeat";
        return;
    }
    goodsVector newBuf(name1,cost1,price1,type1,stock1);
    shopList.append(newBuf);

}

int goodsVector::locaGoods(QString name)
{
    int i = 0;
    QVector <goodsVector>::iterator iter;
    for (iter=shopList.begin();iter!=shopList.end();iter++)
       {
           if(iter->name == name)
           {
               qDebug()<<name<<"is located";
               return i;
           }
           else {
               i++;
               continue;
           }
    }

    return -1;
}

int goodsVector::removeGoods(int i)
{
    shopList.remove(i);
    return 1;
}

int goodsVector::soldTock(QString name, int sold)
{
    int ret = locaGoods(name);//判断是否存在
    if(ret == -1)
    {
        qDebug()<<"goods does't exist";
        return -1;
    }

    if(shopList.at(ret).stock == "0")//判断是否售罄
    {
        qDebug()<<name<<"sold out";
        return -1;
    }
    int nowtock = shopList.at(ret).stock.toInt();
    if(sold > nowtock)//判断库存是否足够
    {
        qDebug()<<"goods tock is not enough";
        return -1;
    }

    nowtock -= sold;
    QString newtock = QString::number(nowtock);

    QVector<goodsVector>::Iterator iter;
    iter = shopList.begin();
    iter[ret].stock = newtock;

    qDebug()<<"sold successed";
    return 1;



}

int goodsVector::changeTcok(QString name, int t)
{
    int ret = locaGoods(name);//判断是否存在
    if(ret == -1)
    {
        qDebug()<<"goods does't exist";
        return -1;
    }

    if(t < 0)
    {
        qDebug()<<"cant set up negatve";
        return -1;
    }




    QString newtock = QString::number(t);

    QVector<goodsVector>::Iterator iter;
    iter = shopList.begin();
    iter[ret].stock = newtock;

    qDebug()<<"tock changed successed";
    return 1;
}

int goodsVector::changeCost(QString name, double t)
{
    int ret = locaGoods(name);//判断是否存在
    if(ret == -1)
    {
        qDebug()<<"goods does't exist";
        return -1;
    }

    if(t < 0)
    {
        qDebug()<<"cant set up negatve";
        return -1;
    }




    QString newtock = QString::number(t);

    QVector<goodsVector>::Iterator iter;
    iter = shopList.begin();
    iter[ret].cost = newtock;

    qDebug()<<"cost changed successed";
    return 1;
}

int goodsVector::changePrice(QString name, double t)
{
    int ret = locaGoods(name);//判断是否存在
    if(ret == -1)
    {
        qDebug()<<"goods does't exist";
        return -1;
    }

    if(t < 0)
    {
        qDebug()<<"cant set up negatve";
        return -1;
    }


    QString newtock = QString::number(t);

    QVector<goodsVector>::Iterator iter;
    iter = shopList.begin();
    iter[ret].price = newtock;

    qDebug()<<"price changed successed";
    return 1;
}
