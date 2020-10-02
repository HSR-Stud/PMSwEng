// File: counter.cpp

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
void Counter::setValue(int value)  // slot
{
    if (value != _value)
    {
        _value = value;
        emit valueChanged(_value);
    }
}
void Counter::incValue()  // slot
{
    _value++;
    qDebug() << "incremented, new Value= " << _value;
    emit valueChanged(_value);
}
void Counter::decValue()  // slot
{
    _value--;
    qDebug() << "decremented, new Value= " << _value;
    emit valueChanged(_value);
}
void Counter::clearValue()  // slot
{
    if (_value != 0)
    {
        _value = 0;
        qDebug() << "Value cleared, new Value= " << _value;
        emit valueChanged(_value);
    }
}
