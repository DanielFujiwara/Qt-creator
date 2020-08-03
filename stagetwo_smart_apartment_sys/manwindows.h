#ifndef MANWINDOWS_H
#define MANWINDOWS_H

#include <QMainWindow>

namespace Ui {
class manwindows;
}

class manwindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit manwindows(QWidget *parent = nullptr);
    ~manwindows();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::manwindows *ui;
};

#endif // MANWINDOWS_H
