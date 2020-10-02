/**
 * Klasse 'Stopwatch' welche eine Stoppuhr realisiert.
 * Gleichzeitig Demo-Beispiel fuer Doxygen.
 * @file StopWatch.cpp
 * @author H. Pletscher
 * @date  5.4.201
 * @version 1.0
 */

//============================================================================
#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "StopWatch.h"

//---------------------------------------------------------------------------
static unsigned long myClock()
// returns the time in millisec about the first call to this
// function. The precision of this start-time-point is only 1 sec.
{
	static unsigned long tpZero= 0;

	struct timeval now;
	gettimeofday( &now, 0);

	if (tpZero == 0) tpZero = now.tv_sec;

	unsigned long tp = (now.tv_sec - tpZero) * 1000;
	tp += now.tv_usec / 1000;
	return tp;
}
//---------------------------------------------------------------------------
StopWatch::StopWatch()
{
	_tpStart = 0;
	_tmElapsed = 0;
	_running = false;
}
//---------------------------------------------------------------------------
void StopWatch::start()
{
	if (! _running)
	{
		_tpStart = myClock() - _tmElapsed;
	}
	_running = true;
}
//---------------------------------------------------------------------------
void StopWatch::stop()
{
	_running = false;
	_tmElapsed = myClock() - _tpStart;

}
//---------------------------------------------------------------------------
void StopWatch::reset()
{
	_tpStart = 0;
	_tmElapsed = 0;
	_running = false;

}
//---------------------------------------------------------------------------
bool StopWatch::isRunning() const
{
	return _running;
}
//---------------------------------------------------------------------------
unsigned long StopWatch::getValue() const
{
	if (_running) return myClock() - _tpStart;
	else return _tmElapsed;
}
//---------------------------------------------------------------------------
void StopWatch::asCString(char result[]) const
{
	unsigned long x = getValue();
	int millisec = x % 1000;
	x = x /1000;
	int sec = x % 60;
	x = x / 60;
	int min = x % 60;
	x = x / 60;
	int std = x % 24;
	sprintf (result, "%2d:%2d:%2d:%3d", std, min, sec, millisec);
}
//---------------------------------------------------------------------------
std::string StopWatch::toString() const
{
	unsigned long x = getValue();
	int millisec = x % 1000;
	x = x /1000;
	int sec = x % 60;
	x = x / 60;
	int min = x % 60;
	x = x / 60;
	int std = x % 24;
    std::ostringstream ss;
    ss << std::setw(2) << std::setfill('0') << std << ":"
       << std::setw(2) << min << ":"
       << std::setw(2) << sec << ":"
       << std::setw(3) << millisec;
    std::string result = ss.str();
    return result;
}
//---------------------------------------------------------------------------
