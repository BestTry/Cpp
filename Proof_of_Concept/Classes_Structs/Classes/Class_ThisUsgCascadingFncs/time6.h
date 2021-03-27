// Class Time Declaration file: 'time6.h'  ....  Cascading member function calls.
#pragma once
//
#ifndef TIME6_H
#define TIME6_H

class Time {

public:
	Time(int = 0, int = 0, int = 0);				// Default constructor initializing parameters to zero
													
													// Each function set call returns a Time object reference
													// Time 'set' functions
	Time& setTime(int, int, int);					// Set hour, minute, second
	Time& setHour(int);								// Set hour
	Time& setMinute(int);							// Set minute
	Time& setSecond(int);							// Set second

													// Time 'get' functions (normally declared const)
	int getHour() const;							// Returns hour
	int getMinute() const;							// Returns minute
	int getSecond() const;							// Returns second

													// Print functions (normally declared const)
	void printUniversal() const;					// Print universal time
	void printStandard() const;						// Print standard time

private:											// These parameters will be validated within the *.cpp file
	int hour;										// 0 - 23 (24-hour clock format)
	int minute;										// 0 - 59
	int second;										// 0 - 59

};													// End class Time

#endif

