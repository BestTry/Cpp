// Declaration File: time4.h
// Declaration of class Time.
// Member functions defined in time4.cpp

#pragma once

#ifndef TIME4_H										// Prevent multiple inclusions of header file
#define TIME4_H 

class Time {

public:
	Time(int = 0, int = 0, int = 0);
	void setTime(int, int, int);
	int getHour();

	int& badSetHour(int);							// DANGEROUS reference return - This member function will 
													// retreive private data without protecting invalid hours
private:
	int hour;
	int minute;
	int second;

};													// End class Time

#endif