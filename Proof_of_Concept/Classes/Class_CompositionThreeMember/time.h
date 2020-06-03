// Time class declaration file: The time class is a component subclass member of the event class 'Event'
#pragma once
class Time                          //Time class
{     

public:

    Time();                         // Default constructor
    Time(int, int);                 // Constructor taking on two arguments hours and minutes
    void setTime(int, int);
    void printTime();
    void incrementHours();
    void incrementMinutes();

private:
    int hr;
    int min;

};

