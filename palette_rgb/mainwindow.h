#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_redSlider_sliderMoved(int position);

    void on_greenSlider_sliderMoved(int position);

    void on_blueSlider_sliderMoved(int position);



    void on_userset_clicked();

    void on_user_0_clicked();

    void on_user_1_clicked();

    void on_user_2_clicked();

private:
    Ui::MainWindow *ui;
    static int flag;
};

#endif // MAINWINDOW_H
