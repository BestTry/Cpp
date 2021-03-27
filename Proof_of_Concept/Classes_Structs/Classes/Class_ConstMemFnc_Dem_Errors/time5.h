// File Declaration and Header File: time5.h
// Declattion of class Time.
// Member functions defined in time5.cpp.
#pragma once
#ifndef TIME5_H
#define TIME5_H

class Time {

public:
	Time(int = 0, int = 0, int = 0);			// Default constructor - showing intialization of objecte attributes

												// Set functions - public assignments 
	void setTime(int, int, int);				// Set time function setting all three attributes of object
	void setHour(int);							// Set hour
	void setMinute(int);						// Set minute
	void setSecond(int);						// Set second

												// Get functions (normally declared const)
	int getHour() const;						// Return hour
	int getMinute() const;						// Return minute
	int getSecond() const;						// Return second

												// Print functions (normally declared const)
	void printUniversal() const;				// Print universal time - Designated as constant object and member function 
	void printStandard();						// Print standard time

private:
	int hour;									// 0 - 23 (24-hour clock format)
	int minute;									// 0 - 59
	int second;									// 0 - 59

};												// End class Time

#endif