#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <qscreen.h>
#include <QtDebug>
#include <QThread>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
static int flag = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("截图工具");
//    QScreen *screen = QGuiApplication::primaryScreen();
//    screen->grabWindow(0).save("123","jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_starBtn_clicked()
{

    if(ui->checkBox->checkState())
    {
        qDebug()<<"checkbox clicked";
        this->hide();

    }

    QString timebox = ui->spinBox->text();
    qDebug()<<timebox;
    timebox = timebox.left(timebox.length() -1);

    QThread::sleep(timebox.toUInt());

    QThread::sleep(1);

    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(0).save("screenshot.jpg","jpg");





   QImage img;
   img.load("./screenshot.jpg");


      pixmap = QPixmap::fromImage(img);
    int w = 370;
    int h = 210;
    QPixmap firpix = pixmap.scaled(w,h,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->screenview->setPixmap(firpix);


    this->show();

    flag = 1;





}

void MainWindow::on_saveBtn_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"保存文件");
    qDebug()<<path;
      this->pixmap.save(path);
    flag = 0;
}

void MainWindow::on_exitBtn_clicked()
{
    if(flag == 1)
    {
        int ret = QMessageBox::information(NULL, "提醒", "有截图未保存是否直接退出？",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(ret == QMessageBox::Yes)
        {
            exit(0);
        }
        else {
            return;
        }
    }


    exit(0);
}
