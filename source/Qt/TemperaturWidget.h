#ifndef TEMPERATURWIDGET_H
#define TEMPERATURWIDGET_H

#include <QtWidgets>

class temperaturwidget : public QWidget
{
private:
    Q_OBJECT

    QGridLayout * mainLayout;
    QGroupBox * radiobutton;
    QHBoxLayout * hbox;
    QFont * font1;
    QFont * font2;
    QLabel * temp;
    QLabel * input;
    QLabel * output;
    QPushButton * rechne;
    QLineEdit * eingabe;
    QLineEdit * ausgabe;
    QRadioButton * celsius;
    QRadioButton * fahrenheit;

public:
    temperaturwidget(QWidget *parent = 0);

private slots:
    void Berechne();        //muss als slot gekennzeichent werden
                            //weil sonst Qt die Funktion nicht erkennt
};

#endif // TEMPERATURWIDGET_H
