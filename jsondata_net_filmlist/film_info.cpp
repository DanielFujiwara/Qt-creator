#include "film_info.h"
#include "ui_film_info.h"

film_info::film_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::film_info)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();
    connect(manager,&QNetworkAccessManager::finished,this,&film_info::readdataPic);

}

film_info::~film_info()
{
    delete ui;
}

void film_info::setFilmdata(QJsonObject &filmdata)
{
    QString name = filmdata.value("title").toString();
    ui->label_name->setText(name);
    QString tpye = filmdata.value("genres").toString();
    ui->label_type->setText(tpye);
    QString rate = filmdata.value("rating_count").toString();
    ui->label_rate->setText(rate);
    QString time = filmdata.value("runtime").toString();
    ui->label_time->setText(time);
    QString country = filmdata.value("film_locations").toString();
    ui->label_country->setText(country);
    QString man = filmdata.value("directors").toString();
    ui->label_man->setText(man);

    QUrl url(filmdata.value("poster").toString());
    QNetworkRequest request(url);
    manager->get(request);

}

void film_info::readdataPic(QNetworkReply *reply)
{
    QByteArray picdata =   reply->readAll();
        qDebug() << QString(picdata);
        QPixmap map;
       bool ok =  map.loadFromData(picdata);

        qDebug() << ok;
        map = map.scaled(QSize(100,100),Qt::KeepAspectRatio);
        ui->label_7->setAlignment(Qt::AlignCenter);
        ui->label_7->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        ui->label_7->setPixmap(map);


}
