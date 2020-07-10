#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QTextCodec>
#include "film_info.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_readFileBtn_clicked()
{
     //如果是本地的文件数据，首先将文件转换成一个QFile对象
    QFile file(":/film.json");
   // QFile file(":/11.txt");
   //QFile file("./film.json");
    //对于RES目录 下的资源文件，只能读取，不要进行写操作，打开文件并读取
    bool isok = file.open(QIODevice::ReadOnly);
    qDebug() << "isok = " << isok;
      QByteArray filmData = file.readAll();
      QTextCodec *codec = QTextCodec::codecForName("UTF-8");
      QString string = codec->toUnicode(filmData);
      qDebug() << "data = " << string;
        QJsonDocument filmdataj = QJsonDocument::fromJson(filmData);
        QJsonObject filmdatao = filmdataj.object();
        QJsonArray filmdataa = filmdatao.value("result").toArray();
//        ui->listWidget->setFrameShape(QFrame::HLine);
//        ui->listWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//        ui->listWidget->setStyleSheet("color: #C5C5C5;");
        ui->listWidget->setStyleSheet("QListWidget::item { border-bottom: 2px solid rgb(255, 228, 184); }");
        for(int i = 0; i<20;i++)
        {

        QJsonObject filmdata_0 = filmdataa.at(i).toObject();

        film_info * test = new film_info(this);

        connect(test,&film_info::getFilmdata,test,&film_info::setFilmdata);
        emit test->getFilmdata(filmdata_0);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(1051,131));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,test);
        }


}


