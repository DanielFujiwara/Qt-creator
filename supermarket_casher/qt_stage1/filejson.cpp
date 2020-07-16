#include "filejson.h"

static int loginflag = 0;

fileJson::fileJson(){
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
    qDebug()<<"init fileJson to doc fileJDdata fileJOdata get";
//    qDebug()<<buf;
}

void fileJson::fileClose()
{
    file.close();
    qDebug()<<"file close";
}

int fileJson::newJsonToFile()//写入fileJDdata 到文件
{
    file.remove();
    file.close();
    file.setFileName("../dataJ.json");
    if(!file.open(QIODevice::ReadWrite )) {
            qDebug() << "File open error";
            return -1;
        } else {
            qDebug() <<"File open!";
        }
    fileJDdata.setObject(fileJOdata);
    file.write(fileJDdata.toJson());
//    qDebug()<<fileJDdata<<"12121211212";
//    qDebug()<<fileJOdata;

    file.close();
    qDebug()<<"write in file";
    return 1;

}

int fileJson::locaUsername(QString name)//定位指定username
{

    this->reloadJDOdata();
    QJsonArray userdata = fileJOdata.value("userdata").toArray();
    for(int i = 0 ;i<userdata.size();i++)
    {
        QJsonObject nameInside = userdata.at(i).toObject();
        QString nameI = nameInside.value("name").toString();
//        qDebug()<<nameI;
        if(name == nameI)
        {
            qDebug()<<"name:"<<name<<"is located";
            return i;
        }
        else {
            continue;
        }
    }

    qDebug()<<"name:"<<name<<"does't exist";
    return -1;

}

int fileJson::checkId(QString name)
{
    this->reloadJDOdata();
    QJsonArray userdata = fileJOdata.value("userdata").toArray();
    for(int i = 0 ;i<userdata.size();i++)
    {
        QJsonObject nameInside = userdata.at(i).toObject();
        QString nameI = nameInside.value("id").toString();
//        qDebug()<<nameI;
        if(name == nameI)
        {
            qDebug()<<"name:"<<name<<"is located";
            return i;
        }
        else {
            continue;
        }
    }

    qDebug()<<"name:"<<name<<"does't exist";
    return -1;
}

bool fileJson::isNameRepeat(QString name)
{
    this->reloadJDOdata();
    int ret = this->locaUsername(name);
    if(ret != -1)
    {
        return false;
    }
    else {
        return true;

    }
}

void fileJson::reloadJDOdata()//重新载入fileJDdata,fileJOdata
{
    file.setFileName("../dataJ.json");
    if(!file.open(QIODevice::ReadWrite)) {
            qDebug() << "File open error";
            return;
        } else {
//            qDebug() <<"File open!";
        }
    QJsonDocument buf(QJsonDocument::fromJson(file.readAll()));
//    fileJDdata = QJsonDocument::fromJson(file.readAll());
    fileJDdata = buf;
//    fileJDdata.setObject(fileJOdata);
    file.close();
    fileJOdata = fileJDdata.object();
    qDebug()<<"reroad";
//    qDebug()<<buf;
}

int fileJson::changeUserName(int i,QString newName)//修改用户名称
{
    this->reloadJDOdata();
    QJsonArray userdata = fileJOdata.value("userdata").toArray();
    QJsonObject changeName = userdata.at(i).toObject();
    changeName["name"] = newName;
    qDebug()<<"new name set";
    userdata.replace(i,changeName);
    fileJOdata.insert("userdata",userdata);
    this->newJsonToFile();
    return 1;
}

int fileJson::changeUserPasswork(int i,QString newPasswork)//修改用户密码
{
    this->reloadJDOdata();
    QJsonArray userdata = fileJOdata.value("userdata").toArray();
    QJsonObject changeName = userdata.at(i).toObject();
    changeName["passwork"] = newPasswork;
    qDebug()<<"new passwork set";
    userdata.replace(i,changeName);
    fileJOdata.insert("userdata",userdata);
    this->newJsonToFile();
    return 1;
}

int fileJson::loginProgram(QString &flag, QString username, QString passwork,QString & id)
{
    this->reloadJDOdata();
    int ret = this->locaUsername(username);
    if(ret == -1)
    {
        qDebug()<<"wrong password or username";
        loginflag++;
        if(loginflag == 3)
        {
            qDebug()<<"wrong password or username three times";
            return -2;
        }
        return -1;
    }

    QJsonArray userdata = fileJOdata.value("userdata").toArray();
    QJsonObject acount = userdata.at(ret).toObject();
    QString name1 = acount.value("name").toString();
    QString passwork1 = acount.value("passwork").toString();
    if(name1 == username && passwork == passwork1)
    {
        qDebug()<<"passwork compera successed";
        if(acount.value("flag").toString() == "管理员")
        {
            flag = "admin";
//            id = acount.value("id").toString();
            loginflag = 0;
            return 2;
        }
        else if(acount.value("flag").toString() == "收银员"){
            flag = "user";
            id = acount.value("id").toString();
            loginflag = 0;
            return 1;
        }


    }
    else
    {
        qDebug()<<"wrong password or username";
        loginflag++;
        if(loginflag == 3)
        {
            qDebug()<<"wrong password or username three times";
            return -2;
        }
        return -1;
    }

}

int fileJson::insertNewAcount(QString username, QString passwork,QString flag,QString id)
{
    this->reloadJDOdata();
//    if(flag != "1" && flag != "0")
//    {
//        qDebug()<<"flag erro(only 0 or 1)";
//        return -1;
//    }

    int check = this->locaUsername(username);
    if(check != -1)
    {
        qDebug()<<"same username error";
        return -2;
    }

    QJsonObject new1;
       new1.insert("name",username);
       new1.insert("flag",flag);
       new1.insert("passwork",passwork);
       new1.insert("id",id);
       QJsonObject newuserdata = fileJDdata.object();
       QJsonArray newuserarray = newuserdata.value("userdata").toArray();

      newuserarray.append(new1);
      newuserdata.insert("userdata",newuserarray);

    fileJOdata = newuserdata;

    int ret = this->newJsonToFile();
    if(ret == -1)
    {
        qDebug()<<"insert new acount erro";
        return -1;
    }

    qDebug()<<"insert new acount";
    return 1;




}

int fileJson::deletAcount(QString username)
{
   this->reloadJDOdata();
    int ret = this->locaUsername(username);
    if(ret == -1)
    {
        qDebug()<<"delet error:acout does't exist";
        return -1;
    }

    QJsonObject deletobj = fileJDdata.object();
    QJsonArray deletarray = deletobj.value("userdata").toArray();
    QJsonObject target = deletarray.at(ret).toObject();

    if(target.value("flag").toString() == "1")
    {
        qDebug()<<"delet error:can't delet super user";
        return -1;
    }
    deletarray.removeAt(ret);
    deletobj.insert("userdata",deletarray);
    fileJOdata = deletobj;
    this->newJsonToFile();
    qDebug()<<"delet successed";
    return 1;


}
