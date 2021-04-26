#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void read_adv_msg();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket *rcvsocket;
    QUdpSocket *anssockrt;
};

#endif // MAINWINDOW_H
