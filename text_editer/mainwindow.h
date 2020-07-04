#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fileinfo.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>

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
    void on_openbtn_clicked();

    void on_savebtn_clicked();

    void on_backgcbtn_clicked();

    void on_fontbtn_clicked();

    void on_infobtn_clicked();

    void on_cosebtn_clicked();

    void on_exitbtn_clicked();

    void on_fontcol_clicked();

    void on_textEdit_textChanged();

private:
    static int textchange;
    static int filenow;
     QString filename;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
