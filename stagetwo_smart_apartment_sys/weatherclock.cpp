#include "weatherclock.h"
#include "ui_weatherclock.h"

static int flag = 0;
//static int weaflag = 0;
weatherclock::weatherclock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::weatherclock)
{
    ui->setupUi(this);

    //天气请求
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&weatherclock::read_data);
//    qDebug()<<__LINE__;
//    this->getWeatherData();


    mTimer = new QTimer(this);


   mtime = QTime::currentTime();
   mdata = QDate::currentDate();
   ui->timelabel->setText(mtime.toString("hh:mm:ss"));
   ui->datalabel->setText(mdata.toString("yyyy年MM月dd日"));
   mTimer->setInterval(500);
   mTimer->start();
}

weatherclock::~weatherclock()
{
    printf("~weatherclock\n");
    delete ui;
}

int weatherclock::getTemp()
{
    return temnow;
}

int weatherclock::getHum()
{
    return humnow;
}

void weatherclock::getWeatherData()
{
//    qDebug()<<__LINE__;
    QUrl url("http://apis.juhe.cn/simpleWeather/query?city=%E5%B9%BF%E5%B7%9E&key=c378c7d804c95f2c7eab9e3c7f1b1710");
//    QUrl url("http://apis.juhe.cn/simpleWeather/query?city=%E5%B9%BF%E5%B7%9E&key=6eaaa433d136ff59653d126c67270943");
    QNetworkRequest request(url);
//    qDebug()<<__LINE__;
    manager->get(request);
//    qDebug()<<__LINE__;
}

int weatherclock::whatTime()
{
//   qDebug()<<mtime.hour();
    flag = 0;
   return mtime.hour();


}

void weatherclock::screenshow()
{
//    qDebug()<<flag<<"flag";
    mtime = QTime::currentTime();
    if(flag == 0)
    {
        ui->timelabel->setText(mtime.toString("hh:mm:ss"));

            flag = 1;

        if(mtime.minute() == 31 && mtime.second() == 10)
        {
            this->getWeatherData();
//            qDebug()<<"getWeather";
        }

        if(mtime.minute() == 01 && mtime.second() == 10)
        {
            this->getWeatherData();
//            qDebug()<<"getWeather";
        }

        return;
    }
     else if(flag == 1)
    {
        ui->timelabel->setText(mtime.toString("hh:mm ss"));
        flag = 0;
        return;
    }


}

void weatherclock::read_data(QNetworkReply *reply)
{
//   qDebug()<<__LINE__;
    QByteArray data =  reply->readAll();

      QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject allguangzhou = doc.object();
    QJsonObject guangzhouresu = allguangzhou.value("result").toObject();
    QJsonObject realtimeguangzhou = guangzhouresu.value("realtime").toObject();
//        qDebug()<<realtimeguangzhou.value("direct").toString();
    ui->direlabel->setText(realtimeguangzhou.value("direct").toString());
    QString  tem = realtimeguangzhou.value("temperature").toString();
    tem += "度";
    ui->temlabel->setText(tem);
//        ui->windlabel->setText(realtimeguangzhou.value("direct").toString());
    ui->winplabel->setText(realtimeguangzhou.value("power").toString());
    ui->infolabel->setText(realtimeguangzhou.value("info").toString());
    ui->aqilabel->setText(realtimeguangzhou.value("aqi").toString());
    ui->humiditylabel->setText(realtimeguangzhou.value("humidity").toString());
//    qDebug()<<__LINE__;
    temnow = realtimeguangzhou.value("temperature").toString().toInt();
    humnow = realtimeguangzhou.value("humidity").toString().toInt();
    infonow = realtimeguangzhou.value("info").toString();
    this->setInfoPic();
    this->setTemTips();
    this->setFlower();
//    qDebug()<<"read data weather";
//    qDebug()<<__LINE__;
//    int min = mtime.minute() * 60 * 1000;
//    if(min > (30*60*1000))
//    {
//        min = (61*60*1000) - min;
//    }
//    else {
//        min = (31*60*1000) - min;
//    }


//    if(weaflag == 1)
//    {
//        weathertimer->stop();
//        qDebug()<<"timer stop";
//    }
//    delete weathertimer;

//    weathertimer = new QTimer;
//    connect(weathertimer,&QTimer::timeout,this,&weatherclock::getWeatherData);

//    weathertimer->setInterval(min);
//    weaflag = 1;
//    qDebug()<<__LINE__;
//   qDebug()<<min;
//    weathertimer->start();
//    qDebug()<<__LINE__;

}

void weatherclock::setInfoPic()
{
    if(infonow.contains("晴",Qt::CaseSensitive))
    {
        QString path = QString("./weather/1.png");
        QPixmap map(path);
        map =  map.scaled(QSize(70,70),Qt::KeepAspectRatio);
        ui->piclabel->setPixmap(map);
        return;
    }

    if(infonow.contains("雨",Qt::CaseSensitive))
    {
        QString path = QString("./weather/2.png");
        QPixmap map(path);
        map =  map.scaled(QSize(70,70),Qt::KeepAspectRatio);
        ui->piclabel->setPixmap(map);
        return;
    }

    if(infonow.contains("阴",Qt::CaseSensitive))
    {
        QString path = QString("./weather/3.png");
        QPixmap map(path);
        map =  map.scaled(QSize(70,70),Qt::KeepAspectRatio);
        ui->piclabel->setPixmap(map);
        return;
    }

    if(infonow.contains("云",Qt::CaseSensitive))
    {
        QString path = QString("./weather/4.png");
        QPixmap map(path);
        map =  map.scaled(QSize(70,70),Qt::KeepAspectRatio);
        ui->piclabel->setPixmap(map);
        return;
    }
}

void weatherclock::setTemTips()
{
    QPalette gpe;
    gpe.setColor(QPalette::WindowText, Qt::green);

    QPalette ype;
    ype.setColor(QPalette::WindowText, Qt::yellow);

    QPalette rpe;
    rpe.setColor(QPalette::WindowText, Qt::red);

       if(temnow > 28)
       {
           ui->feeltemlabel->setPalette(ype);
           ui->feeltemlabel->setText("高温预警");
       }
       else if(temnow > 22)
       {
           ui->feeltemlabel->setPalette(gpe);
           ui->feeltemlabel->setText("温度适宜");
       }
       else {
           ui->feeltemlabel->setPalette(rpe);
           ui->feeltemlabel->setText("低温预警");
       }




}

void weatherclock::setFlower()
{
    QPalette gpe;
    gpe.setColor(QPalette::WindowText, Qt::darkGreen);
    ui->humlabel->setPalette(gpe);
    if(humnow < 70)
    {
        ui->humlabel->setText("已自动打开浇水系统");
    }
}
