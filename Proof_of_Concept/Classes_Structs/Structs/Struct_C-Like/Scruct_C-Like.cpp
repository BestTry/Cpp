// Scruct_C-Like.cpp : Code pulled from "How to Program - Deitel Chapter 6 - Classes and Data Acquistion // Fig. 6.1: fig06_01.cpp
//
// Description of Program:    Deitel recommends NOT to use this type code!
// There are many problems associated with with - See text in chapter for description
// Also - In a video tutorial, the tutorial said that all member in a struct are public
// ..........................................................................................
// ..........................................................................................
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

struct Time {							// structure definition
	int hour;							// 0-23 (24-hour clock format)
	int minute;							// 0-59
	int second;							// 0-59
};										// end struct Time

void printUniversal(const Time&);		// prototype  Reference to a constant Time type object
void printStandard(const Time&);		// prototype  Reference to a constant Time type object

void exitPrgm();						// Use this function as a optional default to terminate the program


int main()								// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "                        Demonstrating a C-Like Structure      \n\n" << endl;

	Time dinnerTime;					// Instantiate an object variable of new type 'Time'
	dinnerTime.hour = 18;				// set hour member of dinnerTime (Using dot notation) - Structs are all public anyway
	dinnerTime.minute = 37;				// set minute member of dinnerTime
	dinnerTime.second = 12;				// set second member of dinnerTime

	cout << "Dinner will be held at ";	// Passing the object reference to the function printUniversal
	printUniversal(dinnerTime);			// dinnerTime is a reference to the object
	cout << " universal time,\nwhich is ";
	printStandard(dinnerTime);			// Passing the object reference to the function printStandard
	cout << " standard time.\n";		

	dinnerTime.hour = 29;				// set hour to invalid value
	dinnerTime.minute = 73;				// set minute to invalid value

	cout << "\nTime with invalid values: ";
	printUniversal(dinnerTime);
	cout << endl;
	

	exitPrgm();							// Option function member to terminate program
	system("pause");					// Some compilers do not recognize this statement
	return 0; 							// Indicates successful termination
}										// End of main

// .............................................   Function Code Definition Implementation  .................................................

void printUniversal(const Time& refTime)				// print time in universal-time format
{
	cout << setfill('0') << setw(2) << refTime.hour << ":"
		<< setw(2) << refTime.minute << ":"
		<< setw(2) << refTime.second;

}														// End function printUniversal

void printStandard(const Time& refTime)					// Print time in standard-time format
{
	cout << ((refTime.hour == 0 || refTime.hour == 12) ?
		12 : refTime.hour % 12) << ":" << setfill('0')	// Strip '12' from the output
		<< setw(2) << refTime.minute << ":"
		<< setw(2) << refTime.second
		<< (refTime.hour < 12 ? " AM" : " PM");
}														// End function printStandard

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