#include "SysModule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SysModule sys;
    return a.exec();
}
