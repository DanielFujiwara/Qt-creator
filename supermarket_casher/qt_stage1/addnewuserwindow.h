#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

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
class addnewuserwindow;
}

class addnewuserwindow : public QMainWindow
{
    Q_OBJECT
signals:
    void sendclasstome(fileJson &userchangee);
    void sendreshow();
public slots:
     void setclasstome(fileJson &userchangee);
public:
    explicit addnewuserwindow(QWidget *parent = nullptr);
    ~addnewuserwindow();

private slots:
     void on_userEdit_textChanged(const QString &arg1);

     void on_idEdit_textChanged(const QString &arg1);

     void on_passworkEdit_textChanged(const QString &arg1);

     void on_ptEdit_textChanged(const QString &arg1);

     void on_sureBtn_clicked();

     void on_cancleBtn_clicked();

private:
    Ui::addnewuserwindow *ui;
    fileJson *userchange;

};

#endif // ADDNEWUSERWINDOW_H
