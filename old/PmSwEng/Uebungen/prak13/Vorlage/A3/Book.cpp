/**
 * @file    Book.cpp
 * @date    30.11.2016
 * @author  Michael Trummer
 */

#include <string>

#include "Author.h"
#include "Book.h"
//---------------------------------------------------------------------------
Book::Book(std::string const &title, Author& author)
: author(author), title(title)
{

}

