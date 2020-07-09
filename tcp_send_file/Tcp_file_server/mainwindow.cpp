#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&server,&QTcpServer::newConnection,this,&MainWindow::newCilent);
    server.listen(QHostAddress::Any,6789);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newCilent()
{
    QTcpSocket *socket = server.nextPendingConnection();
    qDebug()<<"new Client:"<<socket->peerAddress().toString();
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::recvFile);
    qDebug()<<"ready to recv file.";
   filesize = 0;
   recvsize = 0;
   qDebug()<<"simple socket"<<socket;


}

void MainWindow::recvFile()
{
    QTcpSocket *socket = dynamic_cast<QTcpSocket*>(sender());
    qDebug()<<"sender socket"<<socket;
    if(filesize == 0)
    {
        QByteArray fileinfo = socket->readAll();
        QDataStream in(&fileinfo,QIODevice::ReadOnly);
        in >>filesize>>filename;
        qDebug()<<"fileinfo"<<filename<<filesize;
        ui->progressBar->setMaximum(static_cast<int>(filesize));
        file.setFileName(filename);
        file.open(QIODevice::WriteOnly);
    }

    if(recvsize < filesize)
    {
        QByteArray filedata = socket->readAll();
        file.write(filedata);
        recvsize += static_cast<quint64>(filedata.size());
        ui->progressBar->setValue(static_cast<int>(recvsize));
        qDebug()<<"receive size:"<<filedata.size();

    }

    if(recvsize == filesize)
    {
        qDebug()<<"file recived successed";
        file.close();
        socket->disconnectFromHost();
        qDebug()<<"socket disconnect";

    }
}
