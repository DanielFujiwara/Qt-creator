#ifndef MYSKIPLABEL_H
#define MYSKIPLABEL_H
#include <QLabel>
#include <QtDebug>
#include <QEvent>
#include <QMouseEvent>

class myskiplabel : public QLabel
{
//     Q_OBJECT
public:
    explicit myskiplabel(QWidget* parent = nullptr);
    ~myskiplabel();

    virtual bool event(QEvent *e);
};

#endif // MYSKIPLABEL_H
