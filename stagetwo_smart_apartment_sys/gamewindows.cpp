#include "gamewindows.h"
#include "ui_gamewindows.h"
#include "userwindow.h"
#include "peoplegame.h"
#include "textmainwindow.h"
//#include "stopwatchmainwindow.h"
#include "stopwatchgame.h"
#include "caular.h"
gamewindows::gamewindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamewindows)
{
    ui->setupUi(this);
    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    //天气模块
    weather = new weatherclock(this);
    weather->move(600,0);
    weather->show();
    connect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);

//    this->hellolabelset();
    // 新闻模块
    newsLabel = new newslabel(this);
    newsLabel->move(0,430);
    newsLabel->show();

    // 广告ppt模块
    userPpt = new userppt(this);
    userPpt->move(205,30);
    userPpt->show();
    //视频模块
    movie = new usermovie(this);
    movie->move(75,125);
    movie->show();
}

gamewindows::~gamewindows()
{
    printf("~gamewindows\n");
    delete ui;
}

void gamewindows::setMyUser(QString name)
{
    myUser = name;
    qDebug()<<myUser;
}

void gamewindows::on_exitBtn_clicked()
{
    userwindow *userw = new userwindow;
    userw->show();
    connect(userw,&userwindow::sendUserName,userw,&userwindow::setUserName);
    emit userw->sendUserName(myUser);
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);

//    weatherman->close();
//    delete weatherman;
    movie->exitMovie();
    this->close();
    return;
}

void gamewindows::on_manBtn_clicked()
{
    peoplegame *p = new peoplegame();
    connect(p,&peoplegame::sendName,p,&peoplegame::setMyName);
    emit p->sendName(myUser);
    p->show();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);

    movie->exitMovie();
    this->close();
}

void gamewindows::on_gameBtn_clicked()
{
    textMainWindow *text = new textMainWindow();
    connect(text,&textMainWindow::sendMyName,text,&textMainWindow::setMyName);
    emit text->sendMyName(myUser);
    text->show();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);

    movie->exitMovie();
    this->close();
    return;
}

void gamewindows::on_videoBtn_clicked()
{
//    stopwatchMainWindow * stopwatch1 = new stopwatchMainWindow;
//    stopwatchMainWindow *stopnewWacht = new stopwatchMainWindow;
//    stopnewWacht.show();
    stopwatchgame *stopw = new stopwatchgame;
    connect(stopw,&stopwatchgame::sendMyName,stopw,&stopwatchgame::setMyName);
    emit stopw->sendMyName(myUser);
    stopw->show();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
    movie->exitMovie();
    this->close();
    return;
}

void gamewindows::on_lightBtn_clicked()
{
    Caular *mycal = new Caular;
    connect(mycal,&Caular::sendMyName,mycal,&Caular::setMyName);
    emit mycal->sendMyName(myUser);
    mycal->show();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
    movie->exitMovie();
    this->close();
    return;
}
