// File: "tests/AuthorTest.cpp", 22.3.2012 ple, Loesung: 28.3.2012

#include <cppunit/extensions/HelperMacros.h>
#include "../src/Author.h"

class AuthorTest: public CppUnit::TestCase
// Test-Suite "AuthorTest"
{
private:
	Author *author;

	CPPUNIT_TEST_SUITE(AuthorTest);
	CPPUNIT_TEST(testCtors);
	CPPUNIT_TEST_EXCEPTION(testEmptyAuthorException, InvalidAuthor);
	CPPUNIT_TEST(testOperatorEqualEqual);
	CPPUNIT_TEST_SUITE_END();
public:
	void testCtors()
   	{
		author = new Author("Samuel", "Beckett");
    	CPPUNIT_ASSERT(author->getFirstName() == "Samuel");
    	CPPUNIT_ASSERT(author->getLastName() == "Beckett");
    	delete author;
   	}
   	void testEmptyAuthorException()
   	{
   		author = new Author("", "");
   		delete author;
   	}
   	void testOperatorEqualEqual()
   	{
		Author a1 ("Max", "Frisch");
		Author a2 ("Johann", "Frisch");
		Author a3 ("Friedrich", "Glauser");
		Author a4 ("Friedrich", "Duerrenmatt");
    	CPPUNIT_ASSERT(   a1 == a1  );  // beide Namen gleich
    	CPPUNIT_ASSERT(! (a3 == a4) );  // nur Vorname gleich
    	CPPUNIT_ASSERT(! (a1 == a2) );  // nur Nachname gleich
    	CPPUNIT_ASSERT(! (a1 == a3)) ;  // beide Name ungleich
   	}

};
// Alle Tests von 'TestAuthor' in der default-registry registrieren:
CPPUNIT_TEST_SUITE_REGISTRATION(AuthorTest);
