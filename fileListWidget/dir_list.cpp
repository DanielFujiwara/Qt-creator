#include "dir_list.h"
#include "ui_dir_list.h"

dir_list::dir_list(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dir_list)
{
    ui->setupUi(this);
    ui->dir_name->setAlignment(Qt::AlignRight);

}

dir_list::~dir_list()
{
    delete ui;
}

void dir_list::ShowMyName(QFileInfo fileInfo)
{
    ui->dir_name->setText(fileInfo.fileName());
}
