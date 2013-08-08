// File: "tests/BookTest.cpp", 22.3.2012 ple,  Loesung 28.3.2012 ple

#include <cppunit/extensions/HelperMacros.h>

#include "../src/Author.h"
#include "../src/Book.h"

class BookTest: public CppUnit::TestCase
// Testsuite "BookTest"
{
private:
	Author *author1, *author2;
	Book *book;

	CPPUNIT_TEST_SUITE(BookTest);
		CPPUNIT_TEST(testCtors);
		CPPUNIT_TEST(testSetAuthor);
		CPPUNIT_TEST(testOperatorEqualEqual);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp() {
		author1 = new Author("Samuel", "Beckett");
		author2 = new Author("Graham", "Greene");
		book = new Book("Endspiel", *author1);
	}
    void tearDown() {
		delete book;
		delete author1;
		delete author2;
   	}
    void testCtors() {
        Author myauthor("Samuel", "Beckett");
        Book mybook("Endspiel", myauthor);
        CPPUNIT_ASSERT(mybook.getTitle() == "Endspiel");
        CPPUNIT_ASSERT(mybook.getAuthor().getFirstName() == "Samuel");
        CPPUNIT_ASSERT(mybook.getAuthor().getLastName() == "Beckett");
    }
	void testSetAuthor() {
        book->setAuthor(*author2);
        CPPUNIT_ASSERT(book->getTitle() == "Endspiel");
        CPPUNIT_ASSERT(book->getAuthor().getFirstName() == "Graham");
        CPPUNIT_ASSERT(book->getAuthor().getLastName() == "Greene");
        book->setAuthor(*author1);
	}
	void testOperatorEqualEqual()
	{
		Author a1 ("Max", "Frisch");
		Author a2 ("Kurt", "Marti");
		Book b1 ("Tagebuch", a1);
		Book b2 ("Tagebuch", a2);
		Book b3 ("Stiller", a1);
		Book b4 ("Rosa Lui", a2);
		CPPUNIT_ASSERT(   b1 == b1  );  // Author und Titel gleich
		CPPUNIT_ASSERT(! (b1 == b3) );  // nur Author gleich
		CPPUNIT_ASSERT(! (b1 == b2) );  // nur Titel gleich
		CPPUNIT_ASSERT(! (b1 == b4)) ;  // Author und Titel ungleich
	}

};
// Alle Tests der Klasse 'BookTest' in der Default-Registry registrieren:
CPPUNIT_TEST_SUITE_REGISTRATION(BookTest);
