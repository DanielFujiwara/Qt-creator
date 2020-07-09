

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QTextCodec>
#include <QMessageBox>
//#include <string.h>
//using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newClientConnect()
{
    socket = server.nextPendingConnection();
//    QHostAddress addClient = QAbstractSocket::peerAddress();
   qDebug()<< socket->peerAddress().toString()<<" connecting";
   QString addHost = socket->peerAddress().toString();
//   a.substr(0,8);
   ui->clientInfo->setText(socket->peerAddress().toString());
//         socket;
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::newMsg);

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
    ui->textBrowser_2->append(msgg);
}

void MainWindow::on_startBtn_clicked()
{
    QString comHost = ui->comEdit->text();
    quint16 com = comHost.toUInt();
    qDebug()<<com;
    server.listen(QHostAddress::Any,com);
    connect(&server,&QTcpServer::newConnection,this,&MainWindow::newClientConnect);
    ui->clientInfo->setText("waiting for client");
}

void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->msgEdit->text();

    if(msg.isEmpty())
    {
        QMessageBox::warning(this,"Woring","不能发送空白消息");
        return;
    }
    socket->write(msg.toUtf8());
    ui->msgEdit->setText("");
    QString msgg = "me:";
    msgg += msg;
    ui->textBrowser_2->append(msgg);




}

void MainWindow::on_clearBtn_clicked()
{
    ui->msgEdit->setText("");
}
