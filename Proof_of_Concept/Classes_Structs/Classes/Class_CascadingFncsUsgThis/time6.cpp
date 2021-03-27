// Class Definition file: time6.cpp
// Member-function definitions for Time class.

#include "time6.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::setfill;
using std::setw;
                                                    
Time::Time(int hr, int min, int sec)                // Constructor function to initialize private data;
{                                                   // Calls member function setTime to set variables;
    setTime(hr, min, sec);                          // Default values are 0 (see class definition)
}                                                   // End Time constructor


Time& Time::setTime(int h, int m, int s)            // Set values of hour, minute, and second
{                                                   // Returns reference ' *this '
    setHour(h);
    setMinute(m);
    setSecond(s);

    return *this;                                   // Enables cascading
}                                                   // End function setTime


Time& Time::setHour(int h)                          // Set hour value - returns ' *this ' time reference object
{
    hour = (h >= 0 && h < 24) ? h : 0;
    return *this;                                   // Enables cascading
}                                                   // End function setHour


Time& Time::setMinute(int m)                        // Set minute value - returns ' *this ' time reference object
{
    minute = (m >= 0 && m < 60) ? m : 0;
    return *this;                                   // Enables cascading
}                                                   // End function setMinute


Time& Time::setSecond(int s)                        // Set second value - returns ' *this ' time reference object
{
    second = (s >= 0 && s < 60) ? s : 0;
    return *this;                                   // Enables cascading
}                                                   // End function setSecond


int Time::getHour() const                           // Get hour value
{
    return hour;
}                                                   // End function getHour


int Time::getMinute() const                         // Get minute value
{
    return minute;
}                                                   // End function getMinute


int Time::getSecond() const                         // Get second value
{
    return second;
}                                                   // End function getSecond


void Time::printUniversal() const                   // Print Time in universal format 
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;
}                                                   // End function printUniversal


void Time::printStandard() const                    // Print Time in standard format
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second
        << (hour < 12 ? " AM" : " PM");
}                                                   // End function printStandard