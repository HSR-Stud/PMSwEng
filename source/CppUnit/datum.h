#ifndef DATUM_H_
#define DATUM_H_
//---------------------------------------------------------------------------
// Filename: src/datum.h, 13.8.2010 ple

int anzTageSeit1900 (int tag, int monat, int jahr);
// liefert die Anzahl der Tage seit dem 1.1.1900 vom gegebenen Datum.
// oder 0, falls 'jahr' < 1900.
// "anzTageSeit1900(1, 1, 1900)" ergibt 1, "anzTageSeit1900(31, 12, 1900)"
// ergibt 365. Das uebergegebene Datum ist immer plausiblel.

//---------------------------------------------------------------------------
#endif // DATUM_H_
