//Circlebutton CircleButton.cpp
#include "CircleButton.h"

CircleButton::CircleButton(QWidget *parent)
    : QPushButton(parent)
{
    this->setFixedSize(150, 150);

    _sectorAngle = 60*16;     // 30 Grad
    _sectorPosition = 0*16;   // 0 Grad = 3 Uhr
    _rotationSpeed = (int)(90.0* 16.0 / 20); // 90 Grad/sec = (90.0 * 16.0)/ 20
    _isRotating = false;

    _timer = new QTimer(this);
    QObject::connect( _timer, SIGNAL( timeout() ), this, SLOT( onTimeout() ));
}
CircleButton::CircleButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    this->setFixedSize(150, 150);

    _sectorAngle = 30*16;     // 30 Grad
    _sectorPosition = 0*16;   // 0 Grad = 3 Uhr
    _rotationSpeed = (int)(90.0* 16.0 / 20); // 90 Grad/sec = (90.0 * 16.0)/ 20
    _isRotating = false;

    _timer = new QTimer(this);
    QObject::connect( _timer, SIGNAL( timeout() ), this, SLOT( onTimeout() ));
}
void CircleButton::paintEvent(QPaintEvent * pe)
{
    QPushButton::paintEvent(pe);
    QPainter painter(this);

    // schmaler Ring:
    QPen pen(Qt::darkCyan, ringWidthSmall );
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);

    QRect rect ( (width()-2*ringRadius)/2, (height()-2*ringRadius)/2, 2*ringRadius, 2*ringRadius);
    painter.drawEllipse(rect);

    // Ringsegment (breit) zeichen:
    painter.setPen( QPen(Qt::green, ringWidthWide) );

    painter.drawArc(rect, _sectorPosition, _sectorAngle);
}
bool CircleButton::isRotating()
{
    return _isRotating;
}
void CircleButton::setRotating(bool doRotate)
{
    if (doRotate)
    {   if (! _timer->isActive() )
        {
            _timer->start(50);  // 50ms
        }
    }
    else
    {
        _timer->stop();
    }
    _isRotating= doRotate;
    update(); // update (draw) this widget

}
void CircleButton::onTimeout()
{
    _sectorPosition -= _rotationSpeed;
    update(); // update (draw) this widget
}
void CircleButton::setRotationSpeed(int speed)
{
    if (_rotationSpeed != speed)
    {   _rotationSpeed = speed;
        update(); // update (draw) this widget
    }
}
void CircleButton::setSectorPosition(int position)
{
    if (_sectorPosition != position)
    {
        _sectorPosition = position;
        update(); // update (draw) this widget
    }
}
void CircleButton::setSectorAngleDegrees(int angle)
{
    angle = angle * 16;
    if (_sectorAngle != angle)
    {
        _sectorAngle = angle;
        update(); // update (draw) this widget
    }
}
