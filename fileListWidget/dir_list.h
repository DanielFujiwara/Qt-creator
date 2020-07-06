#ifndef DIR_LIST_H
#define DIR_LIST_H

#include <QWidget>
#include <QFile>
#include <QDir>
namespace Ui {
class dir_list;
}

class dir_list : public QWidget
{
    Q_OBJECT

public:
    explicit dir_list(QWidget *parent = nullptr);
    ~dir_list();
signals:
    void GetMyName(QFileInfo fileInfo);
public slots:
    void ShowMyName(QFileInfo fileInfo);
private:
    Ui::dir_list *ui;
};

#endif // DIR_LIST_H
