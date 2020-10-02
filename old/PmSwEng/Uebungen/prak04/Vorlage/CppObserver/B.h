/*
 * EventHandlerClass.h
 *
 *  Created on: Sep 27, 2016
 *      Author: user
 */

#ifndef B_H_
#define B_H_

#include "C.h"

class B //Subject
{
  public:
    B();
    void fooX()
    {
      if (0 != regContext)
        regContext->fooY();
    }
    void registerFoo(C& c)
    {
      regContext = &c;
    }
  private:
    C* regContext;
};


#endif /* B_H_ */
