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
public slots:
    void newClientConnect();
    void newMsg();

private slots:
    void on_startBtn_clicked();

    void on_sendBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer server;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
