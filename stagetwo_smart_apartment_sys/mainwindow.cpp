#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomeppt.h"
#include <unistd.h>

MainWIndow::MainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWIndow)
{
    ui->setupUi(this);



//    ppt->raise();



    // 创建RFID线程
    runRFID();
    printf("run RFID\n");
//    th = new rfidClassThread;

//    th->start();
//    connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);


    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);

    // 按钮初始化
    ui->userBtn->hide();
    ui->passBtn->hide();
    ui->loginBtn->setEnabled(false);

    // 软键盘初始化
    keyBoard = new softkey(ui->centralWidget);
    keyBoard->move(45,260);
    keyBoard->hide();
    ui->userEdit->installEventFilter(this);
    ui->passworkEdit->installEventFilter(this);






    //天气模块
    mweather = new weatherclock(this);
    mweather->move(600,0);
    mweather->show();
//    mweather->whatTime();
    connect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);
    // 新闻模块
    newsLabel = new newslabel(this);
    newsLabel->move(0,430);
    newsLabel->show();

    ui->userEdit->setText("aji");
    ui->passworkEdit->setText("511511");





}

MainWIndow::~MainWIndow()
{
//    qDebug()<<"main close";
    printf("~MainWIndow\n");
    delete ui;
}

bool MainWIndow::eventFilter(QObject *watched, QEvent *event)
{


    if ( (watched == ui->userEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
            keyBoard->show();
            keyBoard->raise();
            ui->userBtn->show();
            ui->userEdit->resize(200,50);
//            ui->userEdit->setFont(QFont("黑体,20,QFont::Bold"));
            ui->userEdit->setStyleSheet("font: 16pt 黑体;");
            newsLabel->hide();
            mweather->hide();
         ui->userEdit->setFocus();
    }
    else if ( (watched == ui->passworkEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
        keyBoard->show();
        keyBoard->raise();
        ui->passBtn->show();
        ui->passworkEdit->resize(200,50);
//        ui->passworkEdit->setFont(QFont("黑体,20,QFont::Bold"));
         ui->passworkEdit->setStyleSheet("font: 16pt 黑体;");
         newsLabel->hide();
         mweather->hide();
        ui->passworkEdit->setFocus();
    }

    return QMainWindow::eventFilter(watched,event);
}






void MainWIndow::on_userEdit_editingFinished()
{
    ui->userEdit->resize(160,30);
    ui->userEdit->setStyleSheet("font: 10pt 黑体;");
    newsLabel->show();
    mweather->show();
    ui->userBtn->hide();
    ui->passBtn->hide();
    keyBoard->hide();
}

void MainWIndow::on_passworkEdit_editingFinished()
{
    ui->passworkEdit->resize(160,30);
    ui->passworkEdit->setStyleSheet("font: 10pt 黑体;");
    newsLabel->show();
    mweather->show();
    ui->userBtn->hide();
    ui->passBtn->hide();
    keyBoard->hide();
}



void MainWIndow::on_userBtn_clicked()
{
    this->on_userEdit_editingFinished();
    this->on_passworkEdit_editingFinished();
}

void MainWIndow::on_passBtn_clicked()
{
    this->on_userEdit_editingFinished();
    this->on_passworkEdit_editingFinished();
}

void MainWIndow::on_userEdit_textChanged(const QString &arg1)
{

    if(arg1 != "" && ui->passworkEdit->text() != "")
    {
        ui->loginBtn->setEnabled(true);
    }
    else {
        ui->loginBtn->setEnabled(false);
    }
}

void MainWIndow::on_passworkEdit_textChanged(const QString &arg1)
{
    if(ui->userEdit->text() != "" && arg1 != "")
    {
        ui->loginBtn->setEnabled(true);
    }
    else {
        ui->loginBtn->setEnabled(false);
    }
}

void MainWIndow::on_loginBtn_clicked()
{
    th->terminate();

    disconnect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);


    accountctrl *test = new accountctrl;
    int ret = test->acountLogin(ui->userEdit->text(),ui->passworkEdit->text());
    delete test;
//    ui->userEdit->setText("");
    ui->passworkEdit->setText("");
//    qDebug()<<ret;
    if(ret == -1)
    {
        int ret = QMessageBox::warning(this,"登录错误","账号或密码错误",tr("重试"),tr("联系物管"));
        if(ret == 0)
        {
            th->start();
            connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

            return;
        }
        else {
            qDebug()<<"联系物管";
            th->start();
            connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

            return;
        }
    }

    if(ret == 2)
    {
        // 用户登录
        qDebug()<<"用户";
        th->terminate();
//        printf("quit\n");


        userwindow *userlogin = new userwindow;
        connect(userlogin,&userwindow::sendUserName,userlogin,&userwindow::setUserName);
        emit userlogin->sendUserName(ui->userEdit->text());
        userlogin->show();
         disconnect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);
         this->close();
         return;
    }
    else
    {
        //物管登录
        qDebug()<<"物管";
        th->terminate();
//        disconnect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);
//            printf("quit\n");


       manwindows *managementw = new manwindows;
        managementw->show();
         disconnect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);
        this->close();
         return;
    }

    th->start();
    connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

    ui->userEdit->setText("");
    ui->passworkEdit->setText("");

//    delete test;

}

void MainWIndow::on_creaBtn_clicked()
{
    disconnect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);

    createacount *test = new createacount();
//    connect(weather1->mTimer,&QTimer::timeout,weather1,&weatherclock::screenshow);

    test->show();
    this->close();
    return;

    //天气模块
//    weatherclock *weather1 = new weatherclock(test);
//    weather1->move(600,0);
//    weather1->show();
//    connect(weather1->mTimer,&QTimer::timeout,weather1,&weatherclock::screenshow);


    // 新闻模块
//    newslabel *newsLabel1 = new newslabel(test);
//    newsLabel1->move(0,440);
    //    newsLabel1->show();
}

void MainWIndow::getIDLoginAdmin(unsigned int ID)
{

//    unsigned int admin = 0x19f90b20;
    th->terminate();

    disconnect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);
    ui->passworkEdit->setText("");

    if(ID != 0x19f90b20 && ID != 0xdc598d9)
    {
        int ret = QMessageBox::warning(this,"登录错误","登录错误",tr("重试"),tr("联系物管"));
        if(ret == 0)
        {
            th->start();
            connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

            return;
        }
    }

    if(ID == 0xdc598d9)
    {
        // 用户登录
        qDebug()<<"用户";
        th->terminate();
//        printf("quit\n");


        userwindow *userlogin = new userwindow;
        connect(userlogin,&userwindow::sendUserName,userlogin,&userwindow::setUserName);
        emit userlogin->sendUserName("awei");
        userlogin->show();
         disconnect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);
         this->close();
         return;
    }
    else
    {
        //物管登录
        qDebug()<<"物管";
        th->terminate();
//        disconnect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);
//            printf("quit\n");


       manwindows *managementw = new manwindows;
        managementw->show();
         disconnect(mweather->mTimer,&QTimer::timeout,mweather,&weatherclock::screenshow);
        this->close();
         return;
    }




//        printf("--------card id: %x\n",ID);
//        th->start();

}

void MainWIndow::on_pushButton_clicked()
{
    deleteLater();
}

void MainWIndow::runRFID()
{
    // 创建RFID线程
//    delete th;
//    QThread::sleep(3);
//    sleep(3);
    th = new rfidClassThread;
//    ui->pushButton_2->setText("RFIDing");
    th->start();
    connect(th,&rfidClassThread::sendIDtoLogin,this,&MainWIndow::getIDLoginAdmin);

}


