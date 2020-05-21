#pragma once
// Declaration of class Time.      >>> Header File <<<
// Member functions are defined in time1.cpp

// prevent multiple inclusions of header file
#ifndef time1_h
#define time1_h

class Time {
public:                                 // Constructor and Member Functions
    Time();                             // Constructor declaration
    void setTime(int, int, int);        // Member Function / Method declaration: Set hour, minute, second
    void printUniversal();              // Member Function: Print universal-time format
    void printStandard();               // Member Function: Print standard-time format

private:                                // Data Members  . . . fields, attributes, parameters
    int hour;                           // 0 - 23 (24-hour clock format)
    int minute;                         // 0 - 59
    int second;                         // 0 - 59

}; // end class Time

#endif