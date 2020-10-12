// Modul PmSwE, Uebung 11 (Qt 1): Aufgabe 1
// Projekt: HelloQt_HtmlLabel, 30.4.2010, 21.5.2012, ple
// File: main.cpp

#include <QtGui>

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
        "Selbstverständlich können auch Umlaute (ä, ö, ü)<br/>"
        " und andere Zeichen verwendet werden."
    );

//    label->setFont(QFont("Times", 15 ));
    label->setFont(QFont("Arial", 14 ));
    label->resize(500, 600);
//    label->setWindowTitle("Ein erstes Qt-Programm");
    label->setWindowTitle("Ihr Name");

    label->show();

//    return app.exec();
    int res = app.exec();
    delete label;
    return res;
}
//--------------------------------------------------------------------------------
// Einige Antworten auf die Fragen:
//
// b) Es fehlt das 'delete' fuer Label. ("Wer new sagt, muss auch delete sagen!")
//    Korrektur, siehe oben.
//
// e) Dann werden die Formatierungsanweisungen nicht interpretiert, sondern
//    als Text angezeigt.
//
// g)  +------------+      +------------+      +-----------+      +-----------+
//     |  QLabel    |----->|  QFrame    |----->|  QWidget  |----->|  QObject  |
//     +------------+      +------------+      +-----+-----+      +-----------+
//                                                   |          +--------------+
//                                                   +--------->| QPaintDevice |
//                                                              +--------------+
// i) Zitat:
//    "Qt's text widgets are able to display rich text, specified using a subset
//    of HTML 4 markup. Widgets that use QTextDocument, such as QLabel and
//    QTextEdit, are able to display rich text specified in this way."
//
//    ==> QTextDokument
//
// j) nein. (Wie findet man das heraus? --> Durch Ausprobieren!)




