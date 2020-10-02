// Modul: PmSwE, UW 12, N-Uebung 8 (Qt 3): Aufgabe 2
// File: MyDialog.cpp, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "Counter.h"
#include "MyDialog.h"
//---------------------------------------------------------------------------
MyDialog::MyDialog(QWidget * parent)
    : QDialog(parent)
{
    // **** Darstellung festlegen:
    mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);

    // Obere Zeile:
    label = new QLabel("0000");
    mainLayout->addWidget(label);

    label->setAlignment(Qt::AlignCenter);
    label->setAutoFillBackground(true);
    label->setStyleSheet("background-color: white;");
    label->setFont( QFont("Arial", 12) );

    // Mittlere Zeile:
    middleLayout = new QHBoxLayout;

    incButton = new QPushButton ("Inc");
    middleLayout->addWidget(incButton);

    decButton = new QPushButton ("Dec");
    middleLayout->addWidget(decButton);

    mainLayout->addLayout(middleLayout);

    // Untere Zeile:
    resetButton = new QPushButton ("Reset");
    mainLayout->addWidget(resetButton);

    // **** Interaktives Verhalten initialisieren:
    QObject::connect(incButton, SIGNAL(clicked()),
                     &counter, SLOT(incValue()));
    QObject::connect(decButton, SIGNAL(clicked()),
                     &counter, SLOT(decValue()));
    QObject::connect(resetButton, SIGNAL(clicked()),
                     this, SLOT(clearCounterValue()));  // <===

    QObject::connect(&counter, SIGNAL(valueChanged(int)),
                     label, SLOT(setNum(int)) );
}
//---------------------------------------------------------------------------
void MyDialog::clearCounterValue()
// Slot: wird aufgerufen falls Button 'Reset' betaetigt.
{
    counter.setValue(0);
}
//---------------------------------------------------------------------------

