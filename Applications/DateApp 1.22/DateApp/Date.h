#pragma once
// Declaration Header File - Declares the class, prototype for the constructor, class fields, class member functions
// Convention/practice keep class fields in the ' *.h ' file
// Function Members are defined here
//
//
// Note the ' ;  ' at the end of the class --- Class is declared here in the ' *.h ' file
// Note the ' ;  ' at the end of the member declaration --- Member functions are declared here in the ' *.h ' file
// Here the Constructor is declared for the 'Date' class.  It does not include the impementation code for it
// The impementation/deinition code and functions/methods for the Date class  resides in the "date.cpp" file
	

/*                     ***** Date Class Methods  &  Local Static Methods *****
	   -------------------------------------------------------------------------------------------
	   * printDate(dateObj)         * dateObj.daysBetween(dateObj)  * println(dateObj)
	   * dateObj.toString()         * dateObj.getMonthName(dateObj) * dateObj.getMonthName(n)
	   * dateObj.getDaysInYear(),   * dateObj.getDaysInMonth()      * dateObj.isLeapYear
	   * dateObj.setDay(dd)         * dateObj.setMonth(mmm)         * dateObj.setYear(yyyy)

	   * dateObj.getDay()           * dateObj.getMonth()            * dateObj.getYear()
	   * dateObj.equals(dateObj)    * dateObj.prevDay()             * dateObj.nextDay()
	   * dateObj.before(dateObj)    * dateObj.getDayOfWeekName()    
	   * dateObj.getWkDayName(n)   * dateObj.getDaySuffix()

	   * Each Date object represents an instance of a unique year/month/day
*/




#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{									
private:							// Date Class Member Fields -- Class fields should be encapsulated as they are here within 'private'									
	int year;						// Represents the year state of each date object
	int month;						// Represents the month state of each date object
	int day;						// Represents the day state of each date object

			
public:	

	Date(int, int, int);			// Default constructor with argument types declared
	Date(Date());					// Constructor with object argument	

	~Date();						// Noisy Destructor


// """""""""""""""""""""""""""""""""""""""""""""""""" Function Declarations Below  """"""""""""""""""""""""""""""""""""""""""""""""""
// 
//  Accessor - Assignment Methods   (Getter/Setter)  .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    
// .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .
//	   
	int getDay();	
	int getMonth();
	int getYear();

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	
	bool isLeapYear();
	int getDaysInYear();
	int getDaysInMonth();

	string getMonthName();
	string getMonthName(int);

	string getWkDayName();
	string getWkDayName(int);

	string getDaySuffix();
	void displayDate();
	//
//
//
//  Mutator Methods   (Date Object State Change)     .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    
// .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .
//
	void nextDay();
	void prevDay();
	Date spanDaysToDate(int);
	bool before(Date);
	bool equals(Date);
	int daysBetween(Date);
//
//
};

