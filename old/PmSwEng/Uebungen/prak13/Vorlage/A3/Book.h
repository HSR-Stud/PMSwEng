/**
 * @file    Book.h
 * @date    30.11.2016
 * @author  Michael Trummer
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include "Author.h"

class Book
{
private:
    Author& author;
    std::string title;
public:
    Book(std::string const &title, Author& author);
    std::string getTitle() const
    {
      return title;
    }
    const Author& getAuthor() const
    {
      return author;
    }
    bool operator==(const Book& rhs)
    {
      return author == rhs.author && title == rhs.title;
    }

};
#endif // BOOK_H_
