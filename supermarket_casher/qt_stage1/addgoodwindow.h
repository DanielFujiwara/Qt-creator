#ifndef ADDGOODWINDOW_H
#define ADDGOODWINDOW_H

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
class addgoodwindow;
}

class addgoodwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addgoodwindow(QWidget *parent = nullptr);
    ~addgoodwindow();
signals:
    void sendreshow();
signals:
    void sendclass(QVector<goodsVector> &shopList,goodsVector &changeclasss);
public slots:
    void getclass(QVector<goodsVector> &shopList,goodsVector &changeclasss);
private slots:
    void on_userEdit_textChanged(const QString &arg1);

    void on_typeEdit_textChanged(const QString &arg1);

    void on_costEdit_textChanged(const QString &arg1);

    void on_priceEdit_textChanged(const QString &arg1);

    void on_stockEdit_textChanged(const QString &arg1);
    void on_sureBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::addgoodwindow *ui;
    QVector<goodsVector> *shopListnew;

    goodsVector *changeclass;
};

#endif // ADDGOODWINDOW_H
