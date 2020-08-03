#ifndef RFIDCLASSTHREAD_H
#define RFIDCLASSTHREAD_H
#include <QThread>
#include <QtDebug>
class rfidClassThread :public QThread
{
    Q_OBJECT
public:
    explicit rfidClassThread(QWidget *parent = nullptr){}
    ~rfidClassThread(){
        printf("~rfidClassThread\n");
    }

    void run() override;
signals:
    void sendIDtoLogin(unsigned int ID);
public:
    void closeInRunTofd();
private:
    QString id;
    unsigned int ID;
    int fd;
};

#endif // RFIDCLASSTHREAD_H
