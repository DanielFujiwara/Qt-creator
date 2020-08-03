#ifndef USERWINDOW_H
#define USERWINDOW_H
#include <QtDebug>
#include "softkey.h"
//#include "welcomepage.h"
#include "weatherclock.h"
#include "newslabel.h"
//#include <QFont>
//#include "accountctrl.h"
#include <QMessageBox>
#include <QMainWindow>
#include "userppt.h"
#include "usermovie.h"

namespace Ui {
class userwindow;
}

class userwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userwindow(QWidget *parent = nullptr);
    ~userwindow();
    void hellolabelset();

signals:
    void sendUserName(QString name);
public slots:
    void setUserName(QString name);
private slots:
    void on_exitBtn_clicked();

    void on_manBtn_clicked();

    void on_gameBtn_clicked();

    void on_videoBtn_clicked();

private:
    Ui::userwindow *ui;
    QString myName;
    softkey *keyBoard;
    newslabel *newsLabel;
//    welcomepage *test;
    weatherclock *weather;
    userppt *userPpt;
    usermovie *movie;
};

#endif // USERWINDOW_H
