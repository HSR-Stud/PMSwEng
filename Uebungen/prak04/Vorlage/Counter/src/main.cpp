/*
 * main.cpp
 *
 *  Created on: Jun 29, 2017
 *      Author: user
 */

#include <cassert>
#include <climits>
#include <iostream>
#include "Counter.h"

using std::cout;
using std::endl;

int main()
{
  static Counter c1;

  /* Test inc/dec,clear around zero */
  assert(0 == c1.getValue());
  c1.incValue();
  assert(1 == c1.getValue());
  c1.clearValue();
  assert(0 == c1.getValue());
  c1.decValue();
  assert(-1 == c1.getValue());

  /* Test inc/dec,set around INT_MAX */
  c1.setValue(INT_MAX);
  assert(INT_MAX == c1.getValue());
  c1.incValue();
  assert(INT_MAX == c1.getValue());
  c1.decValue();
  assert(INT_MAX-1 == c1.getValue());

  /* Test inc/dec,set around INT_MIN */
  c1.setValue(INT_MIN);
  assert(INT_MIN == c1.getValue());
  c1.decValue();
  assert(INT_MIN == c1.getValue());
  c1.incValue();
  assert(INT_MIN+1 == c1.getValue());

  cout << "Test finished" << endl;
  return 0;
}
