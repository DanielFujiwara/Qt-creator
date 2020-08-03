#ifndef NEWSLABEL_H
#define NEWSLABEL_H
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
#include <QWidget>
#include <QFile>

namespace Ui {
class newslabel;
}

class newslabel : public QWidget
{
    Q_OBJECT

public:
    explicit newslabel(QWidget *parent = nullptr);
    ~newslabel();
public:
    void getNewsData();


public slots:
    void loadFile();
    void read_data(QNetworkReply* reply);
    void showToLabel();

private:
    Ui::newslabel *ui;
    QTimer *mTimer;
    QByteArray datafile;
    QNetworkAccessManager *manager;
};

#endif // NEWSLABEL_H
