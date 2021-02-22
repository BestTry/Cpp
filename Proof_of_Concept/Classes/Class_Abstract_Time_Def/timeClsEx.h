// Class Declaration File: timeClassExpl.h 
// (Using the 'time class example name' to not confuse with C++ standard library class name)
// Declaration of class Time.
// Member functions defined in timeClassExpl.h file

#pragma once

#ifndef TIMECLSEX_H 					// Prevents multiple inclusions of header file
#define TIMECLSEX_H


class Time {							// Time abstract data type definition

public:									// Constructor and functions of abstract data type class 'Time'
	Time(int = 0, int = 0, int = 0);	// Default Constructor Works with (0-3) arguments - Initializes private data members
	void setTime(int, int, int);		// Set hour, minute, second by calling on public member function (Method)
	void printUniversal();				// Prints universal-time format of time with first instantiation
	void printStandard();				// Prints standard-time format of time with first instantiation

private:								// Class Imlementation will enforce these restrictions
	int hour;							// 0 - 23 (24-hour clock format)
	int minute;							// 0 - 59
	int second;							// 0 - 59

};										// End class Time

#endif