#ifndef BILLWINDOW_H
#define BILLWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtDebug>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QMessageBox>
#include "shopitemlist.h"
#include "goods.h"
#include "shopcarvector.h"

namespace Ui {
class billwindow;
}

class billwindow : public QMainWindow
{
    Q_OBJECT
signals:
    void sendMylist(QVector<shopcar> & shopCarList,QString ids);
public slots:
    void getMylist(QVector<shopcar> & shopCarList,QString ids);

public:
    explicit billwindow(QWidget *parent = nullptr);
    ~billwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::billwindow *ui;
     QVector<shopcar> byebyelist;
};

#endif // BILLWINDOW_H
