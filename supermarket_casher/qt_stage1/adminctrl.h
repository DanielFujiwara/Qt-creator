#ifndef ADMINCTRL_H
#define ADMINCTRL_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QTime>
#include <QTimer>
namespace Ui {
class adminctrl;
}

class adminctrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminctrl(QWidget *parent = nullptr);
    ~adminctrl();
    void showGOODStoWi();
    void showUSERStoWi();

public slots:
    void setreshow();
    void screenshowTime();
private slots:
    void on_lodingBtn_clicked();

    void DoubleClicked(QListWidgetItem *item);



    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::adminctrl *ui;
    QTimer *timecount;
    QTime workTime;

    QLabel * namelabel;
    QLabel * typelabel;
    QLabel * stocklabel;
    QLabel * pricelabel;
    QLabel * costlabel;

    QLabel * unamelabel;
    QLabel * passworklabel;
    QLabel * idlabel;
    QLabel * flaglabel;

};

class addGoodsinfo{
public:
    addGoodsinfo(QString name=nullptr,QString cost=nullptr,
                 QString type=nullptr,QString price=nullptr,
                 QString stock=nullptr):name(name),cost(cost),
        type(type),price(price),stock(stock){}

    QString name;
    QString cost;
    QString type;
    QString price;
    QString stock;
};

#endif // ADMINCTRL_H
