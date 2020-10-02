// COunter main.cpp Alles im mainfile
#include <QtWidgets>
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

    QHBoxLayout * layoutTop = new QHBoxLayout();
    wTop.setLayout(layoutTop);

    QPushButton * buDec = new QPushButton ("&Decrement");
    layoutTop->addWidget(buDec);

    QLabel * laCount = new QLabel("0000");
    laCount->setAlignment(Qt::AlignCenter);
    layoutTop->addWidget(laCount);

    QPushButton * buInc = new QPushButton ("&Increment");
    layoutTop->addWidget(buInc);

    // **** Interaktives Verhalten initialisieren:
    QObject::connect(buInc, SIGNAL(clicked() ),
                     &counter, SLOT(incValue()));
    QObject::connect(buDec, SIGNAL(clicked()),
                     &counter, SLOT(decValue()));

    QObject::connect(&counter, SIGNAL(valueChanged(int)),
                     laCount, SLOT(setNum(int)) );

    // **** Epilog:
    wTop.show();

    return app.exec();
}
