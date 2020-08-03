#include "accountctrl.h"


accountctrl::accountctrl()
{
    database = QSqlDatabase::addDatabase("QSQLITE");

    //给数据库定义一个名称，后缀 .db
    database.setDatabaseName("account.db");

    if(! database.open())
    {
        qDebug()<<"open failed"<<database.lastError();
    }
//    qDebug()<<"database";
    QSqlQuery sqlQuery1;
    sqlQuery = sqlQuery1;
}

accountctrl::~accountctrl()
{
   printf("~accountctrl\n");
   database.close();

   sqlQuery.clear();
}

int accountctrl::acountLogin(QString name, QString passwork)
{

    QString sqlorder = QString("SELECT * FROM acountdata where name = '%1' and passwork = '%2';").arg(name).arg(passwork);
    if(!sqlQuery.exec(sqlorder))
    {
          qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    if(sqlQuery.next())
    {

            QString iden =sqlQuery.value(4).toString();
//            qDebug()<<iden;
            if(iden == "user")
                return 2;
            else {
                return 1;
            }


     }
    else {
        return -1;
    }

}

int accountctrl::acoutCreateToBads(QString name, QString passwork, QString cardid)
{
    QString sqlorder = QString("SELECT * FROM acountdata where name = '%1';").arg(name);
    if(!sqlQuery.exec(sqlorder))
    {
          qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    if(sqlQuery.next())
    {
        qDebug()<<"重名";
        return -1;
     }

    QString sqlidcheck = QString("SELECT * FROM acountdata where rfid = '%1';").arg(cardid);
    if(!sqlQuery.exec(sqlidcheck))
    {
          qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else {
//         qDebug() << "success";
    }
    if(sqlQuery.next())
    {
        qDebug()<<"重卡";
        return -2;
     }


    QString newacount = QString("insert into acountdata(name,passwork,rfid,identity) values('%1','%2','%3','user');").arg(name).arg(passwork).arg(cardid);
    if(!sqlQuery.exec(newacount))
    {
          qDebug() << "Error:Failed to insert record"<< database.lastError();
    }else {
         qDebug() << "success new acout";
    }


    return 1;
}
