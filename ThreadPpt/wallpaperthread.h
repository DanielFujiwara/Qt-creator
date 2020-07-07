#ifndef WALLPAPERTHREAD_H
#define WALLPAPERTHREAD_H

#include <QThread>
#include <QtDebug>
//#include "mainwindow.h"

class sendCount :public QThread
{
    Q_OBJECT
public:
    explicit sendCount(QWidget *parent = nullptr){}
    ~sendCount(){}


    void run() override {
        int i = 0;
        while(1)
        {

            QThread::sleep(1);
            emit SendToMian(i%4);
            i++;
            qDebug()<<"msg sent";
        }
    }

signals:
    void SendToMian(int i);
};
#endif // WALLPAPERTHREAD_H
