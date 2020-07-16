#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"



addnewuserwindow::addnewuserwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addnewuserwindow)
{
    ui->setupUi(this);
    ui->sureBtn->setEnabled(false);
}

addnewuserwindow::~addnewuserwindow()
{
    delete ui;
}

void addnewuserwindow::setclasstome(fileJson &userchangee)
{
    userchange = &userchangee;
}

void addnewuserwindow::on_userEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" &&
            ui->idEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addnewuserwindow::on_idEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" &&
            ui->idEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addnewuserwindow::on_passworkEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" &&
            ui->idEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addnewuserwindow::on_ptEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->ptEdit->text() != "" &&
            ui->idEdit->text() != "")
        ui->sureBtn->setEnabled(true);
}

void addnewuserwindow::on_sureBtn_clicked()
{
    QString name = ui->userEdit->text();
    QString pass = ui->passworkEdit->text();
    QString ptass = ui->ptEdit->text();
    QString idnew = ui->idEdit->text();

    if(! userchange->isNameRepeat(name))
    {
        QMessageBox::warning(this,"Woring","已经存在此用户名");
        return;
    }

    if(pass != ptass)
    {
        QMessageBox::warning(this,"Woring","两次密码不同");
        return;
    }

    int ret = userchange->checkId(idnew);
    if(ret != -1)
    {
        QMessageBox::warning(this,"Woring","ID重复");
        return;
    }
    userchange->insertNewAcount(name,pass,"收银员",idnew);
    userchange->reloadJDOdata();
    emit this->sendreshow();
   this->close();




}

void addnewuserwindow::on_cancleBtn_clicked()
{
    this->close();
}
