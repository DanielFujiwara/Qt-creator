#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
using namespace std;

int MainWindow::tim = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTimer = new QTimer(this);
    connect(mTimer,&QTimer::timeout,this,&MainWindow::screenshowtime);
    mTimer->setInterval(1);




//    ui->screen->setText(t.toString("hh:mm:ss:zzz"));






}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_starB_clicked()
{
    mTimer->start();
}

void MainWindow::on_saveB_clicked()
{
    ui->textBrowser->append(ui->screen->text());
}

void MainWindow::on_resetB_clicked()
{
    mTimer->stop();
    tim = 0;
    QTime t(0,0,0);
    t = t.addMSecs(tim);
    ui->screen->setText(t.toString("hh:mm:ss:zzz"));
}

void MainWindow::on_stopB_clicked()
{
    mTimer->stop();
}

void MainWindow::screenshowtime()
{
    tim++;
    QTime t(0,0,0);
    t = t.addMSecs(tim);
    ui->screen->setText(t.toString("hh:mm:ss:zzz"));
}
