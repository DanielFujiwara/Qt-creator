#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
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
    void newCilent();
    void recvFile();
private:
    Ui::MainWindow *ui;
    QTcpServer server;
    QFile file;
    QString filename;
    quint64 filesize;
    quint64 recvsize;
};

#endif // MAINWINDOW_H
