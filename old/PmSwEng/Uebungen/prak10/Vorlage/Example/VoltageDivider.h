///
/// \file src/VoltageDivider.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H

#include <QObject>
#include <QString>
#include <cassert>
#include "EResistor.h"

///
/// \brief The VoltageDivider class
///
class VoltageDivider
{
 public:
  ///
  /// \brief The ResultingResistors struct
  ///
  struct ResultingResistors
  {
    ///
    /// \brief r1 represents the upper resistor in an unloaded voltage divider
    ///
    double r1;
    ///
    /// \brief r2 represents the lower resistor in an unloaded voltage divider
    ///
    double r2;
  };

  ///
  /// \brief Calculates the optimal values for R1 and R2. The base formula
  ///        behind this calculation is \f$u1=u2 {r2 \over r2+r1}\f$.
  /// \pre \p u1 > \p u2
  /// \pre \p u2 > 0
  /// \pre \p lowerRTh < \p upperRTh
  /// \pre \p lowerRTh > 0
  /// \param u1 Value for U1 in V
  /// \param u2 Value for U2 in V
  /// \param lowerRTh set the lower bound for resistor value output
  /// \param upperRTh set the higher bound for resistor value output
  /// \return returns the resulting restistor values if calculation finishes
  ///         successful. Otherwise 0 is returned in r1 and r2.
  ///
  static ResultingResistors calc(double u1, double u2,
                                 const EResistor& lowerRTh,
                                 const EResistor& upperRTh)
  {
    assert(u1 > u2);
    assert(u2 > 0);
    assert(lowerRTh < upperRTh);
    assert(lowerRTh > 0);

    double dMin = std::numeric_limits<double>::infinity();
    double r1saved = 0;
    double r2saved = 0;

    for (EResistor r1 = lowerRTh; r1 < upperRTh; ++r1)
    {
      for (EResistor r2 = lowerRTh; r2 < upperRTh; ++r2)
      {
        double ua = (u1 / (r1 + r2)) * r2;
        double d;
        d = ua > u2 ? ua - u2 : u2 - ua;
        if (d < dMin)
        {
          dMin = d;
          r1saved = r1;
          r2saved = r2;
        }
      }
    }
    assert(upperRTh >= r1saved);
    assert(lowerRTh <= r1saved);
    assert(upperRTh >= r2saved);
    assert(lowerRTh <= r2saved);
    ResultingResistors resResistors;
    resResistors.r1 = r1saved;
    resResistors.r2 = r2saved;
    return resResistors;
  }

 private:
  ///
  /// \brief VoltageDivider Ctor is private to restrict any instantiation of
  /// this class.
  ///
  VoltageDivider()
  {
  }

  enum
  {
    destExp = 2,
  };
};

#endif  // VOLTAGEDIVIDER_H
