#ifndef SIMPLE_FILE_H
#define SIMPLE_FILE_H

#include <QWidget>
#include <QDir>
namespace Ui {
class simple_file;
}

class simple_file : public QWidget
{
    Q_OBJECT

public:
    explicit simple_file(QWidget *parent = nullptr);
    ~simple_file();
signals:
    void GetMyName(QFileInfo fileInfo);
public slots:
    void ShowMyName(QFileInfo fileInfo);
private:
    Ui::simple_file *ui;
};

#endif // SIMPLE_FILE_H
