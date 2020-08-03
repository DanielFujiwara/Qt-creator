#include "textfileinfo.h"
#include "ui_textfileinfo.h"
#include <QFile>
#include <QDateTime>
#include <QFileInfo>
#include <QTime>
#include <QtDebug>
#include <string.h>
#include <cstring>
using namespace std;

textfileinfo::textfileinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fileinfo)
{
    ui->setupUi(this);
     textfileinfo::setWindowTitle("文件信息");
}

textfileinfo::~textfileinfo()
{
    printf("~textfileinfo\n");
    delete ui;
}

void textfileinfo::on_pushButton_clicked()
{
    this->close();
    return;
}

void textfileinfo::showinfo(QString path)
{
    QFileInfo  info(path);
    QString name = "名   字: ";
    name += info.fileName().toUtf8().data();
    ui->textBrowser->append(name);
    QString backname = "后   缀： ";
    backname += info.suffix();
    ui->textBrowser->append(backname);
    QString sizef = "大   小： ";
    sizef += QString::number(info.size());
    ui->textBrowser->append(sizef);
    QString timef = "创建时间：";
    QDateTime t = info.created();
    qDebug()<<t;
//    time.toString("yyyy-MM-dd hh:mm:ss");
    timef += t.toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->append(timef);









}
