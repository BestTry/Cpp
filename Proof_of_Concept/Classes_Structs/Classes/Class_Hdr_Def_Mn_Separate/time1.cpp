// Member-function definitions for class Time.  >>> Implementation Code File <<<
//
#include <iostream>                                         // Appears that these includes must be inserted here as well
#include <iomanip>
using std::cout;

using std::setfill;
using std::setw;

#include "time1.h"                                          // include definition of class Time from time1.h

Time::Time()                                                // Time constructor initializes each data member to zero.
{                                                           // Ensures all Time objects start in a consistent state.
    hour = minute = second = 0;

}                                                           // end Time constructor

void Time::setTime(int h, int m, int s)                    // Set new Time value using universal time. Perform validity
{                                                           // checks on the data values. Set invalid values to zero.
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;

}                                                           // end function setTime


void Time::printUniversal()                                // print Time in universal format
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;

}                                                           // end function printUniversal


void Time::printStandard()                                 // print Time in standard format
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second
        << (hour < 12 ? " AM" : " PM");

}                                                           // end function printStandard

