// Class Definition File: time5.cpp
// Member-function definitions for class Time.  Showing constant attributed functions

#include <iostream>
#include <iomanip>
#include "time5.h"                          // include definition of class Time from time5.h

using std::cout;
using std::setfill;
using std::setw;
                                            // Constructor function to initialize private data;
                                            // calls member function setTime to set variables;
                                            // default values are set to zero: 0 (see class definition)
Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);

}                                           // End Time constructor

                                            // Set time function: Set hour, minute and second values
void Time::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}                                           // End function setTime


void Time::setHour(int h)                   // Set hour value
{
    hour = (h >= 0 && h < 24) ? h : 0;
}                                           // End function setHour


void Time::setMinute(int m)                 // Set minute value
{
    minute = (m >= 0 && m < 60) ? m : 0;
}                                           // End function setMinute


void Time::setSecond(int s)                 // Set second value
{
    second = (s >= 0 && s < 60) ? s : 0;
}                                           // End function setSecond


int Time::getHour() const                   // Return hour value    - Constant Function
{
    return hour;
}                                           // End function getHour 


int Time::getMinute() const                 // Return minute value  - Constant Function
{
    return minute;
}                                           // End function getMinute


int Time::getSecond() const                 // Return second value  - Constant Function
{
    return second;
}                                           // End function getSecond


void Time::printUniversal() const           // Print Time in universal format   - Constant Function
{
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;
}                                           // End function printUniversal

                                            
void Time::printStandard()                  // Print Time in standard format    - Constant Function
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second
        << (hour < 12 ? " AM" : " PM");
}                                           // End function printStandard

