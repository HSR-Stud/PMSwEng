/*
 * EventClass.h
 *
 *  Created on: Sep 27, 2016
 *      Author: user
 */

#ifndef A_H_
#define A_H_

#include "C.h"
#include "B.h"

class A : public C //Observer
{
  public:
    A(B& b) : b(b)
    {
      b.registerFoo(*this);
    }
    virtual void fooY();
  private:
    B& b;
};


#endif /* A_H_ */
