#include "createacount.h"
#include "ui_createacount.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "rfidclassthread.h"
#include <QThread>
#include "rfidclassthread.h"
#include "readrfidid.h"


createacount::createacount(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::createacount)
{
    ui->setupUi(this);
    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    // 软键盘初始化
    keyBoardc = new softkey(ui->centralwidget);
    keyBoardc->move(45,260);
    keyBoardc->hide();

    ui->userEdit->installEventFilter(this);
    ui->passworkEdit->installEventFilter(this);
    ui->passworkEdit_2->installEventFilter(this);
    ui->cardEdit->installEventFilter(this);

    //天气模块
    weather1 = new weatherclock(this);
    weather1->move(600,0);
    weather1->show();
//    weather1->whatTime();
    connect(weather1->mTimer,&QTimer::timeout,weather1,&weatherclock::screenshow);
    // 新闻模块
    newsLa = new newslabel(this);
    newsLa->move(0,430);
    newsLa->show();

    // 按钮初始化
    ui->userBtn->hide();
    ui->passBtn->hide();
    ui->passBtn_2->hide();
    ui->pushButton->setEnabled(false);

    //二次密码label颜色设置
    QPalette pe;

    pe.setColor(QPalette::WindowText, Qt::red);

    ui->passworkLabel->setPalette(pe);
}

createacount::~createacount()
{
    printf("~createacount\n");
    delete ui;
}

bool createacount::eventFilter(QObject *watched, QEvent *event)
{

    if ( (watched == ui->userEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
            keyBoardc->show();
            keyBoardc->raise();
            ui->userBtn->show();
            ui->userEdit->resize(200,50);
            weather1->hide();
            newsLa->hide();
//            ui->userEdit->setFont(QFont("黑体,20,QFont::Bold"));
            ui->userEdit->setStyleSheet("font: 16pt 黑体;");

         ui->userEdit->setFocus();
    }
    else if ( (watched == ui->passworkEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        keyBoardc->show();
        keyBoardc->raise();
        ui->passBtn->show();
        ui->passworkEdit->resize(200,50);
         ui->passworkEdit->setStyleSheet("font: 16pt 黑体;");
         weather1->hide();
         newsLa->hide();
        ui->passworkEdit->setFocus();
    }
    else if ((watched == ui->passworkEdit_2) && (event->type() == QEvent::MouseButtonPress)) {
        keyBoardc->show();
        keyBoardc->raise();
        ui->passBtn_2->show();
        ui->passworkEdit_2->resize(200,50);
        ui->passworkEdit_2->move(280,170);
        ui->label_4->move(190,180);
        ui->passBtn_2->move(490,180);
         ui->passworkEdit_2->setStyleSheet("font: 16pt 黑体;");
         weather1->hide();
         newsLa->hide();
        ui->passworkEdit_2->setFocus();
    }
    else if ((watched == ui->cardEdit) && (event->type() == QEvent::MouseButtonPress)) {
        ui->cardEdit->setText("none");
        ui->cardEdit->setFocus();

    }

    return QMainWindow::eventFilter(watched,event);
}

void createacount::runRFIDCreat()
{
//    th1 = new rfidClassThread;
//    ui->pushButton_2->setText("RFIDing");
//    th1->start();
//    connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

}

void createacount::on_pushButton_clicked()
{
    accountctrl *test = new accountctrl;
   int ret = test->acoutCreateToBads(ui->userEdit->text(),ui->passworkEdit->text(),ui->cardEdit->text());
   delete test;
   if(ret == -1)
   {
        QMessageBox::warning(this,"用户名重复","用户名重复，请修改");
        return;
   }
   else if(ret == -2)
   {
       QMessageBox::warning(this,"门禁卡重复","不可以用别人的卡注册oh");
       return;
   }
   else {
       int ret = QMessageBox::information(this,"注册成功","欢迎加入！",QMessageBox::Yes);
       if(ret >= 0)
       {
           disconnect(weather1->mTimer,&QTimer::timeout,weather1,&weatherclock::screenshow);
            MainWIndow *mainback = new MainWIndow;
            mainback->show();
           this->close();
            return;
       }

   }
}

void createacount::on_pushButton_2_clicked()
{
    disconnect(weather1->mTimer,&QTimer::timeout,weather1,&weatherclock::screenshow);
    MainWIndow *mainback = new MainWIndow;
    mainback->show();
    this->close();
    return;
}

void createacount::on_userBtn_clicked()
{
    this->on_userEdit_editingFinished();
    this->on_passworkEdit_editingFinished();
    this->on_passworkEdit_2_editingFinished();
}

void createacount::on_passBtn_clicked()
{
    this->on_userEdit_editingFinished();
    this->on_passworkEdit_editingFinished();
    this->on_passworkEdit_2_editingFinished();
}

void createacount::on_passBtn_2_clicked()
{
    this->on_userEdit_editingFinished();
    this->on_passworkEdit_editingFinished();
    this->on_passworkEdit_2_editingFinished();
}

void createacount::on_userEdit_editingFinished()
{
    ui->userEdit->resize(160,30);
    ui->userEdit->setStyleSheet("font: 10pt 黑体;");
    weather1->show();
    newsLa->show();
    ui->userBtn->hide();
    ui->passBtn->hide();
    ui->passBtn_2->hide();
    keyBoardc->hide();
}

void createacount::on_passworkEdit_editingFinished()
{
    ui->passworkEdit->resize(160,30);
    ui->passworkEdit->setStyleSheet("font: 10pt 黑体;");
    weather1->show();
    newsLa->show();
    ui->userBtn->hide();
    ui->passBtn->hide();
    ui->passBtn_2->hide();
    keyBoardc->hide();
}

void createacount::on_passworkEdit_2_editingFinished()
{
    ui->passworkEdit_2->resize(160,30);
    ui->passworkEdit_2->setStyleSheet("font: 10pt 黑体;");
    ui->passworkEdit_2->move(280,250);
    weather1->show();
    newsLa->show();
    ui->label_4->move(190,260);
    ui->passBtn_2->move(490,260);
    ui->userBtn->hide();
    ui->passBtn->hide();
    ui->passBtn_2->hide();
    keyBoardc->hide();
}

void createacount::on_userEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->passworkEdit_2->text() != "" &&
            ui->cardEdit->text() != "")
    {
        ui->pushButton->setEnabled(true);
//        qDebug()<<"usereidit true";
    }
    else {
        ui->pushButton->setEnabled(false);
//        qDebug()<<"usereidit false";
    }




}

void createacount::on_passworkEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->passworkEdit_2->text() != "" &&
            ui->cardEdit->text() != "")
    {
        if(ui->passworkEdit->text() == ui->passworkEdit_2->text())
        {
            ui->pushButton->setEnabled(true);
            ui->passworkLabel->setText("");
        }
        else {
            ui->pushButton->setEnabled(false);
            ui->passworkLabel->setText("两次密码不一致");
        }
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}

void createacount::on_passworkEdit_2_textChanged(const QString &arg1)
{

    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->passworkEdit_2->text() != "" &&
            ui->cardEdit->text() != "")
    {
        if(ui->passworkEdit->text() == ui->passworkEdit_2->text())
        {
            ui->pushButton->setEnabled(true);
            ui->passworkLabel->setText("");
        }
        else {
            ui->pushButton->setEnabled(false);
            ui->passworkLabel->setText("两次密码不一致");
        }
    }
    else {
        ui->pushButton->setEnabled(false);
    }


}

void createacount::on_cardEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" &&
            ui->passworkEdit->text() != "" &&
            ui->passworkEdit_2->text() != "" &&
            ui->cardEdit->text() != "")
    {
        ui->pushButton->setEnabled(true);
    }
    else {
        ui->pushButton->setEnabled(false);
    }
}
