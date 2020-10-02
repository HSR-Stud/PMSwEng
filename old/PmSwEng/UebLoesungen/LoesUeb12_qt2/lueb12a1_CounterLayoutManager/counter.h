#ifndef _COUNTER_H
#define _COUNTER_H

// Projekt: Qtcounter, 30.4.2010, ple
// File: counter.h

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

