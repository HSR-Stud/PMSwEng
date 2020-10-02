///
/// \file VoltageDivider.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H

#include <QObject>
#include <QString>
#include "ESeries.h"

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
  /// \pre \p lowerRTh < \p upperRTh
  /// \param u1 Value for U1 in V
  /// \param u2 Value for U2 in V
  /// \param lowerRTh set the lower bound for resistor value output
  /// \param upperRTh set the higher bound for resistor value output
  /// \param resSerie gives the resister e-series on which the resistor are
  ///                  calculated
  /// \return returns the resulting restistor values if calculation finishes
  ///         successful. Otherwise 0 is returned in r1 and r2.
  ///
  static ResultingResistors calc(double u1, double u2, double lowerRTh,
                                 double upperRTh, const ESeries& resSerie);

 private:
  ///
  /// \brief VoltageDivider Ctor is private to restrict any instantiation of
  /// this class.
  ///
  VoltageDivider();

  enum
  {
    destExp = 2,
  };
  unsigned int getLowerOrEqIndex(double lowerRTh, const ESeries& actResSerie);
  unsigned int getUpperOrEqIndex(double upperRTh, const ESeries& actResSerie);
};

#endif  // VOLTAGEDIVIDER_H
