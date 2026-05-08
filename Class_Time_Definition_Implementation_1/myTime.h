// Fig. 9.7: myTime.h ***************************************************************************************************
// Class definition 'myTime' - myTime header file with *.h extension placed within header folder            
// Member functions of the 'myTime' class are defined in the myTime.cpp file under the "Source Files" folder
#pragma once                           // Prevents multiple inclusions of header during compilation
#include <iostream>                    // Required to implement cout
#include <string>
#include <string_view>                 // Required for long strings with spaces between text/individual strings 

using namespace std;
using std::format;
using std::cout;
using std::endl;
                                       
class myTime {                         // Declaration of class "myTime"

public:                                // Function Prototypes / Declarations (not definitions) - Placed in the header file
   myTime();

   void setTime(int hour, int minute, int second);
   string to24HourString() const;      // 24-hour string format - Does not modify data - only conversions functions
   string to12HourString() const;      // 12-hour string format - Does not modify data - only conversions functions

private:                               // Utilizing "In-Class" initializers - recommended - may be overridden within constructor
   int m_hour{ 0 };                    // 0 - 23 (24-hour clock format)
   int m_minute{ 0 };                  // 0 - 59 Minutes
   int m_second{ 0 };                  // 0 - 59 Seconds
  
};                                     // Note mandatory ending semicolon ' ; ' after class ending brace


