/**
 * @file    main.cpp
 * @date    30.11.2016
 * @author  Michael Trummer
 */

#include <iostream>
#include <cassert>
#include <stdexcept>

#include "Author.h"
#include "Book.h"

using namespace std;

void bookTestCtors()
{
  Author myAuthor("Samuel", "Beckett");
  Book mybook("Endspiel", myAuthor);
  assert(mybook.getTitle() == "Endspiel");
  assert(mybook.getAuthor() == myAuthor);
  std::cout << "BookTest Ctors successful" << std::endl;
}

void bookTestEqual()
{
  Author myAuthor("Samuel", "Beckett");
  Book mybook1("Endspiel", myAuthor);
  Book mybook2("Endspiel", myAuthor);
  assert(mybook1 == mybook2);
  std::cout << "BookTest Equality successful" << std::endl;
}

void bookTestNameNotEqual()
{
  Author myAuthor("Samuel", "Beckett");
  Book mybook1("Spiel", myAuthor);
  Book mybook2("Endspiel", myAuthor);
  assert(!(mybook1 == mybook2)); //to test operator==
  std::cout << "BookTest Equality successful" << std::endl;
}

void bookTestAuthorNotEqual()
{
  Author myAuthor1("Samuel", "Beckett");
  Author myAuthor2("Samuel", "Muster");
  Book mybook1("Endspiel", myAuthor1);
  Book mybook2("Endspiel", myAuthor2);
  assert(!(mybook1 == mybook2)); //to test operator==
  std::cout << "BookTest Equality successful" << std::endl;
}

void authorTestCtors()
{
  Author* author = new Author("Samuel", "Beckett");
  assert(author->getFirstName() == "Samuel");
  assert(author->getLastName() == "Beckett");
  assert(author == author);
  std::cout << "AuthorTest Ctors successful" << std::endl;
  delete author;
}

void authorTestEmptyAuthorException()
{
  try
  {
    Author* author = new Author("", "");
    delete author;
    assert(0); //this line should not be reached
  }
  catch(std::runtime_error& e)
  {
    std::cout << "AuthorTest Empty Author successful" << std::endl;
  }
}

int main( int argc, char* argv[] )
{
  bookTestCtors();
  bookTestEqual();
  bookTestNameNotEqual();
  bookTestAuthorNotEqual();

  authorTestCtors();
  authorTestEmptyAuthorException();

  std::cout << "ALL TESTS SUCCESSFUL" << std::endl;
  return 0;
}
