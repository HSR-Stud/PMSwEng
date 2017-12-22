/*
 * Stack.h
 *
 *  Created on: 25.05.2015
 *      Author: rbondere
 */

#ifndef STACK_H_
#define STACK_H_

class Stack
{
  public:
    Stack(int theSize = 10);
    // Default-Konstruktor

    ~Stack();
    // Destruktor

    void push(int e);
    // legt ein Element auf den Stack, falls der Stack noch nicht voll ist
    // wasError() gibt Auskunft, ob push() erfolgreich war

    int pop();
    // nimmt ein Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob pop() erfolgreich war

    int peek() const;
    // liest das oberste Element vom Stack, falls der Stack nicht leer ist
    // wasError() gibt Auskunft, ob peek() erfolgreich war

    bool isEmpty() const;
    // return: true: Stack ist leer
    //            false: sonst

    bool wasError() const;
    // return: true: Operation war fehlerhaft
    //         false: sonst

  private:
    int size;   // Anzahl Elemente im Stack
    int top;    // Arrayindex des naechsten freien Elements
    mutable bool error; // true: Fehler passiert; false: sonst
    // mutable: auch const-Methoden koennen dieses Attribut setzen
   int* elems; // Dynamischer Speicher fuer Speicherung des Stacks

};

#endif // STACK_H_
