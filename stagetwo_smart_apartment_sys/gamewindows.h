#ifndef GAMEWINDOWS_H
#define GAMEWINDOWS_H

#include <QMainWindow>
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
class gamewindows;
}

class gamewindows : public QMainWindow
{
    Q_OBJECT
signals:
    void sendMyUser(QString name);
public:
    explicit gamewindows(QWidget *parent = nullptr);
    ~gamewindows();
public slots:
    void setMyUser(QString name);
private slots:
    void on_exitBtn_clicked();

    void on_manBtn_clicked();

    void on_gameBtn_clicked();

    void on_videoBtn_clicked();

    void on_lightBtn_clicked();

private:
    Ui::gamewindows *ui;
    newslabel *newsLabel;
//    welcomepage *test;
    weatherclock *weather;
    userppt *userPpt;
    usermovie *movie;
    QString myUser;
};

#endif // GAMEWINDOWS_H
