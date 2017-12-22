/*
 * main.c
 *
 *  Created on: Sep 28, 2016
 *      Author: user
 */

#include <stdio.h>
#include "a.h"
#include "a2.h"
#include "b.h"

int main (void) {
  aInit();
  a2Init();

  bFooX(); /* fire event */
  printf("aFoo should be called now\n");
  printf("a2Foo should be called now\n");

  return 0;
}
