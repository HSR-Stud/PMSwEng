// Modul: PmSwE, UW 13, N-Uebung 9 (Qt 4): Aufgabe 3: Temperatur-Umrechnung
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
    label1 = new QLabel("<b>Temperatur Umrechnung:</b>");
    mainLayout->addWidget( label1, 0, 0, 1, 3 );

    label1->setAlignment(Qt::AlignLeft);
    label1->setAlignment(Qt::AlignVCenter);
    label1->setAutoFillBackground(true);
    //label1->setStyleSheet("background-color: white;");
    label1->setFont( QFont("Arial", 12) );

    // Mittlere Zeile:
    label2 = new QLabel("Eingabe:");
    mainLayout->addWidget( label2, 1, 0 );
    eingabeLineEdit = new QLineEdit();
    mainLayout->addWidget( eingabeLineEdit, 1, 1 );
    boxLayout = new QHBoxLayout;
    groupBox = new QGroupBox;
    groupBox->setLayout(boxLayout);
    tCelsiusButton = new QRadioButton("°C", groupBox);
    tCelsiusButton->setChecked(true);
    boxLayout->addWidget(tCelsiusButton);
    tFahrenheitButton = new QRadioButton("°F", groupBox);
    boxLayout->addWidget(tFahrenheitButton);
    mainLayout->addWidget(groupBox, 1, 2);

    // Untere Zeile:
    label3 = new QLabel("Ergebnis= ");
    mainLayout->addWidget( label3, 2, 0 );
    resultLineEdit = new QLineEdit();
    resultLineEdit->setReadOnly(true);
    mainLayout->addWidget( resultLineEdit, 2, 1 );

    rechneButton = new QPushButton("Rechne");
    mainLayout->addWidget( rechneButton, 2, 2 );

    // **** Interaktives Verhalten initialisieren:
    QObject::connect(rechneButton, SIGNAL(clicked()),
                     this, SLOT(rechne()) );
    QObject::connect(eingabeLineEdit, SIGNAL(editingFinished()),
                     this, SLOT(rechne()) );
}
//---------------------------------------------------------------------------
void TemperaturWidget::rechne()
// Slot: wird aufgerufen falls Button 'Rechne' betaetigt.
{
    QString s = eingabeLineEdit->text();
    bool okay;
    double x = s.toDouble(&okay);
    if (!okay)
    {
        resultLineEdit->setText("Eingabe falsch");
        eingabeLineEdit->setText("0.0");
        QMessageBox::warning(this, "Temperaturumrechnung",
                             "Eingabe ist falsch!");
    }
    else
    {
        double res = 0;
        if (tCelsiusButton->isChecked() )
        {   // Umrechnung Celsius --> Fahrenheit
            res = x * 1.8 +32;
        }
        else
        {   // Umrechnung  Fahrenheit --> Celsius
            res = (x - 32) * 5.0 / 9.0;
        }
        QString r = QString("%1").arg(res, 0, 'g', 5 );
        resultLineEdit->setText(r);
    }
}
//---------------------------------------------------------------------------

