#include "stopwatchgame.h"
#include "ui_stopwatchgame.h"
#include "gamewindows.h"

int stopwatchgame::tim = 0;
void stopwatchgame::setMyName(QString name)
{
    myname = name;
}

void stopwatchgame::screenshowtime()
{
    tim++;
    QTime t(0,0,0);
    t = t.addMSecs(tim);
    ui->screen->setText(t.toString("hh:mm:ss:zzz"));
}

stopwatchgame::stopwatchgame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stopwatchgame)
{
    ui->setupUi(this);

    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout,this,&stopwatchgame::screenshowtime);
    mTimer->setInterval(1);
}

stopwatchgame::~stopwatchgame()
{
    printf("~stopwatchgame\n");
    delete ui;
}

void stopwatchgame::on_starB_clicked()
{
    mTimer->start();
}

void stopwatchgame::on_resetB_clicked()
{
    mTimer->stop();
    tim = 0;
    QTime t(0,0,0);
    t = t.addMSecs(tim);
    ui->screen->setText(t.toString("hh:mm:ss:zzz"));

}

void stopwatchgame::on_saveB_clicked()
{
    ui->textBrowser->append(ui->screen->text());

}

void stopwatchgame::on_stopB_clicked()
{
     mTimer->stop();
}

void stopwatchgame::on_commandLinkButton_clicked()
{
    gamewindows *p = new gamewindows;
    connect(p,&gamewindows::sendMyUser,p,&gamewindows::setMyUser);
    emit p->setMyUser(myname);
    p->show();
   disconnect(mTimer,&QTimer::timeout,this,&stopwatchgame::screenshowtime);
    mTimer->stop();

    this->close();
    return;
}
