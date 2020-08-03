#include "peoplegame.h"
#include "ui_peoplegame.h"
#include <QMessageBox>
#include "gamewindows.h"
peoplegame::peoplegame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peoplegame)
{
    ui->setupUi(this);
    QPixmap m;
    m.load("./pic/people.jpg");
//    m =  m.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->label_2->setPixmap(m);

     // 软键盘初始化
    keyBoard = new softkey(ui->centralwidget);
    keyBoard->move(45,260);
    keyBoard->hide();
    ui->lineName->installEventFilter(this);
    ui->userBtn->hide();


}

peoplegame::~peoplegame()
{
    printf("~peoplegame\n");
    delete ui;
}

bool peoplegame::eventFilter(QObject *watched, QEvent *event)
{
    if ( (watched == ui->lineName) && (event->type() == QEvent::MouseButtonPress) )
    {
            keyBoard->show();
            keyBoard->raise();
            ui->userBtn->show();
//            ui->userEdit->resize(200,50);
//            ui->userEdit->setFont(QFont("黑体,20,QFont::Bold"));
//            ui->userEdit->setStyleSheet("font: 16pt 黑体;");
//            newsLabel->hide();
//            weather->hide();
         ui->lineName->setFocus();
    }
    return QMainWindow::eventFilter(watched,event);
}

void peoplegame::on_pushStart_clicked()
{
    if((ui->lineName->text()) == "")
    {
        QMessageBox::warning(this,"woring","名字不能为空！");
        retry();

        return;
    }

    ui->label_scor->show();
    ui->label_word->show();
    ui->label_name->show();

    ui->label_name_2->setText(ui->lineName->text());



    int a = rand()%100;
//    qDebug() << a;



        ui->label_name_3->setText(QString::number(a));

    if(0 <= a && a < 34)
    {
        ui->label_name_4->setText("你的评分有点差喔！");
    }
    else if(a < 68)
    {
        ui->label_name_4->setText("你的评分一般般而已喔！");
    }
    else {
        ui->label_name_4->setText("你的评分很好喔！");
    }
}

void peoplegame::setMyName(QString name)
{
    myname = name;
    qDebug()<<myname;
}

void peoplegame::retry()
{
    ui->label_scor->hide();
    ui->label_word->hide();
    ui->label_name->hide();
    ui->label_name_3->setText("");
    ui->label_name_2->setText("");
    ui->label_name_4->setText("");
    ui->lineName->setText("");
}

void peoplegame::on_pushStart_2_clicked()
{
    ui->label_scor->hide();
    ui->label_word->hide();
    ui->label_name->hide();
    ui->label_name_3->setText("");
    ui->label_name_2->setText("");
    ui->label_name_4->setText("");
    ui->lineName->setText("");
}

void peoplegame::on_userBtn_clicked()
{
    this->on_lineName_editingFinished();
}

void peoplegame::on_lineName_editingFinished()
{
//    ui->passworkEdit->resize(160,30);
//    ui->passworkEdit->setStyleSheet("font: 10pt 黑体;");
//    newsLabel->show();
//    weather->show();
    ui->userBtn->hide();
//    ui->passBtn->hide();
    keyBoard->hide();
}

void peoplegame::on_commandLinkButton_clicked()
{
    gamewindows *p = new gamewindows;
    connect(p,&gamewindows::sendMyUser,p,&gamewindows::setMyUser);
    emit p->setMyUser(myname);
    p->show();


    this->close();
    return;
}
