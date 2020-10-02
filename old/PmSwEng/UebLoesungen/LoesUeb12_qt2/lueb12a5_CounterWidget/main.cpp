// Modul PmSwE, Uebung 12 (Qt 2): Aufgabe 5
// File: main.cpp, 20.5.2010, 21.5.2012, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "MyDialog.h"
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyDialog windowTop;

    windowTop.show();
    return app.exec();
}


