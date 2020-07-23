#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <qscreen.h>


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
    void on_starBtn_clicked();

    void on_saveBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
