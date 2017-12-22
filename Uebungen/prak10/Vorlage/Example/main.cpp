#include <QCoreApplication>
#include <iostream>
#include "ESeries.h"
#include "VoltageDivider.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  EResistor rMin(1e3, EResistor::assignUpperEValue, ESeries(IESeries::e24));
  EResistor rMax(10e3, EResistor::assignLowerEValue, ESeries(IESeries::e24));

  VoltageDivider::ResultingResistors resResistor =
      VoltageDivider::calc(12, 5, rMin, rMax);

  std::cout << "R1: " << resResistor.r1 << std::endl;
  std::cout << "R2: " << resResistor.r2 << std::endl;

  return 0;
}
