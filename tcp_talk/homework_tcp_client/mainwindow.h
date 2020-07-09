#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendHostIp();
private slots:
    void on_startBtn_clicked();
    void connectSuccess();
//    void connectErro();
    void on_sendBtn_clicked();
    void newMsg();

    void on_clearBtn_clicked();
    void setHostIp();

private:
    Ui::MainWindow *ui;
    QTcpSocket socket;
    QString hostip;
};

#endif // MAINWINDOW_H
