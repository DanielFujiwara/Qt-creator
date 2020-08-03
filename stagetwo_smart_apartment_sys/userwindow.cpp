#include "userwindow.h"
#include "ui_userwindow.h"
#include "mainwindow.h"
//#include "peoplegame.h"
#include "gamewindows.h"
userwindow::userwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userwindow)
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
//    weather->whatTime();
    connect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
    this->hellolabelset();
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

userwindow::~userwindow()
{
    printf("~userwindow\n");
    delete ui;
}

void userwindow::hellolabelset()
{
    int ret = weather->whatTime();


        if(ret >= 0 && ret <= 12)
        {
            if(ret <= 5)
            {
                ui->helloLabel->setText("夜深了");
            }
            else
            {
                ui->helloLabel->setText("上午好");
            }
        }
        else {
            if(ret <= 18)
            {
                ui->helloLabel->setText("下午好");
            }
            else {
                ui->helloLabel->setText("晚上好");
            }
        }




}

void userwindow::setUserName(QString name)
{
    ui->usernameLabel->setText(name);
//    qDebug()<<name;
    myName = name;
}

void userwindow::on_exitBtn_clicked()
{
   movie->exitMovie();
   disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
   MainWIndow *loginw = new MainWIndow;
   loginw->show();
    this->close();
   return;

}

void userwindow::on_manBtn_clicked()
{
    user_management *uman = new user_management;
    connect(uman,&user_management::getMyUserName,uman,&user_management::setMyUserName);
    emit uman->getMyUserName(myName);
//    qDebug()<<myName<<"1";
    uman->show();
    movie->exitMovie();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
//    delete weather;
    this->close();
    return;
}

void userwindow::on_gameBtn_clicked()
{
    gamewindows *game = new gamewindows();
    connect(game,&gamewindows::sendMyUser,game,&gamewindows::setMyUser);
    emit game->sendMyUser(myName);
    game->show();
    movie->exitMovie();
    disconnect(weather->mTimer,&QTimer::timeout,weather,&weatherclock::screenshow);
//    delete weather;
    this->close();
    return;
}
