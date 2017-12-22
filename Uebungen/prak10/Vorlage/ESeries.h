///
/// \file src/ESeries.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef ESERIES_H
#define ESERIES_H

#include <QString>
#include <cassert>
#include "IESeries.h"

///
/// \brief The ESeries class represents the E resistor series E12 and E24. If
/// more E resistor series are required, this class can be appended.
///
class ESeries : public IESeries {
 public:
  ///
  /// \brief ESeries Ctor
  /// \param serie defines which
  ///
  ESeries(IESeries::SeriesType serie) : type(serie)
  {
    switch (serie)
    {
      case IESeries::e12:
        values = e12Values;
        elemCnt = 12;
        name = "E12";
        break;
      default:
      case IESeries::e24:
        values = e24Values;
        elemCnt = 24;
        name = "E24";
        break;
    }
  }

  ///
  /// \brief getElemCnt function returns the count of desired E series. E.g. an
  /// object generated as E12 object returns 12.
  /// \return count of elements in represented E series
  ///
  unsigned int getElemCnt() const
  {
    return elemCnt;
  }

  ///
  /// \brief getName function returns the string of the desired E series. E.g.
  /// "E12" for an E12 serie.
  /// \return
  ///
  std::string getName() const
  {
    return name;
  }

  ///
  /// \brief operator [] to get an element of the serie with an index.
  /// \pre index < size of serie (element count)
  /// \pre index >= 0
  /// \param index of the element to be returned
  /// \return the element that at the index position in the serie represented
  ///         by the object
  ///
  unsigned int operator[](int index) const
  {
    assert(index < static_cast<int>(elemCnt));
    assert(index >= 0);
    return values[index];
  }

 private:
  const unsigned int* values;
  unsigned int elemCnt;
  std::string name;
  SeriesType type;
  static const unsigned int e12Values[];
  static const unsigned int e24Values[];
};
#endif  // ESERIES_H
