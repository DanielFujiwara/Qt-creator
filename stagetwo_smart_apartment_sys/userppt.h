#ifndef USERPPT_H
#define USERPPT_H

#include <QWidget>
#include <QtDebug>
#include <QTimer>
namespace Ui {
class userppt;
}

class userppt : public QWidget
{
    Q_OBJECT

public:
    explicit userppt(QWidget *parent = nullptr);
    ~userppt();
public slots:
    void setPPTtoLabel();

private:
    Ui::userppt *ui;
    QTimer *mtime;
};

#endif // USERPPT_H
