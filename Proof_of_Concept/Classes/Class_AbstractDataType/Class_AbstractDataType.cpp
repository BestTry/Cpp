// Class_AbstractDataType.cpp :  Code pulled from "How to Program - Deitel Chapter 6 - Classes and Data Acquistion // Fig. 6.3: fig06_03.cpp
//

// Additonal Code Description : Examples of class / Structure Declarations:
// 1 - Time timeObject;				// Object of type Time of class Time
// 2 - Time timeArray[ 10 ];		// Array of time type objects ( Ten elements )
// 3 - Time *timePointer;			// Pointer to a time type object intialized to the address ot timeObject 
// 4 - Time &timeRef;				// Reference to a time type object (alias) that is initialize with timeObject
//
                        // The Preprocessor Directives: (Header Files) 							
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions
#include <fstream>		// Inherited from 'basic_fstream' for file I/O - Defines Data types: ofstream, ifstream, and fstream
#include <sstream>		// Used when interfacing strings by reading from and writing to files
#include <string>		// Use the s suffix for literal strings 'string' class - required as a new way of using strings, non char sequence
#include <windows.h>	// Required to implement adjusting the Consoles window size and position - CAUSES PROBLEMS with <limits>
#include <typeinfo>		// Necessary for imlementing the typeid() function 
#include <memory>		// Necessary when using smart pointers. Syntax: unique_ptr<int> ptrName( new int );
#include <array>		// Necessary when using the array class i.e array<arrType, size>
#include <vector>		// Support vector operations - See inputDate
#include <algorithm>	// Copy algorithm - Needed to utilize Standard Template Library functions
                        // Before compiling symbol '#' indicates a preprocessing contents of  
                        // the input/output stream header file iostream.  This file must be 
                        // included with any keyboard input or console screen output
                        // Functions within the standard library are as follows:
                        // Since classes below are part of C++ stadard library < > are placed around them
#include <cmath>		// Enables the use of the "pow" function with the math library and other mathematical functions
#include <functional>	// References the standard function library - std::function
#include <limits>		// Contains clasees for defining numerical data type limits on each computer platform
#include <thread>		// std::this_thread::sleep_for(std::chrono::seconds(XX) << endl;
#include <chrono>		// std::chrono::seconds(XX)
#include <cstdlib>		// Required to implement the rand() & srand() function.  Also, needed to execute the 'exit()' function.
#include <ctime>		// Required to implement the time(0) function providing a number to seed rand() using srand(): srand( time( 0 ) );
                        // Arguement (0) yields an interger value of the calendar in seconds

                        // The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setfill;		// Fills output with leading characters between the sign and value when a number is displayed: from <iomannip> 
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// .........................................   Function Prototype Declaration Header References   ............................................

void exitPrgm();						    // Use this function as a optional default to terminate the program

                                            // Time abstract data type (ADT) definition
class Time {

public:
    Time();                                 // Default constructor  - Function members - Methods
    void setTime(int, int, int);            // Set hour, minute, second
    void printUniversal();                  // Print universal-time format
    void printStandard();                   // Print standard-time format

private:
    int hour;     // 0 - 23 (24-hour clock format)
    int minute;   // 0 - 59
    int second;   // 0 - 59

}; // end class Time


Time::Time()
{                                           // Time constructor initializes each data member to zero and                           
    hour = minute = second = 0;             // Ensures all Time objects start in a consistent state

}                                           // end constructor Time

                                            // Function Member 'setTime()'
void Time::setTime(int h, int m, int s)     // Set new Time value using universal time, perform validity
{                                           // Checks on the data values and set invalid values to zero
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;

} // end function setTime


void Time::printUniversal()                 // Funciton Member  'printUniversal()'
{                                           // Print Universal Time Function Member _ print Time in universal format
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second;

} // end function printUniversal


void Time::printStandard()                  // print Time in standard format
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
        << ":" << setfill('0') << setw(2) << minute
        << ":" << setw(2) << second
        << (hour < 12 ? " AM" : " PM");

} // end function printStandard

int main()
{
    Time t;  // instantiate object t of class Time

    // output Time object t's initial values
    cout << "The initial universal time is ";
    t.printUniversal();  // 00:00:00

    cout << "\nThe initial standard time is ";
    t.printStandard();   // 12:00:00 AM

    t.setTime(13, 27, 6);   // change time

    // output Time object t's new values
    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal();  // 13:27:06

    cout << "\nStandard time after setTime is ";
    t.printStandard();   // 1:27:06 PM

    t.setTime(99, 99, 99);  // attempt invalid settings

    // output t's values after specifying invalid values
    cout << "\n\nAfter attempting invalid settings:"
        << "\nUniversal time: ";
    t.printUniversal();  // 00:00:00

    cout << "\nStandard time: ";
    t.printStandard();   // 12:00:00 AM
    cout << endl;

    exitPrgm();					// Option function member to terminate program
    system("pause");			// Some compilers do not recognize this statement
    return 0; 					// Indicates successful termination
}								// End of main



// .............................................   Function Code Definition Implementation  .................................................
//    When functional coded is declared above before the main coding section use this area for functional code implementation

void exitPrgm()
{
    cout << "\n\n                  >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
    cout << " \n\n\n " << endl;
    exit(0);					// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
          |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/
