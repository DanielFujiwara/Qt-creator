#include "usermovie.h"
#include "ui_usermovie.h"
#include <QtDebug>
#include "fifotomplayer.h"
usermovie::usermovie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usermovie)
{
    ui->setupUi(this);
    creatFifoFlie();
//    mkfifo /tmp/fifofile;
    QString cmd = QString("mplayer -slave -loop 0 "
                          "-geometry 75:125= -zoom -x 520 -y 254 "
                          " -input file=/tmp/tmpfifo <movie> "
                          " -wid %1 "
                          "./usermovie.mp4").arg(QString::number(ui->label->winId()));

    if(mProcess.state() == QProcess::Running)
    {
        mProcess.kill();
        mProcess.waitForFinished();
    }

     mProcess.start(cmd);
}

usermovie::~usermovie()
{
    printf("~usermovie\n");
    delete ui;

}

void usermovie::exitMovie()
{
//    if(mProcess.state() == QProcess::Running)
//    {
//        mProcess.kill();
//        system("quit\n");
    quitMplayer();

//    mProcess.write("quit");
//        mProcess.waitForFinished();
//    }
}
