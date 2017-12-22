/*
 * a2.c
 *
 *  Created on: Aug 31, 2017
 *      Author: user
 */

#include <stdio.h>
#include "b.h"

static void a2Foo(void);

void a2Init(void) {
  bRegisterFoo(&a2Foo);
}

void a2Foo(void) {
  printf("a2Foo called\n");
}

