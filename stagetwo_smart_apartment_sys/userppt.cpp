#include "userppt.h"
#include "ui_userppt.h"

static int i = 1;
userppt::userppt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userppt)
{
    ui->setupUi(this);
    mtime = new QTimer;
    mtime->setInterval(5000);
    connect(mtime,&QTimer::timeout,this,&userppt::setPPTtoLabel);
    this->setPPTtoLabel();
    mtime->start();

}

userppt::~userppt()
{
    printf("~userppt\n");
    delete ui;
}

void userppt::setPPTtoLabel()
{
    QString path = QString("./userppt/%1.jpg").arg(i);
    QPixmap map(path);
    map =  map.scaled(QSize(390,80),Qt::KeepAspectRatio);
    ui->label->setPixmap(map);
    i++;
    if(i == 6)
        i = 1;
}
