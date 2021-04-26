#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Socket_List_Search();

    AboradTimer = new QTimer(this);
    AboradTimer->setInterval(2000);
    connect(AboradTimer,&QTimer::timeout,this,&MainWindow::Send_LocalIp);
    AboradTimer->start();
    this->ui->pushButton->setText("暂停");
    this->ui->progressBar->setMaximum(510);
    counting = 0;
    sumpage = 0;
    coutingms = 0;
    lastTime = 0;
    summs = 0;

}

void MainWindow::AboradTimer_Timeout()
{

}

void MainWindow::Send_LocalIp()
{
    int speedint = counting/2;
    QString speed = QString::number(speedint);
//            speed+=" kb/s";
    this->ui->lineEdit->setText(speed);
    this->ui->progressBar->setValue(speedint);
//    QString summs = QString::number(1000/speedint) + "ms";
//    this->ui->lineEdit_4->setText(summs);
     counting= 0;
    QJsonObject sendj;
    QJsonDocument doc;
    QString jsonq;
    for (int i = 0;i<UdpHandleList.size();i++) {

        sendj.insert("qc",true);
        sendj.insert("ip",this->LocalIpList.at(i));
        sendj.insert("com",14001);
        sendj.insert("val",14001);
        doc.setObject(sendj);
        QByteArray bytj = doc.toJson(QJsonDocument::Compact);
        jsonq.prepend(bytj);
            UdpHandleList.at(i)->writeDatagram(jsonq.toLocal8Bit(),QHostAddress::Broadcast,4001);
            jsonq.clear();

    }

}

void MainWindow::Rcv_Msg()
{

    char a[2048] = {0};
    for(int i = 0;i<UdpHandleList.size();i++)
    {
        if(UdpHandleList.at(i)->pendingDatagramSize() > 0)
        {
            UdpHandleList.at(i)->readDatagram(a,UdpHandleList.at(i)->pendingDatagramSize());
//            qDebug()<<a;
            counting++;
                 this->ui->lineEdit_2->setText(QString::number(sumpage++));
//            UdpHandleList.at(i)->
        }
        else {

        }
    }

}

int MainWindow::Socket_List_Search()
{
    LocalIpList.clear();
    UdpHandleList.clear();
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    /*筛选仅IPV4*/
        foreach(QHostAddress address,list)
        {
            if(address.protocol() == QAbstractSocket::IPv4Protocol)
            {
                this->LocalIpList.append(address.toString());
                qDebug()<<address.toString();
                QUdpSocket *p = new QUdpSocket();
                p->bind(address,14001);
                connect(p,&QUdpSocket::readyRead,this,&MainWindow::Rcv_Msg);
                UdpHandleList.append(p);
            }
        }
        return LocalIpList.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(this->ui->pushButton->text() == "开始")
        {
            this->AboradTimer->start();
            this->ui->pushButton->setText("暂停");
    }
    else {
        this->AboradTimer->stop();
        this->ui->pushButton->setText("开始");
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString text = QString::number(QDateTime::currentMSecsSinceEpoch() - lastTime);
    this->ui->lineEdit_3->setText(text);
    lastTime = QDateTime::currentMSecsSinceEpoch();
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if((coutingms++ % 50) == 0)
    {
        this->ui->lineEdit_4->setText(QString::number(summs/50));
        summs = 0;
    }

    summs += arg1.toInt();
}
