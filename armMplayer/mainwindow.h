#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void getWeatherData();


public slots:
    void screenshow();
    void read_data(QNetworkReply* reply);
    void labelchange();

private:
    Ui::MainWindow *ui;
    QProcess mProcess;
    QTime mtime;
    QDate mdata;
    QTimer *mTimer;
    QTimer *mTimerlabel;
    QNetworkAccessManager *manager;
};

#endif // MAINWINDOW_H
