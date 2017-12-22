/*
 * stack.cpp
 *
 *  Created on: 19.05.2015
 *      Author: rbondere
 */

#include "Stack.h"

Stack::Stack(int theSize) :
  size(theSize), top(0), error(false), elems(new int[size])
{
}

Stack::~Stack()
{
  delete[] elems;
}

void Stack::push(int e)
{
  error = top == size;
  if (!error)
  {
    elems[top] = e;
    top++;
  }
}

int Stack::pop()
{
  error = top == 0;
  if (!error)
  {
    --top;
    return elems[top];
  }
  else
    return 0;
}

int Stack::peek() const
{
  error = top == 0;
  if (!error)
    return elems[top - 1];
  else
    return 0;
}

bool Stack::isEmpty() const
{
  return top == 0;
}

bool Stack::wasError() const
{
  return error;
}
