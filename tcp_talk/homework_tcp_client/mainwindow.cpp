#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&socket,&QTcpSocket::hostFound,this,&MainWindow::connectSuccess);
    connect(this,&MainWindow::sendHostIp,this,&MainWindow::setHostIp);
//    connect(&socket,&QTcpSocket::error,this,&MainWindow::connectErro);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    QString com = ui->comEdit->text();
    quint16 comm = com.toUInt();
//    qDebug()<<hostip<<"hostip";
    QString ipHost = ui->serverAdd->text();
    hostip = ipHost;
    socket.connectToHost(ipHost,comm);
    ui->clientInfo->setText("connecting……");


}

void MainWindow::connectSuccess()
{
    MainWindow::ui->clientInfo->setText("1212");
    qDebug()<<"host found!";
    connect(&socket,&QTcpSocket::readyRead,this,&MainWindow::newMsg);
    qDebug()<<ui->serverAdd->text()<<"ippp";
//     QTcpSocket* mscoekt = dynamic_cast<QTcpSocket*>( sender());

     qDebug()<<hostip<<"hostip";
     ui->clientInfo->setText(hostip);
     emit sendHostIp();




}

//void MainWindow::connectErro()
//{
//    qDebug()<<"connect erro";
//}

void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();

    if(msg.isEmpty())
    {
        QMessageBox::warning(this,"Woring","不能发送空白消息");
        return;
    }
    socket.write(msg.toUtf8());
    ui->msgEdit->setText("");
    QString msgg = "me:";
    msgg += msg;
    ui->msgBox->append(msgg);
}

void MainWindow::newMsg()
{
    QTcpSocket* mscoekt = dynamic_cast<QTcpSocket*>( sender()); //信息的发送者
    QByteArray msg = mscoekt->readAll();

     //对接收中文为UTF-8格式数据的编码处理，如果是英文信息，不需要增加
    /******************************************************/
      QTextCodec *codec = QTextCodec::codecForName("UTF-8");
      QString string = codec->toUnicode(msg);
      /************************************************/
    //并能获取对言信息
    QString ip = mscoekt->peerAddress().toString();
    qDebug() << "ip = " << ip << "msg = "<< string;
    QString msgg = "client:";
    msgg += msg;
    ui->msgBox->append(msgg);
    ui->clientInfo->setText(hostip);
    qDebug()<<"sssss";
}

void MainWindow::on_clearBtn_clicked()
{
    ui->msgEdit->setText("");
}

void MainWindow::setHostIp()
{
    ui->clientInfo->setText(hostip);
    qDebug()<<"sssss";
}
