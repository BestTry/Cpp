// Class declaration file: 'envent.h'
#pragma once
#include "time.h"
#include "date.h"
#include<iostream>
#include<string>

using namespace std;

class Event                                                     // Event class
{

public:
    Event(int hours = 0, int minutes = 0, int m = 1,            // Variable names unnessary, show for understanding
        int d = 1, int y = 1900, string name = "Christmas");
                                                                
        void setEventData(int hours, int minutes, int m, int d, int y, string name);
        void printEventData();

private:
    string eventName;
    Time eventTime;
    Date eventDay;

};