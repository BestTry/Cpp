// Defintion File: timeClassExpl.cpp
// Member-function definitions for class Time.

#include "timeClsEx.h"                             // Include declaration of class Time from  timeClsExp.h
#include <iostream>                                 // Perenteses are used when file is outside of C++ standard library
#include <iomanip>

using std::cout;
using std::setfill;
using std::setw;


Time::Time(int hr, int min, int sec)                // Time constructor initializes each data member to zero or client values; See Declaration file
{                                                   // This ensures all Time objects start in a consistent state
    setTime(hr, min, sec);                          // Validates acceptable values and sets time

}                                                   // End Time constructor

                                                    // Constructor take universal values for arguments
void Time::setTime(int h, int m, int s)             // Set new Time value using universal time format, perform validity
{                                                   // Checks on the data values and sets invalid values to zero
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}                                                   // End function setTime


void Time::printUniversal()                         // Print time in universal format
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;

}                                                   // End function printUniversal


void Time::printStandard()                          // Print Time in standard format
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second
        << (hour < 12 ? " AM" : " PM");
}                                                   // End function printStandard
