#ifndef FILEINFO_H
#define FILEINFO_H

#include <QMainWindow>

namespace Ui {
class fileinfo;
}

class textfileinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit textfileinfo(QWidget *parent = nullptr);
    ~textfileinfo();
signals:
    void senddata(QString path);
private slots:
    void on_pushButton_clicked();
public slots:
    void showinfo(QString path);
private:
    Ui::fileinfo *ui;
};

#endif // FILEINFO_H
