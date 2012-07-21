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
	                       // pruefung ('mutable' wegen 'isValid() const').
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
	// liefert das Datum, das |n| Tage nach (n > 0) oder vor (n < 0) dem
	// aktuellen Datum liegt.
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
	// **** Uebung 2, Aufgaben 1-3:

	// Vergleichsoperatoren zum Vergleichen der Datumswerte.
	bool operator==(const MyDate& other) const;
	bool operator!=(const MyDate& other) const;
	bool operator<(const MyDate& other) const;
	bool operator<=(const MyDate& other) const;
	bool operator>(const MyDate& other) const;
	bool operator>=(const MyDate& other) const;

	int daysTil(const MyDate& til) const;
	// liefert Anzahl Tage bis zum angegebenen Datum (kann auch negativ sein)
	//-----------------------------------------------------------------------
    // Hilfsfunktionen

	MyDate & incDay();
	// inkrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.

	MyDate & decDay();
	// dekrementiert das aktuelle Datum um einen Tag und gibt es dann zurueck.

	int getDaysInMonth() const;
	// liefert die Anzahl Tage des aktuellen Monats im aktuellen Jahr.

	void print() const;
	// Hilfsfunktion fuer Tests und Debugging

	//-----------------------------------------------------------------------
	// **** Uebung 4: Aufgabe 3:
	int daysSince1() const;
	// liefert die Anzahl Tage seit dem Jahre 1 unter der Annahme, das der
	// Gregorianische Kalender während der ganzen Zeit gilt.
	// "MyDate(1, 1, 1).daysSince1()" ergibt 0.

	MyDate& setDateFromNofDays(int nDaysSince1);
	// Umkehrfunktion zu 'daysSince1()'
	// Vorbedingung: nDaysSince1 > 0

	static MyDate dateFromDays(int nday);
	// Datum 'nday' Tage seit Zeitpunkt 0.1.0001.
	// Vorbedingung: 'nday' > 0
	// n= 1    ergibt Datum  1. 1.0001  (Tag 1 im Jahre 0001)
	// n= 365  ergibt Datum 31.12.0001  (Tag 365 im Jahre 0001)
	// n= 366  ergibt Datum  1. 1.0002   Tag 1 im Jahre 0002)

	// Hilfsmethoden fuer 'daysSince1()'
	int daysSinceStartOfYear() const;
	int daysSince1InPreviousYears() const;
//===========================================================================
};
#endif /* MYDATE_H_ */
