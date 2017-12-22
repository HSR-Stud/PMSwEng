#include "IESeries.h"

IESeries::SeriesType& operator++(IESeries::SeriesType& serie)
{
  switch (serie)
  {
    case IESeries::e12:
      serie = IESeries::e24;
      break;
    case IESeries::e24:
    default:
      serie = IESeries::e12;
  }
  return serie;
}
