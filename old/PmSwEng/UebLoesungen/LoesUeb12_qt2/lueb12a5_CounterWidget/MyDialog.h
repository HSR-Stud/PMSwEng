#ifndef MYDIALOG_H
#define MYDIALOG_H
//---------------------------------------------------------------------------
// Modul PmSwE, Uebung 12 (Qt 2): Aufgabe 5
// File: MyDialog.h, 20.5.2010, 21.5.2012, H. Pletscher
//---------------------------------------------------------------------------
#include <QtGui>

#include "counter.h"
//---------------------------------------------------------------------------
class MyDialog : public QDialog
{
private:    // **** Problem-Domain:
    Counter counter;

private:    // **** GUI-Stuff:
    QVBoxLayout * layout;
    QLabel * label;
    QPushButton * buInc;
    QPushButton * buDec;

public:
    MyDialog(QWidget * parent = 0);
};
//---------------------------------------------------------------------------
#endif // MYDIALOG_H
