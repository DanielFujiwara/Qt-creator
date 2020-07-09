#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtDebug>
#include <QFileDialog>
#include <QTcpSocket>
#include <QTcpServer>


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
    void on_openBtn_clicked();

    void on_sendBtn_clicked();

    void on_ipEdit_textChanged(const QString &arg1);

    void on_comEdit_textChanged(const QString &arg1);
public slots:
    void sendFileInfo();
    void sendFileData();

private:
    Ui::MainWindow *ui;
    QTcpSocket socket;
    QString filename;
    quint64 filesize;
    quint64 sendsize;
    QFile file;
    QString filePathQs;

};

#endif // MAINWINDOW_H
