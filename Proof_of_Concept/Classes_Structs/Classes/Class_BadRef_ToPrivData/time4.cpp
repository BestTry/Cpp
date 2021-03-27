// Class Definition File: time4.cpp
// Member-function definitions for Time class.

#include "time4.h"									// Include definition of class Time from time4.h

													// Constructor function to initialize private data; 																								
Time::Time(int hr, int min, int sec)				// Calls member function setTime to set variables;		
{													// Default values are 0 (see class declaration file)
	setTime(hr, min, sec);

}													// End Time constructor

void Time::setTime(int h, int m, int s)				// Sets values of hour, minute and second
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;

}													// End function setTime


int Time::getHour()									// Return hour value
{
	return hour;

}													// End function getHour

													// POOR PROGRAMMING PRACTICE:
int& Time::badSetHour(int hh)						// Returning a reference to a private data member.
{
	hour = (hh >= 0 && hh < 24) ? hh : 0;

	return hour;									// DANGEROUS reference return

}													// End function badSetHour

