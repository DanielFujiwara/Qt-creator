#ifndef BILLCHECK_H
#define BILLCHECK_H

#include <QMainWindow>

namespace Ui {
class billcheck;
}

class billcheck : public QMainWindow
{
    Q_OBJECT

public:
    explicit billcheck(QWidget *parent = nullptr);
    ~billcheck();

private slots:
    void on_pushButton_clicked();

private:
    Ui::billcheck *ui;
};

#endif // BILLCHECK_H
