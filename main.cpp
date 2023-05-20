#include "mainwindow.h"

#include <QApplication>
#include <QResource>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/img/appicon1.icns"));
    MainWindow w;
    w . setWindowIcon(QIcon("img/appicon.icns"));
    w.show();
    QResource::registerResource("/resource.qrc");
    return a.exec();
}
