#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
static int flag = 0;
static int newflag = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //label color
    QPalette pe;

    pe.setColor(QPalette::WindowText, Qt::white);

    ui->datalabel->setPalette(pe);
    ui->timelabel->setPalette(pe);
     ui->typelabel->setPalette(pe);

    QFont font ( "Microsoft YaHei",16,99);
    ui->winplabel->setFont(font);
     ui->infolabel->setFont(font);
      ui->direlabel->setFont(font);
      ui->temlabel->setFont(font);
      ui->guangzhoulabel->setFont(font);
//     ui->windlabel->setPalette(pe);
     pe.setColor(QPalette::WindowText, Qt::white);
     ui->winplabel->setPalette(pe);
      ui->infolabel->setPalette(pe);
       ui->direlabel->setPalette(pe);
       ui->temlabel->setPalette(pe);
       ui->guangzhoulabel->setPalette(pe);
//       ui->typelabel->setPalette(pe);

    //天气请求
    manager = new QNetworkAccessManager();

    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::read_data);
    this->getWeatherData();

    //广告视频


     mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout,this,&MainWindow::screenshow);

    mtime = QTime::currentTime();
    mdata = QDate::currentDate();
    ui->timelabel->setText(mtime.toString("hh:mm:ss"));
    ui->datalabel->setText(mdata.toString("yyyy年MM月dd日"));
    mTimer->setInterval(500);
    mTimer->start();
//     set background pic
        QPixmap pixmap = QPixmap(":/kobe.jpg").scaled(this->size());
        QPalette palette(this->palette());
        palette.setBrush(QPalette::Background, QBrush(pixmap));
        this->setPalette(palette);


    // set video
        if(mProcess.state() == QProcess::Running)
        {
            mProcess.kill();
            mProcess.waitForFinished();
        }
        //利用第三方播放器来实现视频播放
        //mplayer -slave -quiet -geometry 0:0 -zoom -x 800 -y 400 ./test_1.mp4
        QString cmd = QString("mplayer -slave  -loop 0 "
                              "-geometry 0:0 -zoom -x 620 -y 413 "
                              " -wid %1 "
                              "./test_3.mp4").arg(QString::number(ui->label->winId()));
        mProcess.start(cmd);

        //滚动label
        mTimerlabel = new QTimer(this);
       connect(mTimerlabel,&QTimer::timeout,this,&MainWindow::labelchange);
       mTimerlabel->setInterval(5000);
       mTimerlabel->start();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getWeatherData()
{

    QUrl url("http://apis.juhe.cn/simpleWeather/query?city=%E5%B9%BF%E5%B7%9E&key=c378c7d804c95f2c7eab9e3c7f1b1710");
    QNetworkRequest request(url);
     manager->get(request);

}


void MainWindow::screenshow()
{
  mtime = QTime::currentTime();
  if(flag == 0)
  {
      ui->timelabel->setText(mtime.toString("hh:mm:ss"));
      flag = 1;
      return;
  }

  if(flag == 1)
  {
      ui->timelabel->setText(mtime.toString("hh:mm ss"));
      flag = 0;
      return;
  }


}

void MainWindow::read_data(QNetworkReply *reply)
{
        QByteArray data =  reply->readAll();

        //因为从服务器返回来的数据中文它为UTF-8格式，但是，windows中qt它显示中文的格式
        //GB18030，如果默认直接输出服务器的数据，那么就相当于用GB18030来显示UTF-8的格式
        //数据，这样子，结果就可能显示不出来，要进行编码转换,QTextCodec

         // QTextCodec *codec = QTextCodec::codecForName("UTF-8");
         // QString string = codec->toUnicode(data);

         // qDebug() << "data = " << string;
          //[1] 将数据转换成QJsonDocment QJsonDocument::fromJson()
          //
         // static QJsonDocument  fromJson(const QByteArray &json, QJsonParseError *error = nullptr)
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



}

void MainWindow::labelchange()
{
    QString news[4] = {"无线模拟电视今年底退出历史舞台，我国全面进入数字电视时代","中国驻美使馆再调查留学生乘临时航班回国意愿","上半年大部分贷款投向实体经济 精准“输血”助企业过难关","嵌入式广告位置出租 13249252445 何蔚"};
    if(newflag == 4)
        newflag = 0;

    ui->typelabel->setText(news[newflag]);
    newflag++;

}

