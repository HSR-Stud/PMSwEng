#include <cassert>
#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main()
{
  static Stack s1(3);
  assert(true == s1.isEmpty());
  s1.push(3);
  assert(3 == s1.pop());
  assert(false == s1.wasError());
  assert(true == s1.isEmpty());
  s1.push(4);
  assert(4 == s1.peek());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());
  s1.push(5);
  assert(5 == s1.peek());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());
  s1.push(6);
  assert(6 == s1.peek());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());
  s1.push(7);
  assert(true == s1.wasError());
  assert(6 == s1.peek());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());

  assert(6 == s1.pop());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());
  assert(5 == s1.pop());
  assert(false == s1.wasError());
  assert(false == s1.isEmpty());
  assert(4 == s1.pop());
  assert(false == s1.wasError());
  assert(true == s1.isEmpty());

  cout << "Stack Library Test finished" << endl;
  return 0;
}
