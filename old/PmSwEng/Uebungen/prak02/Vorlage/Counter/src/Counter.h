#ifndef _COUNTER_H
#define _COUNTER_H

// Projekt: Qtcounter, 28.09.2016
// Author: M. Trummer
// File: counter.h

#include <iostream>

class Counter
{
  public:
    Counter();
    int getValue() const
    {
      return value;
    }
    void incValue();
    void decValue();
    void setValue(int value);
    void clearValue();
  private:
    int value;
};
#endif

