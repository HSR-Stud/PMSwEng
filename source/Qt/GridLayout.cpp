// Projekt: Qt5 Demo GridLayout, 3.5.2015 ple
// File: main.cpp

#include <QtWidgets>  // fuer Qt5

int main(int argc, char *argv[])
{
    // **** Qt-Prolog:
    QApplication app(argc, argv);

    // Main-widget:
    QWidget *w = new QWidget();

	// Grid layout:
    QGridLayout *gridLayout = new QGridLayout;  
	
    // Set the grid layout as the main layout:
    w->setLayout(gridLayout);

    // Buttons:
    QPushButton *b1 = new QPushButton("A");
    QPushButton *b2 = new QPushButton("B");
    QPushButton *b3 = new QPushButton("C");
    QPushButton *b4 = new QPushButton("D");
    QPushButton *b5 = new QPushButton("E");
    QPushButton *b6 = new QPushButton("F");

    // Einen Button zu 'gridlayout' hinzufuegen mit:
    //    'addWidget(QWidget*, int row, int column)' oder
    //    'addWidget(QWidget*, int row, int column, int rowspan, int colspan)'
    // Zeile 0:
    gridLayout->addWidget(b1, 0, 0);  // Zeile 0, Spalte 0
    gridLayout->addWidget(b2, 0, 1);  // Zeile 0, Spalte 1
    gridLayout->addWidget(b3, 0, 2);  // Zeile 0, Spalte 2

    // Zeile 1:
    gridLayout->addWidget(b4, 1, 0);  // Zeile 1, Spalte 0

    // Zeile 2:
    gridLayout->addWidget(b5, 2, 0, 1, 2);  // Zeile 2; 2 Spalten, ab Spalte 0

    // Zeile 3:
    gridLayout->addWidget(b6, 3, 0, 1, 3);  // Zeile 3; 3 Spalten, ab Spalte 0

    w->setWindowTitle("Demo GridLayout");

    w->show();

    return app.exec();
}
