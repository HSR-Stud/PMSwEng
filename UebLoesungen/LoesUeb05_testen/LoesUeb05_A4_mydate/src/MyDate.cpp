//===========================================================================
// Modul PmSwe, Uebung 2, Aufgaben 1-3:
//   Klasse "MyDate": neu: Vergleichsoperatoren, Differenz zwischen zwei
//   Datumswerten ('daysTil()'), 'addDays(x)' auch fuer x < 0.

// File "MyDate.cpp", 4.6.2012, H. Pletscher
//===========================================================================
#include <cassert>
#include <climits>
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
// liefert 'true' falls Schaltjahr, sonst 'false'.
{
	// gewöhnliches Schaltjahr, aber kein Jahrhunderjahr oder wenn, ein Jahr
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
// liefert das Datum, das |n| Tage nach (n > 0) oder vor (n < 0) dem
// aktuellen Datum liegt.
#if 1
// Neu Uebung 4: Effiziente Implementierung mit Hilfe von 'daysSince1()'
// und 'dateFromDays()':
{
	return MyDate::dateFromDays( this->daysSince1() + n );

}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#else
// Implementierung ist nicht effizient:
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
#endif
//===========================================================================
// Vergleichsoperatoren:

bool MyDate::operator== (const MyDate & d) const
// Test auf Gleichheit (beide Werte ungueltig gelten als gleich).
{
	if ( !this->isValid() && !d.isValid() ) return true;
	return _day == d._day && _month == d._month && _year == d._year;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool MyDate::operator!= (const MyDate & d) const
// Test auf Ungleichheit (beide Werte ungueltig, gelten als gleich).
{
	return ! (*this == d);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool MyDate::operator<= (const MyDate & other) const
// Test ob kleiner oder gleich.
{
	return  (*this < other) || (*this == other);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool MyDate::operator> (const MyDate & other) const
// Test ob groesser (ein oder beide Werte ungueltig ergeben false).
{
	return  (other < *this);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
// Neu Uebung 4: Effiziente Implementierung mit Hilfe von 'daysSince1()'
#if 1
{
	return  til.daysSince1() - this->daysSince1();
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#else
{
	// Nicht effiziente Implementierung
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
#endif
//---------------------------------------------------------------------------
void MyDate::print() const
// Hilfsfunktion
{
	cout << _day << "." << _month << "." << _year << flush;
}
//===========================================================================

int MyDate::daysSinceStartOfYear() const
// liefert Anzahl Tage seit Jahresbeginn bis zum aktuellen Datum
// "MyDate(1, 1, 2010).dayInYear()"  ergibt 1.
// "MyDate(31, 12, 2010).dayInYear()"  ergibt 365.
// "MyDate(31, 12, 2008).dayInYear()"  ergibt 366.
{
	// Anzahl Tage im aktuellen Jahr (je ohne und mit Schaltjahr):
	static int daysInYear[2][12] =
	{	//      Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov     Dec
		//  0,  31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,     31
		{   0,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334 },// 365
		//  0,  31,  29,  31,  30,  31,  30,  31,  31,  30,  31,  30,     31
		{   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335 } // 366
	};
	return daysInYear[!!isLeapYear()][_month-1] + _day;
}
//---------------------------------------------------------------------------
int MyDate::daysSince1InPreviousYears() const
{
	int years = _year - 1;
	// Anzahl Tage = 365 Tage für alle Jahre + 1 Tag fuer jedes gewoehnliche
	// Schaltjahr (durch 4 teilbar) - Anz. Tage, Jahr durch 100 teilbar +
	// Anz. Tage, Jahr durch 400 teilbar (Schaltjahr).
	return years*365 + years/4 - years/100 + years/400;
}
//---------------------------------------------------------------------------
int MyDate::daysSince1() const
{
	return  daysSince1InPreviousYears() + daysSinceStartOfYear();
}
//---------------------------------------------------------------------------
static bool isLeapYear(int j)
// Hilfsfunktion
{
	return j % 400 == 0 || (j % 4 == 0 &&  j % 100 != 0);
}
//===========================================================================
MyDate MyDate::dateFromDays(int nday)
// Umkehrfunktion zu 'daysSince1()'
// liefert Datum des 'nday'-ten Tag seit dem 1.1.0001.
// Vorbedingung: 'n' > 0
// nday= 1     ==>  Datum  1. 1.0001 (Tag 1 im Jahre 0001)
// nday= 2     ==>  Datum  2. 1.0001 (Tag 2 im Jahre 0001)
// nday= 3     ==>  Datum  3. 1.0001 (Tag 3 im Jahre 0001)
// nday= 365   ==>  Datum 31.12.0001 (Tag 365 im Jahre 0001)
// nday= 365+1 ==>  Datum  1. 1.0002 (Tag 1 im Jahre 0002)
{
	assert (nday > 0);

	// *** Anzahl vollstaendige Jahr bestimmen:

	// Dazu durch durchschnittliche Dauer eines Jahres dividieren und danach
	// daraus die Anzahl Tage zurueckrechnen

	// Durchschnittliche Dauer (Anzahl Tage) eines Jahres:
	//   ndm =   365     + 1/4  - 1/100 + 1/400
	//       = ( 400*365 + 100  - 4     + 1     ) / 400
	//   ndm =  146097 / 400 = 365.2425  Tage
	//
	// Ungefaehre Anzahl ganze Jahre bestimmen:
	int nyears = 0;

	if (nday <= INT_MAX/400)
	{	// keine Overflow Gefahr.
		nyears = (nday * 400) / 146097;
	}
	else
	{	// Overflow verhindern, Berechnung in mehreren Schritten:
		const int N_MAX = INT_MAX/400;
		int nn = nday;
		while (nn >= N_MAX)
		{
			nyears += (N_MAX * 400) / 146097;
			assert (nyears >= 0);
			nn = nn - N_MAX;
		}
		nyears += (nn * 400) / 146097;
		assert ( nyears >= 0);
	}

	// 'nyears' in entsprechende Anzahl Tage 'nd' zurueckrechnen:
	int nd = nyears*365 + nyears/4 - nyears/100 + nyears/400;
	assert (nd >= 0); assert (nd <= nday);

	// Noch nicht in 'nyears' berücksichtigte Tage bestimmen:
	int n = nday - nd;
	assert (n >= 0);

	// Jahr 'j' des bisher gefundenen Datums:
	int j = nyears + 1;

	// Jahr 'j' evt. korrigieren, da 'nyears' evt. zu klein ist:
	while (n > 366)
	{	// korrigieren:
		n -= ::isLeapYear(j) ? 366 : 365;
		j++;
	}

	if (n > 365)
	{	// Jahr 'j' korrigieren, aber nur falls kein Schaltjahr
		if (! ::isLeapYear(j) )
		{
			//d._year++; n= 1;
			j++; n = 1;
		}
	}

	// *** Monat und Tag im letzten, angebrochenen Jahr bestimmen:
	int m= 0, t= 0;

	// Anzahl Tage im aktuellen Jahr (je ohne und mit Schaltjahr):
	static int tabDaysInYear[2][13] =
	{	//      Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec
		//  0,  31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31
		{   0,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
		//  0,  31,  29,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31
		{   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
	};

	if (n == 0)
	{	// keine Tage mehr ==> Datum ist letzter Tag im Vorjahr:
		t = 31; m = 12; j -= 1;
	}
	else
	{   // n ist hier "Tag im Jahr", d.h. 1...365/366
		assert (n > 0); assert (n <= 366);
		// Aktuelles Jahr ist evt. Schaltjahr:
		bool sj = !! ::isLeapYear(j);
		assert (sj || n <= 365);
		// Innerhalb Tabelle von oben her suchen. Dabei Startindex
	    // geschickt waehlen.
		for (m = n/30; m >= 0; m--)
//		for (m = 12; m >= 0; m--)
		{
			if (n > tabDaysInYear[sj][m]) break;
		}
		t = n - tabDaysInYear[sj][m];
		assert (t > 0); assert (t <= 31);
		m = m+ 1;
	}
	MyDate res (t, m, j);
	res._isValid = true;
	return res;
}

//---------------------------------------------------------------------------
MyDate& MyDate::setDateFromNofDays(int nDaysSince1)
// Umkehrfunktion zu 'daysSince1()'
// Vorbedingung: nDaysSince1 > 0
{
	static MyDate d;
	return d;
//	return *this = MyDate( nDaysSince1 );
}
//---------------------------------------------------------------------------
#if 0
MyDate MyDate::dateFromDaysOfYear(int ndays, int year)
{
	assert (n >= 0); assert (n <= 366);

	// *** Das letzte, angebrochene Jahr:

	// Anzahl Tage im aktuellen Jahr (je ohne und mit Schaltjahr):
	static int daysInYear[2][13] =
	{	//      Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec
		//  0,  31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31
		{   0,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
		//  0,  31,  29,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31
		{   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
	};

	if (n == 0)
	{	// keine Tage mehr ==> Datum ist letzter Tag im Vorjahr:
		t = 31; m = 12; j -= 1;
	}
	else
	{   // Aktuelles Jahr ist evt. Schaltjahr:
		bool sj = j % 400 == 0 || (j % 4 == 0 &&  j % 100 != 0);
		// Innerhalb Tabelle von oben her suchen. Dabei Startindex
	    // geschickt waehlen.
		for (m = n/30; m >= 0; m--)
		{
			if (n > daysInYear[sj][m]) break;
		}
		t = n - daysInYear[sj][m];
		assert (t > 0); assert (t <= 31);
		m = m+ 1;
	}
	_day = t; _month = m; _year = j; _isValid = true;
}
//---------------------------------------------------------------------------
#endif
#if 0
//---------------------------------------------------------------------------
int MyDate::daysSinceStartOfYearV2() const
// Version 2, von Werner Brenner
{
	int days = _day - 1;
	switch (_month) { // fall through, adding all previous months ...
	case 12:
		days += 30;
	case 11:
		days += 31;
	case 10:
		days += 30;
	case 9:
		days += 31;
	case 8:
		days += 31;
	case 7:
		days += 30;
	case 6:
		days += 31;
	case 5:
		days += 30;
	case 4:
		days += 31;
	case 3:
		if (isLeapYear())
			days += 29;
		else
			days += 28;
	case 2:
		days += 31;
	case 1:
		;
	}
	return days;
}
//---------------------------------------------------------------------------
int MyDate::daysSince1InPreviousYears() const
{
	int years = _year - 1;
	// Anzahl Tage = 365 Tage für alle Jahre + 1 Tag fuer jedes gewoehnliche
	// Schaltjahr (durch 4 teilbar) -
	return years*365 + years/4 - years/100 + years/400;
}
//---------------------------------------------------------------------------

int MyDate::daysSince1(void) const {
	if (_isValid)
		return daysSinceStartOfYear() + daysInPreviousYears();
	return -1;
}

MyDate MyDate::dateFromDays(int days)
{
	if (days < 0)
		return MyDate();

	int years, daysInNextMonth;
	years = (days+1)*400/146097; // <=> days/365.2425 (365 + 1/4 - 1/100 + 1/400)
	MyDate date(1, 1, years+1);
	days -= years*365 + years/4 - years/100 + years/400;

	for (;;) {
		daysInNextMonth = date.getLastDayOfMonth();
		if (days < daysInNextMonth)
			break;
		++date._month;
		days -= daysInNextMonth;
	}

	date._day = days+1;
	return date;
}
#endif
