#include "loginwindows.h"
#include <QApplication>
#include <filejson.h>
#include <QtDebug>
#include <QTextCodec>
#include "goods.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //定制皮肤在程序运行之前设置
            QFile file(":/pic/otherco.qss");
            file.open(QIODevice::ReadOnly);
           QByteArray array =  file.readAll();
          // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
           qApp->setStyleSheet(array);
    loginWindows w;
    w.show();

//    fileJson file;
//    file.fileClose();
//    QFile file;
//    file.setFileName("./serours/dataJ.json");
//    if(!file.open(QIODevice::ReadWrite)) {
//            qDebug() << "File open error";
//        } else {
//            qDebug() <<"File open!";
//        }
//    QJsonDocument myJ(QJsonDocument::fromJson((file.readAll())));//文件内容转为DOC

//    file.close();

//    QJsonObject myjo = myJ.object();//把doc中整个object读取

//    QJsonArray userdata = myjo.value("userdata").toArray();//读取大object中的userdata arry

//    QJsonObject u1 = userdata.at(0).toObject();//读取 userdata 中第一个object

//    qDebug()<<u1.value("name").toString();

//    u1["name"] = "admin";//修改userdata第一个boject中的name的值

//    qDebug()<<u1.value("name").toString();

//    userdata.replace(0,u1);//把新的 object替换到userdata数组中


//向userdata里面插入一个新的object
//    QJsonObject new1;
//    new1.insert("name","iamnew");
//    new1.insert("flag","0");
//    new1.insert("passwork","123");
//    new1.insert("id","12");

//    userdata.insert(0,new1);

//    userdata.removeAt(0);
//        userdata.removeLast();


//    myjo.insert("userdata",userdata);//把新的userdata插入大的object中




//    file.setFileName("./serours/dataJ.json");
//    if(!file.open(QIODevice::ReadWrite )) {
//            qDebug() << "File open error";
//        } else {
//            qDebug() <<"File open!";
//        }


//    file.remove();
//    file.close();

//    file.setFileName("./serours/dataJ.json");
//    if(!file.open(QIODevice::ReadWrite )) {
//            qDebug() << "File open error";
//        } else {
//            qDebug() <<"File open!";
//        }

//    myJ.setObject(myjo);//把修改后的object转为DOC
//    file.seek(0);
//    file.write(myJ.toJson());

//    file.close();
//filejson test
//    fileJson test;
//    int i = test.locaUsername("user1");
//    qDebug()<<i;
//    test.reloadJDOdata();

//    test.changeUserName(2,"heioioiohe");
//    test.changeUserPasswork(0,"511511");

//    QString flag;
//    int ret = test.loginProgram(flag,"admin","511511");
//    qDebug()<<flag<<ret;
//    test.loginProgram(flag,"admin","5115111");
//    test.loginProgram(flag,"admin","5115111");
//    test.loginProgram(flag,"admin","5115111");

//    test.insertNewAcount("aa","511511","0","12");

//    test.deletAcount("admin");

//vector test
//QVector<goods> testgoods;
//goods a1("a","a","a","a","a");
//goods a2("a2","a2","a2","a2","a2");
//goods a3("a3","a3","a3","a3","a3");

//    testgoods.append(a1);
//    testgoods.append(a2);
//    testgoods.append(a3);

//    QVector<goods>::Iterator iter;
//    for(iter=testgoods.begin();iter!=testgoods.end();iter++)
//    {
//        qDebug()<<iter->name;
//    }
//    goods t;
//    goodsVector p;


//    t.getGoodsData(p.shopList);

//    p.apendNewGoods("可乐","a","a","a","a");
//     p.showShopList();
//     int ret =
//     p.locaGoods("a");
//     p.removeGoods(ret);
//     p.showShopList();
//     p.soldTock("可乐",10);
//     p.showShopList();
//     p.changeTcok("可乐",224);
//     p.changeCost("可乐",133.25);
//     p.changePrice("可乐",125.22);
//     p.showShopList();
//    t.rewriteGoodsToFile(p.shopList);
//    t.getGoodsData(p.shopList);
//    p.apendNewGoods("a","a","a","a","a");
//    p.showShopList();
//     t.rewriteGoodsToFile(p.shopList);










    return a.exec();
}
