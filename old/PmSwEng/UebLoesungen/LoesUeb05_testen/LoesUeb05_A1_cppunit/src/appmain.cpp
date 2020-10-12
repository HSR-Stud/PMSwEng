// Filename: "src/appmain.cpp", 22.3.2012 ple

#include <iostream>

#include "Author.h"
#include "Book.h"

using namespace std;

int main()
{

	Author *author1, *author2;
	Book *book1, *book2;

	author1 = new Author("Samuel", "Beckett");
	author2 = new Author("Graham", "Greene");
	book1 = new Book("Endspiel", *author1);
	book2 = new Book("Our Man in Havana", *author2);

	cout << "Application Program:" << endl;
	cout << "  Book 1: " << flush;
 	cout << book1->getAuthor().getFirstName() << "  "
		 << book1->getAuthor().getLastName() << ": "
		 << book1->getTitle() << endl;
	cout << "  Book 2: " << flush;
	cout << book2->getAuthor().getFirstName() << "  "
		 << book2->getAuthor().getLastName() << ": "
		 << book2->getTitle() << endl;

	delete author1; delete author2;
	delete book1; delete book2;
	return 0;
}
