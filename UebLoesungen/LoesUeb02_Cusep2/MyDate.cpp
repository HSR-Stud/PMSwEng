//===========================================================================
// Modul PmSwe, Uebung 2, Aufgaben 1-3:
//   Klasse "MyDate": neu: Vergleichsoperatoren, Differenz zwischen zwei
//   Datumswerten (daysTil()), addDays(x) auch fuer x < 0.

// File "MyDate.cpp", 4.6.2012, H. Pletscher
//===========================================================================
#include <iostream>

#include "MyDate.h"

using namespace std;
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
// liefert true falls Schaltjahr, sonst false.
{
	// gewoehnliches Schaltjahr, aber kein Jahrhunderjahr oder wenn, ein Jahr
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
//===========================================================================
MyDate & MyDate::incDay()
// inkrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.
{
	if (_day < getDaysInMonth() ) _day++;
	else
	{
		_day = 1;
		if (_month < 12) _month++;
		else
		{
			_month= 1;
			_year++;
		}
	}
	return *this;
}
//---------------------------------------------------------------------------
MyDate & MyDate::decDay()
// dekrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.
{
	if (_day > 1) _day--;
	else
	{
		if (_month > 1) _month--;
		else
		{
			_month= 12;
			_year--;
			if (_year <= 0) _isValid = false;
		}
		_day = getDaysInMonth();
	}
	return *this;
}
//---------------------------------------------------------------------------
MyDate MyDate::addDays(int n) const
// liefert das Datum, das n Tage nach dem aktuellen Datum liegt.
// n kann >= 0 oder < 0 sein.
// Hinweis: Implementierung ist noch nicht effizient.

{
	MyDate tmp = *this;
	while (n > 0)
	{
		tmp.incDay(); n--;
	}
	while (n < 0)
	{
		tmp.decDay(); n++;
	}
	return tmp;
}
//===========================================================================
// Vergleichsoperatoren:

bool MyDate::operator== (const MyDate & d) const
// Test auf Gleichheit (beide Werte ungueltig gelten als gleich).
{
	if ( !this->isValid() && !d.isValid() ) return true;
	return _day == d._day && _month == d._month && _year == d._year;
}

bool MyDate::operator!= (const MyDate & d) const
// Test auf Ungleichheit (beide Werte ungueltig, gelten als gleich).
{
	return ! (*this == d);
}

bool MyDate::operator< (const MyDate & other) const
// Test ob kleiner (ein oder beide Werte ungueltig ergeben false).
{
	if ( !this->isValid() || !other.isValid() ) return false;

	if (_year < other._year)   return true;
	if (_year > other._year)   return false;
	if (_month < other._month) return true;
	if (_month > other._month) return false;
	return _day < other._day;
}

bool MyDate::operator<= (const MyDate & other) const
// Test ob kleiner oder gleich.
{
	return  (*this < other) || (*this == other);
}
bool MyDate::operator> (const MyDate & other) const
// Test ob groesser (ein oder beide Werte ungueltig ergeben false).
{
	return  (other < *this);
}
bool MyDate::operator>= (const MyDate & other) const
// Test ob kleiner oder gleich.
{
	return  (other <= *this);
}
//---------------------------------------------------------------------------
int MyDate::getDaysInMonth() const
// Hilfsfunktion:
// liefert die Anzahl Tage des aktuellen Monats im aktuellen Jahr.
{
	static int daysInMonth[2][13] =
	{		// Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
		{	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, // normal
		{	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, // Leap-Year
	};

	return  daysInMonth [!!isLeapYear()] [_month] ;

}
//---------------------------------------------------------------------------
int MyDate::daysTil(const MyDate & til) const
// liefert Anzahl Tage bis zum angegebenen Datum (kann auch negativ sein).
// Hinweis: Implementierung ist noch nicht effizient.
{
	MyDate temp(til);
	int n = 0;

	while (temp > *this)
	{
		n++;
		temp.decDay();
	}
	while (temp < *this)
	{
		n--;
		temp.incDay();
	}
	return n;
}
//---------------------------------------------------------------------------
void MyDate::print() const
// Hilfsfunktion
{	cout << _day << "." << _month << "." << _year;
}
