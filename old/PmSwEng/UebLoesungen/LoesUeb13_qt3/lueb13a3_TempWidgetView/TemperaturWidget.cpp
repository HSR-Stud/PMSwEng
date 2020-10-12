// Modul: PmSwE, UW 12, N-Uebung 8, Qt 3: Aufgabe 3: Temperatur-Umrechnung
// File: TemperaturWidget.cpp, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "TemperaturWidget.h"
//---------------------------------------------------------------------------
TemperaturWidget::TemperaturWidget(QWidget * parent)
    : QWidget(parent)
{
    // **** Darstellung festlegen:
    mainLayout = new QGridLayout;
    this->setLayout(mainLayout);

    // Obere Zeile:
    label1 = new QLabel("Temperatur Umrechnung:");
    mainLayout->addWidget( label1, 0, 0, 1, 3 );

    label1->setAlignment(Qt::AlignLeft);
    label1->setAlignment(Qt::AlignVCenter);
    label1->setAutoFillBackground(true);

    // Mittlere Zeile:
    label2 = new QLabel("Eingabe:");
    mainLayout->addWidget( label2, 1, 0 );
    eingabeLineEdit = new QLineEdit();
    mainLayout->addWidget( eingabeLineEdit, 1, 1 );
    boxLayout = new QHBoxLayout;
    groupBox = new QGroupBox;
    groupBox->setLayout(boxLayout);
    tCelsiusButton = new QRadioButton("'C", groupBox);
    boxLayout->addWidget(tCelsiusButton);
    tFahrenheitButton = new QRadioButton("'F", groupBox);
    boxLayout->addWidget(tFahrenheitButton);
    mainLayout->addWidget(groupBox, 1, 2);

    // Untere Zeile:
    label3 = new QLabel("Ergebnis= ");
    mainLayout->addWidget( label3, 2, 0 );
    resultLineEdit = new QLineEdit();
    mainLayout->addWidget( resultLineEdit, 2, 1 );

    rechneButton = new QPushButton("Rechne");
    mainLayout->addWidget( rechneButton, 2, 2 );

}
//---------------------------------------------------------------------------

