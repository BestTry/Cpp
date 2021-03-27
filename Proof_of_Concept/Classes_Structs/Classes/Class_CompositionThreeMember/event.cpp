// Class definition file: event.cpp''
//
#include "event.h"
#include<iostream>
#include<string>

using namespace std;

Event::Event(int hours, int minutes, int m, int d, int y, string name)
      : eventTime(hours, minutes), eventDay(m, d, y)
{
    eventName = name;
}

void Event::setEventData(int hours, int minutes, int month, int day, int year, string name)
{
    eventTime.setTime(hours, minutes);
    eventDay.setDate(month, day, year);
    eventName = name;
}


void Event::printEventData()                            // Display event on console
{
    cout << " The event '" << eventName << "' occurs on date ";
    eventDay.printDate();
    cout << " at time ";
    eventTime.printTime();

    cout << endl;

}