#include "textmainwindow.h"
#include "ui_textmainwindow.h"
#include "gamewindows.h"

int textMainWindow::textchange = 0;
textMainWindow::textMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 背景模块
    QString path = QString("./pic/background.jpg");
    QPixmap map(path);
    map =  map.scaled(QSize(800,480),Qt::KeepAspectRatio);
    ui->bgLabel->setPixmap(map);


    ui->fileLabel->setText("null");
    QString styleb = QString("background-color: rgb(0, 255, 0);");
    ui->stabtn->setStyleSheet(styleb);
    this->filename = "";
    textMainWindow::setWindowTitle("文档编辑器");

    // 软键盘初始化
    keyBoard = new softkey(ui->centralWidget);
    keyBoard->move(45,260);
    keyBoard->hide();
    ui->userBtn->hide();
    ui->textEdit->installEventFilter(this);
//    ui->passworkEdit->installEventFilter(this);


}

textMainWindow::~textMainWindow()
{
    printf("~textMainWindow\n");
    delete ui;
}

void textMainWindow::setMyName(QString name)
{
    myname = name;
}

bool textMainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if ( (watched == ui->textEdit) && (event->type() == QEvent::MouseButtonPress) )
    {
            keyBoard->show();
//            keyBoard->raise();
            ui->userBtn->show();

         ui->textEdit->setFocus();
    }

    return QMainWindow::eventFilter(watched,event);
}

void textMainWindow::on_openbtn_clicked()
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

void textMainWindow::on_savebtn_clicked()
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

void textMainWindow::on_backgcbtn_clicked()
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

void textMainWindow::on_fontbtn_clicked()
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

void textMainWindow::on_infobtn_clicked()
{
    if(this->filename == "")
    {
        QMessageBox::information(NULL, "Title", "当前没有被打开的文件");
        return;

    }


    textfileinfo *a = new textfileinfo(this);
//     connect(n,&TeacherDe::sendData,n,&TeacherDe::getData);
    connect(a,&textfileinfo::senddata,a,&textfileinfo::showinfo);
    emit a->senddata(filename);
    a->show();

}

void textMainWindow::on_cosebtn_clicked()
{

    if(this->filename == "")
    {
        QMessageBox::information(NULL, "Title", "当前没有被打开的文件");
        return;

    }





    QString text = ui->textEdit->toPlainText();
    if(textchange == 0 || text.isEmpty())
    {
        ui->textEdit->setText("");
        this->filename = "";
        ui->fileLabel->setText("null");
        QString styleb = QString("background-color: rgb(0, 255, 0);");
        ui->stabtn->setStyleSheet(styleb);
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

void textMainWindow::on_exitbtn_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if(textchange == 0 || text.isEmpty())
    {
        gamewindows *back = new gamewindows;
        connect(back,&gamewindows::sendMyUser,back,&gamewindows::setMyUser);
        emit back->sendMyUser(myname);
        back->show();
        this->close();
        return;
    }
    else {
        QMessageBox:: StandardButton result=
        QMessageBox::information(NULL, "Wrong", "你有修改未保存，是否直接退出？",QMessageBox::Yes|QMessageBox::No);

        switch (result) {
        case QMessageBox::Yes:
        {
            gamewindows *back = new gamewindows;
            connect(back,&gamewindows::sendMyUser,back,&gamewindows::setMyUser);
            emit back->sendMyUser(myname);
            back->show();
            this->close();
            return;
        }
        case QMessageBox::No:
            return;

        }
    }
}

void textMainWindow::on_fontcol_clicked()
{
//    bool succ;
    QColor color = QColorDialog::getColor();
//    int r = color.red();
//    int g = color.green();
//    int b = color.blue();
    ui->textEdit->setTextColor(color);


}

void textMainWindow::on_textEdit_textChanged()
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

void textMainWindow::on_userBtn_clicked()
{
//    ui->userEdit->resize(160,30);
//    ui->userEdit->setStyleSheet("font: 10pt 黑体;");
//    newsLabel->show();
//    mweather->show();
    ui->userBtn->hide();
//    ui->passBtn->hide();
    keyBoard->hide();
}

void textMainWindow::on_textEdit_selectionChanged()
{
//    if ( (watched == ui->textEdit) && (event->type() == QEvent::MouseButtonPress) )
//    {
            keyBoard->show();
//            keyBoard->raise();
            ui->userBtn->show();

         ui->textEdit->setFocus();
//    }

//    return QMainWindow::eventFilter(watched,event);
}
