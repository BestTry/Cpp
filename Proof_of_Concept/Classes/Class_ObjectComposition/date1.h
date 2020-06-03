// Class Declaration Header File: date1.h 
// Date class declaration.
// Member functions defined in date1.cpp

#pragma once
#ifndef DATE1_H
#define DATE1_H

class Date {

public:
	Date(int = 1, int = 1, int = 1900);			// Default constructor with initialization parameters
	void print() const;							// Public print function: print date in month/day/year format
	~Date();									// Provided to confirm destruction order

private:
	int month;									// 1-12 (January-December)
	int day;									// 1-31 based on month
	int year;									// Any year
	
	int checkDay(int) const;					// Utility functions to test for proper day month and year
	int checkMonth(int) const;
	int checkYear(int) const;
};												// End class Date

#endif
