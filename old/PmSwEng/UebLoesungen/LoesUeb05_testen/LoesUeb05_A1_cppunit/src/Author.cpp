// Filename: "Author.cpp", 22.3.2012 ple, Loesung: 28.3.2012 ple

#include <string>

#include "MyTools.h"
#include "Author.h"

//---------------------------------------------------------------------------
Author::Author(std::string const &firstname, std::string const &lastname)
: _firstname(firstname), _lastname(lastname)
{
   myWait( 200 );
   if (firstname.empty() || lastname.empty()) throw InvalidAuthor() ;
}
//---------------------------------------------------------------------------
std::string  Author::getFirstName()
{
   myWait( 200 );
   return _firstname;
}
//---------------------------------------------------------------------------
std::string  Author::getLastName()
{
   myWait( 200 );
   return _lastname;
}
//---------------------------------------------------------------------------
bool Author::operator==(Author const & x)
{
// return _firstname == x._firstname || _lastname == x._lastname; // <== BUG!
   return _firstname == x._firstname && _lastname == x._lastname;
}
//---------------------------------------------------------------------------
