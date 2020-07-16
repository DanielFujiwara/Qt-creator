#ifndef SIMPLECASHERCTRL_H
#define SIMPLECASHERCTRL_H
#include "goods.h"
#include <QMainWindow>
#include <QtDebug>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class simplecasherctrl;
}

class simplecasherctrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit simplecasherctrl(QWidget *parent = nullptr);
    ~simplecasherctrl();
    void setCarwidgets();
signals:
    void sendID(QString ID);
public slots:
    void setID(QString ID);
public:
    void setListWidgets(QVector<goodsVector> & shopList);
private slots:
    void on_pushButton_2_clicked();
    void screenshowTime();



    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_addBtn_clicked();

    void on_pushButton_3_clicked();

    void on_reduceBtn_clicked();

    void on_listWidget_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::simplecasherctrl *ui;
    QTimer *timecount;
    QTime workTime;
    QLabel * namelabel;
    QLabel * stocklabel;
    QLabel * pricelabel;
    QString IDw;
// ////////////////////////
    QLabel * pricelabelCar;
    QLabel * namelabelCar;
    QLabel * numlabelCar;
    QLabel * ppricelabelCar;

};



#endif // SIMPLECASHERCTRL_H
