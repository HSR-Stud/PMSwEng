/**
 * @file    Author.h
 * @date    30.11.2016
 * @author  Michael Trummer
 */

#ifndef AUTHOR_H_
#define AUTHOR_H_
#include <string>

class Author
{
private:
    std::string firstName;
    std::string lastName;
public:
    Author(std::string const &firstname,
           std::string const &lastname);
    std::string getFirstName() const
    {
      return firstName;
    }
    std::string getLastName() const
    {
      return lastName;
    }
    bool operator==(const Author& rhs) const
    {
      return firstName == rhs.firstName && lastName == rhs.lastName;
    }
};
#endif // AUTHOR_H_
