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
     void clearValue();
     void setValue(int value);

 signals:
     void valueChanged(int newValue);
};
#endif

