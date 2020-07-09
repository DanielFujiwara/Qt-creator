#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTime>
#include <QTimer>
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
    void on_starB_clicked();

    void on_saveB_clicked();

    void on_resetB_clicked();

    void on_stopB_clicked();
public slots:
    void screenshowtime();
private:
    Ui::MainWindow *ui;
    QTimer* mTimer;
    static int tim;
};

#endif // MAINWINDOW_H
