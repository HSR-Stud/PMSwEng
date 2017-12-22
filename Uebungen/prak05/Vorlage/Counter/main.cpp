// Modul: PmSwE, Uebung 12 (Qt 2): Aufgabe 2: Reset-Button
// Basis: Projekt Qtcounter, 30.4.2010, 21.5.2012 ple
// 6.5.2015 ple: Anpassung fuer Qt5
// File: main.cpp

#include <QtWidgets>

#include "counterwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CounterWidget counter;
    counter.show();

    return app.exec();
}


