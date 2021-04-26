#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rcvsocket = new QUdpSocket;
    rcvsocket->bind(4001,QUdpSocket::ShareAddress);
    connect(rcvsocket,SIGNAL(readyRead()),this,SLOT(read_adv_msg()));


    anssockrt = new QUdpSocket;
    anssockrt->bind(QHostAddress("192.168.8.153"),4001);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_adv_msg()
{


    char bufrcv[100];
    memset(bufrcv,0,100);
    while (rcvsocket->hasPendingDatagrams()) {
        rcvsocket->readDatagram(bufrcv,100);
        this->ui->textBrowser->append(bufrcv);
        memset(bufrcv,0,100);
    }
}

void MainWindow::on_pushButton_clicked()
{
    qint64 ret = anssockrt->writeDatagram("aaa",QHostAddress("192.168.8.153"),14001);
    qDebug()<<ret;
}
