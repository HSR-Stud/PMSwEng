// Modul PmSwE, Uebung 12 (Qt 2): Aufgabe 5
// File: MyDialog.cpp, 20.5.2010, 21.5.2012, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>
#include "Counter.h"

#include "MyDialog.h"
//---------------------------------------------------------------------------
MyDialog::MyDialog(QWidget * parent)
    : QDialog(parent)
{
    // **** GUI-Darstellung aufbauen:
    this->resize(200, 100); // w, h

    QVBoxLayout * layout = new QVBoxLayout();
    this->setLayout(layout);

    label = new QLabel("0000");
    label->setAlignment(Qt::AlignHCenter);
    layout->addWidget(label);

    buInc = new QPushButton ("Increment");
    layout->addWidget(buInc);

    buDec = new QPushButton ("Decrement");
    layout->addWidget(buDec);

    // **** Interaktives Verhalten initialisieren:
    QObject::connect(buInc, SIGNAL(clicked() ),
                     &counter, SLOT(incValue()));
    QObject::connect(buDec, SIGNAL(clicked()),
                     &counter, SLOT(decValue()));

    QObject::connect(&counter, SIGNAL(valueChanged(int)),
                     label, SLOT(setNum(int)) );
}
