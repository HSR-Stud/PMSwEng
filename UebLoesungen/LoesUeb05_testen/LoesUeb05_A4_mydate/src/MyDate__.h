#ifndef MYDATE_H_
#define MYDATE_H_
class MyDate {
private:
	int _day; // 1..31
	int _month; // 1..12
	int _year; // 1..
	bool _isValid; // Datum gueltig?
public:
	// Erzeugt ein neues ungueltiges Datum-Objekt
	MyDate(void);

	// Erzeugt neues initialisiertes Datum-Objekt.
	// Falls kein gueltiges Datum angegeben wurde wird ein ungueltiges Datum-Objekt angelegt.
	MyDate(int day, int month, int year);

	// Copy-Constructor.
	MyDate(const MyDate & x);

	// Zuweisungsoperator.
	MyDate & operator=(const MyDate & x);

	// Liefert true falls Schaltjahr.
	// Ein ungueltiges Datum-Objekt liefert immer true (keine Exception).
	bool isLeapYear(void) const;

	// Ist das akt. Datum gueltig, d.h. plausibel? (z.B. nicht 31.2.2009)
	bool isValid(void) const;

	// Liefert neues Datum-Objekt n Tage nach dem aktuellen Datum
	// n darf auch negativ sein --> Datum vor dem aktuellen Datum.
	// Das resultierende Datum kann auch ungueltig sein (bei ungueltigem
	// Ausgangsdatum oder wenn das Resultat vor dem 1.1.0001 liegen würde).
	MyDate addDays(int n) const;

	// Liefert Anzahl Tage bis zum angegebenen Datum. Das Resultat ist negativ
	// wenn das til-Datum vor dem aktuellen Datum liegt.
	// Das Verhalten bei ungueltigen Datumsobjekten nicht festgelegt!
	int daysTil(const MyDate& til) const;

	// Liefert Anzahl Tage seit dem 1.1.0001.
	// In ungueltiges Datum liefert einen negativen Wert.
	int daysSince1(void) const;

	// Datum days Tage nach dem 1.1.0001.
	// Eine negative Anzahl Tage liefert ein ungueltiges Datumsobjekt.
	static MyDate dateFromDays(int days);

	/// Vergleichsfunktionen
	/// Vergleichen die Datumswerte.
	/// Ungueltige Datumsobjekte werden als gleich betrachtet!
	/// Ein unguelties Datumsobjekt ist weder < noch > als ein Gueltiges
	bool operator==(const MyDate& other) const;
	bool operator!=(const MyDate& other) const;
	bool operator<(const MyDate& other) const;
	bool operator<=(const MyDate& other) const;
	bool operator>(const MyDate& other) const;
	bool operator>=(const MyDate& other) const;

	// Alle get...()-Methoden liefern 0 bei ungueltigem Datum
	int getDay() const;
	int getMonth() const;
	int getYear() const;

private:
	// Hilfsmethode
	int getLastDayOfMonth(void) const;

	// Hilfsmethoden fuer daysSince1
	int daysSinceStartOfYear(void) const;
	int daysInPreviousYears(void) const;
};
#endif /* MYDATE_H_ */
