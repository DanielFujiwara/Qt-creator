#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include <QFile>
#include <QMainWindow>
#include <string.h>

using namespace ::std;


namespace Ui {
class loginWindows;
}

class loginWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindows(QWidget *parent = nullptr);
    ~loginWindows();

private slots:
    void on_loginBtn_clicked();
    
    void on_creatBtn_clicked();
    
    void on_userEdit_textChanged(const QString &arg1);
    
    void on_passworkEdit_textChanged(const QString &arg1);
    
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::loginWindows *ui;
};

#endif // LOGINWINDOWS_H
