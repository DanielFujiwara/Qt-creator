#include "billcheck.h"
#include "ui_billcheck.h"
#include <QFile>
billcheck::billcheck(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::billcheck)
{
    ui->setupUi(this);
    QFile file("../sold.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
//         QMessageBox::warning(this,"woring","open error");
         return;
    }

    QByteArray array = file.readAll();
//    ui->->setPlainText(array);
    ui->textBrowser->setPlainText(array);
    file.close();

}

billcheck::~billcheck()
{
    delete ui;
}

void billcheck::on_pushButton_clicked()
{
    this->close();
}

