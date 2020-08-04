#ifndef MYSERIALCRT_H
#define MYSERIALCRT_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QButtonGroup>
#include <QRadioButton>
#include <QTimer>
#include <QString>
#include <QKeyEvent>

namespace Ui {
class MySerialCRT;
}

class MySerialCRT : public QMainWindow
{
    Q_OBJECT

public:
    explicit MySerialCRT(QWidget *parent = nullptr);
    ~MySerialCRT();
    bool eventFilter(QObject *target, QEvent *event);//事件过滤器

private slots:
    void on_starBtn_clicked();
    void getDataFromPort();

    void on_refrushBtn_clicked();

    void on_autosendCheck_stateChanged(int arg1);

    void on_newlineCheck_stateChanged(int arg1);

    void textTypeStatus();

    void on_textEdit_textChanged();

    void on_clearBtn_clicked();

    void on_sendBtn_clicked();

    void autoSendToport();

    void on_spinBox_valueChanged(const QString &arg1);

    void on_textBrowser_textChanged();

private:
    Ui::MySerialCRT *ui;
    QSerialPort mserial; //串口类对象
    QList<QSerialPortInfo> infos; //串口信息类
    bool newLine;
    bool autoSend;
    bool textStatu;
    QTimer *autoTimer;

     QButtonGroup* btnGroup;
};

#endif // MYSERIALCRT_H
