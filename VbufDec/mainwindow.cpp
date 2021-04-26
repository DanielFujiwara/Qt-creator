#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->FileTimer = new QTimer(this);
//    FileTimer->setInterval(15000);
    connect(FileTimer,&QTimer::timeout,this,&MainWindow::Check_Vbuf_full);
    TimerRun = 0;
    this->LogFile = nullptr;
    errtime = 0;
    timeflag = 0;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Check_Vbuf_full()
{
    if(TimerRun == 0 || LogFile == nullptr)
        return;


    this->LogFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QString bufSet;
    if(this->fileLastetsize == LogFile->size())
    {
//        QMessageBox *boxWoring = new QMessageBox(this);
//         boxWoring->warning(this,"woring",woringString);
//        this->show();
        bufSet = "ERR :" + QTime::currentTime().toString();
        this->ui->textBrowser->append(bufSet);

        if(timeflag == 0)
        {
            errtime++;
        }
        timeflag = 1;


    }
    else {
        this->fileLastetsize = LogFile->size();
        timeflag = 0;
//        bufSet = "checked :" + QTime::currentTime().toString();
//        this->ui->textBrowser->append("checked");

    }
    QString errstring = QString::number(errtime);
    this->ui->lineEdit_3->setText(errstring);
    LogFile->close();

}

void MainWindow::on_pushButton_clicked()
{
    if(TimerRun == 1)
    {
        this->FileTimer->stop();
        this->LogFile->close();
        this->LogFile = nullptr;
        this->TimerRun = 0;
        errtime = 0;
    }

    this->LogFilePath = QFileDialog::getOpenFileName(this);
    if(LogFilePath.size()<5)
        return;
    this->ui->lineEdit->setText(LogFilePath);
    LogFile = new QFile(this->LogFilePath);
    if(!LogFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"woring","open error");
        return;
    }
    TimerRun = 1;
    fileLastetsize = LogFile->size();
    this->LogFile->close();
    QString timeOut = this->ui->lineEdit_2->text();
    int timeoutint = timeOut.toInt() *1000;
    this->FileTimer->setInterval(timeoutint);
    this->FileTimer->start();
}

void MainWindow::on_textBrowser_textChanged()
{
//    QTime nowTime;
//    nowTime = QTime::currentTime();
//    QString woringString = nowTime.toString();
//    QMessageBox *boxWoring = new QMessageBox();
//        boxWoring->setWindowFlags(Qt::WindowStaysOnTopHint);
//    boxWoring->warning(this,"woring",woringString);

//    this->hide();
//    this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->errtime = 0;
    timeflag = 0;
    this->ui->textBrowser->clear();
}
