#include "mainwindow.h"
#include "ui_mainwindow.h"
int MainWindow::textchange = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fileLabel->setText("null");
    QString styleb = QString("background-color: rgb(0, 255, 0);");
    ui->stabtn->setStyleSheet(styleb);
    this->filename = "";
    MainWindow::setWindowTitle("文档编辑器");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openbtn_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if(textchange == 0 || text.isEmpty())
    {
        ui->textEdit->clear();
//        textchange = 0;
    }
    else {
        QMessageBox:: StandardButton result=
        QMessageBox::information(NULL, "Wrong", "当前文件修改尚未保存，是否直接关闭？",QMessageBox::Yes|QMessageBox::No);

        switch (result) {
        case QMessageBox::Yes:
        {
            ui->textEdit->setText("");
            textchange = 0;

            break;
        }
        case QMessageBox::No:
            return;

        }
    }

    this->filename = QFileDialog::getOpenFileName(this);
    QFile file(this->filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
//         QMessageBox::warning(this,"woring","open error");
         return;
    }
    ui->fileLabel->setText(filename);
    QByteArray array = file.readAll();
    ui->textEdit->setPlainText(array);
    file.close();
    textchange = 0;
    QString styleb = QString("background-color: rgb(0, 255, 0);");
    ui->stabtn->setStyleSheet(styleb);


}

void MainWindow::on_savebtn_clicked()
{
    QString savefile = QFileDialog::getSaveFileName(this);
    QFile file(savefile);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this,"woring","save error");
        return;
    }
    QString data = ui->textEdit->toPlainText();
    file.write(data.toUtf8());
    file.close();
     this->filename = savefile;
    savefile += "  save success!";

//    ui->textEdit->setText(savefile);
    QMessageBox::warning(this,"msg",savefile);
    qDebug()<<"text change flag :" <<textchange;

    ui->fileLabel->setText(filename);
    textchange = 0;
    QString styleb = QString("background-color: rgb(0, 255, 0);");
    ui->stabtn->setStyleSheet(styleb);

}

void MainWindow::on_backgcbtn_clicked()
{
    //    bool succ;
        QColor color = QColorDialog::getColor();
        int red = color.red();
        int green = color.green();
        int blue = color.blue();
        QString style = QString("background-color: rgb(%1, %2, %3);")
                .arg(red).arg(green).arg(blue);
        ui->textEdit->setStyleSheet(style);
        qDebug()<<"background color set"<<style;
}

void MainWindow::on_fontbtn_clicked()
{
    bool succ;
    QFont font = QFontDialog::getFont(&succ,QFont("Helvetica [Cronyx]", 10),this,"字体设置");
    ui->textEdit->setFont(font);
    if(succ)
    {
        qDebug()<<"font set"<<font;
    }
    else {
        qDebug()<<"erro:font set";
    }

}

void MainWindow::on_infobtn_clicked()
{
    if(this->filename == "")
    {
        QMessageBox::information(NULL, "Title", "当前没有被打开的文件");
        return;

    }


    fileinfo *a = new fileinfo(this);
//     connect(n,&TeacherDe::sendData,n,&TeacherDe::getData);
    connect(a,&fileinfo::senddata,a,&fileinfo::showinfo);
    emit a->senddata(filename);
    a->show();

}

void MainWindow::on_cosebtn_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if(textchange == 0 || text.isEmpty())
    {
        ui->textEdit->setText("");
        this->filename = "";
        textchange = 0;
    }
    else {
        QMessageBox:: StandardButton result=
        QMessageBox::information(NULL, "Wrong", "你有修改未保存，是否直接关闭？",QMessageBox::Yes|QMessageBox::No);

        switch (result) {
        case QMessageBox::Yes:
        {
            ui->textEdit->setText("");
            textchange = 0;
            ui->fileLabel->setText("null");
            QString styleb = QString("background-color: rgb(0, 255, 0);");
            ui->stabtn->setStyleSheet(styleb);
            this->filename = "";

        }
        case QMessageBox::No:
            return;

        }
    }
}

void MainWindow::on_exitbtn_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if(textchange == 0 || text.isEmpty())
    {
        exit(1);
    }
    else {
        QMessageBox:: StandardButton result=
        QMessageBox::information(NULL, "Wrong", "你有修改未保存，是否直接退出？",QMessageBox::Yes|QMessageBox::No);

        switch (result) {
        case QMessageBox::Yes:
            exit(1);
        case QMessageBox::No:
            return;

        }
    }
}

void MainWindow::on_fontcol_clicked()
{
//    bool succ;
    QColor color = QColorDialog::getColor();
//    int r = color.red();
//    int g = color.green();
//    int b = color.blue();
    ui->textEdit->setTextColor(color);


}

void MainWindow::on_textEdit_textChanged()
{
    QString styleb;
    textchange++;
    QString filesta = this->filename + "**";
    ui->fileLabel->setText(filesta);
    qDebug()<<"text change flag1:"<<textchange;
    if(textchange == 0)
    {
        styleb = QString("background-color: rgb(255, 0, 0);");
    }
    else {
         styleb = QString("background-color: rgb(255, 0, 0);");
    }
    ui->stabtn->setStyleSheet(styleb);
}
