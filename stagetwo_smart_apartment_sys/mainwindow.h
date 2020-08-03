#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include "softkey.h"
//#include "welcomepage.h"
#include "weatherclock.h"
#include "newslabel.h"
#include <QFont>
#include "accountctrl.h"
#include <QMessageBox>
#include "createacount.h"
#include "userwindow.h"
#include "user_management.h"
#include "manwindows.h"
#include "rfidclassthread.h"
namespace Ui {
class MainWIndow;
}

class MainWIndow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWIndow(QWidget *parent = nullptr);
    ~MainWIndow();
    void getWeatherData();
    bool eventFilter(QObject *watched, QEvent *event);



private slots:
    void on_userEdit_editingFinished();

    void on_passworkEdit_editingFinished();


    void on_userBtn_clicked();

    void on_passBtn_clicked();

    void on_userEdit_textChanged(const QString &arg1);

    void on_passworkEdit_textChanged(const QString &arg1);

    void on_loginBtn_clicked();

    void on_creaBtn_clicked();

    void getIDLoginAdmin(unsigned int ID);
    void on_pushButton_clicked();

    void runRFID();
//    void on_pushButton_2_clicked();

private:
    Ui::MainWIndow *ui;
    softkey *keyBoard;
    newslabel *newsLabel;
//    welcomepage *test;
    weatherclock *mweather;
    rfidClassThread *th;
//    int dei;
//    int welcome;

};

#endif // MAINWINDOW_H
