#include "mainwindow.h"
#include <QApplication>
#include "welcomeppt.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //定制皮肤在程序运行之前设置
            QFile file("./pic/otherco.qss");
            file.open(QIODevice::ReadOnly);
           QByteArray array =  file.readAll();
          // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
           qApp->setStyleSheet(array);

//           welcomePpt *ppt = new welcomePpt();

           //欢迎界面广告
           welcomePpt *ppt = new welcomePpt();
//          this->show();
//           ppt->show();


    MainWIndow w;
    w.show();
     ppt->show();

    return a.exec();
}
