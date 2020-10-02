#include <cppunit/extensions/HelperMacros.h>
#include "../src/Author.h"

class AuthorTest: public CppUnit::TestCase		// Test-Suite "AuthorTest"
{
private:
	Author *author;

	CPPUNIT_TEST_SUITE(AuthorTest);
		CPPUNIT_TEST_EXCEPTION(testEmptyAuthorException, InvalidAuthor);
		CPPUNIT_TEST(testCtors);
		CPPUNIT_TEST(testOperatorEqual1);
		CPPUNIT_TEST(testOperatorEqual2);
		CPPUNIT_TEST(testOperatorEqual3);
		CPPUNIT_TEST(testOperatorEqual4);
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
   	void testOperatorEqual1()
   	{
   		Author a1 ("Max", "Huber");
   		Author a2 ("Max", "Huber");
   		CPPUNIT_ASSERT ( a1 == a2 );
   	}
   	void testOperatorEqual2()
   	{
   		Author a1 ("Max", "Huber");
   		Author a2 ("Max", "Meier");
   		CPPUNIT_ASSERT ( ! (a1 == a2) );
   	}
   	void testOperatorEqual3()
   	{
   		Author a1 ("Max", "Huber");
   		Author a2 ("Fritz", "Huber");
   		CPPUNIT_ASSERT ( ! (a1 == a2) );
   	}
   	void testOperatorEqual4()
   	{
   		Author a1 ("Max", "Huber");
   		Author a2 ("Fritz", "Meier");
   		CPPUNIT_ASSERT ( ! (a1 == a2) );
   	}
};	// Alle Tests von 'TestAuthor' in der default-registry registrieren:
CPPUNIT_TEST_SUITE_REGISTRATION(AuthorTest);
