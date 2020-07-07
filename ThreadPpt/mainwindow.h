#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include "wallpaperthread.h"
#include <QTime>

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
    void pptSetWallpaper(int i);
    void setTime();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    sendCount *th;
    QTime time;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
