// Modul: PmSwE, Uebung 12 (Qt 2): Aufgabe 4: GridLayout
// Basis: Projekt Qtcounter, 30.4.2010, 21.5.2012, ple
// File: main.cpp

#include <QtGui>

#include "counter.h"

int main(int argc, char *argv[])
{
    // **** Qt-Prolog:
    QApplication app(argc, argv);

    // **** Problemdomain:
    Counter counter;
    Counter counter2;

    // **** GUI-Darstellung aufbauen:
    QDialog wTop;
    wTop.resize(200, 100); // w, h

    QGridLayout * layoutTop = new QGridLayout();
    wTop.setLayout(layoutTop);

    // --- Zaehler 1:
    QLabel * laCount = new QLabel("0000");
    laCount->setAlignment(Qt::AlignHCenter);
    layoutTop->addWidget(laCount, 0, 0);  // row 0, col 0

    QPushButton * buInc = new QPushButton ("Increment 1");
    layoutTop->addWidget(buInc, 1, 0);  // row 1, col 0

    QPushButton * buDec = new QPushButton ("Decrement 1");
    layoutTop->addWidget(buDec, 2, 0);  // row 2, col 0

    QPushButton * buReset = new QPushButton ("Reset 1");
    layoutTop->addWidget(buReset, 3, 0);  // row 3, col 0

    // --- Zaehler 2:
    QLabel * laCount2 = new QLabel("0000");
    laCount2->setAlignment(Qt::AlignHCenter);
    layoutTop->addWidget(laCount2, 0, 1);  // row 0, col 1

    QPushButton * buInc2 = new QPushButton ("Increment 2");
    layoutTop->addWidget(buInc2, 1, 1);  // row 1, col 1

    QPushButton * buDec2 = new QPushButton ("Decrement 2");
    layoutTop->addWidget(buDec2, 2, 1);  // row 2, col 1

    QPushButton * buReset2 = new QPushButton ("Reset 2");
    layoutTop->addWidget(buReset2, 3, 1);  // row 3, col 1

    // **** Interaktives Verhalten initialisieren:
    // --- Zaehler 1:
    QObject::connect(buInc, SIGNAL( clicked() ),
                     &counter, SLOT( incValue() ) );
    QObject::connect(buDec, SIGNAL( clicked() ),
                     &counter, SLOT( decValue() ) );
    QObject::connect(buReset, SIGNAL( clicked() ),
                     &counter, SLOT( clearValue() ) );

    QObject::connect(&counter, SIGNAL( valueChanged(int) ),
                     laCount, SLOT( setNum(int) ) );

    // --- Zaehler 2:
    QObject::connect(buInc2, SIGNAL( clicked() ),
                     &counter2, SLOT( incValue() ) );
    QObject::connect(buDec2, SIGNAL( clicked() ),
                     &counter2, SLOT( decValue() ) );
    QObject::connect(buReset2, SIGNAL( clicked() ),
                     &counter2, SLOT( clearValue() ) );

    QObject::connect(&counter2, SIGNAL( valueChanged(int) ),
                     laCount2, SLOT( setNum(int) ) );

    // **** Epilog:
    wTop.show();

    return app.exec();
}


