// Definition / Implementation code file for the date class  -   Fig. 8.11: date1.cpp
// Date class member function definitions.
#include <iostream>
#include "date1.h"


const int Date::days[] =                                    // Specify allow maximum days in each month
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };      // Initialize static member at file scope; - one class-wide copy

Date::Date(int m, int d, int y)                             // Date constructor - will set default date to 1/1/1900
{
    setDate(m, d, y);
}                                                           // End Date constructor


void Date::setDate(int mm, int dd, int yy)                  // Sets month, day and year and validates legitimacy
{
    month = (mm >= 1 && mm <= 12) ? mm : 1;                 // Check validity using if statement's conditional operator (?:)
    year = (yy >= 1900 && yy <= 2100) ? yy : 1900;          // Check year validity        
    if (month == 2 && leapYear(year))                       // Test for a leap year
        day = (dd >= 1 && dd <= 29) ? dd : 1;
    else
        day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}                                                           // End of function setDate


Date& Date::operator++()                                    // overloaded preincrement operator 
{
    helpIncrement();                                        // Use utility function

    return *this;                                           // Reference return to create an lvalue
}                                                           // End function operator++

                                                            // Tricky process to post increment!
Date Date::operator++(int)                                  // Overloaded postincrement operator; note that the dummy 
{                                                           // integer parameter does not have a parameter name
    Date temp = *this;                                      // Hold and return present object unincrmented in date object 'temp'
    helpIncrement();                                        // Utility function will increment the present date object 
                                                            // Return unincremented, saved, temporary object
    return temp;                                            // Value return; not a reference return
}                                                           // End function operator++


const Date& Date::operator+=(int additionalDays)            // Add specified number of days to date
{
    for (int i = 0; i < additionalDays; i=i+1) {            // The old method of incrementing by one !!!
    helpIncrement();
    }
    return *this;                                           // Enables cascading
}                                                           // End of function operator+=


bool Date::leapYear(int testYear) const                     // Check if year is a leap year, return true, otherwise, return false
{
    if (testYear % 400 == 0 ||
        (testYear % 100 != 0 && testYear % 4 == 0))
        return true;                                        // Passes leap year criteria
    else
        return false;                                       // Not a leap year - fails leap year test

}                                                           // End of function leapYear


bool Date::endOfMonth(int testDay) const                    // Determine whether the day is the last day of the month
{
    if (month == 2 && leapYear(year))
        return testDay == 29;                               // Add additional day in last day of Feb. in leap year
    else
        return testDay == days[month];
}                                                           // End function endOfMonth


void Date::helpIncrement()                                  // Utility function to help increment the date per date rules{
{   
    if (!endOfMonth(day))                                   // If day is not end of month, increment the day and exit
        ++day;
    else        
        if (month < 12) {                                   // day is end of month and month < 12 (Not December) or roll over to new year
            ++month;
            day = 1;
        }                                
        else {                                              // Last day of year - December 31 - roll over to new year
            ++year;
            month = 1;
            day = 1;
        }
}                                                           // End of function helpIncrement


ostream& operator<<(ostream& output, const Date& d)         // Overloaded output operator
{
    static const char* monthName[13] = { "", "January",
       "February", "March", "April", "May", "June",
       "July", "August", "September", "October",
       "November", "December" };

    output << monthName[d.month] << ' '
        << d.day << ", " << d.year;

    return output;                                          // Enables cascading

}                                                           // End function operator<<
