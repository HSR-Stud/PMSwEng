// Modul: PmSwE, UW 12, Normal-Uebung 8, Qt 3: Aufgabe 2
// File: main.cpp, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "MyDialog.h"
//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyDialog mainWindow;

    // **** Objekt-Baum zur Memory-Management Kontrolle ausgeben:
    //      (natürlich nicht bei 'richtigen' Programmen)
    //mainWindow.dumpObjectTree();


    mainWindow.show();
    return app.exec();
}


