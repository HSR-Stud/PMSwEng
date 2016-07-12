// File: test/testdatum.cpp, 13.8.2010 ple
// ACHTUNG: unvollstaendig, enthaelt nicht alle sinnvollen Tests
//---------------------------------------------------------------------------
#include <cppunit/extensions/HelperMacros.h>

#include "../src/datum.h"
// enthaelt die Deklaration
//     int anzTageSeit1900(int tag, int monat, int jahr);


//---------------------------------------------------------------------------
class TestDatum: public CppUnit::TestCase
{
private:
	CPPUNIT_TEST_SUITE(TestDatum);
		CPPUNIT_TEST(testAnzTageSince1900);
	CPPUNIT_TEST_SUITE_END();
public:
    void testAnzTageSince1900()
    {
        CPPUNIT_ASSERT( anzTageSeit1900(31, 12, 1899) == 0 );
        CPPUNIT_ASSERT( anzTageSeit1900(30, 12, 1899) == 0 );

        CPPUNIT_ASSERT( anzTageSeit1900( 1,  1, 1900) == 1 );
        CPPUNIT_ASSERT( anzTageSeit1900(31, 12, 1900) == 365 );

        CPPUNIT_ASSERT( anzTageSeit1900( 1,  1, 1901) == 1+365 );
        CPPUNIT_ASSERT( anzTageSeit1900(31, 12, 1901) == 365+365 );

		// ... weitere Tests

    }
};
//---------------------------------------------------------------------------
// Alle Tests von 'TestDatum' in der default-registry registrieren:
CPPUNIT_TEST_SUITE_REGISTRATION(TestDatum);
//---------------------------------------------------------------------------
