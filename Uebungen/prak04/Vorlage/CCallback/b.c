/*
 * framework.c
 *
 *  Created on: Sep 28, 2016
 *      Author: user
 */
#include "b.h"

#include <stdio.h>

static void (*regFct)(void);

void bFooX(void)
{
  if (0 != regFct)
    regFct();
}
int bRegisterFoo(void (*fct)(void))
{
  regFct = fct;
  return 1;
}
