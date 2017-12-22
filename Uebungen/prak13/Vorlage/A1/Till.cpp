#include "Till.h"
#include <cassert>

Till::Till()
{
}

size_t Till::rabatt(size_t rechnunsbetrag, size_t stunde, size_t minute)
{
  assert(rechnunsbetrag > 0);
  assert(stunde < 20 || (stunde == 20 && minute == 0));
  assert(stunde >= 8);
  assert(minute <= 60);

  size_t r;

  if ((stunde == 10 && minute == 0) || stunde < 10)
  {
    if (rechnunsbetrag < 150)
      r = rechnunsbetrag * 100 / 20;

    else if (rechnunsbetrag >= 150 && rechnunsbetrag <= 200)
      r = 1000;
    else
      r = rechnunsbetrag * 100 / 20;
  }
  else
  {
    if (rechnunsbetrag < 150)
      r = 0;
    else
      r = 1000;
  }
  return r;
}
