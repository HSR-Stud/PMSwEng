#include <QtGui>
#include "temperaturwidget.h"
temperaturwidget::temperaturwidget(QWidget *parent) :   QWidget(parent)
{
    //**** GUI aufbauen
    mainLayout = new QGridLayout();
    this->setLayout(mainLayout);
    font1 = new QFont("Arial", 12, QFont::Bold);    //Schriften setzen
    font2 = new QFont("Arial", 10, QFont::Bold);

    //**** Oberste Linie
    temp = new QLabel("Temperatur Umrechnung");
    temp-> setFont(*font1);
    mainLayout->addWidget(temp, 0,0);              //Objekt, Zeile 0, Spalte 0

    //**** Mittlere Linie
    input = new QLabel("Eingabe");
    input ->setFont(*font2);
    mainLayout->addWidget(input, 1, 0 );           //Objekt, Zeile 1, Spalte
    eingabe = new QLineEdit();
    mainLayout->addWidget(eingabe, 1, 1);
    radiobutton = new QGroupBox();
    mainLayout-> addWidget(radiobutton, 1, 2);
    celsius = new QRadioButton("°C");
    fahrenheit = new QRadioButton("°F");
    celsius->setChecked(true);
    hbox = new QHBoxLayout();                        //Layout RadioButtons
    hbox->addWidget(celsius);
    hbox->addWidget(fahrenheit);
    radiobutton->setLayout(hbox);

    //**** Unterste Liniec
    output = new QLabel("Ausgabe");
    output -> setFont(*font2);
    mainLayout->addWidget(output, 2, 0);
    ausgabe = new QLineEdit();
    ausgabe-> setReadOnly(true);
    mainLayout-> addWidget(ausgabe, 2,1);
    rechne = new QPushButton("Berechne");
    rechne->setDefault(true);
    mainLayout->addWidget(rechne, 2, 2);

    //**** Signale Verknüpfen
    QObject::connect(rechne, SIGNAL(clicked()),this , SLOT(Berechne()));
    QObject::connect(eingabe, SIGNAL(editingFinished()), this, SLOT(Berechne()));
}
void temperaturwidget::Berechne()
{
    QString s = eingabe->text();
    bool okay;
    double x = s.toDouble(&okay);
    if(!okay)
    {
        ausgabe->setText("Eingabe falsch");
        eingabe->setText("0.0");
    }
    else         //okay=true umwandlung möglich
    {
        double y;
        if(celsius->isChecked())
        {
            y=(x*1.8)+32;
        }
        else       //fahrenheit is checked
        {
            y=(x-32)*(5.0/9.0);
        }
    QString d = QString("%1").arg(y, 0, 'g', 6);
    ausgabe->setText(d);
    }
}
