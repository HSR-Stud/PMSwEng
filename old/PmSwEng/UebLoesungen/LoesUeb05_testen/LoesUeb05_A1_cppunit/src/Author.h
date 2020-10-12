#ifndef AUTHOR_H_
#define AUTHOR_H_

// Filename: src/Author.h, 18.3.2010, 24.3.2010 ple

#include <string>

class InvalidAuthor {};

class Author
{
private:
    std::string _firstname;
    std::string _lastname;
public:
    Author(std::string const &firstname, std::string const &lastname);

    std::string getFirstName();

    std::string getLastName();

    bool operator==(Author const & x);
};
#endif // AUTHOR_H_
