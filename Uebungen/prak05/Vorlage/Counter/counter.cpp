// Projekt: Qtcounter, 30.4.2010, 3.5.2015, ple
// File: counter.cpp

#include <QDebug>
#include "counter.h"

Counter::Counter(QObject* parent) :
  QObject(parent),
  value(0)
{

}

void Counter::setValue(int value)  // slot
{
    if (value != this->value)
    {
        this->value = value;
        emit valueChanged(value);
    }
}

void Counter::incValue()  // slot
{
    value++;
    qDebug() << "incremented, new Value= " << value;
    emit valueChanged(value);


}
void Counter::decValue()  // slot
{
    value--;
    qDebug() << "decremented, new Value= " << value;
    emit valueChanged(value);

}
void Counter::clearValue()  // slot
{
    if (value != 0)
    {
        value = 0;
        qDebug() << "Value cleared, new Value= " << value;
        emit valueChanged(value);
    }
}

