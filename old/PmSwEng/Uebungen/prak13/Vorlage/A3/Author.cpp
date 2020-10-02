/**
 * @file    Author.cpp
 * @date    30.11.2016
 * @author  Michael Trummer
 */

#include <string>
#include <stdexcept>

#include "Author.h"

//---------------------------------------------------------------------------
Author::Author(std::string const &firstname, std::string const &lastname)
: firstName(firstname), lastName(lastname)
{
   if (firstname.empty() || lastname.empty())
     throw std::runtime_error("Invalid Author");
}
