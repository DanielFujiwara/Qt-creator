#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sendBtn->setEnabled(false);
    ui->openBtn->setEnabled(true);
    connect(&socket,&QTcpSocket::connected,this,&MainWindow::sendFileInfo);
    connect(&socket,&QTcpSocket::bytesWritten,this,&MainWindow::sendFileData);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openBtn_clicked()
{
    filePathQs = QFileDialog::getOpenFileName(this);
    ui->filePath->setText(filePathQs);

    qDebug()<<"file :"<<filePathQs<<"  success!";

    if(ui->filePath->text() != "" && ui->ipEdit->text() != "" && ui->comEdit->text() != "")
        ui->sendBtn->setEnabled(true);
}

void MainWindow::on_sendBtn_clicked()
{
    QString ipServer = ui->ipEdit->text();
    QString comServer = ui->comEdit->text();
    socket.connectToHost(ipServer,comServer.toUShort());
    filesize = 0;
    sendsize = 0;
    qDebug()<<"connecting to host";



}

void MainWindow::on_ipEdit_textChanged(const QString &arg1)
{
    if(ui->filePath->text() != "" && ui->ipEdit->text() != "" && ui->comEdit->text() != "")
        ui->sendBtn->setEnabled(true);
}

void MainWindow::on_comEdit_textChanged(const QString &arg1)
{
    if(ui->filePath->text() != "" && ui->ipEdit->text() != "" && ui->comEdit->text() != "")
        ui->sendBtn->setEnabled(true);
}

void MainWindow::sendFileInfo()
{
       QFileInfo info(filePathQs);
       filename = info.fileName();
       filesize = static_cast<quint64>(info.size());
       ui->progressBar->setMaximum(static_cast<int>(filesize));
       qDebug()<<"get file info:"<<filename<<" "<<filesize;

       QByteArray arry;
       QDataStream outout(&arry,QIODevice::WriteOnly);
       outout <<filesize << filename;
       socket.write(arry);
       file.setFileName(filePathQs);
       file.open(QIODevice::ReadOnly);
       qDebug()<<"file open success ready to send";



}

void MainWindow::sendFileData()
{
    if(sendsize < filesize)
    {
        QByteArray arry = file.read(1024*10);
        socket.write(arry);
        sendsize += static_cast<quint64>( arry.size());
        qDebug()<<"sending:"<<sendsize;
        ui->progressBar->setValue(static_cast<int>( sendsize));

    }
    if(sendsize == filesize)
    {
        file.close();
        qDebug()<<"send all";
    }
}
