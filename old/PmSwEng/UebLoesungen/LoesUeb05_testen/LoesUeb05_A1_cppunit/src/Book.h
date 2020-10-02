#ifndef BOOK_H_
#define BOOK_H_

// Filename: "src/Book.h", 22.3.2012 ple, Loesung 28.3.2012 ple

#include <string>
#include "author.h"

class Book
{
private:
    Author _author;
    std::string _title;
public:
    Book(std::string const &title, Author const &author);

    std::string getTitle();

    Author getAuthor();

    void setAuthor(Author const &author);

    bool operator==(Book const & x);

};
#endif // BOOK_H_
