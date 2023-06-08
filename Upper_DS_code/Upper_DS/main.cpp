#include "DS_Upper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DS_Upper w;
    w.show();
    return a.exec();
}
