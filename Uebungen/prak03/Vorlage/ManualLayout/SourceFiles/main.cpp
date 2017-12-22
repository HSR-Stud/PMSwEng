// Modul PMSwEng, Praktikum 02 (Qt 1): Aufgabe 2
// Projekt: manual Layout
// Created: 25.09.2016
// Author:  M. Trummer
// File:    main.cpp
//---------------------------------------------------------------------------

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setFont(QFont("Times", 15 ));

    QWidget wtop;

    QLabel * label = new QLabel ("Hallo Qt-Welt");
    label->setGeometry(100, 300, 200, 100); // x, y, w, h
    label->setParent(&wtop);
    label->setAutoFillBackground(true);
    label->setStyleSheet("background-color: white;");

    wtop.show();

    return app.exec();
}


