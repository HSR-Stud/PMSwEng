//===========================================================================
// Modul PmSwe, Uebung 1, Aufgaben 1-3: Klasse "MyDate" mit Tests
// File "testMyDate.cpp", 4.6.2012, H. Pletscher
//===========================================================================

#include <iostream>
#include <string>
#include <assert.h>

#include "MyDate.h"

using namespace std;
//===========================================================================
bool equalDates (const MyDate & date, int day, int month, int year)
// Hilfsfunktion, nur zum Testen. Lliefert true falls beide Daten gleich
// (sonst false). bool _isValid wird nicht beruecksichtigt.
{
	if ( date.getDay()   != day   ) return false;
	if ( date.getMonth() != month ) return false;
	if ( date.getYear()  != year  ) return false;
	return true;
}
//===========================================================================
void testDefaultCtor()
{
	cout << "--- Test of Default-Constructor: MyDate d;       :" << flush;
	MyDate d1;
	assert (d1.getDay() == 0);
	assert (d1.getMonth() == 0);
	assert (d1.getYear() == 0);
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testCtorWithValues()
{
	cout << "--- Test of Constructor: MyDate d1 (25, 2, 2010);:" << flush;
	MyDate d1 (25, 2, 2010);
	assert (d1.getDay() == 25);
	assert (d1.getMonth() == 2);
	assert (d1.getYear() == 2010);
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testCopyCtor()
{
	cout << "--- Test of Copy-Constructor: MyDate d2 = d1;    :" << flush;
	MyDate d1 (25, 2, 2010);
	MyDate d2 = d1;
	assert ( d2.getDay()   == d1.getDay() );
	assert ( d2.getMonth() == d1.getMonth() );
	assert ( d2.getYear()  == d1.getYear() );
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testAssignment()
{
	cout << "--- Test of Assignment, op=(): d3 = d2 = d1;     :" << flush;
	MyDate d1 (25, 2, 2010);
	MyDate d2; MyDate d3;
	d3 = d2 = d1;
	assert ( d2.getDay()   == d1.getDay() );
	assert ( d2.getMonth() == d1.getMonth() );
	assert ( d2.getYear()  == d1.getYear() );
	assert ( d3.getDay()   == d2.getDay() );
	assert ( d3.getMonth() == d2.getMonth() );
	assert ( d3.getYear()  == d2.getYear() );
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testIsValid()
{
	cout << "--- Test of isValid()                            :" << flush;
	{   // valid dates:
		MyDate date1(25, 2, 2010);  assert ( date1.isValid() );
		MyDate date2(1, 1, 2000);   assert ( date2.isValid() );
		MyDate date3(31, 1, 2000);  assert ( date3.isValid() );
		MyDate date4(31, 3, 2000);  assert ( date4.isValid() );
		MyDate date5(30, 4, 2000);  assert ( date5.isValid() );
		MyDate date6(29, 2, 2000);  assert ( date6.isValid() );
		MyDate date7(28, 2, 2001);  assert ( date7.isValid() );
		MyDate date8(29, 2, 2004);  assert ( date8.isValid() );
	}
	{ 	// invalid dates:
		MyDate date1(0, 0, 0);      assert ( !date1.isValid() );
		MyDate date2(0, 5, 2000);   assert ( !date2.isValid() );
		MyDate date3(15, 0, 2000);  assert ( !date3.isValid() );
		MyDate date4(15, 12, -1);   assert ( !date4.isValid() );
		MyDate date5(31, 4, 2000);  assert ( !date5.isValid() );
		MyDate date6(29, 2, 2100);  assert ( !date6.isValid() );
		MyDate date7(32,12, 2000);  assert ( !date7.isValid() );
	}
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testIsLeapYear()
{
	cout << "--- Test of isLeapYear()                         :" << flush;
	MyDate d1 (25, 2, 2010);   assert ( d1.isLeapYear() == 0);
	MyDate d2 (25, 2, 2008);   assert ( d2.isLeapYear() != 0);
	MyDate d3 (26, 2, 1600);   assert ( d3.isLeapYear() != 0);
	MyDate d4 (26, 2, 1700);   assert ( d4.isLeapYear() == 0);
	MyDate d5 (26, 2, 1701);   assert ( d5.isLeapYear() == 0);
	MyDate d6 (26, 2, 1702);   assert ( d6.isLeapYear() == 0);
	MyDate d7 (26, 2, 1703);   assert ( d7.isLeapYear() == 0);
	MyDate d8 (26, 2, 1704);   assert ( d8.isLeapYear() != 0);
	cout << " -- OK" << endl;
}
//---------------------------------------------------------------------------
void testAddDays()
{
	cout << "--- Test of addDays()                            :" << flush;
	MyDate d1 (28, 2, 2010);
	MyDate d2, d3;
	d2 = d1.addDays(1);
	assert ( equalDates( d2,  1,3,2010) );

	d3 = d2.addDays(-1);
	assert ( equalDates( d3,  28,2,2010) );


	MyDate date1(1, 1, 1999);
	assert( equalDates( date1.addDays(1), 2, 1, 1999 ) );
	assert( equalDates( date1, 1, 1, 1999 ) );

	assert( equalDates( date1.addDays(0), 1, 1, 1999) );
	assert( equalDates( date1.addDays(30), 31, 1, 1999) );
	assert( equalDates( date1.addDays(31), 1, 2, 1999) );
	assert( equalDates( date1.addDays(31+28), 1, 3, 1999) );

	MyDate date2(31, 12, 1999);
	assert( equalDates( date2.addDays(1), 1, 1, 2000) );

	MyDate date3(28, 2, 2000);
	assert( equalDates( date3.addDays(2), 1, 3, 2000) );

	cout << " -- OK" << endl;

}
//===========================================================================
int main(int argc, char **argv)
{
	testDefaultCtor();
	testCtorWithValues();
	testCopyCtor();
	testAssignment();

	testIsValid();
	testIsLeapYear();

}
//===========================================================================
