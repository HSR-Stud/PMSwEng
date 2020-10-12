// Filename: "Book.cpp", 22.3.2012 ple, Luesung 28.3.2012 ple

#include <string>
#include "MyTools.h"

#include "Author.h"
#include "Book.h"
//---------------------------------------------------------------------------
Book::Book(std::string const &title, Author const &author)
: _author(author), _title(title)
{
   myWait( 200 );
}
//---------------------------------------------------------------------------
std::string Book::getTitle()
{
   myWait( 200 );
   return _title;
}
//---------------------------------------------------------------------------
Author Book::getAuthor()
{
   myWait( 200 );
   return _author;
}
//---------------------------------------------------------------------------
void Book::setAuthor(Author const &author)
{
   myWait( 200 );
   _author = author;
}
//---------------------------------------------------------------------------
bool Book::operator==(Book const & x)
{
   return _author == x._author && _title == x._title;
}
//---------------------------------------------------------------------------

