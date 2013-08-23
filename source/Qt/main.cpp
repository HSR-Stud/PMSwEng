// Modul: PmSwE, UW 13, N-Uebung 9 (Qt 4): Aufgabe 1: Temperatur-Umrechnung
// File: main.cpp, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "TemperaturWidget.h"
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TemperaturWidget mainWindow;

    // **** Objekt-Baum zur Memory-Management Kontrolle ausgeben:
    //      (natürlich nicht bei 'richtigen' Programmen)
    //mainWindow.dumpObjectTree();

    mainWindow.show();
    return app.exec();
}


