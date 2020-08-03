#include "welcomeppt.h"
#include "ui_welcomeppt.h"
#include "mainwindow.h"
#include <QPixmap>

static int i = 3;
static int welcomeflag = 0;
welcomePpt::welcomePpt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::welcomePpt)
{
    ui->setupUi(this);
    flag = 0;
    // 背景模块
    QString path = QString("./pic/welcome.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->label->setPixmap(map);

    printf("ppppppppppp\n");
    ui->commandLinkButton->setText("skip(3)");
    timem = new QTimer(this);
    timem->setInterval(1000);
    connect(timem,&QTimer::timeout,this,&welcomePpt::changeBtnText);
    timem->start();


}

welcomePpt::~welcomePpt()
{
    delete ui;
}

void welcomePpt::changeBtnText()
{
    QString textToBtn = "skip(";
    if(i >= 0)
    {
        textToBtn += QString::number(i);
        textToBtn += ")";
    }
    else {
        textToBtn = "skip";
    }
    i--;
    ui->commandLinkButton->setText(textToBtn);
}

void welcomePpt::on_commandLinkButton_clicked()
{
    printf("welcomeflag %d\n",welcomeflag);
    if(welcomeflag == 1)
    {
        this->hide();
    }

    if(ui->commandLinkButton->text() == "skip")
    {
//                   MainWIndow w;
//            w.show();
        flag = 1;
        welcomeflag = 1;
            this->hide();
    }
    else {
        return;
    }
}

int welcomePpt::getFlag() const
{
    return flag;
}

void welcomePpt::checkWelcomeFlag()
{
    printf("welcomeflag %d\n",welcomeflag);
    if(welcomeflag == 1)
    {
        this->hide();
    }

}
