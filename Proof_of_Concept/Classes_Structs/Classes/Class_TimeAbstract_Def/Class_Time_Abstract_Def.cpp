// Class_Time_Abstract_Def.cpp : 
// Main file: Class_Constr_Init.cpp - Pulled form Deitel, "How to Program" 4th addition, chap 6 - Default Arguments with Constructor.
//
// In this version of the Time class program the header Declaration / Prototype code and the Definition implementation code have been
// moved to external files.  The compiler invokes them by the usage of the #include statements.
//
						// The Preprocessor Directives: (Header Files) 						
#include "timeClsEx.h"	// include declaration of class Time from timeClExp.h	
#include <iostream> 	// Standard Template Library class  -  Used for cout, cin, cerr, printf  ( That is the  reason for brackets < > )
#include <iomanip>		// Required to utilize parameterized stream manipulator ie. calling setprecision(3) & fixed functions

						// The double colons operator '::' is defined as the "Scope Resolution Operator"
using std::cout;		// Console output
using std::cin;			// Console input
using std::endl;		// End of Line - Clears output buffer and terminates with a new-line character
using std::fixed;		// Both 'fixed' & 'showpoint' are nonparamatized stream manipulators that Do Not require the <iomanip> header file
using std::pow;			// Standard Library Function pow(x,y) definded as x raised to the y power
using std::setfill;		// Fills output with leading characters between the sign and value when a number is displayed: from <iomannip> 
using std::setw;		// Assure #include <iomanip> is included which requires a parameterized stream manipulator


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// .........................................   Function Prototype Declaration Header References   ............................................

void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Demonstrating Initializing Constructor with Default Arguments        \n\n" << endl;

											// Multiple objects are constructed with none to various optional argugents.
	Time t1;								// All arguments defaulted to zero as specified in the Time class declaration file: 'time2.h'
	Time t2(2);								// Minute and second defaulted to zero, hour is specified to '2'
	Time t3(21, 34);						// Seecond defaulted to zero, hour and minute specified to '21' and '34'
	Time t4(12, 25, 42);					// All values specified
	Time t5(27, 74, 99);					// All bad invalied values specified that are unverified by the setTime() function memeber

	cout << " Time constructed with:\n\n"
		<< " All default arguments:\n  ";
	t1.printUniversal();					// 00:00:00 Universal format - (No argument were specified)
	cout << "\n  ";
	t1.printStandard();						// 12:00:00 AM - (No argument were specified so attributes defaulted to: 00:00:00)

	cout << "\n\n Hour specified; default minute and second:\n  ";
	t2.printUniversal();					// 02:00:00 - Only the hour (2) was specified during instantiation
	cout << "\n  ";
	t2.printStandard();						// 2:00:00 AM

	cout << "\n\n Hour and minute specified; default second:\n  ";
	t3.printUniversal();					// 21:34:00
	cout << "\n  ";
	t3.printStandard();   					// 9:34:00 PM

	cout << "\n\n Hour, minute, and second specified:\n  ";
	t4.printUniversal();					// 12:25:42
	cout << "\n  ";
	t4.printStandard();						// 12:25:42 PM

	cout << "\n\n All invalid values specified:\n  ";
	t5.printUniversal();					// 00:00:00
	cout << "\n  ";
	t5.printStandard();						// 12:00:00 AM
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