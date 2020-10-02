// Modul PMSwEng, Praktikum 02 (Qt 1): Aufgabe 1
// Projekt: Hello Qt mit HTML
// Created: 25.09.2016
// Author:  M. Trummer
// File:    main.cpp
//---------------------------------------------------------------------------

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel * label = new QLabel
    (
        "<h1>Hallo Qt-Welt</h1>"
        "<h2><i>Qt is cute</i></h2>"
        "<p>Das ist ein QLabel der Text enthält, der <br/>"
        "durch HTML-Anweisungen formatiert wird.</p>"
        "- &lt;h1&gt;...&lt;/h1&gt; umschliessen Titel 1. Ordnung, <br/>"
        "- &lt;h2&gt;...&lt;/h2&gt; umschliessen Titel 2. Ordnung, <br/>"
        "- etc. bis &lt;h6&gt;...&lt;/h6&gt;. <br/>"
        "- &lt;br/&gt; bewirkt einen Zeilenumbruch,  <br/>"
        "- &lt;i&gt;...&lt;/i&gt; sorgt für <i>Schrägstellung (italics)</i>,<br/>"
        "- &lt;b&gt;...&lt;/b&gt; sorgt für <b>Fett (bold)</b> und<br/>"
        "- &lt;br/&gt; bewirkt einen Zeilenumbruch,  </br>"
        "<br/>"
        "Daneben gibt es noch viele weitere HTML-4 <br/>"
        "Anweisungen die verwendet werden können,<br/>"
        "u.a. für Links und Bilder.<br/>"
        "Selbstverständlich können auch Umlaute (Ä, Ö, Ü)<br/>"
        " und andere Zeichen, wie z.B. é, à, £, verwendet werden."
    );

    label->setFont(QFont("Times", 15 ));
    label->resize(500, 600);
    label->setWindowTitle("Ein erstes Qt-Programm");

    label->show();

    return app.exec();

}


