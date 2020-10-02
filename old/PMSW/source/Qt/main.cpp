//TemperaturWidget main.cpp
#include <QtWidgets>
#include "TemperaturWidget.h"
//------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TemperaturWidget mainWindow;

    mainWindow.show();
    return app.exec();
}
