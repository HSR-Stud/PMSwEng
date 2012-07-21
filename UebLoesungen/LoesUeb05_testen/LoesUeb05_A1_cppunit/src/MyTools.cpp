// File: "MyTools.cpp", 22.3.2012 ple

#include <ctime>


void myWait ( int millisecs )
{
   clock_t endwait;

   endwait = clock () + (int)( ( (double)millisecs ) * CLOCKS_PER_SEC / 1000);
   while (clock() < endwait)
   {
      /* do nothing, wait */
   }
}

