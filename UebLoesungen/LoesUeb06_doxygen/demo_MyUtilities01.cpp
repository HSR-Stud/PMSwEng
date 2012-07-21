/**
 * Demoprogramm fuer die Klassen 'Stopwatch' und 'Keyboard.
 * Gleichzeitig Demo-Beispiel fuer Doxygen.
 * @file demo_MyUtilities01.cpp
 * @author H. Pletscher
 * @date  7.4.201
 * @version 1.0
 */
//============================================================================

#include <iostream>
using namespace std;


#include "Keyboard.h"
#include "StopWatch.h"

int main()
{
	Keyboard keyboard;
	cout << "Hello World, here is my Stopwatch: " << endl;

	StopWatch stopwatch;

	stopwatch.start();
	bool quit = false;
	while (! quit)
	{
		cout << "\r" << "time = " << stopwatch.toString()
		     << "     type 's' to start/stop, 'r' to reset and 'q' to quit"
		     << flush;

		if ( keyboard.keypressed() )
		{
			int ch = keyboard.getch();
			switch (ch)
			{
				case 's': case 'S':
				{	if (stopwatch.isRunning() ) stopwatch.stop();
					else stopwatch.start();
					break;
				}
				case 'r': case 'R':
				{	stopwatch.reset();
					break;
				}
				case 'q': case 'Q':
					quit = true;
				default:
					break;
			}
		}
	}
	cout << endl << "bye ... " << endl; ;
	return 0;
}
