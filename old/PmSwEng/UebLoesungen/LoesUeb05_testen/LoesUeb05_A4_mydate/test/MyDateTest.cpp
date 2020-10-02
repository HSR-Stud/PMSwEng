#include <string>
#include <iostream>

#include <cppunit/extensions/HelperMacros.h>

#include "../src/MyDate.h"

using namespace std;
//===========================================================================
// local Helper-Method for outputting a MyDate object
// needed if CPPUNIT_ASSERT_EQUAL() fails
static ostream& operator<<(ostream& out, const MyDate& date)
{
	out << '{' << date.getDay()
    	<< '.' << date.getMonth()
    	<< '.' << date.getYear() << '}';
	return out;
}
//===========================================================================
class MyDateTest: public CppUnit::TestFixture {

	CPPUNIT_TEST_SUITE(MyDateTest);
	    CPPUNIT_TEST(testDefaultCtor);
	    CPPUNIT_TEST(testCtorWithValues);
	    CPPUNIT_TEST(testCopyCtor);
	    CPPUNIT_TEST(testEquals);
	    CPPUNIT_TEST(testNotEquals);
	    CPPUNIT_TEST(testIsValid);
	    CPPUNIT_TEST(testLeapYear);
	    CPPUNIT_TEST(testAssignement);
	    CPPUNIT_TEST(testAddDays);
	    CPPUNIT_TEST(testDaysTil);
	    CPPUNIT_TEST(testDaysSince1);
	    CPPUNIT_TEST(testDateFromDays);
	CPPUNIT_TEST_SUITE_END();

	// Helper-Method
	static bool isSameDate(const MyDate& date, int day, int month, int year)
	{
		return date.getDay() == day &&
			   date.getMonth() == month &&
			   date.getYear() == year;
	}

	// Helper-Method
	// used for getting reference values for succeeding test
	void checkDaysTil(int day, int month, int year)
	{
		static MyDate startDate(1,1,1);
		MyDate tilDate(day, month, year);
		int days = startDate.daysTil(tilDate);
		cout << day << '.' << month << '.' << year << " --> " << days << " days" << endl;
		CPPUNIT_ASSERT_EQUAL( tilDate.daysSince1(), days);

	}

public:
	void testDefaultCtor()
	{
		MyDate date;
		CPPUNIT_ASSERT( !date.isValid() );
	}

	void testCtorWithValues()
	{
		MyDate date1(32, 0, 2010);
		CPPUNIT_ASSERT( !date1.isValid() );

		MyDate date2(25, 2, 2010);
		CPPUNIT_ASSERT( isSameDate(date2, 25, 2, 2010) );
	}

	void testCopyCtor()
	{
		MyDate date1(15, 10, 1961);
		MyDate date2 = date1;
		CPPUNIT_ASSERT( isSameDate(date2, 15, 10, 1961) );
		CPPUNIT_ASSERT( date2.isValid() );

		MyDate date3;
		MyDate date4 = date3;
		CPPUNIT_ASSERT( !date4.isValid() );
	}

	void testEquals()
	{
		MyDate date1(15, 10, 1986);
		CPPUNIT_ASSERT_EQUAL( date1, date1 );
		CPPUNIT_ASSERT_EQUAL( date1, MyDate(15, 10, 1986) );

		CPPUNIT_ASSERT( !(date1 == MyDate(16, 10, 1986)) );
		CPPUNIT_ASSERT( !(date1 == MyDate(15, 11, 1986)) );
		CPPUNIT_ASSERT( !(date1 == MyDate(15, 10, 1987)) );

		// ungueltige Daten
		MyDate date2;
		CPPUNIT_ASSERT( !(date2 == date1) );
		CPPUNIT_ASSERT( !(date1 == date2) );

		// fragliche Tests mit ungueltigen Daten
		CPPUNIT_ASSERT_EQUAL( date2, date2 ); // ???
		CPPUNIT_ASSERT_EQUAL( MyDate(), MyDate() ); // ???
		CPPUNIT_ASSERT_EQUAL( date2, MyDate(15, 0, 1900) ); // ???
	}

	void testNotEquals()
	{
		MyDate date1(15, 10, 1986);
		CPPUNIT_ASSERT( (date1 != date1) == false );
		CPPUNIT_ASSERT( date1 != MyDate(16, 10, 1986) );

		// ungueltige Daten
		MyDate date2;
		CPPUNIT_ASSERT( date2 != date1 );
		CPPUNIT_ASSERT( date1 != date2 );

		// fragliche Tests mit ungueltigen Daten
		CPPUNIT_ASSERT( !(date2 != date2) ); // ???
		CPPUNIT_ASSERT( !(MyDate() != MyDate()) ); // ???
		CPPUNIT_ASSERT( date2 == MyDate(15, 0, 1900) ); // ???
	}

	void testIsValid()
	{
		{ // valid dates
			MyDate date1(25, 2, 2010);
			CPPUNIT_ASSERT( date1.isValid() );

			MyDate date2(1, 1, 2000);
			CPPUNIT_ASSERT( date2.isValid() );

			MyDate date3(31, 1, 2000);
			CPPUNIT_ASSERT( date3.isValid() );

			MyDate date4(31, 3, 2000);
			CPPUNIT_ASSERT( date4.isValid() );

			MyDate date5(30, 4, 2000);
			CPPUNIT_ASSERT( date5.isValid() );

			MyDate date6(29, 2, 2000);
			CPPUNIT_ASSERT( date6.isValid() );

			MyDate date7(28, 2, 2001);
			CPPUNIT_ASSERT( date7.isValid() );

			MyDate date8(29, 2, 2004);
			CPPUNIT_ASSERT( date8.isValid() );
		}

		{ // invalid dates
			MyDate date1(0, 0, 0);
			CPPUNIT_ASSERT( !date1.isValid() );

			MyDate date2(0, 5, 2000);
			CPPUNIT_ASSERT( !date2.isValid() );

			MyDate date3(15, 0, 2000);
			CPPUNIT_ASSERT( !date3.isValid() );

			MyDate date4(15, 12, -1);
			CPPUNIT_ASSERT( !date4.isValid() );

			MyDate date5(31, 4, 2000);
			CPPUNIT_ASSERT( !date5.isValid() );

			MyDate date6(29, 2, 2100);
			CPPUNIT_ASSERT( !date5.isValid() );

			MyDate date7(31, 12, 2000);
			CPPUNIT_ASSERT( date7.isValid() );
		}
	}

	void testLeapYear()
	{
		MyDate date1(25, 2, 2010);
		CPPUNIT_ASSERT( !date1.isLeapYear() );

		MyDate date2(15, 1, 2008);
		CPPUNIT_ASSERT( date2.isLeapYear() );

		MyDate date3(29, 2, 2000);
		CPPUNIT_ASSERT( date3.isValid() );
		CPPUNIT_ASSERT( date3.isLeapYear() );

		MyDate date4(29, 2, 2100);
		CPPUNIT_ASSERT( !date4.isValid() );

		MyDate date5(28, 2, 2400);
		CPPUNIT_ASSERT( date5.isLeapYear() );

		MyDate date6(31, 11, 2000);
		CPPUNIT_ASSERT( !date6.isValid() );
	}

	void testAssignement()
	{
		MyDate date1(1, 1, 2000), date2;
		date2 = date1;
		CPPUNIT_ASSERT( isSameDate(date2, 1, 1, 2000) );

		MyDate date3;
		date2 = date3;
		CPPUNIT_ASSERT( !date2.isValid() );
	}

	void testAddDays()
	{
		MyDate date1(1, 1, 1999);
		CPPUNIT_ASSERT( isSameDate(date1.addDays(0), 1, 1, 1999) );
		CPPUNIT_ASSERT( isSameDate(date1.addDays(1), 2, 1, 1999) );
		CPPUNIT_ASSERT( isSameDate(date1, 1, 1, 1999) );
		CPPUNIT_ASSERT( isSameDate(date1.addDays(-1), 31, 12, 1998) );

		CPPUNIT_ASSERT( isSameDate(date1.addDays(30), 31, 1, 1999) );
		CPPUNIT_ASSERT( isSameDate(date1.addDays(31), 1, 2, 1999) );
		CPPUNIT_ASSERT( isSameDate(date1.addDays(-31), 1, 12, 1998) );
		CPPUNIT_ASSERT( isSameDate(date1.addDays(31 + 28), 1, 3, 1999) );

		MyDate date2(31, 12, 1999);
		CPPUNIT_ASSERT( isSameDate(date2.addDays(1), 1, 1, 2000) );

		MyDate date3(1, 3, 2008);
		CPPUNIT_ASSERT( isSameDate(date3.addDays(-1), 29, 2, 2008) );
		CPPUNIT_ASSERT( isSameDate(date3.addDays(-366), 1, 3, 2007) );
		CPPUNIT_ASSERT( isSameDate(date3.addDays(-367), 28, 2, 2007) );

		MyDate date4(28, 2, 2000);
		CPPUNIT_ASSERT( isSameDate(date4.addDays(2), 1, 3, 2000) );
	}

	void testDaysTil()
	{

		MyDate date1(5, 1, 2010);
		CPPUNIT_ASSERT_EQUAL( date1.daysTil(date1), 0 );
		CPPUNIT_ASSERT_EQUAL( date1.daysTil(MyDate(6, 1, 2010)), 1 );
		CPPUNIT_ASSERT_EQUAL( date1.daysTil(MyDate(4, 1, 2010)), -1 );
		CPPUNIT_ASSERT_EQUAL( date1.daysTil(MyDate(15, 1, 2010)), 10 );
		CPPUNIT_ASSERT_EQUAL( date1.daysTil(MyDate(30, 12, 2009)), -6 );

		// CPPUNIT_ASSERT_EQUAL( date1.daysTil(Date()), ??? ); /// ???
	}

	void testDaysSince1()
	{
		CPPUNIT_ASSERT_EQUAL( MyDate(1,1,1).daysSince1(), 1);
		CPPUNIT_ASSERT_EQUAL( MyDate(2,1,1).daysSince1(), 2 );
		CPPUNIT_ASSERT_EQUAL( MyDate(1,2,1).daysSince1(), 31+1 );
		CPPUNIT_ASSERT_EQUAL( MyDate(3,3,1).daysSince1(), 31+28+2+1 );

		CPPUNIT_ASSERT_EQUAL( MyDate(1,1,2).daysSince1(), 365+1 );

	//	checkDaysTil(1, 1, 3);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 3).daysSince1(), 730+1 );
	//	checkDaysTil(1, 1, 4);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 4).daysSince1(), 1095+1 );
	//	checkDaysTil(1, 3, 4);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 3, 4).daysSince1(), 1155+1 );
	//	checkDaysTil(1, 1, 5);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 5).daysSince1(), 1461+1 );
	//	checkDaysTil(1, 1, 101);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 101).daysSince1(), 36524+1 );
	//	checkDaysTil(1, 1, 202);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 202).daysSince1(), 73413+1 );
	//	checkDaysTil(1, 1, 2001);
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 2001).daysSince1(), 730485+1 );
	//	checkDaysTil(19, 3, 2011);
		CPPUNIT_ASSERT_EQUAL( MyDate(19, 3, 2011).daysSince1(), 734214+1 );
	}

	void testDateFromDays()
	{
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 1), MyDate::dateFromDays(1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(2, 1, 1), MyDate::dateFromDays(2) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 2, 1), MyDate::dateFromDays(31+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(3, 3, 1), MyDate::dateFromDays(31+28+3) );

		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 2), MyDate::dateFromDays(365+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 3), MyDate::dateFromDays(730+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 4), MyDate::dateFromDays(1095+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 3, 4), MyDate::dateFromDays(1155+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 5), MyDate::dateFromDays(1461+1) );

		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 101), MyDate::dateFromDays(36524+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 202), MyDate::dateFromDays(73413+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(1, 1, 2001), MyDate::dateFromDays(730485+1) );
		CPPUNIT_ASSERT_EQUAL( MyDate(19, 3, 2011), MyDate::dateFromDays(734214+1) );

		CPPUNIT_ASSERT_EQUAL( MyDate(31,12, 203), MyDate::dateFromDays( 74143 ) );
		CPPUNIT_ASSERT_EQUAL( MyDate( 1, 1, 204), MyDate::dateFromDays( 74144 ) );
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(MyDateTest);
