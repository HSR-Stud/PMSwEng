/**
 * @class StopWatch
 * @brief Realisiert eine Stoppuhr.
 *
 * Gleichzeitig Demo-Beispiel fuer Doxygen.
 * @file StopWatch.h
 * @author H. Pletscher
 * @date  5.4.201
 * @version 1.0
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <string>

class StopWatch
{
private:
	unsigned long _tpStart;
	unsigned long _tmElapsed;
	bool _running;

public:
	/**
	* Constructor: creates a new stopwatch-object with initial Value 0.
	*
	* @param timeSecs Number of seconds
	*        passed since Jan 1, 1970.
	*/
	StopWatch();

	/**
	* Start (or continue) the stopwatch.
	* Does nothing if the stopwatch is already running.
	*
	*/
	void start();

	/**
	* Stops the stopwatch.
	*
	*/
	void stop();

	/**
	 * Reset the stopwatch to time value 0.
	 */
	void reset();

	/**
	 * @return if the stopwatch is running or not.
	 */
	bool isRunning() const;

	/**
	 * @return the current stopwatch-time in millisecs.
	 */
	unsigned long getValue() const;

	/**
	 * builds the current stopwatch-time as a c-String (char-array)
	 * and put it into 'result'.
	 * Precondition: Size of 'result' >= 13 char's.
	 * The Format is: 'hh:mm:ss:mmm' (hours, minutes seconds, millisecs).
	 */
	void asCString(char result[]) const;

	/**
	 * @return the current stopwatch-time as a std::string.
	 * The Format is: 'hh:mm:ss:mmm' (hours, minutes seconds, millisecs).
	 */
	std::string toString() const;
};
#endif /* STOPWATCH_H_ */
