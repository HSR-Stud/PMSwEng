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

    QLabel * label1 = new QLabel ("000");
    label1->setAutoFillBackground(true);
    label1->setStyleSheet("background-color: white;");
    vLayout->addWidget(label1);
	
	QPushButton * incpush = new QPushButton("Increment");
	incpush->setAutoFillBackground(true);
	incpush->setStyleSheet("background-color: white;");
	vLayout->addWidget(incpush);
	
	QPushButton * decpush = new QPushButton("Decrement");
	decpush->setAutoFillBackground(true);
	decpush->setStyleSheet("background-color: white;");
	vLayout->addWidget(decpush);
	
	connect(incpush, &QPushButton::clicked(), Counter, Counter::incValue());
	connect(decpush, &QPushButton::clicked(), Counter, Counter::decValue());

    wTop.show();

    return app.exec();
}

