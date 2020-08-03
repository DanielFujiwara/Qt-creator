#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

#include <QMainWindow>

namespace Ui {
class orderstatus;
}

class orderstatus : public QMainWindow
{
    Q_OBJECT

public:
    explicit orderstatus(QWidget *parent = nullptr);
    ~orderstatus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::orderstatus *ui;
};

#endif // ORDERSTATUS_H
