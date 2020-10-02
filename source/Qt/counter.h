// File: counter.h
#ifndef _COUNTER_H
#define _COUNTER_H
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
     void clearValue();
 signals:
     void valueChanged(int newValue);
};
#endif
