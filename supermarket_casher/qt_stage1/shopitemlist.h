#ifndef SHOPITEMLIST_H
#define SHOPITEMLIST_H

#include <QWidget>
#include <QtDebug>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class shopitemlist;
}

class shopitemlist : public QWidget
{
    Q_OBJECT

public:
    explicit shopitemlist(QWidget *parent = nullptr);
    ~shopitemlist();
signals:
    void sendData(QString name,QString type,QString price,QString stock);
public slots:
    void setData(QString name,QString type,QString price,QString stock);
private:
    Ui::shopitemlist *ui;
};

#endif // SHOPITEMLIST_H
