#ifndef MYDATE_H_
#define MYDATE_H_
//===========================================================================
// Modul PmSwe, Uebung 1, Aufgaben 1-3: Klasse "MyDate" mit Tests
// File "MyDate.h",  4.6.2012, H. Pletscher
//===========================================================================

class MyDate
{
private:
	int _day;    // 1..31
	int _month;  // 1..12
	int _year;   // z.B. 2010
	mutable bool _isValid; // interner Cache fuer Resultat der Gueltigkeits-
	                       // pruefung (mutable wegen isValid() const).
public:
	MyDate();
	// erzeugt neues ungueltiges Datum-Objekt
	MyDate(int day, int month, int year);
	// erzeugt neues initialisiertes Datum-Objekt
	MyDate (const MyDate & x);
	// Copy-Constructor
	MyDate & operator= (const MyDate & x);
	// Zuweisungsoperator
	bool isLeapYear() const;
	// liefert true falls Schaltjahr
	bool isValid() const;
	// prueft ob akt. Datum gueltig, d.h. plausibel (nicht 31.2.2009)
	MyDate addDays(int n) const;
	// liefert das Datum, das n Tage nach dem aktuellen Datum liegt.
	// n muss >= 0 sein (Vorbedingung).
	//-----------------------------------------------------------------------
	MyDate & incDay();
	// inkrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.
	//-----------------------------------------------------------------------
	// Getter-Methoden:
	int getDay() const
	{
		return _day;
	}
	int getMonth() const
	{
		return _month;
	}
	int getYear() const
	{
		return _year;
	}
	//-----------------------------------------------------------------------

};
//===========================================================================
#endif /* MYDATE_H_ */
