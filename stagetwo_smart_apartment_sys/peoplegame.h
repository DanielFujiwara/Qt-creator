#ifndef PEOPLEGAME_H
#define PEOPLEGAME_H

#include <QMainWindow>
#include "softkey.h"

namespace Ui {
class peoplegame;
}

class peoplegame : public QMainWindow
{
    Q_OBJECT
signals:
    void sendName(QString name);
public:
    explicit peoplegame(QWidget *parent = nullptr);
    ~peoplegame();
    bool eventFilter(QObject *watched, QEvent *event);
public slots:
    void on_pushStart_clicked();
    void setMyName(QString name);
    void retry();
    void on_pushStart_2_clicked();

    void on_userBtn_clicked();

    void on_lineName_editingFinished();

    void on_commandLinkButton_clicked();

private:
    Ui::peoplegame *ui;
    softkey *keyBoard;
    QString myname;
};

#endif // PEOPLEGAME_H
