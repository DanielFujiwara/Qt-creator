#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QHostInfo>
#include <QtDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <string.h>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
        void AboradTimer_Timeout();
public slots:
    void Send_LocalIp();
    void Rcv_Msg();
public:
    int Socket_List_Search();
    void Listen_UdpSocket();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTimer *AboradTimer;
    QUdpSocket *sock;
    QStringList LocalIpList;
    QList<QUdpSocket *> UdpHandleList;
    int counting;
    long long int sumpage;
    qint64 lastTime;
    int coutingms;
    int summs;
};

#endif // MAINWINDOW_H
