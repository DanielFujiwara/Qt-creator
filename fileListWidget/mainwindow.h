#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include <QDialog>
#include <QtDebug>
#include <QFile>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_Dir_btn_clicked();

private:
    Ui::MainWindow *ui;
    QString dirpath;
};

#endif // MAINWINDOW_H
