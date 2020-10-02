#ifndef _COUNTER_H
#define _COUNTER_H
//---------------------------------------------------------------------------
// Modul PmSwE, Uebung 12 (Qt 2): Aufgabe 5
// File: Counter.h, 20.5.2010, 21.5.2012, H. Pletscher
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
     void setValue(int value);

 signals:
     void valueChanged(int newValue);
};
#endif

