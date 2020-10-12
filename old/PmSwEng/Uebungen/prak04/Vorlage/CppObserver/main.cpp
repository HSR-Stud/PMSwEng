/*
 * main.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: user
 */

#include "A.h"
#include "B.h"

int main()
{
  B b;
  A a(b);

  // fire event
  b.fooX();

  return 0;
}
