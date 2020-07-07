#include "mainwindow.h"
#include "ui_mainwindow.h"

static int s = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    th = new sendCount(this);

    connect(th,&sendCount::SendToMian,this,&MainWindow::setTime);

    time = QTime::currentTime();
    ui->label_2->setText(time.toString("hh:mm:ss"));
    th->start();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::pptSetWallpaper(int i)
{
    if(s++ % 3 == 0)
    {

    QString path = QString(":/wallpaper/%1.jpg").arg(i);

    QPixmap map(path);
    map =  map.scaled(QSize(760,520),Qt::KeepAspectRatio);
    ui->label->setPixmap(map);
    }
    else {
        return;
    }
}

void MainWindow::setTime()
{
    time = QTime::currentTime();
    ui->label_2->setText(time.toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_clicked()
{

    connect(th,&sendCount::SendToMian,this,&MainWindow::pptSetWallpaper);
}

void MainWindow::on_pushButton_2_clicked()
{
    th->terminate();
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(1);
}
