#ifndef ADDNEWREPAIR_H
#define ADDNEWREPAIR_H

#include <QMainWindow>

namespace Ui {
class addnewrepair;
}

class addnewrepair : public QMainWindow
{
    Q_OBJECT

public:
    explicit addnewrepair(QWidget *parent = nullptr);
    ~addnewrepair();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addnewrepair *ui;
};

#endif // ADDNEWREPAIR_H
