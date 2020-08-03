#ifndef KEYCLASS_H
#define KEYCLASS_H
#include <QToolButton>


class keyclass : public QToolButton
{
    Q_OBJECT
public:
     explicit keyclass(QWidget *parent = Q_NULLPTR);

private slots:
    void button_clicked(bool);


};

#endif // KEYCLASS_H
