// Source Definition File (*.h)
//
#include "pch.h"
#include <iostream>
#include <string>
#include "Date.h"
#include <vector>

using namespace std;
									// Note that when referencing identifiers in the 'Date.h' file, prefix identfier by Date::identifier

									// String array consisting of month of the year indexed 0-11 -- Used for getMonthName() in function group
string monthList[]	 =	{ "January", "February", "March", "April", "May", "June", "July",
							"August", "September", "October", "November", "December" };

									// String array consisting day of the week indexed 0-6 -- Used for getWkDayName() in function group
string weekDayList[] =	{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };


									// Constructor of this class Date - Used to initialize state of created object  
									// Assure date values are legitimate - No negative & months > 12
									// No negatives, months > 12, or days greater than days in month
Date::Date(int initialYear, int initialMonth, int initialDay)
{
	if (initialYear < 1) 
	{
		throw invalid_argument("Error! Year value must be positive   ");
	}

	if (initialMonth < 1 || month > 12) 
	{
		throw invalid_argument("Error!  Month value must be between 1 anf 12    ");
	}

	if (initialDay < 1 || initialDay > getDaysInMonth()) 
	{
		throw invalid_argument("Error!  Day value must be with month's allowable days   ");
	}
	
	year = initialYear;				// Fields of class declared in the Date.h file
	month = initialMonth;
	day = initialDay;
}


Date refDate0 = Date(2012, 01, 01);	// Instantiate reference date falling on the weekday of a Sunday

Date::~Date()
{
}


// """""""""""""""""""""""""""""""""""""""""""""" Function Definitions Below  """"""""""""""""""""""""""""""""""""""""""""""""""
//
//  Accessor - Assignment Methods   (Getter/Setter)  .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    
// .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .
//
int Date::getDay()									// >>>>>
{
	return day;
} 
//
int Date::getMonth()								// >>>>>		
{
	return month;
} 
//
int Date::getYear()									// >>>>>	
{
	return year;
} 
//
void Date::setDay(int newDay)						// >>>>>	
{
	day = newDay;
}
//
void Date::setMonth(int newMonth)					// >>>>>
{
	month = newMonth;
}
//
void Date::setYear(int newYear)						// >>>>>
{
	year = newYear;
}
//
bool Date::isLeapYear()								// >>>>>
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));	// Check condition of leap year
}
//
int Date::getDaysInYear()							// >>>>>	
{
	if (isLeapYear())
	{
		return 366;
	}
	else 
	{
		return 365;
	}
}
//
int Date::getDaysInMonth()							// >>>>>
{ 	 
	if (month == 9 || month == 4 || month == 6 || month == 11) 
	{
		return 30;								// Month number designations: (9, 4, 6, 11)
	}
	else if (month == 2) 
	{
		if (isLeapYear()) 
		{
			return 29;
		}
		else 
		{
			return 28;
		}
	}
	else
	{											// Month number designations:
		return 31;								//  (1, 3, 5, 7, 8, 10, 12) not (9, 4, 6, 11, or  2)
	}
}				
//
string Date::getMonthName()						// >>>>>
{   	
	return monthList[month - 1];
}
//									
string Date::getMonthName(int month)			// >>>>>
{												// Overloaded 'getMonthName' method
	return monthList[month - 1];
}
//
string getWkDayName(int weekDay)				// >>>>>
{
	return weekDayList[weekDay];
}
//
string Date::getWkDayName()						// acquires the weekday name of Sunday - Saturday
{												// by counting days between refdate0 day and this object's day
	string weekDay;                            
	int dayCount, daysPastSun;
												// sunday, 2012 january 1st is refdate0 - see instantiation above
	dayCount = daysBetween(refDate0);			// count from reference date since it occurs on sunday (weekdaylist ndx == 0)
	daysPastSun = dayCount % 7;                  // acquire day of week in (range 0-6) sun - sat
												// by getting the remainder from (daycount / 7)
	if (before(refDate0))						// chk if 'this' obj date occurs before ref date
	{
		weekDay = weekDayList[7 - daysPastSun];	// get num of days away from ref date sunday
	}											// since output is 1 - 7 > add weekdayname[7] > sun
	else 
	{											
		weekDay = weekDayList[daysPastSun];		// count days forward to 'this' date
	}                                           // which is after the 2012, 01, 01 ref date
	return weekDay;
}
//
string Date::getWkDayName(int weekDay)			// >>>>>
{												// Access string array consisting of day of week indexed 0-6
	return weekDayList[weekDay];
}
//
string Date::getDaySuffix()						// >>>>>
{
	int dayOfMonth = getDay();								
	int lastDigit = dayOfMonth % 10;
	if (dayOfMonth >= 11 && dayOfMonth <= 19)
	{
		return "th";
	}
	else
	{
		switch (lastDigit)
		{
		case (1):
			return "st";
		case (2):
			return "nd"; 
		case (3):
			return "rd";
		default:
			return "th";
		}
	}
}
//
void Date::displayDate()						// >>>>>
{
	cout << getYear() << "/" << getMonth() << "/" << getDay();
}
//





// """""""""""""""""""""""""""""""""""""""""""""" Function Definitions Continued """"""""""""""""""""""""""""""""""""""""""""""""
//
//  Mutator Methods   (Date Object State Change)     .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    
// .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .    .
//
//												
void Date::nextDay()							// Next Day - Increment day which may impact month and or year
{												// Example of a Mutator which changes the state of an object
	day++;										// Check if we exceeded the days in the month
	if (day > getDaysInMonth())					// Account for day exceeding total days in current month
	{											// Days exceeded allowable days in month
		month++;								// Wrap (increment) the date day & month to next month and day 1
		day = 1;
		if (month > 12) {						// Check if allowable 12 month max was exceeded to month 13 
			month = 1;							// Month 12 exceeded -> Wrap to nexr year with month equal 1
			year++;
		}
	}
}
//
//
//												
 void Date::prevDay()							// Previous Day - decrement day which may impact month and or year							
{												// Example of a Mutator which changes the state of an object											
	day--;										
	if (day < 1)								// Check if day falls below first day of month
	{	month--;								// If days falls into previous month, wrap (decrement) the date day/month to previous 
		if (month < 1)							// Check if month is earlier than January, if so wrap to December of previous year
		{
			month = 12;
			year--;
		}										
		day = getDaysInMonth();					// Adjust last day of new month which has month / year dependences
	}
}
//
//
//						
 Date Date::spanDaysToDate(int deltaDays)		// Find new date by moving deltaDays days from present date
 {
	 Date newDate = Date(year, month, day);		// Instantiate newDate date object from this date object parameters so as to not modify orig date object;
	 if (deltaDays > 0) 
	 {
		 while (deltaDays != 0) 
		 {										// Keep incrementing days forward until target day is reached
			 newDate.nextDay();					// Change day's date to next day's date (Increase day by one)
			 deltaDays--;						// Counting down the number of days forward
		 }
	 }
	 else if (deltaDays < 0) 
	 {											// Delta is negative here so we decrement count(increase deltaDays)
		 while (deltaDays != 0) 
		 {										// Keep decrementing days back until target day is reached
			 newDate.prevDay();					// Change day's date to previous day's date (Decrease day by one)
			 deltaDays++;						// Counting down the number of days forward (increase neg number)
		 }
	 }
	 return newDate;							// Return new adjusted target date after moving deltaDays days from 'this', present object date
 }
//
//
//												
int Date::daysBetween(Date other)				// Counts number of days between 'this' object's date & other object's date
{
	int count = 0;								// Count == 0 assumes days between each date are equal: Each object has same date
												
	if (before(other))							
	{											// Case: 'this' objects date is earlier than the 'other' (endDate) object's date tthat is passed in
		 Date endDate = Date(other);			// Use endDate date here so not to modify 'other' object date
		 while (endDate.year != year || endDate.month != month ||  endDate.day != day)
		 {										
			 endDate.prevDay();					// Decrement endDate date into the past until it reaches this object's date
			 count++;							// Counting backward until endDate date == this object's date
		 }										
		 return count;							
	 }
	else			                            
	{											// Case: 'this' objects date is later than the 'other' (endDate) object's date
		 Date endDate = Date(other);			// Use endDate date here so not to modify 'other' object date
		 while (endDate.year != year || endDate.month != month || endDate.day != day)											 
		 {                                 
			 endDate.nextDay();					// Increment endDate date into the future until it reaches this object's date
			 count++;							// Counting forward until endDate date == this object's date
		 }                                 
		 return count;							// return the difference between the two date is the number of days
	 }
}
 //
 //
 //
 bool Date::before(Date other)					// Returns true if 'this' object's date is before 'other' object date
 {												// Check for previous year, same year previous month, or same year and month previous day
	 return ((year < other.year) ||
		 (year == other.year && month < other.month) ||
		 (year == other.year && month == other.month && day < other.day));
 }
 //
 //
 //
 bool Date::equals(Date other)					// Returns true if 'this' object's date is equal 'other' object's date
 {
	 return (year == other.year && month == other.month && day == other.day);
 }
 //
 /*                     ***** Date Class Methods  &  Local Static Methods *****
	   -------------------------------------------------------------------------------------------
									* dateObj.getMonthName(dateObj) * dateObj.getMonthName(n)
	   * dateObj.getDaysInYear(),   * dateObj.getDaysInMonth()      * dateObj.isLeapYear
	   * dateObj.setDay(dd)         * dateObj.setMonth(mmm)         * dateObj.setYear(yyyy)

	   * dateObj.getDay()           * dateObj.getMonth()            * dateObj.getYear()
	   * dateObj.equals(dateObj)    * dateObj.prevDay()             * dateObj.nextDay()
	   * dateObj.before(dateObj)    * dateObj.getDayOfWeekName()
	   * dateObj.getWeekDayName(m   * dateObj.getDaySuffix()
*/