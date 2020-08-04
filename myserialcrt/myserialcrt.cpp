#include "myserialcrt.h"
#include "ui_myserialcrt.h"

MySerialCRT::MySerialCRT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MySerialCRT)
{
    ui->setupUi(this);

    ui->textEdit->setEnabled(false);//禁用编辑器
    ui->textEdit->installEventFilter(this);//调用事件过滤器   安装事件过滤器

    ui->spinBox->setEnabled(false);//禁用spinbox
    newLine = false;//初始化发送新行
    autoSend = false;//初始化自动发送

    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::blue);
    ui->statusLabel->setPalette(pe);
    ui->statusLabel->setText("Wait for connect");//初始化状态栏

    ui->sendBtn->setEnabled(false);//禁用发送按钮
    ui->clearBtn->setEnabled(false);//禁用清空按钮

    //设定文本发送类型按钮组
    ui->radioButton->setChecked(true);//初始化发送文本
    textStatu = false;//初始化发送文本
    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->radioButton,0);
    btnGroup->addButton(ui->radioButton_2,1);
    connect(ui->radioButton,&QRadioButton::clicked,this,&MySerialCRT::textTypeStatus);
    connect(ui->radioButton_2,&QRadioButton::clicked,this,&MySerialCRT::textTypeStatus);



    infos = QSerialPortInfo::availablePorts();
   foreach(QSerialPortInfo info,infos)
   {
       qDebug() << info.portName();
       qDebug() << info.description();
       qDebug() << info.manufacturer();

       qDebug() << infos.size();
       QString portName = "端口：";
       portName += info.portName();
       QString description = "描述：";
       description += info.description();
       QString manuFacturer = "厂商：";
       manuFacturer += info.manufacturer();
        ui->portBox->addItem(info.portName());
       ui->textBrowser->append(portName);
       ui->textBrowser->append(description);
       ui->textBrowser->append(manuFacturer);
       ui->textBrowser->append("\n");
       ui->textBrowser->moveCursor(QTextCursor::Start);



   }
}

MySerialCRT::~MySerialCRT()
{
    delete ui;
}

bool MySerialCRT::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->textEdit)
        {
            if(event->type() == QEvent::KeyPress)//回车键
            {
                 QKeyEvent *k = static_cast<QKeyEvent *>(event);
                 if(k->key() == Qt::Key_Return)
                 {
                     on_sendBtn_clicked();
                     return true;
                 }
            }
        }
        return QWidget::eventFilter(target,event);
 }

void MySerialCRT::on_starBtn_clicked()
{
    mserial.close();
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::red);
    ui->statusLabel->setPalette(pe);
    ui->statusLabel->setText("Disconnect");



    QString portName = ui->portBox->currentText();
    qDebug()<<portName;
    int i = 0;
    foreach(QSerialPortInfo info,infos)
    {
      if(info.portName() == portName)
          break;
      else {
          i++;
      }
    }
    qDebug()<<i;
    mserial.setPort(infos.at(i));//设置端口

    int baudRate = ui->baudrateBox->currentText().toInt();
    mserial.setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate));//设置波特率


    QString dataBitschoic = ui->databitsBox->currentText();
    int dataB = dataBitschoic.toInt();
    mserial.setDataBits( static_cast<QSerialPort::DataBits>(dataB));//设置数据位

    QString parity = ui->parityBox->currentText();
    int parityInt;
    if(parity == "NONE")
    {
        parityInt = 0;
    }
    else if(parity == "EVEN")
    {
        parityInt = 2;
    }
    else if (parity == "ODD") {
        parityInt = 3;
    }
    else if (parity == "SPACE") {
        parityInt = 4;
    }
    else if (parity == "MARK") {
        parityInt = 5;
    }
    else {
        parityInt = -1;
    }

    mserial.setParity(static_cast<QSerialPort::Parity>(parityInt));//奇偶校验
     int stopBits = ui->stopBox->currentText().toInt();
    mserial.setStopBits(static_cast<QSerialPort::StopBits>(stopBits));//停止位


    if(! mserial.open(QIODevice::ReadWrite))
    {
        qDebug() << " open port fail";
        pe.setColor(QPalette::WindowText, Qt::red);
        ui->statusLabel->setPalette(pe);
        ui->statusLabel->setText("Connect Error");
        return;
    }
     ui->sendBtn->setEnabled(true);

     pe.setColor(QPalette::WindowText, Qt::green);
     ui->statusLabel->setPalette(pe);
     ui->statusLabel->setText("Connect");

    ui->textBrowser->clear();
    connect(&mserial,&QSerialPort::readyRead,this,&MySerialCRT::getDataFromPort);

    ui->portBox->setEnabled(false);
    ui->baudrateBox->setEnabled(false);
    ui->databitsBox->setEnabled(false);
    ui->parityBox->setEnabled(false);
    ui->stopBox->setEnabled(false);
     ui->textEdit->setEnabled(true);




}

void MySerialCRT::getDataFromPort()
{
    QByteArray arry = mserial.readAll();

    ui->textBrowser->insertPlainText(arry);
}

void MySerialCRT::on_refrushBtn_clicked()
{
    mserial.close();
     ui->textEdit->setEnabled(false);
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::red);
    ui->statusLabel->setPalette(pe);
    ui->statusLabel->setText("Disconnect");//初始化状态栏

    ui->textBrowser->clear();
    ui->portBox->clear();
    infos = QSerialPortInfo::availablePorts();
   foreach(QSerialPortInfo info,infos)
   {
       qDebug() << info.portName();
       qDebug() << info.description();
       qDebug() << info.manufacturer();

       qDebug() << infos.size();
       QString portName = "端口：";
       portName += info.portName();
       QString description = "描述：";
       description += info.description();
       QString manuFacturer = "厂商：";
       manuFacturer += info.manufacturer();
        ui->portBox->addItem(info.portName());
       ui->textBrowser->append(portName);
       ui->textBrowser->append(description);
       ui->textBrowser->append(manuFacturer);
       ui->textBrowser->append("\n");
       ui->textBrowser->moveCursor(QTextCursor::Start);

       ui->portBox->setEnabled(true);
       ui->baudrateBox->setEnabled(true);
       ui->databitsBox->setEnabled(true);
       ui->parityBox->setEnabled(true);
       ui->stopBox->setEnabled(true);
}
}

void MySerialCRT::on_autosendCheck_stateChanged(int arg1)
{
//    qDebug()<<arg1;
    if(arg1 == 2)
    {
        ui->spinBox->setEnabled(true);
        qDebug()<<"auto send true";
        autoSend = true;
        autoTimer = new QTimer;
        QString msSend = ui->spinBox->text();
        msSend = msSend.left(msSend.length() - 1);
        msSend = msSend.left(msSend.length() - 1);
        autoTimer->setInterval(msSend.toInt());
        connect(autoTimer,&QTimer::timeout,this,&MySerialCRT::autoSendToport);
        qDebug()<<"delay"<<msSend;

    }
    else {
        ui->spinBox->setEnabled(false);
        qDebug()<<"auto send false";
        autoSend = false;
        autoTimer->stop();
        disconnect(autoTimer,&QTimer::timeout,this,&MySerialCRT::autoSendToport);
    }
}

void MySerialCRT::on_newlineCheck_stateChanged(int arg1)
{
    if(arg1 == 2)
    {

        newLine = true;
        qDebug()<<"newline true";
    }
    else {

        newLine = false;
        qDebug()<<"newline false";
    }
}

void MySerialCRT::textTypeStatus()
{
    int checkId = btnGroup->checkedId();
    if(checkId == 0)
    {
        textStatu = false;
        qDebug()<<"text mode";
    }
    else if (checkId == 1) {
        textStatu = true;
        qDebug()<<"hex mode";
    }
}

void MySerialCRT::on_textEdit_textChanged()
{
    if(ui->textEdit->document()->toPlainText() == "")
    {
//        ui->sendBtn->setEnabled(false);
        ui->clearBtn->setEnabled(false);
    }
    else {
//        ui->sendBtn->setEnabled(true);
        ui->clearBtn->setEnabled(true);
    }

    QString datatext = ui->textEdit->document()->toPlainText();

}

void MySerialCRT::on_clearBtn_clicked()
{
    ui->textEdit->clear();
}

void MySerialCRT::on_sendBtn_clicked()
{
    if(autoSend == true)//自动发送检查
    {
        autoTimer->start();
        return;
    }


    if(ui->textEdit->document()->toPlainText() == "")//输入框内容为空判断
    {
        mserial.write("\n");
        return;
    }


    QString sendData = ui->textEdit->document()->toPlainText();
    if(newLine == true)//发送新行检查
    {
        sendData += "\n";
    }

    mserial.write(sendData.toUtf8()); //发送数据
    ui->textEdit->clear();

    ui->textBrowser->moveCursor(QTextCursor::End); //复位浏览器

    return;
}

void MySerialCRT::autoSendToport()
{
   if( ui->textEdit->document()->toPlainText() == "")
   {
       mserial.write("\n");
       qDebug()<<"autosend";
       return;
   }


    QString sendData = ui->textEdit->document()->toPlainText();
    sendData += "\n";
    mserial.write(sendData.toUtf8());
//    mserial.write("\n");
    qDebug()<<"autosend";
    return;
}

void MySerialCRT::on_spinBox_valueChanged(const QString &arg1)
{
    QString msSend = arg1;
    msSend = msSend.left(msSend.length() - 1);
    msSend = msSend.left(msSend.length() - 1);
    autoTimer->setInterval(msSend.toInt());
    qDebug()<<"delay"<<msSend;
}

void MySerialCRT::on_textBrowser_textChanged()
{
    ui->textBrowser->moveCursor(QTextCursor::End);
}
