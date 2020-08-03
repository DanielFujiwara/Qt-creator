#ifndef SOFTKEY_H
#define SOFTKEY_H

#include <QWidget>
#include <QtDebug>
namespace Ui {
class softkey;
}

class softkey : public QWidget
{
    Q_OBJECT

public:
    explicit softkey(QWidget *parent = nullptr);
    ~softkey();
//    bool eventFilter(QObject *watched, QEvent *event);
//    void callKeyBoard();

private:
    Ui::softkey *ui;
};

#endif // SOFTKEY_H
