#ifndef CREATEACOUNT_H
#define CREATEACOUNT_H

#include <QMainWindow>
#include "softkey.h"
#include <QtDebug>
#include "accountctrl.h"
#include "weatherclock.h"
#include "newslabel.h"
#include "rfidclassthread.h"
namespace Ui {
class createacount;
}

class createacount : public QMainWindow
{
    Q_OBJECT

public:
    explicit createacount(QWidget *parent = nullptr);
    ~createacount();
    bool eventFilter(QObject *watched, QEvent *event);
    void runRFIDCreat();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_userBtn_clicked();

    void on_passBtn_clicked();

    void on_passBtn_2_clicked();

    void on_userEdit_editingFinished();

    void on_passworkEdit_editingFinished();

    void on_passworkEdit_2_editingFinished();

    void on_userEdit_textChanged(const QString &arg1);

    void on_passworkEdit_textChanged(const QString &arg1);

    void on_passworkEdit_2_textChanged(const QString &arg1);

    void on_cardEdit_textChanged(const QString &arg1);

private:
    Ui::createacount *ui;
    softkey *keyBoardc;
    weatherclock *weather1;
    newslabel *newsLa;
    rfidClassThread th1;

};

#endif // CREATEACOUNT_H
