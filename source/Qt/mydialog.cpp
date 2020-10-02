//mydialog.cpp counter in mehreren Files
#include "counter.h"
#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent):
    QDialog(parent)
{
    this->resize(200, 100); // w, h

    layoutTop = new QVBoxLayout;
    this->setLayout(layoutTop);

    laCount = new QLabel("0000");
    laCount->setAlignment(Qt::AlignHCenter);
    layoutTop->addWidget(laCount);

    buInc = new QPushButton("&Increment");
    layoutTop->addWidget(buInc);

    buDec = new QPushButton("&Decrement");
    layoutTop->addWidget(buDec);
// **** Interaktives Verhalten initialisieren:
QObject::connect(buInc, SIGNAL(clicked() ),
                 &counter, SLOT(incValue()));
QObject::connect(buDec, SIGNAL(clicked()),
                 &counter, SLOT(decValue()));

QObject::connect(&counter, SIGNAL(valueChanged(int)),
                 laCount, SLOT(setNum(int)) );
}
