#ifndef REPAIRECTRL_H
#define REPAIRECTRL_H

#include <QMainWindow>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <QStringList>

namespace Ui {
class repairectrl;
}

class repairectrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit repairectrl(QWidget *parent = nullptr);
    ~repairectrl();
    void showStatus();

signals:
//    void getMyUserName(QString name);
    void sendAddInfo(QString info);

public slots:
//    void setMyUserName(QString name);
    void deleTableItem();
    void addNewInfo(QString info);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::repairectrl *ui;
//    QString userName;
    QSqlQuery sqlQuery;
    QSqlDatabase database;
    QStringList deleinfo;
//    weatherclock *weatherman;
};

#endif // REPAIRECTRL_H
