// Modul PMSwEng, Praktikum 02 (Qt 1): Aufgabe 3
// Projekt: LayoutManager
// Created: 25.09.2016
// Author:  M. Trummer
// File:    main.cpp
//---------------------------------------------------------------------------
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setFont(QFont("Times", 15 ));

    QWidget wTop;

    QVBoxLayout* vLayout = new QVBoxLayout(&wTop);

    QLabel * label1 = new QLabel ("Hallo Qt-Welt");
    label1->setAutoFillBackground(true);
    label1->setStyleSheet("background-color: white;");
    vLayout->addWidget(label1);

    wTop.show();

    return app.exec();
}



