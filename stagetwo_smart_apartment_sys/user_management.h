#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <QMainWindow>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <QStringList>
#include "weatherclock.h"
namespace Ui {
class user_management;
}

class user_management : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_management(QWidget *parent = nullptr);
    ~user_management();
    void showStatus();
signals:
    void getMyUserName(QString name);
    void sendAddInfo(QString info);
public slots:
    void setMyUserName(QString name);
    void deleTableItem();
    void addNewInfo(QString info);
private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::user_management *ui;
    QString userName;
    QSqlQuery sqlQuery;
    QSqlDatabase database;
    QStringList deleinfo;
    weatherclock *weatherman;
};

#endif // USER_MANAGEMENT_H
