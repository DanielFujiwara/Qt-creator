#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "dir_list.h"
#include "simple_file.h"
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->file_list->resize(829,370);
//    ui->listWidget->addItem("1");
//    ui->listWidget->addItem("2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
//{

//}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug()<<"item clicked"<<item->data(0).toString();
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug()<<"index"<<index.row();
}

void MainWindow::on_Dir_btn_clicked()
{
    dirpath = QFileDialog::getExistingDirectory();
    qDebug()<<dirpath;
    ui->dir_path->setText(dirpath);
    QDir dir(dirpath);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::AllDirs);
        dir.setSorting(QDir::Size | QDir::Reversed);
        QFileInfoList list = dir.entryInfoList();
       qDebug() << "     Bytes Filename" ;

        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);

            if(fileInfo.isDir())
            {
                qDebug()<<"dir add";
                dir_list *dirlist = new dir_list;
                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(829,50));
                ui->file_list->addItem(item);
                ui->file_list->setItemWidget(item,dirlist);
                  ui->file_list->setIconSize(QSize(50,50));
                  item->setIcon(QIcon(":/icon/favicon.ico"));
                  connect(dirlist,&dir_list::GetMyName,dirlist,&dir_list::ShowMyName);
                  emit dirlist->GetMyName(fileInfo);

            }
            else {
                qDebug()<<"file add";
                simple_file *filelist = new simple_file;
                QListWidgetItem *item = new QListWidgetItem();
                item->setSizeHint(QSize(829,50));
                ui->file_list->setIconSize(QSize(50,50));
                item->setIcon(QIcon(":/icon/favicon (1).ico"));
                ui->file_list->addItem(item);
                ui->file_list->setItemWidget(item,filelist);

                connect(filelist,&simple_file::GetMyName,filelist,&simple_file::ShowMyName);
                emit filelist->GetMyName(fileInfo);
            }
//            listWi->addItem(fileInfo.fileName());
//            qDebug()<< qPrintable(QString("%1").arg(fileInfo.fileName()));
        }

}
