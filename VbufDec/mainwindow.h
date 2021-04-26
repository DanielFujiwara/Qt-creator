#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
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
public slots:
        void Check_Vbuf_full();
private slots:
    void on_pushButton_clicked();

    void on_textBrowser_textChanged();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString LogFilePath;
    QTimer *FileTimer;
    int TimerRun;
    QFile *LogFile;
    qint64 fileLastetsize;
    int errtime;
    int timeflag;
};

#endif // MAINWINDOW_H
