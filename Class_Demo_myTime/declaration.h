// Fig. 9.7: declaration.h ***************************************************************************************************
// Declaration of class 'myTime' - myTime header file with *.h extension placed within 'header'Header Files' section  
// Member functions of the myTime' class are defined in the myTime.cpp file under the "Source Files" section
// All the file were / are place within the same 'File Explorer' folder which is 'Class_Demo_MyTime'
//
#pragma once                           // Prevents multiple inclusions of header during compilation
#include <iostream>                    // Required to implement cout
#include <string>
#include <string_view>                 // Required for long strings with spaces #include 

using namespace std;
using std::format;
using std::cout;
using std::endl;

class myTime {                         // Declaration of myTime class

public:                                // Function Prototypes / Declarations (not definitions) are placed in header files
                                       // Functions must be placed within "public" to be accessible
                                       // Declaration of function within 'myTime' class; Displays in 24-hour and 12-hour formats
   myTime();                           // Default constructor must be placed within the 'public' section
  
   void  displayTime(string_view message);
   void setTime(int hour, int minute, int second);
   string to24HourString() const;      // 24-hour string format - Does not modify data - only conversions functions
   string to12HourString() const;      // 12-hour string format - Does not modify data - only conversions functions          

private:                               // Utilizing "In-Class" initializers - recommended - may be overridden within constructor
   int m_hour{ 0 };                    // 0 - 23 (24-hour clock format)
   int m_minute{ 0 };                  // 0 - 59 Minutes
   int m_second{ 0 };                  // 0 - 59 Seconds

};                                     // Note the required ending semicolon ' ; ' after class ending brace


