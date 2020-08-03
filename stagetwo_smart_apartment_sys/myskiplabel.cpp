#include "myskiplabel.h"



myskiplabel::myskiplabel(QWidget *parent): QLabel (parent)
{
    qDebug()<<"--";
}

myskiplabel::~myskiplabel()
{
     printf("~myskiplabel\n");
}

bool myskiplabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *keyEvent = static_cast<QMouseEvent *>(e);
        if(keyEvent->button() == Qt::LeftButton)
        {
            qDebug()<<"clicked";
            return true;
        }
    }
    return QLabel::event(e);
}
