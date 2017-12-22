// Projekt: Qtcounter,
// Created: 28.09.2016
// Author: M. Trummer
// File: counter.cpp

#include <iostream>
#include <climits>
#include "Counter.h"

using std::cout;
using std::endl;

Counter::Counter() :
    value(0)
{

}

void Counter::setValue(int value)  // slot
{
  if (value != this->value)
  {
    this->value = value;
    cout << "Value set to= " << value << endl;
  }
}

void Counter::incValue()  // slot
{
  if (INT_MAX <= value)
  {
    cout << "maximal counter value reached= " << value << endl;
    return;
  }

  value++;
  cout << "incremented, new Value= " << value << endl;

}
void Counter::decValue()  // slot
{
  if (INT_MIN >= value)
  {
    cout << "minimal counter value reached= " << value << endl;
    return;
  }

  value--;
  cout << "decremented, new Value= " << value << endl;
}
void Counter::clearValue()  // slot
{
  if (value != 0)
  {
    value = 0;
    cout << "Value cleared, new Value= " << value << endl;
  }
}

