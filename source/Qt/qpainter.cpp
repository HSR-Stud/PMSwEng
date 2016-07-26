//**** Malvorgang initialisieren
QPixmap pixmap (160, 160);             // Zeichenoberfläche
QPainter painter (&pixmap);            // 'painter' zeichnet auf 'pixmap

//**** Zeichnungsgeräte initialisieren
QPen pen (Qt::blue, 2);
painter.setPen(pen);
QBrush brush (Qt::green);
painter.setBrush(brush);

//**** Zeichenoperation durchführen
painter.drawEllipse(10, 10, 140, 140);    // Kreis zeichnen
