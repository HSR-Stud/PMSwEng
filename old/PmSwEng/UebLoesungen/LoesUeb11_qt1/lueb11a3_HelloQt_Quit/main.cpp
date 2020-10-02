// Modul PmSwE, Uebung 11 (Qt 1): Aufgabe 3
// Projekt: HelloQt_PosLabel, 30.4.2010, 21.5.2012 ple
// File: main.cpp

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setFont(QFont("Times", 15 ));

    QDialog wtop;

    QLabel * label = new QLabel ("Hallo Qt-Welt");
    label->setGeometry(100, 300, 200, 100); // x, y, w, h
    label->setParent(&wtop);
    label->setAutoFillBackground(true);
    label->setStyleSheet("background-color: white;");

    QLabel * label2 = new QLabel ("Hallo Rapperswil");
    label2->setGeometry(100, 300+120, 200, 100); // x, y, w, h
    label2->setParent(&wtop);
    label2->setAutoFillBackground(true);
    label2->setStyleSheet("background-color: white;");

    QPushButton * buLinks = new QPushButton ("Go on");
    buLinks->setGeometry(100, 300+120+120, 90, 60); // x, y, w, h
    buLinks->setParent(&wtop);

    QPushButton * buRechts = new QPushButton ("Good bye");
    buRechts->setGeometry(100+110, 300+120+120, 90, 60); // x, y, w, h
    buRechts->setParent(&wtop);


    QObject::connect( buLinks, SIGNAL( clicked() ), qApp, SLOT( quit() ) );
    QObject::connect( buRechts, SIGNAL( clicked() ), qApp, SLOT( quit() ) );

    wtop.show();

    return app.exec();
}


