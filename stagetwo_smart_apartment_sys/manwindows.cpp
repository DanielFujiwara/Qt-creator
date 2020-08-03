#include "manwindows.h"
#include "ui_manwindows.h"
#include "mainwindow.h"
#include "repairectrl.h"
manwindows::manwindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manwindows)
{
    ui->setupUi(this);
    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);
}

manwindows::~manwindows()
{
    printf("~manwindows\n");
    delete ui;
}

void manwindows::on_pushButton_3_clicked()
{
    MainWIndow *loginw = new MainWIndow;
    loginw->show();
     this->close();
    return;
}

void manwindows::on_pushButton_clicked()
{
    repairectrl *loginw = new repairectrl;
    loginw->show();
//     this->close();
    return;
}
