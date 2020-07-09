#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

int MainWindow::flag = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->redSlider->setValue(170);
    ui->greenSlider->setValue(170);
    ui->blueSlider->setValue(0);
    ui->redlabel->setText("170");
    ui->greenlabel->setText("170");
    ui->bluetabel->setText("0");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_redSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = position;
    int green = ui->greenSlider->value();
    int blue = ui->blueSlider->value();



    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);

    qDebug() << "color = " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
    ui->redlabel->setText(QString::number(red));
    ui->plletenLabel->setStyleSheet(color);

}

void MainWindow::on_greenSlider_sliderMoved(int position)
{
    //获取滑动条的值，并设置调色板的色
    int red = ui->redSlider->value();
    int green = position;
    int blue = ui->blueSlider->value();



    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);

    qDebug() << "color = " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
    ui->greenlabel->setText(QString::number(green));
    ui->plletenLabel->setStyleSheet(color);
}

void MainWindow::on_blueSlider_sliderMoved(int position)
{
    int red = ui->redSlider->value();
    int green = ui->greenSlider->value();
    int blue = position;



    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(red).arg(green).arg(blue);

    qDebug() << "color = " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
    ui->bluetabel->setText(QString::number(blue));
    ui->plletenLabel->setStyleSheet(color);
}



void MainWindow::on_userset_clicked()
{
    if(flag >2)
        flag = 0;

    if(flag == 0)
    {
        int red = ui->redSlider->value();
        int green = ui->greenSlider->value();
        int blue = ui->blueSlider->value();

        QString color = QString("background-color: rgb(%1, %2, %3);")
                         .arg(red).arg(green).arg(blue);

        qDebug() << "color = " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
//        ui->bluetabel->setText(QString::number(blue));
        ui->user_0->setStyleSheet(color);

    }
    else if (flag == 1) {
        int red = ui->redSlider->value();
        int green = ui->greenSlider->value();
        int blue = ui->blueSlider->value();

        QString color = QString("background-color: rgb(%1, %2, %3);")
                         .arg(red).arg(green).arg(blue);

        qDebug() << "color = " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
//        ui->bluetabel->setText(QString::number(blue));
        ui->user_1->setStyleSheet(color);
    }
    else {
        int red = ui->redSlider->value();
        int green = ui->greenSlider->value();
        int blue = ui->blueSlider->value();

        QString color = QString("background-color: rgb(%1, %2, %3);")
                         .arg(red).arg(green).arg(blue);

        qDebug() << "color  " << color<<"red:"<<red<<"green"<<green<<"blue"<<blue;
//        ui->bluetabel->setText(QString::number(blue));
        ui->user_2->setStyleSheet(color);
    }

    flag++;



}

void MainWindow::on_user_0_clicked()
{
    flag = 0;
    QPalette pal = ui->user_0->palette();
    QBrush bush = pal.base();
    QColor col = bush.color();
    int r = col.red();
    int g = col.green();
    int b = col.blue();
    ui->redSlider->setValue(r);
    ui->greenSlider->setValue(g);
    ui->blueSlider->setValue(b);
    ui->redlabel->setText(QString::number(r));
    ui->greenlabel->setText(QString::number(g));
    ui->bluetabel->setText(QString::number(b));

    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(r).arg(g).arg(b);

    qDebug() << "color = " << color<<"red:"<<r<<"green"<<g<<"blue"<<b;
//        ui->bluetabel->setText(QString::number(blue));
    ui->plletenLabel->setStyleSheet(color);

}

void MainWindow::on_user_1_clicked()
{
    flag = 1;
    QPalette pal = ui->user_0->palette();
    QBrush bush = pal.base();
    QColor col = bush.color();
    int r = col.red();
    int g = col.green();
    int b = col.blue();
    ui->redSlider->setValue(r);
    ui->greenSlider->setValue(g);
    ui->blueSlider->setValue(b);
    ui->redlabel->setText(QString::number(r));
    ui->greenlabel->setText(QString::number(g));
    ui->bluetabel->setText(QString::number(b));

    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(r).arg(g).arg(b);

    qDebug() << "color = " << color<<"red:"<<r<<"green"<<g<<"blue"<<b;
//        ui->bluetabel->setText(QString::number(blue));
    ui->plletenLabel->setStyleSheet(color);

}

void MainWindow::on_user_2_clicked()
{
    flag = 2;
    QPalette pal = ui->user_0->palette();
    QBrush bush = pal.base();
    QColor col = bush.color();
    int r = col.red();
    int g = col.green();
    int b = col.blue();
    ui->redSlider->setValue(r);
    ui->greenSlider->setValue(g);
    ui->blueSlider->setValue(b);
    ui->redlabel->setText(QString::number(r));
    ui->greenlabel->setText(QString::number(g));
    ui->bluetabel->setText(QString::number(b));

    QString color = QString("background-color: rgb(%1, %2, %3);")
                     .arg(r).arg(g).arg(b);

    qDebug() << "color = " << color<<"red:"<<r<<"green"<<g<<"blue"<<b;
//        ui->bluetabel->setText(QString::number(blue));
    ui->plletenLabel->setStyleSheet(color);

}
