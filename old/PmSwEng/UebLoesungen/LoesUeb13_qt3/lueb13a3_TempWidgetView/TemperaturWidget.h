#ifndef TEMPERATURWIDGET_H
#define TEMPERATURWIDGET_H
//---------------------------------------------------------------------------
// Modul: PmSwE, UW 12, N-Uebung 8, Qt 3: Aufgabe 3: Temperaturumrechnung
// File: TemperaturWidget.h, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

//---------------------------------------------------------------------------
class TemperaturWidget : public QWidget
{
private:
    Q_OBJECT

private:    // **** GUI-Stuff:
    QGridLayout * mainLayout;
    QLabel *label1, *label2, *label3;
    QLineEdit *eingabeLineEdit, *resultLineEdit;
    QGroupBox *groupBox;

    QHBoxLayout * boxLayout;
    QRadioButton * tCelsiusButton, * tFahrenheitButton;

    QPushButton * rechneButton;

public:
    TemperaturWidget(QWidget * parent = 0);
};
//---------------------------------------------------------------------------
#endif // MYDIALOG_H
