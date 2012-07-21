#ifndef _COUNTER_H
#define _COUNTER_H
//---------------------------------------------------------------------------
// Modul: PmSwE, UW 12, Normal-Uebung 8, Qt 3: Aufgabe 2
// File: Counter.h, 20.5.2010, H. Pletscher
//---------------------------------------------------------------------------
#include <QObject>

 class Counter : public QObject
 {
     Q_OBJECT
 private:
     int _value;

public:
     Counter();

     int value() const;

 public slots:
     void incValue();
     void decValue();
//     void clearValue();
     void setValue(int value);

 signals:
     void valueChanged(int newValue);
};
#endif

