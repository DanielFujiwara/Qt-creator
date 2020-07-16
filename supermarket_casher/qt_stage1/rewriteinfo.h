#ifndef REWRITEINFO_H
#define REWRITEINFO_H

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


namespace Ui {
class rewriteinfo;
}

class rewriteinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit rewriteinfo(QWidget *parent = nullptr);
    ~rewriteinfo();
signals:
    void sendreloda();
    void sendclass(goods &fileclasss,QString name,QVector<goodsVector> &shopList,goodsVector &changeclasss);
public slots:
    void getclass(goods &fileclasss,QString name,QVector<goodsVector> &shopList,goodsVector &changeclasss);
private slots:
    void on_nameEdit_textChanged(const QString &arg1);

    void on_typeEdit_textChanged(const QString &arg1);

    void on_costEdit_textChanged(const QString &arg1);

    void on_priceEdit_textChanged(const QString &arg1);

    void on_stockEdit_textChanged(const QString &arg1);

    void on_sureBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::rewriteinfo *ui;
    QVector<goodsVector> *shopListc;
    goods *fileclass;
    goodsVector *changeclass;
    QString namec;
};

#endif // REWRITEINFO_H
