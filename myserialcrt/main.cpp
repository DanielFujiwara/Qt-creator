#include "myserialcrt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySerialCRT w;
    w.show();

    return a.exec();
}
