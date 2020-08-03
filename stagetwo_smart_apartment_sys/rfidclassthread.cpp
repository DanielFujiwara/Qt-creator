#include "rfidclassthread.h"
#include "readrfidid.h"

void rfidClassThread::run()
{
    unsigned int ID = 0;
//    int fd;
    while(1)
    {
        printf("run thread\n");
        readCardId(ID,fd);
        if(ID != 0)
        {
            emit sendIDtoLogin(ID);
            break;
        }
        QThread::sleep(1);

    }

    printf("your card: %x\n",ID);
}

void rfidClassThread::closeInRunTofd()
{
    closeFd(this->fd);
    printf("close fd");
}
