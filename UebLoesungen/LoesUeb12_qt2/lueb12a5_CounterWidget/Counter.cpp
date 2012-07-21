// Modul PmSwE, Uebung 12 (Qt 2): Aufgabe 5
// File: Counter.cpp, 20.5.2010, 21.5.2012, H. Pletscher
//---------------------------------------------------------------------------
#include <QDebug>
#include "counter.h"

Counter::Counter()
{
    _value = 0;
}

int Counter::value() const
{
    return _value;
}

void Counter::setValue(int value)
{
    if (value != _value)
    {
        _value = value;
        emit valueChanged(_value);
    }
}

void Counter::incValue()
{
    _value++;
    qDebug() << "incremented, new Value= " << _value;
    emit valueChanged(_value);

}
void Counter::decValue()
{
    _value--;
    qDebug() << "decremented, new Value= " << _value;
    emit valueChanged(_value);

}

