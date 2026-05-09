// Fig. 9.8: Time.cpp ********************************************************************************************
// Class 'myTime' member-function Definitions. 
#include <iostream>                    // Required to implement cout
#include <format>
#include <stdexcept>                   // Used for invalid_argument exception class: invalid_argument    
#include <string>
#include "declaration.h"                    // Include definition of class myTime from myTime.h header file

using namespace std;
using std::format;
using std::string;
using std::cout;
// For constructor and all functions the " :: " is required!!!
myTime::myTime() {};                   // Default constructor implementation with empty iplementation; 
   
                                       // Note the functions following the double colon '::' indicates the functions
                                       // are a member of the class 'myTime' and are required!
                                       // Set new Time value using 24-hour time: 
                                       // Definition of 'setTime' member function; Receives three integer arguments
void myTime::setTime(int hour, int minute, int second) {
                                       // Validate hour, minute and second integer type variables
   if ((hour < 0 || hour >= 24) || (minute < 0 || minute >= 60) ||
      (second < 0 || second >= 60)) {  // If any condition is true the object terminates and exception is thrown
      throw std::invalid_argument{     // Throw an exception if validation catches invalid argument
         "Invalid time entered: hour, minute or second was out of range" };
   }                                   // The throw returns the text shown between the " message quotes "
                                       // If code passes thru this validity check without exception,                                       
   m_hour = hour;                      // values are valid and assign argument values to member functions
   m_minute = minute;
   m_second = second;
}                                      // End of 'setTime() function definition 'setTime'                              
                                       // Displays a Time in 24-hour and 12-hour formats
                                       // A reference address to a myTime constant is passed to the function
void myTime::displayTime(string_view message) {
   cout << format("{}\n 24-hour time: {}\n 12-hour time: {}\n\n",
      message, to24HourString(), to12HourString());
}
                                       // Note:
                                       // Syntax < :: > double colon is the 'Scope Resolution Operator'
                                       // Read as 'to24HourString()' is included in myTime class definition
                                       // Returns time as a string in 24-hour format (HH:MM:SS): Definition of member function 
                                       // The 'Scope Resolution Operator"::" is required to know under what class 
                                       // the 'constructor and the fuction (setTime) resides 
                                       // (See the header file 'declaration.h' for declarations 

string myTime::to24HourString() const {
   return format("{:02d}:{:02d}:{:02d}", m_hour, m_minute, m_second);
}                                      // End of 'to24HourString()' function definition

                                       // Return Time as string in 12-hour format (HH:MM:SS AM or PM):
                                       // Definition of member function 
string myTime::to12HourString() const {
   return format("{}:{:02d}:{:02d} {}",
      ((m_hour % 12 == 0) ? 12 : m_hour % 12), m_minute, m_second,
      (m_hour < 12 ? "AM" : "PM"));
}                                       // End of 'to24HourString()' function definition

