//Circlebutton CircleButton.h
#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <QtWidgets>

class CircleButton : public QPushButton
{
  
private:
    Q_OBJECT

private:
    // Size of the Ring:
    enum { ringRadius = 60 };
    enum { ringWidthSmall = 5 };
    enum { ringWidthWide = 15 };

    // Circular sector data:
    int _sectorPosition;  // Kreissektor-Position in 1/16 Grad (0 <=> 3 Uhr)
    int _sectorAngle;     // Kreissektor-Winkel in 1/16 Grad
    int _rotationSpeed;   // Umdrehungsgeschwindigkeit in 1/16 Grad pro 50ms
    bool _isRotating;     // Rotation is enabled / disabled
    // Other data:
    QTimer * _timer;

private:
    void paintEvent(QPaintEvent *);

public:
    explicit CircleButton(const QString & text, QWidget * parent = 0);
    explicit CircleButton(QWidget * parent = 0);

    bool isRotating();
    // returns if ring rotating is enabled (true) or disabled (false)

    void setRotating(bool doRotate);
    // enable/disable ring rotating

private slots:
    void onTimeout();

public slots:
    void setSectorPosition(int position);
    // Kreissektor-Position in 1/16 Grad setzen
    // pos 0 entspricht der Uhrposition 3 Uhr

    void setSectorAngleDegrees(int angle);
    // Grösse des Sektorwinkel in Grad setzen

    void setRotationSpeed(int speed);
    // Rotationsgeschwindigkeit in 1/16 Grad pro 50ms setzen
};

#endif // CIRCLEBUTTON_H
