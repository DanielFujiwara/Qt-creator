#ifndef WELCOMEPPT_H
#define WELCOMEPPT_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class welcomePpt;
}

class welcomePpt : public QMainWindow
{
    Q_OBJECT

public:
    explicit welcomePpt(QWidget *parent = nullptr);
    ~welcomePpt();
public slots:
    void changeBtnText();
private slots:
    void on_commandLinkButton_clicked();
public:
    int flag;
    int getFlag() const;

public:
    void checkWelcomeFlag();

private:
    Ui::welcomePpt *ui;
    QTimer *timem;
};

#endif // WELCOMEPPT_H
