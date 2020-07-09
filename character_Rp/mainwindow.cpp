#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    ui->label_scor->hide();
    ui->label_word->hide();
    ui->label_name->hide();
    connect(ui->pushStart,&QPushButton::clicked,this,&MainWindow::testresult);
    connect(ui->pushStart_2,&QPushButton::clicked,this,&MainWindow::retry);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testresult()
{
    if((ui->lineName->text()) == "")
    {
        QMessageBox::warning(this,"woring","名字不能为空！");
        retry();

        return;
    }

    ui->label_scor->show();
    ui->label_word->show();
    ui->label_name->show();

    ui->label_name_2->setText(ui->lineName->text());



    int a = rand()%100;
    qDebug() << a;
    if((ui->lineName->text()) == "刘惠铭")
        a = 100;


        ui->label_name_3->setText(QString::number(a));

    if(0 <= a && a < 34)
    {
        ui->label_name_4->setText("你的评分有点差喔！");
    }
    else if(a < 68)
    {
        ui->label_name_4->setText("你的评分一般般而已喔！");
    }
    else {
        ui->label_name_4->setText("你的评分很好喔！");
    }

}

void MainWindow::retry()
{
    ui->label_scor->hide();
    ui->label_word->hide();
    ui->label_name->hide();
    ui->label_name_3->setText("");
    ui->label_name_2->setText("");
    ui->label_name_4->setText("");
    ui->lineName->setText("");
}

void MainWindow::on_pushButton_clicked()
{

}
