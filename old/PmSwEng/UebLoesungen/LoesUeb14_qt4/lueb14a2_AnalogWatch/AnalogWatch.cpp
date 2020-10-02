#include <QtGui>

#include "AnalogWatch.h"

AnalogWatch::AnalogWatch(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{
    this->_timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(update()));
    _timer->start(50);  // Update all 50 ms

    this->setWindowTitle("Analog Watch");
    this->setStyleSheet("background-color: white;");

    this->setMinimumSize(100, 100);
    this->resize(600, 600);
}

void AnalogWatch::paintEvent(QPaintEvent *)
{
    // Sekundenzeiger:
    static const QPoint secondHand[4] = {
        QPoint(+1, 20),
        QPoint(-1, 20),
        QPoint(-1, -42),
        QPoint(+1, -42)
    };
    // Minutenzeiger:
    static const QPoint minuteHand[4] = {
        QPoint(+2, +14),
        QPoint(-2, +14),
        QPoint(-1, -59),
        QPoint(+1, -59)
    };
    // Stundenzeiger:
    static const QPoint hourHand[4] = {
        QPoint(+2, +14),
        QPoint(-2, +14),
        QPoint(-1, -45),
        QPoint(+1, -45)
    };
    // Ziffernblatt-Markierung alle 5 Minuten:
    static const QPoint mark5min[4] = {
        QPoint(+2, -46),
        QPoint(-2, -46),
        QPoint(-2, -60),
        QPoint(+2, -60)
    };
    // Ziffernblatt-Markierung jede Minute:
    static const QPoint mark1min[4] = {
        QPoint(+1, -56),
        QPoint(-1, -56),
        QPoint(-1, -60),
        QPoint(+1, -60)
    };


    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Logisches Koordinatensystem (x,y je -100..+100) setzen:
    int side = qMin(width(), height());
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen( Qt::NoPen );
    painter.setBrush( QColor(Qt::lightGray) );
    painter.drawEllipse( QPoint(0, 0), 74, 74);
    painter.setBrush( QColor(Qt::white) );
    painter.drawEllipse( QPoint(0, 0), 65, 65);

    // Ziffernblatt zeichnen:
    painter.setBrush( QColor(Qt::black) );
    for (int i= 0; i < 60; i++)
    {
        if (i % 5 == 0)
            painter.drawConvexPolygon(mark5min, 4);
        else
            painter.drawConvexPolygon(mark1min, 4);
        painter.rotate( 6.0 );
    }

    double nsecs = time.second() + time.msec()/1000.0;
    double nmins = time.minute(); // + nsecs / 100;
    double nhour = time.hour() + nmins / 60;

    // Stundenzeiger zeichnen:    (1 h <=> 30 Degrees)
    painter.save();
    painter.rotate(30.0 * nhour);
    painter.drawConvexPolygon(hourHand, 4);
    painter.restore();

    // Minutenzeiger zeichnen:    (1 min <=> 6 Degress)
    painter.save();
    painter.rotate(6.0 * nmins );
    painter.drawConvexPolygon(minuteHand, 4);
    painter.restore();

    // Sekundenzeiger zeichnen:    (1 sec = 6 degrees)
    painter.setBrush( QColor(Qt::red) );
    painter.setPen( QColor(Qt::red) );
    painter.save();
    painter.rotate(6.0 * nsecs);
    painter.drawConvexPolygon(secondHand, 4);
    painter.drawEllipse( QPoint(0, -42), 5, 5 );
    painter.restore();

    // Mittelpunkt zeichnen:
    painter.drawEllipse( QPoint(0, 0), 2, 2);
    painter.setBrush( QColor(Qt::black) );
    painter.drawEllipse( QPoint(0, 0), 1, 1);

}

