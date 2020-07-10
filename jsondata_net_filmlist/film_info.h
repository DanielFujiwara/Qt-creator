#ifndef FILM_INFO_H
#define FILM_INFO_H

#include <QWidget>
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
class film_info;
}

class film_info : public QWidget
{
    Q_OBJECT

public:
    explicit film_info(QWidget *parent = nullptr);
    ~film_info();
signals:
    void getFilmdata(QJsonObject & filmdata);
public slots:
    void setFilmdata(QJsonObject & filmdata);
    void readdataPic(QNetworkReply *reply);

private:
    Ui::film_info *ui;
    QNetworkAccessManager *manager;
};

#endif // FILM_INFO_H
