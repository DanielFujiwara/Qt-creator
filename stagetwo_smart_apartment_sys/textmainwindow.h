#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "textfileinfo.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QtDebug>
#include <QFile>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include "softkey.h"


namespace Ui {
class MainWindow;
}

class textMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit textMainWindow(QWidget *parent = nullptr);
    ~textMainWindow();
signals:
    void sendMyName(QString name);
public slots:
    void setMyName(QString name);
    bool eventFilter(QObject *watched, QEvent *event);


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

    void on_userBtn_clicked();

    void on_textEdit_selectionChanged();

private:
    static int textchange;
    static int filenow;
     QString filename;
    Ui::MainWindow *ui;
    QString myname;
    softkey *keyBoard;
};

#endif // MAINWINDOW_H
