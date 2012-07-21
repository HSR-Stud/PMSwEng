// Modul: PmSwE, Uebung 12 (Qt 2): Aufgabe 2: Reset-Button
// Basis: Projekt Qtcounter, 30.4.2010, 21.5.2012 ple
// File: main.cpp

#include <QtGui>

#include "counter.h"

int main(int argc, char *argv[])
{
    // **** Qt-Prolog:
    QApplication app(argc, argv);

    // **** Problemdomain:
    Counter counter;

    // **** GUI-Darstellung aufbauen:
    QDialog wTop;
    wTop.resize(200, 100); // w, h

    QVBoxLayout * layoutTop = new QVBoxLayout();
    wTop.setLayout(layoutTop);

    QLabel * laCount = new QLabel("0000");
    laCount->setAlignment(Qt::AlignHCenter);
    layoutTop->addWidget(laCount);

    QPushButton * buInc = new QPushButton ("Increment");
    layoutTop->addWidget(buInc);

    QPushButton * buDec = new QPushButton ("Decrement");
    layoutTop->addWidget(buDec);

    QPushButton * buReset = new QPushButton ("Reset");
    layoutTop->addWidget(buReset);

    // **** Interaktives Verhalten initialisieren:
    QObject::connect(buInc, SIGNAL( clicked() ),
                     &counter, SLOT( incValue() ) );
    QObject::connect(buDec, SIGNAL( clicked() ),
                     &counter, SLOT( decValue() ) );
    QObject::connect(buReset, SIGNAL( clicked() ),
                     &counter, SLOT( clearValue() ) );

    QObject::connect(&counter, SIGNAL( valueChanged(int) ),
                     laCount, SLOT( setNum(int) ) );

    // **** Epilog:
    wTop.show();

    return app.exec();
}


