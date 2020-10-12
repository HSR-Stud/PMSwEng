#ifndef _COUNTER_H
#define _COUNTER_H

// Projekt: Qtcounter, 30.4.2010, 3.5.2015, ple
// File: counter.h

#include <QObject>

 class Counter : public QObject
 {
     Q_OBJECT
 private:
     int value;

public:
     Counter(QObject* parent = 0);
     int getValue() const
     {
         return value;
     }

     void incValue();
     void decValue();
     void setValue(int value);
     void clearValue();

 signals:
     void valueChanged(int newValue);
};
#endif

