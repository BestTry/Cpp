// Class_GetterSetter.cpp : Pulled code freom Deitel - "How to Program" Chapter 6 - Using Set and Get Functions
//
// Description of Program  Demonstrate Set and Get functions.  Convention is to use the names Set and Get but this is optional.

						// The Preprocessor Directives: (Header Files)
#include "time3.h"		// Include declaration of class Time from time3.h
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
using std::setprecision;// setprecision(2)indicates a double variable value should be printed with 2 digits to the right of the decimal point


using namespace std;	// Common practice to implement the "std" namespace as it contains multiple supporting useful functions


// .........................................   Function Prototype Declaration Header References   ............................................

											
void incrementMinutes(TimeCls&, const int);	// Prototype - Takes time reference object and constant interger - 'minute'
void exitPrgm();							// Use this function as a optional default to terminate the program


int main()									// Function main() begins program execution - Entry point for the program
{
	cout << "\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>   Main Code Execution   <<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "            Demonstrating the Data Memeber Handlers - Getters and Setters       \n\n" << endl;

	TimeCls tObj;							// Create Time object 'tObj'
											// Set time using individual set functions instead of all three arguments at once
	tObj.setHour(17);						// Set hour to valid value
	tObj.setMinute(34);						// Set minute to valid value
	tObj.setSecond(25);						// Set second to valid value

											// Use get functions to obtain hour, miunute and second
	cout << " Result of setting all valid time values:\n "
		 << "  Hours: "   << tObj.getHour()
		 << "  Minutes: " << tObj.getMinute()
		 << "  Seconds: " << tObj.getSecond();

	// Set time using individual set functions
	tObj.setHour(234);						// Invalid hour set to 0
	tObj.setMinute(43);						// Set minute to valid value
	tObj.setSecond(6373);					// Invalid second set to 0

											// display hour, minute and second after setting 
											// invalid hour and second values
	cout << "\n\n Result of attempting to set invalid hour and seconds:\n"
		 << "  Hours: "   << tObj.getHour()
		 << "  Minutes: " << tObj.getMinute()
		 << "  Seconds: " << tObj.getSecond() << "\n\n";

	tObj.setTime(11, 57, 0);				// Set time
	incrementMinutes(tObj, 5);				// Increment tObj's minute by 3 (Function argument 'tObj' object and '5' integer minute


	exitPrgm();								// Option function member to terminate program
	system("pause");						// Some compilers do not recognize this statement
	return 0; 								// Indicates successful termination
}											// End of main

// .............................................   Function Code Definition Implementation  .................................................


void incrementMinutes(TimeCls& tRefObj, const int count)	// Add specified number of minutes to a Time object
{
	cout << " Incrementing minute " << count << " times:\n  Start time: ";
	tRefObj.printStandard();

	for (int i = 0; i < count; i++) {						// Sets minute by first retrieving present time, minute parameter
		tRefObj.setMinute((tRefObj.getMinute() + 1) % 60);	// Adds one to existing minute, unless present minute is '59'

		if (tRefObj.getMinute() == 0)						// Minute turned over from '59' to '60' => reset minute to zero 
			tRefObj.setHour((tRefObj.getHour() + 1) % 24);	// Increment hour since minute advanced past '59'

		cout << "\n  minute + 1: ";
		tRefObj.printStandard();
	}														// End for-loop
	cout << endl;
}															// End function IncrementMinutes


void exitPrgm()
{
	cout << "\n\n   		   >>>>>>>>>>  Program has Terminated  <<<<<<<<<< " << endl;
	cout << " \n\n\n " << endl;
	exit(0);												// Terminate running program from anywhere it is called:
}

/*

|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|....|
012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		  |         |         |         |         |         |         |         |         |         |         |         |         |         |
00		  10        20        30        40        50        60        70        80        90		00		  10        20        30        40

*/