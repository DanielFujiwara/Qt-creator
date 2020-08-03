#ifndef ACCOUNTCTRL_H
#define ACCOUNTCTRL_H
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlRecord>
class accountctrl
{
public:
    accountctrl();
    ~accountctrl();
    int acountLogin(QString name,QString passwork);
    int acoutCreateToBads(QString name,QString passwork,QString cardid);
private:

    QSqlQuery sqlQuery;
    QSqlDatabase database;
};

#endif // ACCOUNTCTRL_H
