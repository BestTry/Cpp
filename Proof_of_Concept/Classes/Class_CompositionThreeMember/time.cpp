// Time class definition file: time.cpp

#include "time.h"
#include<iostream>
#include<string>

using namespace std;


Time::Time()                                    // Default constructor - initializes attributes 
{     
    hr = 0;
    min = 0;
}


Time::Time(int hours, int minutes)              // Constructor taking on arguments
{                                               // Class time constructor that accepts parameters
    if (0 <= hours && hours < 24) {             // Verify hours are valid
        hr = hours;
    }
    else {
        hr = 0;
    }

    if (0 <= minutes && minutes < 60) {         // Verify minutes are valid
        min = minutes;
    }
    else {
        min = 0;
    }
}


void Time::setTime(int hours, int minutes)      // Sets a valid time
{ 
    if (0 <= hours && hours < 24) {
        hr = hours;
    }
    else {
        hr = 0;
    }

    if (0 <= minutes && minutes < 60) {
        min = minutes;
    }
    else {
        min = 0;
    }
}


void Time::printTime()                          // Displays the hours and minutes to the console
{
    if (hr < 10) {                              // Formating time output in xx:xx
        cout << "0";
    }
    cout << hr << ":";

    if (min < 10) {
        cout << "0";
    }
    cout << min << endl;
}


void Time::incrementHours()                     // Increments hours by one hour
{  
    hr++;
    if (hr > 23) {
        hr = 0;
    }
}


void Time::incrementMinutes()                   // Increments minutes by one
{     
    min++;
    if (min > 59) {                             // Check for advancing to next hour
        min = 0;
        incrementHours();
    }
}