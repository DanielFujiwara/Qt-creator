#ifndef FILEJSON_H
#define FILEJSON_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QDir>
//Json数据文件类
class fileJson{

public:
    fileJson();
    void fileClose();
    int newJsonToFile();
    int locaUsername(QString name);//查找用户名在数组那个位置
    int locaShoplist(QString name);//查找商品在那个位置
    int checkId(QString name);//ID查重
    bool isNameRepeat(QString name);//判断是否有重名用户
    void reloadJDOdata();//重载文件
    int changeUserName(int i,QString newName);//修改用户名称
    int changeUserPasswork(int i,QString newPasswork);//修改用户密码
    int loginProgram
    (QString &flag,QString username,QString passwork,QString & id);//登录账户验证

    int insertNewAcount(QString username, QString passwork,QString flag,QString id);//新建账户
    int deletAcount(QString username);//删除账户

    ~fileJson(){
        file.close();
        qDebug()<<"fileJson~";
    }

    QFile file;
    QJsonDocument fileJDdata;
    QJsonObject fileJOdata;

};



#endif // FILEJSON_H
