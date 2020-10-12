#ifndef MYDIALOG_H
#define MYDIALOG_H
//---------------------------------------------------------------------------
// Modul: PmSwE, UW 12, Normal-Uebung 8, Qt 3: Aufgabe 1
// File: MyDialog.h, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QDialog>
class QWidget;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QPushButton;

#include "counter.h"
//---------------------------------------------------------------------------
class MyDialog : public QDialog
{
private:    // **** Problem-Domain:
    Counter counter;

private:    // **** GUI-Stuff:
    QVBoxLayout * mainLayout;
    QLabel * label;
    QHBoxLayout * middleLayout;
    QPushButton * incButton;
    QPushButton * decButton;
    QPushButton * resetButton;

public:
    MyDialog(QWidget * parent = 0);
};
//---------------------------------------------------------------------------
#endif // MYDIALOG_H
