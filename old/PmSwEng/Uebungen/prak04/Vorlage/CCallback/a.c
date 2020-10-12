/*
 * foo.c
 *
 *  Created on: Sep 28, 2016
 *      Author: user
 */

#include <stdio.h>
#include "a.h"
#include "b.h"

static void aFoo(void);

void aInit(void)
{
  bRegisterFoo(&aFoo);
}

void aFoo(void)
{
  printf("aFoo called\n");
}
