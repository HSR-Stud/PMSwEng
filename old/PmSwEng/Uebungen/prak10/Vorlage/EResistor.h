#ifndef ERESISTOR_H
#define ERESISTOR_H

#include <cmath>
#include "IESeries.h"

///
/// \brief An Object of the EResistor class represents a resistor of the
/// corresponding E series passed in Ctor.
/// series.
///
class EResistor {
 public:
  ///
  /// \brief The AssignMethod enum is used as argument in Ctor. It defines
  /// whether the nearest E series value representant is search below or above a
  /// given value.
  ///
  enum AssignMethod
  {
    assignUpperEValue,
    assignLowerEValue
  };

  ///
  /// \brief EResistor Ctor
  /// \param value for this value a representant will be searched in the
  /// corresponding serieType E-Serie
  /// \param method defines wheter the representant is search above the passed
  /// value oder below.
  /// \param serie is used to define which E series should be used to search the
  /// representant.
  ///
  EResistor(double value, AssignMethod method, const IESeries& serie);

  ///
  /// \brief operator <
  /// \param rhs object on the right hand side
  /// \return true if the value of the lhs object is smaller.
  ///
  bool operator<(const EResistor& rhs) const
  {
    return getValue() < rhs.getValue();
  }

  ///
  /// \brief operator <=
  /// \param rhs object on the right hand side
  /// \return true if the value of the lhs object is smaller or equal than the
  /// rhs.
  ///
  bool operator<=(const EResistor& rhs) const
  {
    return getValue() <= rhs.getValue();
  }

  ///
  /// \brief operator >
  /// \param rhs object on the right hand side
  /// \return true if the value of the lhs object is greater than the
  /// rhs object.
  ///
  bool operator>(const EResistor& rhs) const
  {
    return getValue() > rhs.getValue();
  }

  ///
  /// \brief operator >=
  /// \param rhs object on the right hand side
  /// \return true if the value of the lhs object is greater or equal than the
  /// rhs object.
  ///
  bool operator>=(const EResistor& rhs) const
  {
    return getValue() >= rhs.getValue();
  }

  ///
  /// \brief operator ++ increments the resistor value. The next value in the
  /// corresponding E serie is choosen. If an E serie overflow occurs for the
  /// next value, the exponent of the value is incremented too.
  /// \return the incremented representant
  ///
  const EResistor& operator++()
  {
    if (++index >= eSerie.getElemCnt())
    {
      index = 0;
      exp++;
    }
    return *this;
  }

  ///
  /// \brief operator +
  /// \param rhs object on the right hand side
  /// \return the sum of the rhs value and the lhs value as double type.
  ///
  double operator+(const EResistor& rhs)
  {
    double sum = getValue() + rhs.getValue();

    return sum;
  }

  ///
  /// \brief operator *
  /// \param rhs object on the right hand side
  /// \return the product of the rhs value and the lhs value as double type.
  ///
  double operator*(const EResistor& rhs)
  {
    double rhsVal = rhs.getValue();
    double val = getValue();
    return rhsVal * val;
  }

  ///
  /// \brief operator double for type convertion from EResistor to double
  ///
  operator double() const
  {
    return getValue();
  }

  ///
  /// \brief getValue
  /// \return the actual value of the resistor
  ///
  double getValue() const
  {
    return eSerie[index] * pow(10, exp - normExp);
  }

  ///
  /// \brief getSerie getter method
  /// \return the corresponding E-Serie
  ///
  const IESeries& getSerie() const
  {
    return eSerie;
  }

 private:
  enum
  {
    normExp = 2
  };

  unsigned int index;
  int exp;

  void setLowerOrEqValue(double value);
  void setUpperOrEqValue(double value);

  const IESeries& eSerie;
};

#endif  // ERESISTOR_H
