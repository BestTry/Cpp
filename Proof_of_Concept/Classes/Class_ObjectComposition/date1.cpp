// Class Definition File: date1.cpp
// Member-function definitions for class Date.
//
#include <iostream>
#include "date1.h"                      // Include Date class definition from date1.h

using std::cout;
using std::endl;

Date::Date(int mn, int dy, int yr)      // Constructor confirms proper value for month; calls
{                                       // Utility function checks to confirm proper date values    
    month = checkMonth(mn);             // Validate the month
    day   = checkDay(dy);               // Validate the day
    year  = checkYear(yr);              // Validate year
                                        
    cout << " Date object constructor was called for date: ";
    print();                            // Display date object indicating its constructor was called
    cout << endl;

}                                       // End Date constructor


Date::~Date()                           // Destructor - Output Date object to show when its destructor is called
{
    cout << " Date object destructor for date: ";
    print();
    cout << endl;

}                                       // End ~Date destructor


int Date::checkMonth(int month) const
{
    if (month > 0 && month <= 12)       // Validate the month
        return month;
    else {                              // Invalid month set to 1
        cout << " Month: " << month << "   is invalid.  Set to month   '1'\n";
        return 1;
    }

}


int Date::checkDay(int testDay) const   // Utility function to confirm proper day value based 
{                                       // on month and year; handles leap years, too
    static const int daysPerMonth[13] =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    if (month == 2 && testDay == 29 &&  // February 29 check for leap year 
        (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0)))
        return testDay;
    // If flow control has dropped to here, date value is invalid
    cout << " Day:   " << testDay << "   is invalid.  Set to day     '1' \n";
    return 1;                           // Leave object in consistent state if bad value

}                                       // End function checkDay


int Date::checkYear(int year) const // Utility function to confirm proper year value 
{
    if (year > 999 && year < 7777)
    {
        return year;
    }
    else {
        cout << " Year:  " << year << " is invalid.  Set to year '0001' \n";
        return 0001;
    }

}

void Date::print() const                // Print date object attributes in form month/day/year
{
    cout << month << '/' << day << '/' << year;

}                                       // End function print