#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include <QDialog>
//#include <QtDebug>
#include <QFile>
#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QtDebug>
#include <QByteArray>
#include <QJsonObject>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

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
    void on_readFileBtn_clicked();
//    void readdataPic(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
