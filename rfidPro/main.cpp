#include "mainwindow.h"
#include <QApplication>
#include "readrfidid.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    unsigned int ID = 0;
    while(1)
    {

        readCardId(ID);
        if(ID != 0)
        {
            exit(0);
        }
        sleep(1);
    }
    return a.exec();
}
