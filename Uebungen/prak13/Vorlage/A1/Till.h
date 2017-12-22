#ifndef TILL_H
#define TILL_H

#include <cstdlib>

class Till {
 public:
  Till();
  static size_t rabatt(size_t rechnunsbetrag, size_t stunde, size_t minute);
};

#endif  // TILL_H
