#include "simple_file.h"
#include "ui_simple_file.h"

simple_file::simple_file(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simple_file)
{
    ui->setupUi(this);
    ui->file_name->setAlignment(Qt::AlignRight);
    ui->file_size->setAlignment(Qt::AlignRight);
}

simple_file::~simple_file()
{
    delete ui;
}

void simple_file::ShowMyName(QFileInfo fileInfo)
{
    ui->file_name->setText(fileInfo.fileName());

    QString size = QString::number((fileInfo.size())/1024,10);
    size += " kb";
    ui->file_size->setText(size);
}
