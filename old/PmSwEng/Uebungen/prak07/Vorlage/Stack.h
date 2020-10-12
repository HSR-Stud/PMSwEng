/*
 * Stack.h
 *
 *  Created on: 05.10.2016
 *      Author: mtrummer
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackSignals.h"

template<typename ElemType, int size = 10>
class Stack : public StackSignals {
 public:
  // Default-Konstruktor
  Stack();

  // legt ein Element auf den Stack, falls der Stack noch nicht voll ist
  // wasError() gibt Auskunft, ob push() erfolgreich war
  void push(const ElemType* e);

  // nimmt ein Element vom Stack, falls der Stack nicht leer ist
  // wasError() gibt Auskunft, ob pop() erfolgreich war
  ElemType pop();

  // liest das oberste Element vom Stack, falls der Stack nicht leer ist
  // wasError() gibt Auskunft, ob peek() erfolgreich war
  const ElemType& peek() const;

  // return: true: Stack ist leer
  //         false: sonst
  bool isEmpty() const
  {
    return top == 0;
  }

  // return: true: Stack ist voll
  //         false: sonst
  bool isFull() const
  {
    return top == size;
  }

  // return: true: Operation war fehlerhaft
  //         false: sonst
  bool wasError() const;

 private:
  ElemType elems[size];  // Speicher fuer Speicherung des Stacks
  int top;               // Arrayindex des naechsten freien Elements
  mutable bool error;    // true: Fehler passiert; false: sonst
  // mutable: auch const-Methoden koennen dieses Attribut setzen
};

// template definitions
template<typename ElemType, int size>
Stack<ElemType, size>::Stack() : top(0), error(false)
{
}

template<typename ElemType, int size>
void Stack<ElemType, size>::push(const ElemType* e)
{
  error = top == size;
  if (!error)
  {
    elems[top] = *e;
    ++top;
    emit itemPushed();
  }
}

template<typename ElemType, int size>
ElemType Stack<ElemType, size>::pop()
{
  error = top == 0;
  if (!error)
  {
    --top;
    emit itemPopped();
  }
  return elems[top];
}

template<typename ElemType, int size>
const ElemType& Stack<ElemType, size>::peek() const
{
  error = top == 0;
  return elems[top - 1];
}

template<typename ElemType, int size>
bool Stack<ElemType, size>::wasError() const
{
  return error;
}
#endif  // STACK_H_
