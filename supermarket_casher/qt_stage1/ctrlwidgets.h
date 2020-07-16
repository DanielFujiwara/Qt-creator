#ifndef CTRLWIDGETS_H
#define CTRLWIDGETS_H

#include <QWidget>

namespace Ui {
class ctrlwidgets;
}

class ctrlwidgets : public QWidget
{
    Q_OBJECT

public:
    explicit ctrlwidgets(QWidget *parent = nullptr);
    ~ctrlwidgets();
signals:
    void sendData(QString num1,QString num2,QString num3,QString num4,QString num5);
public slots:
    void setData(QString num1,QString num2,QString num3,QString num4,QString num5);
private:
    Ui::ctrlwidgets *ui;
};

#endif // CTRLWIDGETS_H
