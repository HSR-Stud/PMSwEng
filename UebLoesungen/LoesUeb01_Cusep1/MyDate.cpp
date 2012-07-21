//===========================================================================
// Modul PmSwe, Uebung 1, Aufgaben 1-3: Klasse "MyDate" mit Tests
// File "MyDate.cpp", 4.6.2012, H. Pletscher
//===========================================================================
#include "MyDate.h"

//---------------------------------------------------------------------------
MyDate::MyDate()
// erzeugt (ungueltiges) Datum-Objekt
:	_day(0), _month(0), _year(0), _isValid(false)
{
}
//---------------------------------------------------------------------------
MyDate::MyDate(int day, int month, int year)
// erzeugt Datum-Objekt aus int-Werten.
:	_day(day), _month(month), _year(year), _isValid(false)
{
}
//---------------------------------------------------------------------------
MyDate::MyDate(const MyDate & x)
// Copy-Constructor.
:_day(x._day), _month(x._month), _year(x._year), _isValid(x._isValid)
{
}
//---------------------------------------------------------------------------
MyDate & MyDate::operator=(const MyDate & x)
// Zuweisungsoperator.
{
	if (this != &x)
	{
		_day = x._day; _month = x._month; _year = x._year;
		_isValid = x._isValid;
	}
	return *this;
}
//---------------------------------------------------------------------------
bool MyDate::isLeapYear() const
{
	// gewoehnliches Schaltjahr, aber kein Jahrhunderjahr oder wenn ein Jahr
	// durch 400 teilbar.
	return _year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0);
}
//---------------------------------------------------------------------------
bool MyDate::isValid() const
// prueft ob akt. Datum gueltig, d.h. plausibel (nicht 31.2.2009).
{
	static int daysInMonth[2][13] =
	{		// Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
		{	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, // normal
		{	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, // Leap-Year
	};

	if (_isValid) return true;
	if (_day < 1 || _day > 31) return false;
	if (_month < 1 || _month > 12) return false;
//	if (_year <= 1582) return false;  // (Gregorianischer Kalender)
	if (_year <= 0) return false;

	if ( _day > daysInMonth [!!isLeapYear()] [_month] ) return false;
	_isValid = true;
	return true;
}
//---------------------------------------------------------------------------
MyDate & MyDate::incDay()
// inkrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.
{
	++_day;
	_isValid = false;
	if (!isValid())
	{
		_day = 1;
		if (_month == 12)
		{
			_month = 1;
			++ _year;
		}
		else ++ _month;
	}
	return *this;
}
//---------------------------------------------------------------------------
MyDate MyDate::addDays(int n) const
// liefert das Datum, das n Tage nach dem aktuellen Datum liegt.
// n muss >= 0 sein (Vorbedingung).
{
	MyDate tmp = *this;
	while (n-- > 0)
	{
		tmp.incDay();
	}
	return tmp;
}
//---------------------------------------------------------------------------
