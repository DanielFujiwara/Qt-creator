#ifndef USERCHANGEINFO_H
#define USERCHANGEINFO_H

#include <QMainWindow>

#include <QMainWindow>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
//#include <QDateTime>
//#include <QDir>
#include <QVector>
#include "goods.h"
#include "adminctrl.h"
#include "filejson.h"
namespace Ui {
class userchangeinfo;
}

class userchangeinfo : public QMainWindow
{
    Q_OBJECT
signals:
    void sendclasstome(QString namec);
    void sendreshow();
public slots:
     void setclasstome(QString namec);

public:
    explicit userchangeinfo(QWidget *parent = nullptr);
    ~userchangeinfo();

private slots:
     void on_userEdit_textChanged(const QString &arg1);

     void on_idEdit_textChanged(const QString &arg1);

     void on_passworkEdit_textChanged(const QString &arg1);

     void on_ptEdit_textChanged(const QString &arg1);

     void on_cancleBtn_clicked();

     void on_sureBtn_clicked();

private:
    Ui::userchangeinfo *ui;
    QString idi;
    QString pass;
    QString name;
};

#endif // USERCHANGEINFO_H
