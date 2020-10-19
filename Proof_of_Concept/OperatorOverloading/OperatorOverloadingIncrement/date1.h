// Declaration / Header / Prototypecode for the date class // Fig. 8.10: date1.h
#pragma once

#ifndef DATE1_H
#define DATE1_H
#include <iostream>

using std::ostream;

class Date {
	friend ostream& operator<<(ostream&, const Date&);

public:
	Date(int m = 1, int d = 1, int y = 1900);			// Default constructor initializes date: 1/1/1900
	void setDate(int, int, int);						// Set the date function

	Date& operator++();									// preincrement operator - Returns a reference
	Date operator++(int);								// postincrement operator - Returns a value

	const Date& operator+=(int);						// Add days, modifies object attributes

	bool leapYear(int) const;							// Check if this is a leap year?
	bool endOfMonth(int) const;							// Check if this day is at end of month?

	
private:
	int month;
	int day;
	int year;
	
	static const int days[];									// Within the definition file an array will specify days per month
	void helpIncrement();								// Utility function to process the overload operator 'operator++'

};														// End of class Date

#endif