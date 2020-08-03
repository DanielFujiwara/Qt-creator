#include "newslabel.h"
#include "ui_newslabel.h"

static int falg = 0;
newslabel::newslabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newslabel)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();

    connect(manager,&QNetworkAccessManager::finished,this,&newslabel::read_data);
    this->getNewsData();

    mTimer = new QTimer;
    mTimer->setInterval(5000);
    connect(mTimer,&QTimer::timeout,this,&newslabel::showToLabel);

}

newslabel::~newslabel()
{
   printf("~newslabel\n");
    delete ui;
}

void newslabel::getNewsData()
{
    QUrl url("http://v.juhe.cn/toutiao/index?type=&key=6179ef793d598486e9add6ae93164926");
    QNetworkRequest request(url);
     manager->get(request);
}

void newslabel::loadFile()
{
    QFile file;
    file.setFileName("./news.json");
    if (! file.open(QIODevice::ReadWrite))
    {
        printf("news file error\n");
    }

    datafile = file.readAll();
//    qDebug()<<datafile;
    file.close();
//    qDebug()<<datafile;

    QJsonDocument data = QJsonDocument::fromJson(datafile);
    QJsonObject dataO = data.object();
    QJsonObject dataR = dataO.value("result").toObject();
    QJsonArray dataD  = dataR.value("data").toArray();
    falg = dataD.size() - 1 ;
//    qDebug()<<falg;
//    printf("falg:%d\n",falg);
    this->showToLabel();
    mTimer->start();
}

void newslabel::read_data(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QFile file;
    file.setFileName("./news.json");
    file.remove();
//    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (! file.open(QIODevice::ReadWrite))
    {
        printf("news file error\n");
    }

    file.write(data);
//    printf("data get\n");

    file.close();

    this->loadFile();


}

void newslabel::showToLabel()
{
    QJsonDocument data = QJsonDocument::fromJson(datafile);
    QJsonObject dataO = data.object();
    QJsonObject dataR = dataO.value("result").toObject();
    QJsonArray dataD  = dataR.value("data").toArray();
    if(falg < 0)
    {
        falg = dataD.size() - 1;
    }
//    qDebug()<<falg;
    QJsonObject newsl = dataD.at(falg).toObject();
//    qDebug()<<newsl.value("title").toString();
    ui->newslabel_2->setText(newsl.value("title").toString());
    falg--;
}
