#ifndef STOPWATCHGAME_H
#define STOPWATCHGAME_H

#include <QMainWindow>
#include<QTime>
#include <QTimer>

namespace Ui {
class stopwatchgame;
}

class stopwatchgame : public QMainWindow
{
    Q_OBJECT
signals:
    void sendMyName(QString name);
public slots:
    void setMyName(QString name);
    void screenshowtime();
public:
    explicit stopwatchgame(QWidget *parent = nullptr);
    ~stopwatchgame();

private slots:
    void on_starB_clicked();

    void on_resetB_clicked();

    void on_saveB_clicked();

    void on_stopB_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::stopwatchgame *ui;
    QTimer* mTimer;
    static int tim;
    QString myname;
};

#endif // STOPWATCHGAME_H
