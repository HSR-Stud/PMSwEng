#include <QApplication>

#include "AnalogWatch.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AnalogWatch clock (0, Qt::WindowStaysOnTopHint | /* Qt::FramelessWindowHint | */ Qt::WindowSystemMenuHint);
//    AnalogWatch clock (0, 0);

    Qt::WindowFlags flags = clock.windowFlags();
//    clock.setWindowFlags(flags | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

    clock.show();
    return app.exec();
}
