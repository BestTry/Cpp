// Fig. 9.8: Time.cpp ********************************************************************************************
// Class 'myTime' member-function Definitions. 
#include <iostream>                    // Required to implement cout
#include <format>
#include <stdexcept>                   // Used for invalid_argument exception class: invalid_argument    
#include <string>
#include "myTime.h"                    // Required 'Include' declaration of class myTime from myTime.h header file

using namespace std;
using std::format;
using std::string;
using std::cout; 

myTime::myTime() {};                   // Default Constructor with empty implementation 
                                       // The 'Scope Resolution Operator"::" is required to know under what class 
                                       // the 'constructor and the fuction (setTime) resides 
                                       // (See the header file 'myTime.h' for declarations 
                                       // 
                                       // Set new Time value using 24-hour time format: 
                                       // Definition of 'setTime' member function; Receives three integer arguments
void myTime::setTime(int hour, int minute, int second) {
                                       // Validate hour, minute and second integer type variables before proceeding
   if ((hour < 0 || hour >= 24) || (minute < 0 || minute >= 60) ||
      (second < 0 || second >= 60)) {  // If any condition is true the object terminates and exception is thrown
      throw std::invalid_argument{     // Throw an exception if validation catches invalid argument
         "Invalid time entered: hour, minute or second was out of range" };
                                       // The throw returns the text shown between the " message quotes " shown here
   }                                   // If code passes thru this validity check without exception, assign value to members

   m_hour = hour;                      // Values are valid (Verified above) - assign argument values to member functions
   m_minute = minute;
   m_second = second;
}                                      // End of 'setTime() function definition

                                       // Note:
                                       // Syntax < :: > double colon is Scope Resolution Operator ties it under 'myTime" class
                                       // Read as 'to24HourString()' is included in Time class definition
                                       // Returns Time as a string in 24-hour format (HH:MM:SS): Definition of member function     
string myTime::to24HourString() const {
   return format("{:02d}:{:02d}:{:02d}", m_hour, m_minute, m_second);
}                                      // End of 'to24HourString()' function definition

                                       // Return Time as string in 12-hour format (HH:MM:SS AM or PM):
                                       // Definition of member function 
string myTime::to12HourString() const {
   return format("{}:{:02d}:{:02d} {}",// Accomadate before/after noon numeric output with modulus operator
      ((m_hour % 12 == 0) ? 12 : m_hour % 12), m_minute, m_second,
      (m_hour < 12 ? "AM" : "PM"));    // Before noon insert 'AM', After noon insert 'PM'
}                                       // End of 'to24HourString()' function definition

