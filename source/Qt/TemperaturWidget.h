#ifndef TEMPERATURWIDGET_H
#define TEMPERATURWIDGET_H
//---------------------------------------------------------------------------
// Modul: PmSwE, UW 13, N-Uebung 9 (Qt 4): Aufgabe 1: Temperaturumrechnung
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

private slots:
    void rechne();

};
//---------------------------------------------------------------------------
#endif // MYDIALOG_H
