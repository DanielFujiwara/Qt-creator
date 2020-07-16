#include "loginwindows.h"
#include "ui_loginwindows.h"
#include <filejson.h>
#include "filejson.h"
#include <QMessageBox>
#include "simplecasherctrl.h"
#include "adminctrl.h"
fileJson loginClass;
loginWindows::loginWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindows)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("登录界面");
    ui->loginBtn->setEnabled(false);
    ui->pushButton->setIconSize(QSize(21,21));
    ui->pushButton->setIcon(QIcon(":/pic/eye.jpg"));
    ui->userEdit->setText("hewei");
    ui->passworkEdit->setText("1313");



}

loginWindows::~loginWindows()
{
    delete ui;
}

void loginWindows::on_loginBtn_clicked()
{


    QString flag;
    QString id;
    int ret = loginClass.loginProgram(flag,ui->userEdit->text(),ui->passworkEdit->text(),id);
//    qDebug()<<flag<<"a"<<ret;
    if(ret == -2)
    {
        QMessageBox::warning(this,"Woring","错误次数过多，违规操作！");
        exit(0);
    }
    else if(ret == -1)
    {
        QMessageBox::warning(this,"Woring","密码或账号错误！");
    }
    else if(ret ==1)
    {
        qDebug()<<"user"<<id;
        simplecasherctrl *casher = new simplecasherctrl(this);
        connect(casher,&simplecasherctrl::sendID,casher,&simplecasherctrl::setID);
        emit casher->sendID(id);
        casher->show();
        ui->passworkEdit->setText("");
        ui->userEdit->setText("");
        ui->loginBtn->setEnabled(false);
        this->hide();
    }
    else if (ret == 2) {
        qDebug()<<"admin";
        adminctrl *admin = new adminctrl(this);
        admin->show();
        ui->passworkEdit->setText("");
        ui->userEdit->setText("");
        ui->loginBtn->setEnabled(false);
        this->hide();

    }
}

void loginWindows::on_creatBtn_clicked()
{
    exit(0);
}



void loginWindows::on_userEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" && ui->passworkEdit->text() != "")
        ui->loginBtn->setEnabled(true);
    else {
        ui->loginBtn->setEnabled(false);
    }


}

void loginWindows::on_passworkEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" && ui->passworkEdit->text() != "")
        ui->loginBtn->setEnabled(true);
    else {
        ui->loginBtn->setEnabled(false);
    }


}

void loginWindows::on_pushButton_pressed()
{
    ui->passworkEdit->setEchoMode(QLineEdit::Normal);
//    ui->pushButton;
    ui->pushButton->setIconSize(QSize(20,30));
    ui->pushButton->setIcon(QIcon(":/pic/eyedisp.jpg"));
}

void loginWindows::on_pushButton_released()
{
    ui->passworkEdit->setEchoMode(QLineEdit::Password);
    ui->pushButton->setIconSize(QSize(20,30));
    ui->pushButton->setIcon(QIcon(":/pic/eye.jpg"));
}
