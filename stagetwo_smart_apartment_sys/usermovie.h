#ifndef USERMOVIE_H
#define USERMOVIE_H

#include <QWidget>
#include <QTimer>
#include <QProcess>

namespace Ui {
class usermovie;
}

class usermovie : public QWidget
{
    Q_OBJECT

public:
    explicit usermovie(QWidget *parent = nullptr);
    ~usermovie();
    void exitMovie();

private:
    Ui::usermovie *ui;

    QProcess mProcess;
};

#endif // USERMOVIE_H
