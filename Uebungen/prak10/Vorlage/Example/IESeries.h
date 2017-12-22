#ifndef IESERIES_H
#define IESERIES_H

#include <string>

///
/// \brief The IESeries class is an interface to be able to mock ESeries class
/// for test reasons.
///
class IESeries {
 public:
  ///
  /// \brief An object of the ESeries class represents a resistor E-Serie. Eg.
  /// E12, E24
  ///
  enum SeriesType
  {
    e12 = 0,
    e24,
    nrOfESeries
  };

  ///
  /// \brief operator ++ use to increment the enum items of SeriesType. If an
  /// overflow occurs the next item is the first of the SeriesType enum.
  /// \param serie instance of SeriesType enum
  /// \return the serie instance which is incremented by one.
  ///
  friend SeriesType& operator++(SeriesType& serie);

  ///
  /// \brief getElemCnt function returns the count of desired E series. E.g. an
  /// object generated as E12 object returns 12.
  /// \return count of elements in represented E series
  ///
  virtual unsigned int getElemCnt() const = 0;

  ///
  /// \brief getName function returns the string of the desired E series. E.g.
  /// "E12" for an E12 serie.
  /// \return
  ///
  virtual std::string getName() const = 0;

  ///
  /// \brief operator [] to get an element of the serie with an index.
  /// \pre index < size of serie (element count)
  /// \pre index >= 0
  /// \param index of the element to be returned
  /// \return the element that at the index position in the serie represented
  ///         by the object
  ///
  virtual unsigned int operator[](int index) const = 0;
};

#endif  // IESERIES_H
