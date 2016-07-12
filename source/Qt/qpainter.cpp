#include <QtWidgets>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    //**** Malvorgang initialisieren
    QPixmap pixmap (160, 160);             // Zeichenoberfläche
    QPainter painter (&pixmap);            // 'painter' zeichnet auf 'pixmap
    pixmap.fill( QColor(Qt::white));       // Hintergrund mit Weiss füllen

    //**** Zeichnungsgeräte initialisieren
    QPen pen (Qt::blue, 2);                 //Zeichenstift: blau, Breite= 2
    painter.setPen(pen);
    QBrush brush (Qt::green);               //Pinsel: gruen
    painter.setBrush(brush);

    //**** Zeichenoperation durchführen
    painter.drawEllipse(10, 10, 140, 140);   // Kreis zeichnen

    //**** In einem QLabel anzeigen:
    QLabel label;
    label.setPixmap( pixmap );
    label.show();
    return app.exec();
}
