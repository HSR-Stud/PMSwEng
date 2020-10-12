/*
 * counter.cpp
 *
 *  Created on: 22.09.2017
 *      Author: cvdg
 
 
 */

class Counter {	
	int CounterValue = 0;
	public:
	int getValue() const;  
	void incValue();
	void decValue();
	void setValue(int value);
	void clearValue(); 
	};

int Counter::getValue() const
{
  return CounterValue;
}

void Counter::incValue()
{
	CounterValue = CounterValue + 1;
}

void Counter::decValue()
{
	if (CounterValue !=0)
	{	
	CounterValue = CounterValue - 1;
    }
}
	
void Counter::setValue(int value)
{
  if (value >= 0)
  {
    CounterValue = value;
  }
}

void Counter::clearValue()
{
  CounterValue = 0;
}


