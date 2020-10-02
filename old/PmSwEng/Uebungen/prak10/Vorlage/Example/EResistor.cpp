#include "EResistor.h"
#include <cassert>

EResistor::EResistor(double value, AssignMethod method,
                     const IESeries& eSerie)
    : eSerie(eSerie)
{
  switch (method)
  {
    case assignUpperEValue:
      setUpperOrEqValue(value);
      break;
    case assignLowerEValue:
      setLowerOrEqValue(value);
      break;
  }
}

void EResistor::setLowerOrEqValue(double value)
{
  assert(0 < value);
  double dblExp = log10(value);
  exp = round(dblExp);
  double nrmValue = value * pow(10, normExp - exp);

  int i;
  for (i = eSerie.getElemCnt() - 1; i >= 0; --i)
  {
    if (nrmValue >= eSerie[i])
      break;
  }
  if (i >= 0)
  {
    index = i;
  }
  else
  {
    index = eSerie.getElemCnt() - 1;
    exp--;
  }
}

void EResistor::setUpperOrEqValue(double value)
{
  assert(0 < value);
  double dblExp = log10(value);
  exp = round(dblExp);
  double nrmValue = value * pow(10, normExp - exp);
  unsigned int i;
  for (i = 0; i < eSerie.getElemCnt(); ++i)
  {
    if (nrmValue <= eSerie[i])
      break;
  }
  if (i >= eSerie.getElemCnt())
  {
    index = 0;
    exp++;
  }
  else
  {
    index = i;
  }
}
