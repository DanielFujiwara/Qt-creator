#ifndef WEATHERCLOCK_H
#define WEATHERCLOCK_H

#include <QWidget>
#include <QProcess>
#include <QPixmap>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QTextCodec>
//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}


namespace Ui {
class weatherclock;
}

class weatherclock : public QWidget
{
    Q_OBJECT

public:
    explicit weatherclock(QWidget *parent = nullptr);
    ~weatherclock();
    int getTemp();
    int getHum();
    QTimer *mTimer;
public:

    int whatTime();

public slots:
    void screenshow();
    void read_data(QNetworkReply* reply);
    void setInfoPic();
    void setTemTips();
    void setFlower();
    void getWeatherData();
private:
    Ui::weatherclock *ui;
    QTime mtime;
    QDate mdata;

    QNetworkAccessManager *manager;
    int temnow;
    int humnow;
    QString infonow;
//    QTimer *weathertimer;
};

#endif // WEATHERCLOCK_H
