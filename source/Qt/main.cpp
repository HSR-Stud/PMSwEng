#include "temperaturwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    temperaturwidget w;
    w.show();

    return a.exec();
}
