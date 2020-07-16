#include "userchangeinfo.h"
#include "ui_userchangeinfo.h"

fileJson userchange;
void userchangeinfo::setclasstome(QString namec)
{

    name = namec;
    qDebug()<<__LINE__;
    int ret = userchange.locaUsername(name);
    ui->userEdit->setText(name);
    qDebug()<<__LINE__;
     QJsonArray userdata = userchange.fileJOdata.value("userdata").toArray();
     QJsonObject nameInside = userdata.at(ret).toObject();
    idi = nameInside.value("id").toString();
//    QString flag = nameInside.value("flag").toString();
    pass = nameInside.value("passwork").toString();
   qDebug()<<__LINE__;
    ui->idEdit->setText(idi);
    ui->passworkEdit->setText(pass);
    ui->ptEdit->setText(pass);

}

userchangeinfo::userchangeinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userchangeinfo)
{
    ui->setupUi(this);
    ui->sureBtn->setEnabled(false);
}

userchangeinfo::~userchangeinfo()
{
    delete ui;
}

void userchangeinfo::on_userEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->idEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" )
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void userchangeinfo::on_idEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->idEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" )
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }

    if(ui->idEdit->text() != idi)
    {
        QMessageBox::warning(this,"Woring","不想你修改ID,9527是你终生编号！");
        ui->idEdit->setText(idi);
        return;
    }
}

void userchangeinfo::on_passworkEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->idEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" )
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void userchangeinfo::on_ptEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->idEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" )
        ui->sureBtn->setEnabled(true);
    else {
        ui->sureBtn->setEnabled(false);
    }
}

void userchangeinfo::on_cancleBtn_clicked()
{
    this->close();
}

void userchangeinfo::on_sureBtn_clicked()
{
    if(ui->ptEdit->text() != ui->passworkEdit->text())
    {
        QMessageBox::warning(this,"Woring","两次密码不相同");
        return;
    }

   int ret =  userchange.locaUsername(name);

   QJsonArray userdata = userchange.fileJOdata.value("userdata").toArray();

   for(int i = 0 ;i<userdata.size();i++)
   {
       QJsonObject nameInside = userdata.at(i).toObject();
       QString nameI = nameInside.value("name").toString();
       if(ui->userEdit->text() == nameI)
       {
           qDebug()<<"name:"<<name<<"is located";
           if(i == ret)
           {
               continue;
           }
           else {
               QMessageBox::warning(this,"Woring","用户名重复");
               return;
           }
       }
       else {
           continue;
       }
   }

//    qDebug()<<"sleep";

   userchange.changeUserName(ret,ui->userEdit->text());
   userchange.changeUserPasswork(ret,ui->passworkEdit->text());
    emit sendreshow();
   this->close();



}
